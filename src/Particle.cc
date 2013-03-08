
// ----------------------------------------------------------------------------
//  $Id$
//
//  Author:  <paola.ferrario@ific.uv.es>
//  Created: 14 Feb 2013
//  
//  Copyright (c) 2013 NEXT Collaboration
// ---------------------------------------------------------------------------- 

#include "Particle.h"
#include "Units.h"
#include "Track.h"

#include <iostream>

ClassImp(irene::Particle);

namespace irene {

  Particle::Particle() : _PDGcode(0), _G4TrackID(0),
			 _primary(false), _has_mother(false),
			 _mass(0), _charge(0),
			 _lifetime(0)
  {
    _tracks = 0;
    _daughters = 0;
    _mother = 0;
    _name = "unknown";
    _decay_volume = "unknown";
    _origin_volume = "unknown";
    _creator_process = "unknown";
    _initial_vertex.SetXYZT(0.,0.,0.,0.);
    _decay_vertex.SetXYZT(0.,0.,0.,0.);
    _initial_momentum.SetXYZT(0.,0.,0.,0.);
    _decay_momentum.SetXYZT(0.,0.,0.,0.);
    SetParameters(0,0,-1);
    _properties.clear();
  }

  Particle::Particle(const int& pdg_code)
  {
    SetPDGcode(pdg_code);
    SetName(pdg_code);
  }

  Particle::Particle(std::string name)
  {
    SetParticleName(name);
  }

  Particle::~Particle()
  {
    _daughters.Delete();
  }

 

  void Particle::SetInitialVertex(const double x, const double y,
				  const double z, const double t) 
  { _initial_vertex.SetX(x);
    _initial_vertex.SetY(y);
    _initial_vertex.SetZ(z);
    _initial_vertex.SetT(t);      
  }

   void Particle::SetDecayVertex(const double x, const double y,
				  const double z, const double t) 
  { _decay_vertex.SetX(x);
    _decay_vertex.SetY(y);
    _decay_vertex.SetZ(z);
    _decay_vertex.SetT(t);      
  }

   void Particle::SetInitialMomentum(const double x, const double y,
				  const double z, const double t) 
   { _initial_momentum.SetX(x);
    _initial_momentum.SetY(y);
    _initial_momentum.SetZ(z);
    _initial_momentum.SetT(t);      
  }

   void Particle::SetDecayMomentum(const double x, const double y,
				  const double z, const double t) 
  { _decay_momentum.SetX(x);
    _decay_momentum.SetY(y);
    _decay_momentum.SetZ(z);
    _decay_momentum.SetT(t);      
  }

  void Particle::SetPrimary(bool is_primary)
  {
    _primary = is_primary;
    _has_mother = false;
  }
  
  bool Particle::IsPrimary()
  {
    if (_primary == true) 
      return true;
    else
      return false;    
  }
  
  void Particle::SetMother(irene::Particle* mother) 
  {
    _mother = mother;
    _has_mother = true;
  }

  const Particle* Particle::GetMother() const
  {
    if (!_mother.GetObject()) {
      std::cerr << "[ERROR: irene::Particle::GetMother()]:" 
		<< " the particle is primary, it has no mother!" << std::endl;
    }
    return dynamic_cast<Particle*> (_mother.GetObject());
  }

  Particle* Particle::GetMother()
  {
    if (!_mother.GetObject()) {
      std::cerr << "[ERROR: irene::Particle::GetMother()]:" 
		<< " the particle is primary, it has no mother!" << std::endl;
    }
    return dynamic_cast<Particle*> (_mother.GetObject());
  }

  // void Particle::SetTrack(Track* track) 
  // {
  //   _track = track;
  // }

  // const Track* Particle::GetTrack() const
  // {
  //   return dynamic_cast<Track*> (_track.GetObject());
  // }

  // Track* Particle::GetTrack()
  // {
  //   if (!_track.GetObject()) {
  //     std::cerr << "[ERROR: irene::Particle::GetTrack()]:" 
  // 		<< " the particle doesn't have a track associated,"
  // 		<< " because it has not produced true hits" << std::endl;
  //   }
  //   return dynamic_cast<Track*> (_track.GetObject());
  // }

