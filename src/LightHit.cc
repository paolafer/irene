#include "LightHit.h"

#include <iomanip>

using namespace irene; 

ClassImp(LightHit)

namespace irene {

  LightHit::LightHit() : _waveform(0),   
			 _pes(0),
			 _id(0),
			 _bin_width(0)		      
  {
    _detector_name = "unknown";
    _position.SetXYZ(0., 0., 0.);
  }

  LightHit::LightHit(std::string det_name) 
  {
    _detector_name = det_name;
  }
  

  void LightHit::SetSample(const double& amp, 
			   const double& time) {
    std::pair<double, int> sample;
    sample.first = time;
    sample.second = amp;
    _waveform.push_back(sample);
  } 
  
  void LightHit::Info(ostream& s) const
  {
    s << std::endl;    
    s << this->GetDetectorName() << " hit, ID = " << this->GetID()  
     << std::endl;
    s  << " x (mm)    y (mm)    z (mm)    " << std::endl;
    s << std::setw(5) << _position.X() <<"     " 
      << std::setw(5) << _position.Y() <<"     " 
      << std::setw(5) << _position.Z() << std::endl;
    s << "total charge = "<< _pes << std::endl;
  }

} // namespace irene

ostream& operator << (ostream& s, const irene::LightHit& lh) {
  lh.Info(s);
  return s; 
}
