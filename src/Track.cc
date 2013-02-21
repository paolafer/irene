
// ----------------------------------------------------------------------------
//  $Id$
//
//  Author:  <paola.ferrario@ific.uv.es>
//  Created: 14 Feb 2013
//  
//  Copyright (c) 2013 NEXT Collaboration
// ---------------------------------------------------------------------------- 

#include "Track.h"
#include "Particle.h"

#include <iostream>
#include <iomanip>

using namespace irene;

ClassImp(Track)

namespace irene {

  Track::Track()
  {
    _particle = 0;
    _hits.clear();
  }

  Track::~Track()
  {  
  }

  void Track::AddHit(const double& x, const double& y, const double& z, 
  		const double& t, const double& energy)
  {
    std::pair<TLorentzVector,double> newhit;
    newhit.first.SetXYZT(x,y,z,t);
    newhit.second = energy;
    
    _hits.push_back(newhit);
    
  }


  void Track::SetParticle(irene::Particle* particle) 
  {
    _particle = (irene::Particle*)particle;
  }

  void Track::Info(ostream& s) const
  {
    for (int i=0; i<_hits.size(); ++i) {
      std::pair<TLorentzVector,double> myhit = _hits[i];
      s  << " x (mm)    y (mm)    z (mm)    " << std::endl;
      s << std::setw(5) << myhit.first.X() <<"     " 
	<< std::setw(5) << myhit.first.Y() <<"     " 
	<< std::setw(5) << myhit.first.Z() << std::endl;
      s << "deposited energy = "<< myhit.second << std::endl;
      s << "time = "<< myhit.first.T() << std::endl;
      s << "--------------------------------------" << std::endl;
    }
  }

}  // namespace irene

ostream& operator << (ostream& s, const irene::Track& tr) {
  tr.Info(s);
  return s; 
}
