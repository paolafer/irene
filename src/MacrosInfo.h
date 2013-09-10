#ifndef MACROSINFO_H
#define MACROSINFO_H

#include <TNamed.h>
#include <TObject.h>

namespace irene {

  class MacrosInfo: public TNamed
  {
  public:
    /// Constructor
    MacrosInfo() {}
  MacrosInfo(const char* name, const char* title): TNamed(name, title) {}
    /// Destructor
    ~MacrosInfo() {}
    
  public:
    void SetContent(const std::string& v);
    std::string GetContent() const;
    
  private:
    std::string _content;

    ClassDef(MacrosInfo,1);
  };

  inline void MacrosInfo::SetContent(const std::string& v) {_content = v;}
  inline std::string MacrosInfo::GetContent() const {return _content;}
}

#endif 
