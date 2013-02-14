// ----------------------------------------------------------------------------
///  \file   Track.h
///  \brief  A collection of hits produced by a particle.
///
///  \author   <paola.ferrario@ific.uv.es>
///  \date     14 Feb 2013
///  \version  $Id$
///
///  Copyright (c) 2013 NEXT Collaboration
// ----------------------------------------------------------------------------

#ifndef __TRACK__
#define __TRACK__

#include <TObject.h>
#include <TVector3.h>
#include <vector>

namespace irene {

  /// A collection of hits produced by a particle in a detection medium

  class Track: public TObject {
    
  public:
    /// Constructor
    Track();
    /// Destructor
    ~Track();

  private:
    std::vector<std::pair<TVector3,double> > _hits;
    
    
    
    ClassDef(Track,1);
    
  };

} // namespace irene

#endif