  void Particle::AddTrack(Track* track)
  {
    _tracks.Add(track);
  }
  
  TRefArray& Particle::GetTracks()
  {   
    return _tracks;
  }

  const TRefArray Particle::GetTracks() const
  {   
    return _tracks;
  }

  void Particle::AddDaughter(Particle* daughter)
  {
    _daughters.Add(daughter);
  }
  
  TRefArray& Particle::GetDaughters()
  {   
    return _daughters;
  }

  const TRefArray Particle::GetDaughters() const
  {   
    return _daughters;
  }

  void Particle::SetParameters(double m, double q, double l)
  {
    _mass = m;     
    _charge = q;   
    _lifetime = l;
  }

  void Particle::SetName(const int& code) 
  {
    if (code == 22) {
      _name = "gamma";
      SetParameters(0,0,-1);
    } else if (code == -11) {
      _name = "e+";
      SetParameters(5.10998902E-04*GeV,1,-1);
    } else if (code == 11) {
      _name = "e-";
      SetParameters(5.10998902E-04*GeV,-1,-1);
    } else if (code == -13) {
      _name = "mu+";
      SetParameters(1.05658357E-01*GeV,1,2.197e-6*second);
    } else if (code == 13) {
      _name = "mu-";
      SetParameters(1.05658357E-01*GeV,1,2.197e-6*second);
    } else if (code == -15) {
      _name = "tau+";
      SetParameters(1.77699*GeV,1,291e-15*second);
    } else if (code == 15) {
      _name = "tau-";
      SetParameters(1.77699*GeV,-1,291e-15*second);
    } else if (code == 12) {
      _name = "nu_e";
      SetParameters(0,0,-1);
    } else if (code == -12) {
      _name = "anti_nu_e";
      SetParameters(0,0,-1);
    } else if (code == 14) {
      _name = "nu_mu";
      SetParameters(0,0,-1);
    } else if (code == -14) {
      _name = "anti_nu_mu";
      SetParameters(0,0,-1);
    }  else if (code == 16) {
      _name = "nu_tau";
      SetParameters(0,0,-1);
    } else if (code == -16) {
      _name = "anti_nu_tau";
      SetParameters(0,0,-1);
    } else if (code == 211) {
      _name = "pi+";
      SetParameters(1.3957018E-01*GeV,1,2.603e-8*second);
    } else if (code == -211) {
      _name = "pi-";
      SetParameters(1.3957018E-01*GeV,-1,2.603e-8*second);
    } else if (code == 111) {
      _name = "pi0";
      SetParameters(1.349766E-01*GeV,0,8.4e-17*second);
    } else if (code == 321) {
      _name = "kaon+";
      SetParameters(4.93677E-01*GeV,1,1.2386e-8*second);
    } else if (code == -321) {
      _name = "kaon-";
      SetParameters(4.93677E-01*GeV,-1,1.2386e-8*second);
    } else if (code == 130) {
      _name = "kaon0L";
      SetParameters(4.97672E-01*GeV,0,5.17e-8*second);
    } else if (code == 311) {
      _name = "kaon0";
      SetParameters(4.97672E-01*GeV,0,0.89e-10*second);
    } else if (code == 2212) {
      _name = "proton";
      SetParameters(9.3827200E-01*GeV,1,-1);
    } else if (code == -2212) {
      _name = "anti_proton";
      SetParameters(9.3827200E-01*GeV,-1,-1);
    } else if (code == 2112) {
      _name = "neutron";
      SetParameters(9.3956533E-01*GeV,0,-1);
    } else if (code == -2112) {
      _name = "anti_neutron";
      SetParameters(9.3956533E-01*GeV,0,-1);
    } else if (code == 1000020040) {
      _name = "alpha";
      SetParameters(3.727*GeV,0,-1);
    }

  }


