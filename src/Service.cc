
// ----------------------------------------------------------------------------
//  $Id$
//
//  Author:  <paola.ferrario@ific.uv.es>
//  Created: 14 Feb 2013
//  
//  Copyright (c) 2013 NEXT Collaboration
// ---------------------------------------------------------------------------- 

#include "Service.h"

namespace irene {

  Service* Service::_s_instance = 0;

  Service* Service::GetInstance()
  {
    if (!_s_instance) 
      _s_instance = new Service();
    return _s_instance;
  }

  Service::Service()
  {
   _root_writer = RootWriter();
   _event = new Event(0);
  }

  Service::~Service()
  {
  }

}
