// ----------------------------------------------------------------------------
///  \file   RootWriter.h
///  \brief  Class to write events to a ROOT file, inside a Tree .
///
///  \author   <paola.ferrario@ific.uv.es>
///  \date     14 Feb 2013
///  \version  $Id$
///
///  Copyright (c) 2013 NEXT Collaboration
// ----------------------------------------------------------------------------

#ifndef __ROOTWRITER__
#define __ROOTWRITER__

#include <TFile.h>
#include <TTree.h>
#include "Event.h"

namespace irene {

  class RootWriter {

  public:
    /// Constructor
    RootWriter();
    /// Destructor
    ~RootWriter() {}

  private:
    TFile* _file; ///< ROOT file where the output is written
    TTree* _evtTree; ///< ROOT tree where the events are stored
    Event* _event; ///< event to be stored
    bool _isopen; ///< true is the file is already open

  public:

    void Open(const std::string filename, std::string option);
    void Write(Event& event);
    void Close();
    bool IsOpen();

  };

} // end namespace irene

#endif
