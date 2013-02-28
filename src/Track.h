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
    std::vector<std::pair<TLorentzVector,double> > _hits; ///< true hits in the track
    TRef _particle; ///< reference to the particle the track is created by
    int _id; ///< unique identification number for the track. It should be the same as its particles's
    double _track_length; ///< total length

  public:
    void AddHit(const double& x, const double& y, const double& z, 
		const double& t, const double& energy);
    const std::vector<std::pair<TLorentzVector,double> >& GetHits();
   
    void SetParticle(Particle* particle);
    Particle* GetParticle();
    void SetID(const int& id);
    int GetID() const;
    void SetLength(const double& length);
    double GetLength() const;
    
    void Info(ostream& s) const;
    
    ClassDef(Track,1);
    
  };

  // INLINE methods
  inline const std::vector<std::pair<TLorentzVector,double> >& Track::GetHits() {return _hits;}
  inline void Track::SetID(const int& id) {_id = id;}
  inline int Track::GetID() const {return _id;}
  inline void Track::SetLength(const double& length) {_track_length = length;}
  inline double Track::GetLength() const {return _track_length;}

} // end namespace irene

ostream& operator << (ostream& s, const irene::Track& tr);

#endif