  void Particle::Info(ostream& s) const
  {
    s << std::endl;    
    s << "Particle name = " << _name << ", PDG code = " << _PDGcode << 
      ", mass (MeV) = " << _mass << ", charge = "<< _charge << std::endl;
    s << "++++at production vertex ++++" << std::endl;
    s << "particle 3 momentum (MeV) =" << std::endl;
    s << "(" << _initial_momentum.X()/MeV << "," << _initial_momentum.Y()/MeV <<
      "," << _initial_momentum.Z()/MeV << ")" << std::endl;
    s << " momentum (MeV) = " << this->Momentum()/MeV << std::endl;
    s << " energy (MeV)= " << this->Energy()/MeV << std::endl;
    s << " vertex (mm)= " <<  std::endl;
    s << "(" << _initial_vertex.X()/mm << "," << _initial_vertex.Y()/mm <<
      "," << _initial_vertex.Z()/mm << ")" << std::endl;
    s << "++++at decay vertex ++++" << std::endl;
    s << "particle 3 momentum (MeV) =" << std::endl;
    s << "(" << _decay_momentum.X()/MeV << "," << _decay_momentum.Y()/MeV <<
      "," << _decay_momentum.Z()/MeV << ")" << std::endl;
    s << " momentum (MeV) = " << sqrt(_decay_momentum.X()*_decay_momentum.X() + 
				      _decay_momentum.Y()*_decay_momentum.Y() +
				      _decay_momentum.Z()*_decay_momentum.Z())/MeV << std::endl;
    s << " energy (MeV)= " << _decay_momentum.T()/MeV << std::endl;
    s << " vertex (mm)= " <<  std::endl;
    s << "(" << _decay_vertex.X()/mm << "," << _decay_vertex.Y()/mm <<
      "," << _decay_vertex.Z()/mm << ")" << std::endl;
    s << "creator process = " << _creator_process << std::endl;
    s << "origin volume = " << _origin_volume << std::endl;
    s << "decay volume = " << _decay_volume << std::endl;
    s << "G4TrackID = " << _G4TrackID << std::endl;
    //    s << "track length = " << _track_length << std::endl;

    if (_primary) {
      s << "particle is primary " << std::endl;
    } else {
      s << "particle is secondary" << std::endl;
      if (_has_mother) {
	s << "mother of particle is " << this->GetMother()->Name() << std::endl;
	s << "with 3 momentum (MeV) ="  << std::endl;
	s << "(" << this->GetMother()->GetInitialMomentum().X()/MeV << "," << 
	  this->GetMother()->GetInitialMomentum().Y()/MeV << "," << 
	  this->GetMother()->GetInitialMomentum().Z()/MeV << ")" << std::endl;
	s << "and energy (MeV)= " << this->GetMother()->Energy()/MeV << std::endl;
      }
    }

     s << " List of additional properties "
       << "-----------------------------" << std::endl;  
     std::map<std::string, double>::const_iterator it;
    for (it=_properties.begin(); it!=_properties.end(); ++it) {
      s << it->first << ": " << it->second << std::endl;
    }

    

    s << " List of secondary particles "
      << "-----------------------------" << std::endl;
 
    for (int i=0; i<_daughters.GetLast()+1; ++i){
      Particle* p = (Particle*)_daughters.At(i);
      s << "daughter name = " << p->Name()
	<< ", daughter mass (MeV)= " << p->GetMass()/MeV
	<< ", daughter charge = " << p->GetCharge()
	<< std::endl;     
     
      s << "particle 3 momentum (MeV) = " << std::endl;
      s << "(" << p->GetInitialMomentum().X()/MeV << "," << 
	p->GetInitialMomentum().Y()/MeV << "," << 
	p->GetInitialMomentum().Z()/MeV << ")" << std::endl;
      s << "particle momentum (MeV) =" << p->Momentum()/MeV << std::endl;      
      s << "particle energy (MeV)= " << p->Energy()/MeV << std::endl;
      
    }
    
    s << std::endl;
    s << "List of true hits of the particle"
      << " ----------------------" << std::endl;
    
    // if ((this->GetTrack())) {
    //   s << *(this->GetTrack()) << std::endl;
    //   s << "Track length = " << this->GetTrack()->GetLength() << std::endl;
    // }

  }
    
