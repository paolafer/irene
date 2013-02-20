// ----------------------------------------------------------------------------
///  \file   SensorHit.h
///  \brief  The response of a sensor.
///
///  \author   <paola.ferrario@ific.uv.es>
///  \date     14 Feb 2013
///  \version  $Id$
///
///  Copyright (c) 2013 NEXT Collaboration
// ----------------------------------------------------------------------------

#ifndef __SENSORHIT_H__
#define __SENSORHIT_H__

#include <iostream>
#include <TObject.h>
#include <TVector3.h>

namespace irene {

  class SensorHit : public TObject {
    
  public:
    // default constructor
    SensorHit();
    
    SensorHit(std::string det_name);
    // destructor
    virtual ~SensorHit() {}
    
  private:
    
    std::vector<std::pair<double, int> > _waveform;   
    double _amplitude;
    int _id;
    double _bin_width;
    std::string _detector_name;
    TVector3 _position;

  public:
    
    // set counts for a given time
    void SetSample(const double& amp, const double& time);
    const std::vector<std::pair<double, int> > GetWaveform() const;
 
    void SetAmplitude(const double& amplitude);   
    double GetAmplitude() const; 

    void SetID(const int& id);
    int GetID() const;

    void SetBinWidth(const double& width);
    double GetBinWidth() const;
    
    void SetPosition(const double& x, const double& y, const double& z);
    TVector3 GetPosition() const;

    void SetDetectorName(const std::string);
    std::string GetDetectorName() const;

    void Info(ostream& s) const;
    

    ClassDef(SensorHit,1);

  };
  
  // IN-LINE FUNCTIONS
  
  inline const std::vector<std::pair<double, int> > SensorHit::GetWaveform() const {return _waveform;}
  inline void SensorHit::SetAmplitude(const double& amplitude) {_amplitude = amplitude;}
  inline double SensorHit::GetAmplitude() const {return _amplitude;}
  inline void SensorHit::SetID(const int& id) {_id = id;}
  inline int SensorHit::GetID() const {return _id;}
  inline void SensorHit::SetBinWidth(const double& width) {_bin_width = width;}
  inline double SensorHit::GetBinWidth() const {return _bin_width;}
  inline void SensorHit::SetPosition(const double& x, const double& y, const double& z) {_position.SetXYZ(x, y, z);}
  inline TVector3 SensorHit::GetPosition() const {return _position;}
  inline void SensorHit::SetDetectorName(const std::string det_name) {_detector_name = det_name;}
  inline std::string SensorHit::GetDetectorName() const {return _detector_name;}

}

ostream& operator << (ostream& s, const irene::SensorHit& lh);

#endif
