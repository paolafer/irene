// ----------------------------------------------------------------------------
///  \file   Particle.h
///  \brief  A class that describes a particle with all its properties.
///
///  \author   <paola.ferrario@ific.uv.es>
///  \date     14 Feb 2013
///  \version  $Id$
///
///  Copyright (c) 2013 NEXT Collaboration
// ----------------------------------------------------------------------------

#ifndef __PARTICLE__
#define __PARTICLE__

#include <string>
#include <map>

#include <TObject.h>
#include <TLorentzVector.h>
#include <TRef.h>
#include <TRefArray.h>

namespace irene {class Track;}

namespace irene {

  /// This class describes a simulated particle with its properties
  class Particle : public TObject
  {

  public:
    /// Constructors
    Particle();
    Particle(std::string name);
    Particle(const int& pdg);
    /// Destructor
    ~Particle();
    
  private:
    int _PDGcode; ///< PDG code of the particle
    TLorentzVector _initial_vertex; ///< point and time of generation
    TLorentzVector _decay_vertex; ///< point and time of death
    TLorentzVector _initial_momentum; ///< initial momentum and energy
    TLorentzVector _decay_momentum; ///< final momentum and energy
    int _G4TrackID; ///< identification number coming from the Geant4 simulation
    bool _primary; ///< true if the particle is the one directly generated in Geant4
    bool _has_mother; ///< true if the particle comes from another particle through some process
    TRef _mother; ///< reference to the mother particle
    TRef _track; ///< reference to the track which contains the true hits of the particle
    TRefArray _daughters; ///< array of references to the secondary particles
    double _mass; ///< mass. It cannot be set, it is given through the name or the PDG code.
    double _charge; ///< charge. It cannot be set, it is given through the name or the PDG code.
    double _lifetime; ///< life time. It cannot be set, it is given through the name or the PDG code.
    double _track_length; ///< length of the associated track
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

    void SetTrackLength(const double& length);
    const double GetTrackLength() const;
    
    void SetPrimary(bool is_primary);
    const bool IsPrimary();

    void SetMother(const irene::Particle* mother);
    const irene::Particle* GetMother() const;

    void SetTrack(const irene::Track* track);
    const irene::Track* GetTrack() const;
    irene::Track* GetTrack();

    void AddDaughter(irene::Particle* daughter);
    
    const TRefArray GetDaughters() const;
    TRefArray& GetDaughters();
 
    void SetParameters(double m, double q, double l);

    void SetParticleName(std::string name);
    void SetName(const int& code);
    const std::string Name() const;

    void SetOriginVolume(const std::string& vol);
    const std::string GetOriginVolume() const;

    void SetDecayVolume(const std::string& vol);
    const std::string GetDecayVolume() const;

    void SetCreatorProcess(const std::string& process);
    const std::string GetCreatorProcess() const;

    void AddProperty(std::string pname, double& pvalue);
    const double FindProperty(const std::string pname);

    const double GetMass() const;
    const double GetCharge() const;

    /* Useful methods to access some properties*/

    double Energy() const;
    double Momentum() const;

    void Info(ostream& s) const;
    
    

    ClassDef(Particle,1);

  };

  // INLINE functions
  inline void Particle::SetPDGcode(const int& pdg) {_PDGcode = pdg;}
  inline const int Particle::GetPDGcode() const {return _PDGcode;}
  inline const TLorentzVector Particle::GetInitialVertex() const {return _initial_vertex;}
  inline const TLorentzVector Particle::GetDecayVertex() const {return _decay_vertex;}
  inline const TLorentzVector Particle::GetInitialMomentum() const {return _initial_momentum;}
  inline const TLorentzVector Particle::GetDecayMomentum() const {return _decay_momentum;}
  inline void Particle::SetG4TrackID(const int& trackID) {_G4TrackID = trackID;}
  inline const int Particle::GetG4TrackID() const {return _G4TrackID;}
  inline void Particle::SetTrackLength(const double& length) {_track_length = length;}
  inline const double Particle::GetTrackLength() const {return _track_length;}
  inline const std::string Particle::Name() const {return _name;}
  inline void Particle::SetOriginVolume(const std::string& vol) {_origin_volume = vol;}
  inline const std::string Particle::GetOriginVolume() const {return _origin_volume;}
  inline void Particle::SetDecayVolume(const std::string& vol) {_decay_volume = vol;}
  inline const std::string Particle::GetDecayVolume() const {return _decay_volume;}
  inline void Particle::SetCreatorProcess(const std::string& process) {_creator_process = process;}
  inline const std::string Particle::GetCreatorProcess() const {return _creator_process;}
  inline void Particle::AddProperty(std::string pname, double& pvalue) {_properties[pname] = pvalue;}
  inline const double Particle::FindProperty(const std::string pname) {return _properties[pname];}
  inline const double Particle::GetMass() const {return _mass;}
  inline const double Particle::GetCharge() const {return _charge;}

  inline double Particle::Energy() const {return _initial_momentum.Energy();}
  inline double Particle::Momentum() const {return _initial_momentum.P();}

}

ostream& operator << (ostream& s, const irene::Particle& p);

#endif