  void Particle::SetParticleName(std::string name) 
  {
    _name = name;

    if (name == "gamma"){  
      SetParameters(0,0,-1);
      _PDGcode = 22;    
    }
    else if (name == "e+"){
      SetParameters(5.10998902E-04*GeV,1,-1);
      _PDGcode  = -11;
    }
    else if (name == "e-"){
      SetParameters(5.10998902E-04*GeV,-1,-1);
      _PDGcode  = 11;
    }
    else if (name == "mu-"){
      SetParameters(1.05658357E-01*GeV,-1,2.197e-6*second);
      _PDGcode  = 13;
    }
    else if (name == "mu+"){
      SetParameters(1.05658357E-01*GeV,1,2.197e-6*second);
      _PDGcode  = -13;
    }
    else if (name == "tau+"){
      SetParameters(1.77699*GeV,1,291e-15*second);
      _PDGcode  = -15;
    }
    else if (name == "tau-"){
      SetParameters(1.77699*GeV,-1,2.291e-15*second);
      _PDGcode  = 15;
    }
    else if (name == "nu_e"){
      SetParameters(0,0,-1);
      _PDGcode  = 12;
    }
    else if (name == "anti_nu_e"){
      SetParameters(0,0,-1);
      _PDGcode  = -12;
    }
    else if (name == "nu_mu"){
      SetParameters(0,0,-1);
      _PDGcode  = 14;
    }
    else if (name == "anti_nu_mu"){
      SetParameters(0,0,-1);
      _PDGcode = -14;
    }
    else if (name == "nu_tau"){
      SetParameters(0,0,-1);
      _PDGcode  = 16;
    }
    else if (name == "anti_nu_tau"){
      SetParameters(0,0,-1);
      _PDGcode  = -16;
    }
    else if (name == "pi+"){
      SetParameters(1.3957018E-01*GeV,1,2.603e-8*second);
      _PDGcode = 211;
    }
    else if (name == "pi-"){
      SetParameters(1.3957018E-01*GeV,-1,2.603e-8*second);
      _PDGcode  = -211;
    }
    else if (name == "pi0"){
      SetParameters(1.349766E-01*GeV,0,8.4e-17*second);
      _PDGcode  = 111;
    }
    else if (name == "kaon+"){
      SetParameters(4.93677E-01*GeV,1,1.2386e-8*second);
      _PDGcode  = 321;
    }
    else if (name == "kaon-"){
      SetParameters(4.93677E-01*GeV,-1,1.2386e-8*second);
      _PDGcode  = -321;
    }
    else if (name == "kaon0L"){
      SetParameters(4.97672E-01*GeV,0,5.17e-8*second);
      _PDGcode  = 130;
    }
    else if (name == "kaon0"){
      SetParameters(4.97672E-01*GeV,0,0.89e-10*second);
      _PDGcode  = 310;
    }
    else if (name == "proton"){
      SetParameters(9.3827200E-01*GeV,1,-1);
      _PDGcode  = 2212;
    }
    else if (name == "anti_proton"){
      SetParameters(9.3827200E-01*GeV,-1,-1);
      _PDGcode  = -2212;
    }
    else if (name == "neutron"){
      SetParameters(9.3956533E-01*GeV,0,-1);
      _PDGcode  = 2112;
    }
    else if (name == "anti_neutron"){
      SetParameters(9.3956533E-01*GeV,0,-1);
      _PDGcode = -2112;
    }
    else if (name == "deuteron"){
      SetParameters(1.875613*GeV,0,-1);
      _PDGcode  = 0;
    }
    else if (name == "tritium"){
      SetParameters(2.80925*GeV,0,-1);
      _PDGcode  = 0;
    }
    else if (name == "alpha"){
      SetParameters(3.727*GeV,0,-1);
      _PDGcode  = 0;
    }
    else if (name == "unknown"){ // assume pion mass
      SetParameters(1.3957018E-01*GeV,-1,2.603e-8*second);
      _PDGcode  = 0;
    }    
    else if (name == "void"){
      SetParameters(0,0,0);
      _PDGcode  = 0;
    }    
    else {
      SetParameters(0,0,-1);
      _PDGcode=0;
    }
    
  }


  
}

ostream& operator << (ostream& s, const irene::Particle& p) {
  p.Info(s);
  return s; 
}

