/**************************************************************************\
 * Copyright (c) Kongsberg Oil & Gas Technologies AS
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 * 
 * Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 * 
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 * 
 * Neither the name of the copyright holder nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
\**************************************************************************/

#ifndef DIME_LAYER_H
#define DIME_LAYER_H

#include <dime/Basic.h>

class DIME_DLL_API dimeLayer
{
public:

  enum Flags {
    FROZEN               = 0x1,
    FROZEN_NEW_VIEWPORTS = 0x2,
    LOCKED               = 0x4
  };

  const char *getLayerName() const;
  int getLayerNum() const;

  int16 getColorNumber() const;
  void setColorNumber(const int16 num);
  
  int16 getFlags() const;
  void setFlags(const int16 &flags);

  bool isDefaultLayer() const;

  static const dimeLayer *getDefaultLayer();

  static void colorToRGB(const int colornum, 
                         dxfdouble &r, dxfdouble &g, dxfdouble &b);

private:
  friend class dimeModel;
  
  dimeLayer();
  dimeLayer(const char * const name, const int num, 
            const int16 colnum, const int16 flags); 
  const char *layerName;
  int layerNum;
  int16 colorNum;
  int16 flags;

  static void cleanup_default_layer(void);
  static dimeLayer * defaultLayer;

}; // class dimeLayer

inline const char *
dimeLayer::getLayerName() const
{
  return layerName;
}

inline int 
dimeLayer::getLayerNum() const
{
  return layerNum;
}

inline int16 
dimeLayer::getColorNumber() const
{
  return colorNum;
}

inline void 
dimeLayer::setColorNumber(const int16 num)
{
  this->colorNum = num;
}
  
inline int16 
dimeLayer::getFlags() const
{
  return this->flags;
}

inline void 
dimeLayer::setFlags(const int16 &flags)
{
  this->flags = flags;
}

inline bool 
dimeLayer::isDefaultLayer() const
{
  return this == dimeLayer::getDefaultLayer();
}

#endif // ! DIME_LAYER_H

