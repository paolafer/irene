#ifndef __ROOTWRITER__
#define __ROOTWRITER__

#include <TFile.h>
#include <TTree.h>
#include "Event.h"

namespace irene {

  class RootWriter {

  public:
    RootWriter();
    ~RootWriter() {}

  private:
    TFile* _file;
    TTree* _evtTree;
    irene::Event* _event;
    bool _isopen;

  public:

    void Open(const std::string filename, std::string option);
    void Write(irene::Event& event);
    void Close();
    bool IsOpen();

  };

}

#endif
