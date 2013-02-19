// ----------------------------------------------------------------------------
///  \file   Track.h
///  \brief  A collection of hits produced by a particle.
///
///  \author   <paola.ferrario@ific.uv.es>
///  \date     14 Feb 2013
///  \version  $Id$
///
///  Copyright (c) 2013 NEXT Collaboration
// ----------------------------------------------------------------------------

#ifndef __TRACK__
#define __TRACK__

#include <TObject.h>
#include <TLorentzVector.h>
#include <TRef.h>
#include <vector>

namespace irene {class Particle;}

namespace irene {

  /// A collection of hits produced by a particle in a detection medium

  class Track: public TObject {
    
  public:
    /// Constructor
    Track();
    /// Destructor
    ~Track();

  private:
    std::vector<std::pair<TLorentzVector,double>*> _hits;
    TRef _particle;
    int _id;

  public:
    void AddHit(const double& x, const double& y, const double& z, 
		const double& t, const double& energy);
    std::vector<std::pair<TLorentzVector,double>*> GetHits();
   
    void SetParticle(irene::Particle* particle);
    void SetID(const int& id);
    const int GetID() const;
    
    void Info(ostream& s) const;
    
    ClassDef(Track,1);
    
  };

  // INLINE methods
  inline std::vector<std::pair<TLorentzVector,double>*> Track::GetHits() {return _hits;}
  inline void Track::SetID(const int& id) {_id = id;}
  inline const int Track::GetID() const {return _id;}

} // namespace irene

ostream& operator << (ostream& s, const irene::Track& tr);

#endif
