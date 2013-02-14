// ----------------------------------------------------------------------------
///  \file   Service.h
///  \brief  Class which provides access to the current event class.
///
///  \author   <paola.ferrario@ific.uv.es>
///  \date     14 Feb 2013
///  \version  $Id$
///
///  Copyright (c) 2013 NEXT Collaboration
// ----------------------------------------------------------------------------

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

  };

  // INLINE methods
  inline irene::Event& Service::GetEvent() {return _event;}
  inline irene::RootWriter& Service::GetRootWriter() {return _root_writer;}
	  
}

#endif
