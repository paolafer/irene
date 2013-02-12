#ifndef __EVENT_H__
#define __EVENT_H__

#include "LightHit.h"
#include "IonizationHit.h"
#include "Particle.h"

#include <iostream>
#include <TObject.h>

/*No forward declarations of classes to be streamed
  allowed here --- understand why*/

class TObjArray;

namespace irene {

  class Event : public TObject {
    
  public: 
    Event();

    ~Event();

  private:

    TObjArray* _light_hits;
    TObjArray* _ionization_hits;
    TObjArray* _particles;
    int _eventID;
  

  public:
    void AddLightHit(irene::LightHit* hit);
    const TObjArray* GetLightHits() const;

    void AddIonizationHit(irene::IonizationHit* hit);
    const TObjArray* GetIonizationHits() const;

    void AddParticle(irene::Particle* particle);
    /* not constant because I want to be able to remove items */
    TObjArray* GetParticles() const; 
    void RemoveParticle(irene::Particle* particle);

    void SetID(const int& id); 
    const int GetID() const;

    void Clear();

    void Info(ostream& s) const;
   
    ClassDef(Event,1);
    
  };

  // INLINE methods
  inline const TObjArray* Event::GetLightHits() const {return _light_hits;}
  inline const TObjArray* Event::GetIonizationHits() const {return _ionization_hits;}
  inline TObjArray* Event::GetParticles() const {return _particles;}
  inline void Event::SetID(const int& id) {_eventID = id;}
  inline const int Event::GetID() const {return _eventID;}  
}

ostream& operator << (ostream& s, const irene::Event& ev);

#endif // __EVENT_H__
