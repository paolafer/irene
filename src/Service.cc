#include "Service.h"

using namespace irene;

//ClassImp(Service);

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
  }

}
