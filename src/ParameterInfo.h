// ----------------------------------------------------------------------------
///  \file   ParameterInfo.h
///  \brief  Class to store a parameter with its value
///
///  \author   <paola.ferrario@ific.uv.es>
///  \date     11 Sept 2013
///  \version  $Id$
///
///  Copyright (c) 2013 NEXT Collaboration
// ----------------------------------------------------------------------------

#ifndef PARAMETERINFO_H
#define PARAMETERINFO_H

#include <TNamed.h>
#include <TObject.h>

namespace irene {
  /// Class to store a parameter with its value. 
  /// The name of the parameter is the argument of the constructor
  /// while its value is set through the SetContent() method.
  class ParameterInfo: public TNamed
  {
  public:
    /// Constructor
    ParameterInfo() {}
  ParameterInfo(const char* name): TNamed(name, name) {}
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
