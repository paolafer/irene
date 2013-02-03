#ifndef __PEVENT_H__
#define __PEVENT_H__

#include "IonizationHit.h"

#include <iostream>
#include <TObject.h>
#include <TRefArray.h>


namespace irene { 
  class LightHit;
  class Particle;}

class TClonesArray;

namespace irene {

  class Event : public TObject {
    
  public: 
    Event();
    //    Event(const irene::Event& evt);
    ~Event() {}

  private:

    static TClonesArray* _slight_hits;

    TClonesArray* _light_hits;
    //    TRefArray _ionization_hits;
    //   TRefArray _particles;
    int _eventID;

    int _nlhits;
  

  public:
    irene::LightHit* AddLightHit(const std::string det_name); 
    const TClonesArray* GetLightHits() const;

    /* void AddIonizationHit(const irene::IonizationHit* hit);  */
    /* const std::vector<irene::IonizationHit*> GetIonizationHits() const; */

    /* void AddParticle(const irene::Particle* hit);  */
    /* const std::vector<irene::Particle*> GetParticles() const; */

    void SetID(const int& id); 
    const int GetID() const;

    void Clear();

    void Info(ostream& s) const;
   
    ClassDef(Event,1);
    
  };

  // INLINE methods
  inline const TClonesArray* Event::GetLightHits() const {return _light_hits;}
  inline void Event::SetID(const int& id) {_eventID = id;}
  inline const int Event::GetID() const {return _eventID;}  
}

ostream& operator << (ostream& s, const irene::Event& ev);

#endif
