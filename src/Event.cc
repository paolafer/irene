
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
    _sensor_hits = new TObjArray();
    _tracks = new TObjArray();
    _particles = new TObjArray(); 
  }

  Event::Event(const Event& right)
  {
    *this = right;
  } 

  Event& Event::operator=(const Event& right) 
  {
    if (this != &right) {
      _sensor_hits = (TObjArray*)right._sensor_hits->Clone();
      _tracks = (TObjArray*)right._tracks->Clone();
      _particles = (TObjArray*)right._particles->Clone();
    
      _eventID = right._eventID;
    }

    return *this;
  }



  Event::~Event() {
    IClear();  
    delete _sensor_hits;
    delete _tracks;
    delete _particles;	
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

  void Event::FillHitVector(std::vector<std::pair<TLorentzVector,double> >& evthits, 
                            std::string det) const
  {
    const TObjArray* tracks = GetTracks();

    for (int itr=0; itr<tracks->GetLast()+1; ++itr) 
    {
      Track* mytrack = (Track*)tracks->At(itr);
      if (mytrack->GetDetectorName() == det) 
      {
	     for (int ihit=0; ihit<mytrack->GetHits().size(); ++ihit) 
        {
	       std::pair<TLorentzVector,double> myhit = (mytrack->GetHits())[ihit];
	       evthits.push_back(myhit);
	       }
      }
    }
  }

  std::vector<std::pair<TLorentzVector,double> > Event::FillHitVector(std::string det) const
  {
    std::vector<std::pair<TLorentzVector,double> > evthits;
    FillHitVector(evthits,det);
    return evthits;
  }
                          
  
  void Event::IClear()
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

  std::vector<const irene::Track*> Event::Tracks() const
  {
    size_t n_itrks = _tracks->GetEntries();
    std::vector<const Track*> trks;
    
    for (size_t it = 0; it < n_itrks; ++it) { 
      const Track* itrk = dynamic_cast<const Track*> (_tracks->At(it)) ; 
      trks.push_back(itrk);
    }
    
    return trks;
  }

  std::vector<const irene::Track*> Event::Tracks(std::string det) const
  {
    size_t n_itrks = _tracks->GetEntries();
    std::vector<const Track*> trks;
    
    for (size_t it = 0; it < n_itrks; ++it) { 
      const Track* itrk = dynamic_cast<const Track*> (_tracks->At(it)) ; 
      if (itrk->GetDetectorName() == det) {
	trks.push_back(itrk);
      }
    }
    
    return trks;
  }
  
  std::vector<const irene::Particle*> Event::Particles() const
  {
    size_t n_p = _particles->GetEntries();
    std::vector<const Particle*> parts;

    for (size_t it = 0; it < n_p; ++it)
    { 
      const Particle* ip = dynamic_cast<const Particle*> (_particles->At(it)) ; 
      parts.push_back(ip);
    }

    return parts;
  }

  void Event::IInfo(ostream& s) const
  {
    s << std::endl;    
    s << "event number = " << GetID() << std::endl;

    const TObjArray* tracks = GetTracks();
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

    const TObjArray* sensorhits = GetSensorHits();
     
    for (unsigned int ihit=0; ihit<sensorhits->GetLast()+1; ++ihit) {
      SensorHit* myhit = (SensorHit*)sensorhits->At(ihit);
      s << *myhit <<std::endl;
    }
  
    s << " List of true hits in the event"
      << "------------------------------------" << std::endl;
    s << std::endl;   
    
    for (unsigned int itrack=0; itrack<tracks->GetLast()+1; ++itrack) {
      Track* mytrack = (Track*)tracks->At(itrack);
      s << std::endl;
      s << "Detector " << mytrack->GetDetectorName() << std::endl;
      s << std::endl;
      s << *mytrack <<std::endl;
    }


    s << " List of particles in the event"
      << "------------------------------------" << std::endl;
    const TObjArray* particles = GetParticles();
    
    for (unsigned int ipart=0; ipart<particles->GetLast()+1; ipart++){
      Particle* mypart = (Particle*)particles->At(ipart);
      s << *mypart <<std::endl;
    }    
  
  }

} // end namespace irene

ostream& operator << (ostream& s, const irene::Event& ev) {
  ev.IInfo(s);
  return s; 
}
