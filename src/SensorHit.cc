
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

ClassImp(irene::SensorHit)

namespace irene {

  SensorHit::SensorHit() : _amplitude(0),
			 _id(0),
			 _bin_width(0)		      
  {
    _waveform.clear();
    _detector_name = "unknown";
    _position.SetXYZ(0., 0., 0.);
  }

  SensorHit::SensorHit(std::string det_name) : _amplitude(0),
					       _id(0),
					       _bin_width(0)	
  {
    _waveform.clear();
    _detector_name = det_name;
    _position.SetXYZ(0., 0., 0.);
  }

  SensorHit::~SensorHit() 
  {
    
  }  

  void SensorHit::SetSample(double amp, 
			    double time) {
    std::pair<double, int> sample;
    sample.first = time;
    sample.second = amp;
    _waveform.push_back(sample);
  } 
  
  void SensorHit::SInfo(ostream& s) const
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
  lh.SInfo(s);
  return s; 
}
