#ifndef __PARTICLE__
#define __PARTICLE__

#include <string>
#include <map>

#include <TObject.h>
#include <TLorentzVector.h>
#include <TRef.h>
#include <TRefArray.h>

namespace irene {class IonizationHit;}

namespace irene {

  class Particle : public TObject
  {

  public:
    // constructor
    Particle();
    //    Particle(std::string);
    Particle(const int& pdg);
    // destructor
    ~Particle() {}
    
  private:
    int _PDGcode;
    TLorentzVector _initial_vertex;
    TLorentzVector _decay_vertex;
    TLorentzVector _initial_momentum;
    TLorentzVector _decay_momentum;
    int _G4TrackID;
    bool _primary;
    TRef _mother;
    TRefArray _daughters;
    TRefArray _ionization_hits;
    double _mass;
    double _charge;
    double _lifetime;
    double _track_length;
    std::string _name;
    std::string _origin_volume;
    std::string _decay_volume;
    std::string _creator_process;
    // temporary, needed for ionization clusters
    std::map<std::string, double> _properties;
    
    

  public:
    void SetPDGcode(const int& pdg);
    const int GetPDGcode() const;

    void SetInitialVertex(const double x, const double y, 
			  const double z, const double t);
    const TLorentzVector GetInitialVertex() const;
   
    void SetDecayVertex(const double x, const double y, 
			   const double z, const double t);
    const TLorentzVector GetDecayVertex() const;

    void SetInitialMomentum(const double x, const double y, 
			   const double z, const double t);
    const TLorentzVector GetInitialMomentum() const;

    void SetDecayMomentum(const double x, const double y, 
			   const double z, const double t);
    const TLorentzVector GetDecayMomentum() const;

    void SetG4TrackID(const int& trackID);
    const int GetG4TrackID() const;
    
    void SetPrimary(bool is_primary);
    const bool IsPrimary();

    void SetMother(const irene::Particle* mother);
    const irene::Particle* GetMother() const;

    void AddDaughter(const irene::Particle* daughter);
    const std::vector<irene::Particle*> GetDaughters() const;

    void AddIoniHit(const irene::IonizationHit* hit);
    const std::vector<irene::IonizationHit*> GetIoniHits() const;
 
    void SetParameters(double m, double q, double l);

    //   void SetParticleName(std::string name);
    void SetName(const int& code);
    const std::string Name() const;

    void SetTrackLength(const double& length);
    const double GetTrackLength() const;

    void SetOriginVolume(const std::string& vol);
    const std::string GetOriginVolume() const;

    void SetDecayVolume(const std::string& vol);
    const std::string GetDecayVolume() const;

    void SetCreatorProcess(const std::string& process);
    const std::string GetCreatorProcess() const;

    void AddProperty(std::string pname, double& pvalue);
    const double FindProperty(const std::string pname);

    /* Useful methods to access some properties*/

    const double Energy();
    
    

    ClassDef(Particle,1);

  };

  // INLINE functions
  inline void Particle::SetPDGcode(const int& pdg) {_PDGcode = pdg;}
  inline const int Particle::GetPDGcode() const {return _PDGcode;}
  inline const TLorentzVector Particle::GetInitialVertex() const {return _initial_vertex;}
  inline const TLorentzVector Particle::GetDecayVertex() const {return _decay_vertex;}
  inline const TLorentzVector Particle::GetInitialMomentum() const {return _initial_momentum;}
  inline const TLorentzVector Particle::GetDecayMomentum() const {return _decay_momentum;}
  inline void Particle::SetMother(const irene::Particle* mother) {_mother = (irene::Particle*)mother;}
  inline void Particle::SetG4TrackID(const int& trackID) {_G4TrackID = trackID;}
  inline const int Particle::GetG4TrackID() const {return _G4TrackID;}
  inline const std::string Particle::Name() const {return _name;}
  inline void Particle::SetTrackLength(const double& length) {_track_length = length;}
  inline const double Particle::GetTrackLength() const {return _track_length;}
  inline void Particle::SetOriginVolume(const std::string& vol) {_origin_volume = vol;}
  inline const std::string Particle::GetOriginVolume() const {return _origin_volume;}
  inline void Particle::SetDecayVolume(const std::string& vol) {_decay_volume = vol;}
  inline const std::string Particle::GetDecayVolume() const {return _decay_volume;}
  inline void Particle::SetCreatorProcess(const std::string& process) {_creator_process = process;}
  inline const std::string Particle::GetCreatorProcess() const {return _creator_process;}
  inline void Particle::AddProperty(std::string pname, double& pvalue) {_properties[pname] = pvalue;}
  inline const double Particle::FindProperty(const std::string pname) {return _properties[pname];}

  inline const double Particle::Energy() {return _initial_momentum.Energy();}

}

#endif
