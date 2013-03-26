
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

ClassImp(irene::Track)

namespace irene {

  Track::Track()
  {
    _id = 0;
    _track_length = 0;
    _particle = 0;
    _detector_name = "unknown";
    _hits.clear();
  }

  Track::Track(std::string& detector)
  {
    _detector_name = detector;
    _id = 0;
    _track_length = 0;
    _particle = 0;
    _hits.clear();
  }

  Track::~Track()
  {  
  }

  void Track::AddHit(double x, double y, double z, 
		     double t, double energy)
  {
    std::pair<TLorentzVector,double> newhit;
    newhit.first.SetXYZT(x,y,z,t);
    newhit.second = energy;
    
    _hits.push_back(newhit);
    
  }


  void Track::SetParticle(Particle* particle) 
  {
    _particle = particle;
  }

  Particle* Track::GetParticle() 
  {
    if (!_particle.GetObject()) {
      std::cerr << "[ERROR: irene::Track::GetParticle()]:" 
		<< " the track has no particle associated!" << std::endl;
    }
    return dynamic_cast<Particle*> (_particle.GetObject());
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
