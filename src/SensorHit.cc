
// ----------------------------------------------------------------------------
//  $Id$
//
//  Author:  <paola.ferrario@ific.uv.es>
//  Created: 14 Feb 2013
//  
//  Copyright (c) 2013 NEXT Collaboration
// ---------------------------------------------------------------------------- 

#include "SensorHit.h"

#include <iomanip>

using namespace irene; 

ClassImp(SensorHit)

namespace irene {

  SensorHit::SensorHit() : _waveform(0),   
			 _amplitude(0),
			 _id(0),
			 _bin_width(0)		      
  {
    _detector_name = "unknown";
    _position.SetXYZ(0., 0., 0.);
  }

  SensorHit::SensorHit(std::string det_name) 
  {
    _detector_name = det_name;
  }
  

  void SensorHit::SetSample(const double& amp, 
			   const double& time) {
    std::pair<double, int>* sample = new std::pair<double, int>;
    sample->first = time;
    sample->second = amp;
    _waveform.push_back(sample);
  } 
  
  void SensorHit::Info(ostream& s) const
  {
    //  s << std::endl;    
    s << this->GetDetectorName() << " hit, ID = " << this->GetID()  
     << std::endl;
    s  << " x (mm)    y (mm)    z (mm)    " << std::endl;
    s << std::setw(5) << _position.X() <<"     " 
      << std::setw(5) << _position.Y() <<"     " 
      << std::setw(5) << _position.Z() << std::endl;
    s << "total charge = "<< _amplitude << std::endl;
  }

} // namespace irene

ostream& operator << (ostream& s, const irene::SensorHit& lh) {
  lh.Info(s);
  return s; 
}
