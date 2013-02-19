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

#ifndef __EVENT_H__
#define __EVENT_H__

#include <iostream>
#include <TObject.h>

namespace irene {class SensorHit;}
namespace irene {class Track;}
namespace irene {class Particle;}

class TObjArray;

namespace irene {

  class Event : public TObject {
    
  public: 
    Event();

    ~Event();

  private:

    TObjArray* _sensor_hits;
    TObjArray* _tracks;
    TObjArray* _particles;
    int _eventID;
  

  public:
    void AddSensorHit(irene::SensorHit* hit);
    const TObjArray* GetSensorHits() const;

    void AddTrack(irene::Track* track);
    const TObjArray* GetTracks() const;

    void AddParticle(irene::Particle* particle);
 
    const TObjArray* GetParticles() const; 
    TObjArray* GetParticles(); 

    void SetID(const int& id); 
    const int GetID() const;

    void Clear();

    void Info(ostream& s) const;
   
    ClassDef(Event,1);
    
  };

  // INLINE methods
  inline const TObjArray* Event::GetSensorHits() const {return _sensor_hits;}
  inline const TObjArray* Event::GetTracks() const {return _tracks;}
  inline const TObjArray* Event::GetParticles() const {return _particles;}
  inline TObjArray* Event::GetParticles() {return _particles;}
  inline void Event::SetID(const int& id) {_eventID = id;}
  inline const int Event::GetID() const {return _eventID;}  
}

ostream& operator << (ostream& s, const irene::Event& ev);

#endif // __EVENT_H__
