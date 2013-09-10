#ifndef PARAMETERINFO_H
#define PARAMETERINFO_H

#include <TNamed.h>
#include <TObject.h>

namespace irene {

  class ParameterInfo: public TNamed
  {
  public:
    /// Constructor
    ParameterInfo() {}
  ParameterInfo(const char* name, const char* title): TNamed(name, title) {}
    /// Destructor
    ~ParameterInfo() {}
    
  public:
    void SetContent(const std::string& v);
    std::string GetContent() const;
    
  private:
    std::string _content;

    ClassDef(ParameterInfo,1);
  };

  inline void ParameterInfo::SetContent(const std::string& v) {_content = v;}
  inline std::string ParameterInfo::GetContent() const {return _content;}
}

#endif 
