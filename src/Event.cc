#include "Event.h"
#include "LightHit.h"
#include "Particle.h"

#include <TRef.h>
#include <TClonesArray.h>

using namespace irene;

ClassImp(Event)

namespace irene {

  TClonesArray* Event::_slight_hits = 0;

  Event::Event() : _eventID(0), _nlhits(0)
  {
    if (!_slight_hits) {
      _slight_hits = new TClonesArray("irene::LightHit", 100);
      std::cout << "Existe!" << std::endl;
    }
  
    _light_hits = _slight_hits;
  }
 
  LightHit* Event::AddLightHit(const std::string det_name)
  {
    if (!_light_hits) 
      std::cout << "Now it doesn't exist!" << std::endl;
    std::cout << "Entering AddLighHit in position " << std::endl;
    irene::LightHit* lhit = (irene::LightHit*)_light_hits->ConstructedAt(_nlhits++);
    std::cout << "hit created" << std::endl;
    lhit->SetDetectorName(det_name);
    std::cout << "Name set" << std::endl;
    return lhit;
  }

  // void Event::AddIonizationHit(const irene::IonizationHit* hit)
  // {
  //   _ionization_hits.Add((irene::IonizationHit*) hit);
  // }

  // const std::vector<irene::IonizationHit*> Event::GetIonizationHits() const
  // {
  //   std::vector<irene::IonizationHit*> hits;

  //   for (int i=0; i<_ionization_hits.GetLast()+1; ++i) {
  //     irene::IonizationHit* myhit = dynamic_cast<irene::IonizationHit*> (_ionization_hits[i]);
  //     hits.push_back(myhit);
  //   }
  //   return hits;
  // }

  //  void Event::AddParticle(const irene::Particle* part)
  // {
  //   _particles.Add((irene::Particle*) part);
  // }

  // const std::vector<irene::Particle*> Event::GetParticles() const
  // {
  //   std::vector<irene::Particle*> particles;

  //   for (int i=0; i<_particles.GetLast()+1; ++i) {
  //     irene::Particle* mypart = dynamic_cast<irene::Particle*> (_particles[i]);
  //     particles.push_back(mypart);
  //   }
  //   return particles;
  // }

  void Event::Clear()
  {
    _light_hits->Clear();
    // _ionization_hits.Clear();
    // _particles.Clear();
    _eventID = 0;
  }

  void Event::Info(ostream& s) const{

  // s << std::endl;
    
  // s << " event number= " << this->GetID() << std::endl;
    
  // //  s << " event vertex (mm)= " << this->GetOriginvertex()  << std::endl;
    
  // s << " Event has " << this->GetIonizationHits().size() << " ionization hits"
  //   << std::endl;
  // // s << " Event has " << this->GetLightHits()->size() << " light hits"
  // //   << std::endl;
  // s << " Event has " << this->GetParticles().size() << " particles"
  //   << std::endl;    
  
  // s << " List of ionization hits in the event"
  //   << "------------------------------------" << std::endl;
  // std::vector<IonizationHit*> ionihits = this->GetIonizationHits();
    
  // // typedef multimap<string, hit*>::const_iterator I;  
  // for(unsigned int ihit=0; ihit<ionihits.size(); ++ihit)
  //   {
  //     //  s << ionihits[ihit]->GetDetectorName() <<" hit: "<<std::endl; 
  //      s << ionihits[ihit]->GetEnergy() <<std::endl; 
  //     //  s << *(i->second) <<std::endl;
  //   }


  // s << " List of particles in the event"
  //   << "------------------------------------" << std::endl;
  // std::vector<Particle*> particles = this->GetParticles();
    
  // for(unsigned int ipart=0; ipart<this->GetParticles().size(); ipart++){
      
  //   // Particle& p = *this->true_particles()[ipart];
  //   // s << p << std::endl;
    // }    
  
}

} // namespace irene

ostream& operator << (ostream& s, const irene::Event& ev) {
  ev.Info(s);
  return s; 
}
