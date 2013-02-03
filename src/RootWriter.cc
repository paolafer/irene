#include "RootWriter.h"

using namespace irene;

namespace irene {

  RootWriter::RootWriter()
  {
    _file = 0;
    _evtTree = 0;   
    //_event = 0;
    _isopen = false;
  }

  void RootWriter::Open(const std::string filename, std::string option)
  {
    if (_file)
      delete _file;

    _event = 0;

    _file = new TFile(filename.c_str(), option.c_str());
    _evtTree = new TTree("EVENT","Irene event tree");
    TTree::SetBranchStyle(1);
    _evtTree->Branch("EventBranch","irene::Event",&_event,32000,0);
    _isopen = true;
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
    _evtTree->Fill();
  }

  bool RootWriter::IsOpen()
  {
    return _isopen;
  }


}
