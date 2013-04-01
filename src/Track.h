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
    /// Constructors
    Track();
    Track(std::string& detector);
    /// Destructor
    ~Track();

  private:
    std::vector<std::pair<TLorentzVector,double> > _hits; ///< true hits in the track
    TRef _particle; ///< reference to the particle the track is created by
    int _id; ///< identification number for the track. It should be the same as its particles's. Thus, if the particle has more than one track, two or more tracks can have the same ID number.
    double _track_length; ///< total length
    std::string _detector_name; ///< detector where hits have been produced

  public:
    void AddHit(double x, double y, double z, 
		double t, double energy);
    const std::vector<std::pair<TLorentzVector,double> >& GetHits();
   
    void SetParticle(Particle* particle);
    Particle* GetParticle();
    void SetID(int id);
    int GetID() const;
    void SetLength(double length);
    double GetLength() const;
    void SetDetector(std::string det);
    const std::string& GetDetectorName() const;
    
    void Info(ostream& s) const;
    
    ClassDef(Track,2);
    
  };

  // INLINE methods
  inline const std::vector<std::pair<TLorentzVector,double> >& Track::GetHits() {return _hits;}
  inline void Track::SetID(int id) {_id = id;}
  inline int Track::GetID() const {return _id;}
  inline void Track::SetLength(double length) {_track_length = length;}
  inline double Track::GetLength() const {return _track_length;}
  inline void Track::SetDetector(std::string det) {_detector_name = det;}
  inline const std::string& Track::GetDetectorName() const {return _detector_name;}

} // end namespace irene

ostream& operator << (ostream& s, const irene::Track& tr);

#endif
