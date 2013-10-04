
// ----------------------------------------------------------------------------
//  $Id$
//
//  Author:  <paola.ferrario@ific.uv.es>
//  Created: 14 Feb 2013
//  
//  Copyright (c) 2013 NEXT Collaboration
// ---------------------------------------------------------------------------- 

#include "RootWriter.h"
#include "ParameterInfo.h"

#include <sys/stat.h>

//#include <iostream>     
#include <sstream>

namespace irene {

  RootWriter::RootWriter()
  {
    _file = 0;
    _evtTree = 0;   
    _isopen = false;
  }

  bool RootWriter::Open(const std::string filename, std::string option)
  {
    if (_file)
      delete _file;

    // Check if the path exists
    std::istringstream iss(filename);
    std::vector<std::string> myline;
    std::string text;
    while (getline(iss, text, '/')) { 
      myline.push_back(text);
    }   

    std::string path;
    if (myline.size() == 1) {
      path = ".";
    }
    for (int i=0; i<myline.size()-1; ++i) {
      path.append(myline[i]);
      if (i != myline.size()-2)
	path.append("/");
    }
    
    struct stat st;
    if (stat(path.c_str(),&st) != 0)
      return false;

    _event = 0;
    _file = new TFile(filename.c_str(), option.c_str());
    _evtTree = new TTree("EVENT","Irene event tree");
    TTree::SetBranchStyle(1);
    _evtTree->Branch("EventBranch","irene::Event",&_event);
    _isopen = true;
  
    return true;
  }

  void RootWriter::Close()
  {
    if (!_file || !_file->IsOpen())
      return;
    
    _file->Write();
    _file->Close();

    _isopen = false;
  }

  void RootWriter::Write(Event& event)
  {
    _event = &event;

    if (!_evtTree)
      std::cout << "Event tree does not exist!" << std::endl;

    _evtTree->Fill();
  }

  bool RootWriter::IsOpen()
  {
    return _isopen;
  }

  void RootWriter::WriteMetadata(ParameterInfo* mdata)
  {
    _evtTree->GetUserInfo()->Add(mdata);
  }


}
