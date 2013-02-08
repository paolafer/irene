#include "Event.h"
#include "LightHit.h"
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

  void Event::AddLightHit(irene::LightHit* hit)
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
    _light_hits->Clear();
    _ionization_hits->Clear();
    _particles->Clear();
    _eventID = 0;
  }

  void Event::Info(ostream& s) const
  {
    s << std::endl;    
    s << " event number = " << this->GetID() << std::endl;
    
    //  s << " event vertex (mm)= " << this->GetOriginvertex()  << std::endl;
    
    s << " Event has " << this->GetIonizationHits()->GetLast()+1 << " ionization hits"
      << std::endl;
    s << " Event has " << this->GetLightHits()->GetLast()+1 << " light hits"
      << std::endl;
    s << " Event has " << this->GetParticles()->GetLast()+1 << " particles"
      << std::endl;  

    s << " List of light hits in the event"
      << "------------------------------------" << std::endl;
    TObjArray* lighthits = (TObjArray*)this->GetLightHits();
    
    for (unsigned int ihit=0; ihit<lighthits->GetLast()+1; ++ihit) {
      irene::LightHit* myhit = (irene::LightHit*)lighthits->At(ihit);
      s << " hit of type " << myhit->GetDetectorName() <<std::endl; 
      s << " energy = " << myhit->GetPes() << " pes" <<std::endl; 
      //  s << *(i->second) <<std::endl;
    }
  
    s << " List of ionization hits in the event"
      << "------------------------------------" << std::endl;
    TObjArray* ionihits = (TObjArray*)this->GetIonizationHits();
    
    for (unsigned int ihit=0; ihit<ionihits->GetLast()+1; ++ihit) {
      irene::IonizationHit* myhit = (irene::IonizationHit*)ionihits->At(ihit);
      s << " hit of type " << myhit->GetDetectorName() <<std::endl; 
      s << " energy = " << myhit->GetEnergy() << " MeV" <<std::endl; 
      //  s << *(i->second) <<std::endl;
    }


    s << " List of particles in the event"
      << "------------------------------------" << std::endl;
    TObjArray* particles = (TObjArray*)this->GetParticles();
    
    for (unsigned int ipart=0; ipart<this->GetParticles()->GetLast()+1; ipart++){
      
      // Particle& p = *this->true_particles()[ipart];
      // s << p << std::endl;
    }    
  
  }

} // namespace irene

ostream& operator << (ostream& s, const irene::Event& ev) {
  ev.Info(s);
  return s; 
}
