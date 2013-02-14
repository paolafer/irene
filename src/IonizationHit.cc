// ----------------------------------------------------------------------------
//  $Id$
//
//  Author:  <paola.ferrario@ific.uv.es>
//  Created: 14 Feb 2013
//  
//  Copyright (c) 2013 NEXT Collaboration
// ---------------------------------------------------------------------------- 

#include "IonizationHit.h"
#include <iomanip>

using namespace irene;

ClassImp(IonizationHit)

namespace irene {

  IonizationHit::IonizationHit(): _deposited_energy(0),
				  _ionizationID(0),
				  _particle(0)				  
  {
    _space_time.SetXYZT(0., 0., 0., 0.);
    _detector_name = "unknown";
   }

  IonizationHit::IonizationHit(std::string det_name)
  {
    _detector_name = det_name;
  }

  IonizationHit::~IonizationHit()
  {
    
  }

  const irene::Particle* IonizationHit::GetParticle() const
  {
    return dynamic_cast<irene::Particle*> (_particle.GetObject());
  }

  void IonizationHit::Info(ostream& s) const
  {
    // s << std::endl;  
    s << _detector_name << " hit " << std::endl;
    s  << " x (mm)    y (mm)    z (mm)    " << std::endl;
    s << std::setw(5) << _space_time.X() <<"     " 
      << std::setw(5) << _space_time.Y() <<"     " 
      << std::setw(5) << _space_time.Z() << std::endl;
    s << "deposited energy = "<< _deposited_energy << std::endl;
    s << "time = "<< _space_time.T() << std::endl;
  }
  
} // namespace irene

ostream& operator << (ostream& s, const irene::IonizationHit& ih) {
  ih.Info(s);
  return s; 
}
