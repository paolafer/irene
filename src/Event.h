// ----------------------------------------------------------------------------
///  \file   Event.h
///  \brief  Fundamental class which contains all the information of the event
///
///  \author   <paola.ferrario@ific.uv.es>
///  \date     14 Feb 2013
///  \version  $Id$
///
///  Copyright (c) 2013 NEXT Collaboration
// ----------------------------------------------------------------------------

#ifndef EVENT_H_
#define EVENT_H_

#include <iostream>
#include <TObject.h>
#include <TObjArray.h>

namespace irene {class SensorHit;}
namespace irene {class Track;}
namespace irene {class Particle;}

class TLorentzVector;

namespace irene {

  /// Class which contains all the information of the event, namely
  /// the true hits, the sensor response and the particle content
  class Event : public TObject {
    
  public: 
    /// Constructor
    Event();
    Event(int id);
    /// Copy Constructor
    Event(const Event& right);
    /// Destructor
    ~Event();

  private:

    TObjArray* _sensor_hits; ///< sensor response
    TObjArray* _tracks; ///< true hits of particles
    TObjArray* _particles; ///< particles
    int _eventID; ///< unique identificative number
  

  public:

    Event& operator=(const Event& right);
    
    void AddSensorHit(SensorHit* hit);
    const TObjArray* GetSensorHits() const;

    void AddTrack(Track* track);
    const TObjArray* GetTracks() const;

    void AddParticle(Particle* particle);
 
    const TObjArray* GetParticles() const; 
    TObjArray* GetParticles(); 

    void SetID(int id); 
    int GetID() const;

    void FillHitVector(std::vector<std::pair<TLorentzVector,double> >& evthits, std::string det);

    void Clear();

    void Info(ostream& s) const;
   
    ClassDef(Event,1);
    
  };

  // INLINE methods
  inline const TObjArray* Event::GetSensorHits() const {return _sensor_hits;}
  inline const TObjArray* Event::GetTracks() const {return _tracks;}
  inline const TObjArray* Event::GetParticles() const {return _particles;}
  inline TObjArray* Event::GetParticles() {return _particles;}
  inline void Event::SetID(int id) {_eventID = id;}
  inline int Event::GetID() const {return _eventID;}  

} // end namespace irene

ostream& operator << (ostream& s, const irene::Event& ev);

#endif // __EVENT_H__
