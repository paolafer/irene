// ----------------------------------------------------------------------------
///  \file   Service.h
///  \brief  Class that provides access to the current event object.
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

  /// This class is a singleton, and provides access to the current event object
  /// and to the class that writes the ROOT file
  class Service {

  private:
    /// Constructor
    Service();
    /// Destructor
    ~Service();

  private:
    static Service* _s_instance; ///< unique instance of the class
    Event* _event; ///< event to be accessed
    RootWriter _root_writer; ///< instance of the class that writes the ROOT file
    
  public:
    static Service* GetInstance();
    Event* GetEvent();
    RootWriter& GetRootWriter();

  };

  // INLINE methods
  inline Event* Service::GetEvent() {return _event;}
  inline RootWriter& Service::GetRootWriter() {return _root_writer;}
	  
} // end namespace irene

#endif
