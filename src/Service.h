#ifndef __SERVICE__
#define __SERVICE__

#include "Event.h"
#include "RootWriter.h"

namespace irene {

  class Service {

  private:
    Service();
    ~Service();
    
  public:
    static Service* GetInstance();
    Event& GetEvent();
    RootWriter& GetRootWriter();
    
    
  private:
    static Service* _s_instance;

    irene::Event _event;
    irene::RootWriter _root_writer;

    //    ClassDef(Service,1);

  };

  // INLINE methods
  inline irene::Event& Service::GetEvent() {return _event;}
  inline irene::RootWriter& Service::GetRootWriter() {return _root_writer;}
	  
}

#endif
