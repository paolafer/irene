#include "IonizationHit.h"

using namespace irene;

ClassImp(IonizationHit)

namespace irene {

  IonizationHit::IonizationHit(): _deposited_energy(0),
				  _ionizationID(0),
				  _particle(0),
				  _detector_name(0)
  {
    _space_time.SetXYZT(0., 0., 0., 0.);
   }

  IonizationHit::IonizationHit(std::string det_name)
  {
    _detector_name = det_name;
  }

  const irene::Particle* IonizationHit::GetParticle() const
  {
    return dynamic_cast<irene::Particle*> (_particle.GetObject());
  }
  
}
