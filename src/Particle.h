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

#ifndef PARTICLE_H_
#define PARTICLE_H_

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
    Particle(int pdg);
    /// Destructor
    ~Particle();

   
  private:
    int _PDGcode; ///< PDG code of the particle
    TLorentzVector _initial_vertex; ///< point and time of generation
    TLorentzVector _decay_vertex; ///< point and time of death
    TLorentzVector _initial_momentum; ///< initial momentum and energy
    TLorentzVector _decay_momentum; ///< final momentum and energy
    int _particleID; ///< identification number coming from the Geant4 simulation
    bool _primary; ///< true if the particle is the one directly generated in Geant4
    TRef _mother; ///< reference to the mother particle
    TRefArray _tracks; ///< reference to the tracks that contains the true hits of the particle
    TRefArray _daughters; ///< array of references to the secondary particles
    double _mass; ///< mass. It cannot be set, it is given through the name or the PDG code.
    double _charge; ///< charge. It cannot be set, it is given through the name or the PDG code.
    double _lifetime; ///< life time. It cannot be set, it is given through the name or the PDG code.
    double _track_length; ///< length of the associated track
    std::string _name; ///< name
    std::string _origin_volume; ///< name of the volume where the particle is created
    std::string _decay_volume; ///< name of the volume where the particle dies
    std::string _creator_process; ///< name of the process that creates the particle
    // temporary, needed for ionization clusters
    std::map<std::string, double> _properties; ///< map of useful properties for ionization clusters
    

  public:
    void SetPDGcode(int pdg);
    int GetPDGcode() const;

    void SetInitialVertex(double x, double y, 
			  double z, double t);
    TLorentzVector GetInitialVertex() const;
   
    void SetDecayVertex(double x, double y, 
			double z, double t);
    TLorentzVector GetDecayVertex() const;

    void SetInitialMomentum(double px, double py, 
			    double pz, double energy);
    TLorentzVector GetInitialMomentum() const;

    void SetDecayMomentum(double px, double py, 
			  double pz, double energy);
    TLorentzVector GetDecayMomentum() const;

    void SetParticleID(int trackID);
    int GetParticleID() const;

    void SetTrackLength(double length);
    double GetTrackLength() const;
    
    void SetPrimary(bool is_primary);
    bool IsPrimary();
    bool IsPrimary() const;

    void SetMother(Particle* mother);
    const Particle* GetMother() const;
    Particle* GetMother();

    void AddTrack(Track* track);    
    const TRefArray GetTracks() const;
    TRefArray& GetTracks();
    Track* GetTrack(const std::string& det);

    void AddDaughter(Particle* daughter);    
    const TRefArray GetDaughters() const;
    TRefArray& GetDaughters();
 
    void SetParameters(double m, double q, double l);

    void SetParticleName(const std::string& name);
    void SetName(int code);
    const std::string& Name() const;

    void SetInitialVolume(const std::string& vol);
    const std::string& GetInitialVolume() const;

    void SetDecayVolume(const std::string& vol);
    const std::string& GetDecayVolume() const;

    void SetCreatorProcess(const std::string& process);
    const std::string& GetCreatorProcess() const;

    void AddProperty(const std::string& pname, double pvalue);
    double FindProperty(const std::string& pname);
    std::map<std::string, double> const & GetProperties() const;

    double GetMass() const;
    double GetCharge() const;

    /* Useful methods to access some properties*/

    double Energy() const;
    double Momentum() const;

    void IInfo(ostream& s) const;
    
    ClassDef(Particle,4);

  };

  // INLINE functions
  inline void Particle::SetPDGcode(int pdg) {_PDGcode = pdg;}
  inline int Particle::GetPDGcode() const {return _PDGcode;}
  inline TLorentzVector Particle::GetInitialVertex() const {return _initial_vertex;}
  inline TLorentzVector Particle::GetDecayVertex() const {return _decay_vertex;}
  inline TLorentzVector Particle::GetInitialMomentum() const {return _initial_momentum;}
  inline TLorentzVector Particle::GetDecayMomentum() const {return _decay_momentum;}
  inline void Particle::SetParticleID(int partID) {_particleID = partID;}
  inline int Particle::GetParticleID() const {return _particleID;}
  inline void Particle::SetTrackLength(double length) {_track_length = length;}
  inline double Particle::GetTrackLength() const {return _track_length;}
  inline const std::string& Particle::Name() const {return _name;}
  inline void Particle::SetInitialVolume(const std::string& vol) {_origin_volume = vol;}
  inline const std::string& Particle::GetInitialVolume() const {return _origin_volume;}
  inline void Particle::SetDecayVolume(const std::string& vol) {_decay_volume = vol;}
  inline const std::string& Particle::GetDecayVolume() const {return _decay_volume;}
  inline void Particle::SetCreatorProcess(const std::string& process) {_creator_process = process;}
  inline const std::string& Particle::GetCreatorProcess() const {return _creator_process;}
  inline void Particle::AddProperty(const std::string& pname, double pvalue) {_properties[pname] = pvalue;}
  inline double Particle::FindProperty(const std::string& pname) {return _properties[pname];}
  inline std::map<std::string, double> const & Particle::GetProperties() const {return _properties;}

  inline double Particle::GetMass() const {return _mass;}
  inline double Particle::GetCharge() const {return _charge;}

  inline double Particle::Energy() const {return _initial_momentum.Energy();}
  inline double Particle::Momentum() const {return _initial_momentum.P();}

} // end namespace irene

ostream& operator << (ostream& s, const irene::Particle& p);

#endif
