
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

using namespace irene;

ClassImp(Event)

namespace irene {

  Event::Event() : _eventID(0)
  {
    _sensor_hits = new TObjArray();
    _tracks = new TObjArray();
    _particles = new TObjArray();
  }

  Event::~Event() {
    Clear();
  }

  void Event::AddSensorHit(irene::SensorHit* hit)
  {
    _sensor_hits->AddLast(hit);
  }

  void Event::AddTrack(irene::Track* track)
  {
    _tracks->AddLast(track);
  }

   void Event::AddParticle(irene::Particle* particle)
  {
    _particles->AddLast(particle);
  }

  void Event::Clear()
  {
    _sensor_hits->Delete();
    _tracks->Delete();
    _particles->Delete();
    _eventID = 0;
  }

  void Event::Info(ostream& s) const
  {
    s << std::endl;    
    s << "event number = " << this->GetID() << std::endl;

    TObjArray* tracks = (TObjArray*)this->GetTracks();
    int tothits=0;
    for (unsigned int itrack=0; itrack<tracks->GetLast()+1; ++itrack) {
      irene::Track* mytrack = (irene::Track*)tracks->At(itrack);     
      tothits = tothits +  mytrack->GetHits().size();
    }
    s << "event has " << tothits << " true hits"
      << std::endl;
    s << "event has " << this->GetSensorHits()->GetLast()+1 << " sensor hits"
      << std::endl;
    s << "event has " << this->GetParticles()->GetLast()+1 << " particles"
      << std::endl;  

    s << std::endl;  
    s << " List of sensor hits in the event"
      << "------------------------------------" << std::endl;
    s << std::endl;   

    TObjArray* sensorhits = (TObjArray*)this->GetSensorHits();
     
    for (unsigned int ihit=0; ihit<sensorhits->GetLast()+1; ++ihit) {
      irene::SensorHit* myhit = (irene::SensorHit*)sensorhits->At(ihit);
      s << *myhit <<std::endl;
    }
  
    s << " List of true hits in the event"
      << "------------------------------------" << std::endl;
    s << std::endl;   
    
    for (unsigned int itrack=0; itrack<tracks->GetLast()+1; ++itrack) {
      irene::Track* mytrack = (irene::Track*)tracks->At(itrack);
      s << *mytrack <<std::endl;
    }


    s << " List of particles in the event"
      << "------------------------------------" << std::endl;
    TObjArray* particles = (TObjArray*)this->GetParticles();
    
    for (unsigned int ipart=0; ipart<particles->GetLast()+1; ipart++){
      irene::Particle* mypart = (irene::Particle*)particles->At(ipart);
      s << *mypart <<std::endl;
    }    
  
  }

} // end namespace irene

ostream& operator << (ostream& s, const irene::Event& ev) {
  ev.Info(s);
  return s; 
}
