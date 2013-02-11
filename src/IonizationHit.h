#ifndef __IONIHIT__
#define __IONIHIT__

#include "Particle.h"

#include <iostream>
#include <TObject.h>
#include <TLorentzVector.h>
#include <TRef.h>

namespace irene {
  
  class IonizationHit: public TObject {

  public:
    // constructor
    IonizationHit();
    IonizationHit(std::string det_name);
    // destructor
    ~IonizationHit();

  private:
    TLorentzVector _space_time;
    double _deposited_energy;
    int _ionizationID;
    TRef _particle;
    std::string _detector_name;

  public:
    
    void SetSpacetime(const double& x, const double& y, const double& z, const double& t);    
    const TLorentzVector GetSpacetime() const;

    void SetEnergy(const double& energy);
    const double GetEnergy() const;

    void SetIonizationID(const int& ioniID);
    const double GetIonizationID() const;

    void SetParticle(const Particle* part);
    const irene::Particle* GetParticle() const;

    const std::string GetDetectorName() const;

    void Info(ostream& s) const;

    ClassDef(IonizationHit,1);

  };

  // INLINE functions
  inline  void IonizationHit::SetSpacetime(const double& x, const double& y, const double& z, const double& t) {
    _space_time.SetXYZT(x, y, z, t);
  }
  inline const TLorentzVector IonizationHit::GetSpacetime() const {return _space_time;}
  inline void IonizationHit::SetEnergy(const double& energy) {_deposited_energy = energy;} 
  inline const double IonizationHit::GetEnergy() const {return _deposited_energy;}
  inline void IonizationHit::SetIonizationID(const int& ioniID) {_ionizationID = ioniID;}
  inline const double IonizationHit::GetIonizationID() const {return _ionizationID;}
  inline void IonizationHit::SetParticle(const irene::Particle* part) {_particle = (irene::Particle*)part;}
  inline const std::string IonizationHit::GetDetectorName() const {return _detector_name;}
  
}

ostream& operator << (ostream& s, const irene::IonizationHit& lh);

#endif
