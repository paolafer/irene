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

#ifndef SENSORHIT_H_
#define SENSORHIT_H_

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
    ~SensorHit();
    
  private:
    
    std::vector<std::pair<double, int> > _waveform; ///< times and counts of the sensor's response  
    double _amplitude; ///< total counts summed over all the times
    int _id; ///< unique identification number 
    double _bin_width; ///< width of the time bins
    std::string _detector_name; ///< type of sensor
    TVector3 _position; ///< position of the sensor

  public:
    
    void SetSample(double amp, double time);
    const std::vector<std::pair<double,int> >& GetWaveform() const;
 
    void SetAmplitude(double amplitude);   
    double GetAmplitude() const; 

    void SetID(int id);
    int GetID() const;

    void SetBinWidth(double width);
    double GetBinWidth() const;
    
    void SetPosition(double x, double y, double z);
    TVector3 GetPosition() const;

    void SetDetectorName(std::string);
    const std::string& GetDetectorName() const;

    void SInfo(ostream& s) const;
    
    ClassDef(SensorHit,1);

  };
  
  // IN-LINE FUNCTIONS
  
  inline const std::vector<std::pair<double, int> >& SensorHit::GetWaveform() const {return _waveform;}
  inline void SensorHit::SetAmplitude(double amplitude) {_amplitude = amplitude;}
  inline double SensorHit::GetAmplitude() const {return _amplitude;}
  inline void SensorHit::SetID(int id) {_id = id;}
  inline int SensorHit::GetID() const {return _id;}
  inline void SensorHit::SetBinWidth(double width) {_bin_width = width;}
  inline double SensorHit::GetBinWidth() const {return _bin_width;}
  inline void SensorHit::SetPosition(double x, double y, double z) {_position.SetXYZ(x,y,z);}
  inline TVector3 SensorHit::GetPosition() const {return _position;}
  inline void SensorHit::SetDetectorName(std::string det_name) {_detector_name = det_name;}
  inline const std::string& SensorHit::GetDetectorName() const {return _detector_name;}

} // end namespace irene

ostream& operator << (ostream& s, const irene::SensorHit& lh);

#endif
