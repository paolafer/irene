#ifndef __LIGHTHIT_H__
#define __LIGHTHIT_H__

#include <iostream>
#include <TObject.h>
#include <TVector3.h>

namespace irene {

  class LightHit : public TObject {
    
  public:
    // default constructor
    LightHit();
    
    LightHit(std::string det_name);
    // destructor
    virtual ~LightHit() {}
    
  private:
    
    std::vector<std::pair<double, int> > _waveform;   
    double _pes;
    int _id;
    double _bin_width;
    std::string _detector_name;
    TVector3 _position;

  public:
    
    // set counts for a given time
    void SetSample(const double& amp, const double& time);
    const std::vector<std::pair<double, int> > GetWaveform() const;
 
    void SetPes(const double& pes);   
    const double GetPes() const; 

    void SetID(const int& id);
    const int GetID() const;

    void SetBinWidth(const double& width);
    double const GetBinWidth();
    
    void SetPosition(const double& x, const double& y, const double& z);
    const TVector3 GetPosition() const;

    void SetDetectorName(const std::string);
    const std::string GetDetectorName() const;

    void Info(ostream& s) const;
    

    ClassDef(LightHit,1);

  };
  
  // IN-LINE FUNCTIONS
  
  inline const std::vector<std::pair<double, int> > LightHit::GetWaveform() const {return _waveform;}
  inline void LightHit::SetPes(const double& pes) {_pes = pes;}
  inline const double LightHit::GetPes() const {return _pes;}
  inline void LightHit::SetID(const int& id) {_id = id;}
  inline const int LightHit::GetID() const {return _id;}
  inline void LightHit::SetBinWidth(const double& width) {_bin_width = width;}
  inline const double LightHit::GetBinWidth() {return _bin_width;}
  inline void LightHit::SetPosition(const double& x, const double& y, const double& z) {_position.SetXYZ(x, y, z);}
  inline const TVector3 LightHit::GetPosition() const {return _position;}
  inline void LightHit::SetDetectorName(const std::string det_name) {_detector_name = det_name;}
  inline const std::string LightHit::GetDetectorName() const {return _detector_name;}

}

ostream& operator << (ostream& s, const irene::LightHit& lh);

#endif
