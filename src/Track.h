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

#ifndef TRACK_H_
#define TRACK_H_

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
    std::vector<std::pair<TLorentzVector,double> > _hits; ///< true hits in the track. The TLorentzVector is the position and the time of the hit, and the double is the energy
    TRef _particle; ///< reference to the particle the track is created by
    //  int _id; ///< identification number for the track. It should be the same as its particles's. Thus, if the particle has more than one track, two or more tracks can have the same ID number.
    //    double _track_length; ///< total length
    std::string _detector_name; ///< detector where hits have been produced

  public:
    void AddHit(double x, double y, double z, 
		double t, double energy);
    const std::vector<std::pair<TLorentzVector,double> >& GetHits() const;
    std::vector<std::pair<TLorentzVector,double> >& GetHits();
   
    void SetParticle(Particle* particle);
    const Particle* GetParticle() const;
    Particle* GetParticle();
    // void SetID(int id);
    // int GetID() const;
    // void SetLength(double length);
    //  double GetLength() const;
    void SetDetector(const std::string& det);
    const std::string& GetDetectorName() const;
    
    void IInfo(ostream& s) const;
    
    ClassDef(Track,3);
    
  };

  // INLINE methods
  
  // inline void Track::SetID(int id) {_id = id;}
  // inline int Track::GetID() const {return _id;}
  // inline void Track::SetLength(double length) {_track_length = length;}
  // inline double Track::GetLength() const {return _track_length;}
  inline void Track::SetDetector(const std::string& det) {_detector_name = det;}
  inline const std::string& Track::GetDetectorName() const {return _detector_name;}

} // end namespace irene

ostream& operator << (ostream& s, const irene::Track& tr);

#endif
