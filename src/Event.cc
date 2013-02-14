
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
#include "IonizationHit.h"
#include "Particle.h"

#include <TObjArray.h>

using namespace irene;

ClassImp(Event)

namespace irene {

  Event::Event() : _eventID(0)
  {
    _light_hits = new TObjArray();
    _ionization_hits = new TObjArray();
    _particles = new TObjArray();
  }

  Event::~Event() {
    Clear();
  }

  void Event::AddSensorHit(irene::SensorHit* hit)
  {
    _light_hits->AddLast(hit);
  }

  void Event::AddIonizationHit(irene::IonizationHit* hit)
  {
    _ionization_hits->AddLast(hit);
  }

   void Event::AddParticle(irene::Particle* particle)
  {
    _particles->AddLast(particle);
  }

  void Event::Clear()
  {
    _light_hits->Delete();
    _ionization_hits->Delete();
    _particles->Delete();
    _eventID = 0;
  }

  void Event::Info(ostream& s) const
  {
    s << std::endl;    
    s << "event number = " << this->GetID() << std::endl;
    
    s << "event has " << this->GetIonizationHits()->GetLast()+1 << " ionization hits"
      << std::endl;
    s << "event has " << this->GetSensorHits()->GetLast()+1 << " light hits"
      << std::endl;
    s << "event has " << this->GetParticles()->GetLast()+1 << " particles"
      << std::endl;  

    s << std::endl;  
    s << " List of light hits in the event"
      << "------------------------------------" << std::endl;
    s << std::endl;   

    TObjArray* lighthits = (TObjArray*)this->GetSensorHits();
     
    for (unsigned int ihit=0; ihit<lighthits->GetLast()+1; ++ihit) {
      irene::SensorHit* myhit = (irene::SensorHit*)lighthits->At(ihit);
      s << *myhit <<std::endl;
    }
  
    s << " List of ionization hits in the event"
      << "------------------------------------" << std::endl;
    s << std::endl;   

    TObjArray* ionihits = (TObjArray*)this->GetIonizationHits();
    
    for (unsigned int ihit=0; ihit<ionihits->GetLast()+1; ++ihit) {
      irene::IonizationHit* myhit = (irene::IonizationHit*)ionihits->At(ihit);
      s << *myhit <<std::endl;
    }


    s << " List of particles in the event"
      << "------------------------------------" << std::endl;
    TObjArray* particles = (TObjArray*)this->GetParticles();
    
    for (unsigned int ipart=0; ipart<particles->GetLast()+1; ipart++){
      irene::Particle* mypart = (irene::Particle*)particles->At(ipart);
      s << *mypart <<std::endl;
    }    
  
  }

} // namespace irene

ostream& operator << (ostream& s, const irene::Event& ev) {
  ev.Info(s);
  return s; 
}
