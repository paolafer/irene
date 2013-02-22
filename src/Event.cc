
// ----------------------------------------------------------------------------
//  $Id$
//
//  Author:  <paola.ferrario@ific.uv.es>
//  Created: 14 Feb 2013
//  
//  Copyright (c) 2013 NEXT Collaboration
// ---------------------------------------------------------------------------- 

#include "Event.h"
#include "SensorHit.h"
#include "Track.h"
#include "Particle.h"

#include <TObjArray.h>
#include <TLorentzVector.h>

ClassImp(irene::Event)

namespace irene {

  Event::Event() : _eventID(0)
  {
    _sensor_hits = 0;
    _tracks = 0;
    _particles = 0;
  }

  Event::Event(int id) : _eventID(id) 
  {
    std::cout << "Event constructor" << std::endl;   
    _sensor_hits = new TObjArray();
    _tracks = new TObjArray();
    _particles = new TObjArray();
  }

  Event::~Event() {
    std::cout << "Event destructor" << std::endl;
    Clear();
  }

  void Event::AddSensorHit(SensorHit* hit)
  {
    _sensor_hits->AddLast(hit);
  }

  void Event::AddTrack(Track* track)
  {
    _tracks->AddLast(track);
  }

   void Event::AddParticle(Particle* particle)
  {
    _particles->AddLast(particle);
  }

  void Event::GetHits(std::vector<std::pair<TLorentzVector,double> >& evthits)
  {
    TObjArray* tracks = (TObjArray*)GetTracks();

    for (int itr=0; itr<tracks->GetLast()+1; ++itr) {
      Track* mytrack = (Track*)tracks->At(itr);
      for (int ihit=0; ihit<mytrack->GetHits().size(); ++ihit) {
	std::pair<TLorentzVector,double> myhit = (mytrack->GetHits())[ihit];
	evthits.push_back(myhit);
      }
    }
   
  }
  
  void Event::Clear()
  {
    if (_sensor_hits) {
      _sensor_hits->Delete();
    }
    if (_tracks) {
      _tracks->Delete();
    }
    if (_particles) {
      _particles->Delete();
    }
    _eventID = 0;
  }

  void Event::Info(ostream& s) const
  {
    s << std::endl;    
    s << "event number = " << GetID() << std::endl;

    TObjArray* tracks = (TObjArray*)GetTracks();
    int tothits=0;
    for (unsigned int itrack=0; itrack<tracks->GetLast()+1; ++itrack) {
      Track* mytrack = (Track*)tracks->At(itrack);     
      tothits = tothits +  mytrack->GetHits().size();
    }
    s << "event has " << tothits << " true hits"
      << std::endl;
    s << "event has " << GetSensorHits()->GetLast()+1 << " sensor hits"
      << std::endl;
    s << "event has " << GetParticles()->GetLast()+1 << " particles"
      << std::endl;  

    s << std::endl;  
    s << " List of sensor hits in the event"
      << "------------------------------------" << std::endl;
    s << std::endl;   

    TObjArray* sensorhits = (TObjArray*)GetSensorHits();
     
    for (unsigned int ihit=0; ihit<sensorhits->GetLast()+1; ++ihit) {
      SensorHit* myhit = (SensorHit*)sensorhits->At(ihit);
      s << *myhit <<std::endl;
    }
  
    s << " List of true hits in the event"
      << "------------------------------------" << std::endl;
    s << std::endl;   
    
    for (unsigned int itrack=0; itrack<tracks->GetLast()+1; ++itrack) {
      Track* mytrack = (Track*)tracks->At(itrack);
      s << *mytrack <<std::endl;
    }


    s << " List of particles in the event"
      << "------------------------------------" << std::endl;
    TObjArray* particles = (TObjArray*)GetParticles();
    
    for (unsigned int ipart=0; ipart<particles->GetLast()+1; ipart++){
      Particle* mypart = (Particle*)particles->At(ipart);
      s << *mypart <<std::endl;
    }    
  
  }

} // end namespace irene

ostream& operator << (ostream& s, const irene::Event& ev) {
  ev.Info(s);
  return s; 
}
