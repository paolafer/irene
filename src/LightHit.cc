#include "LightHit.h"

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
  

  // LightHit::LightHit(const irene::LightHit& hit)
  // {
  //   _pes = hit._pes;
  //   _waveform = hit._waveform;
  // }

  void LightHit::SetSample(const double& amp, 
			   const double& time) {
    std::pair<double, int> sample;
    sample.first = time;
    sample.second = amp;
    _waveform.push_back(sample);
  } 

} // namespace irene


