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

/*!
  \class dimeLayer dime/Layer.h
  \brief The dimeLayer class handles layers.

  Each entity will have a pointer to a dimeLayer class. If no layer
  is specified by the user, a pointer to a default layer will be used.
  An instance of this class can only be constructed by the dimeModel
  class.

  To add new layers to your model, you must use the dimeLayerTable
  class, and add them to a dimeTablesSection.

  \sa dimeModel::addLayer()
*/

#include <dime/Layer.h>
#include <stdlib.h>

// palette for color indices 1-255
static dxfdouble colortable[] = {
  1,0,0, // 1
  1,1,0,
  0,1,0,
  0,1,1,
  0,0,1,
  1,0,1,
  1,1,1,          
  0.5,0.5,0.5,  //0.5,0.5,0.5,     
  0.75,0.75,0.75,  //0.75,0.75,0.75, 
  1,0,0,              
  1,0.5,0.5,
  0.65,0,0,
  0.65,0.325,0.325,
  0.5,0,0,
  0.5,0.25,0.25,
  0.3,0,0,
  0.3,0.15,0.15,
  0.15,0,0,
  0.15,0.075,0.075,
  1,0.25,0,   // 20        
  1,0.625,0.5,
  0.65,0.1625,0,
  0.65,0.4063,0.325,
  0.5,0.125,0,
  0.5,0.3125,0.25,
  0.3,0.075,0,
  0.3,0.1875,0.15,
  0.15,0.0375,0,
  0.15,0.0938,0.075,
  1,0.5,0,
  1,0.75,0.5,
  0.65,0.325,0,
  0.65,0.4875,0.325,
  0.5,0.25,0,
  0.5,0.375,0.25,
  0.3,0.15,0,
  0.3,0.225,0.15,
  0.15,0.075,0,
  0.15,0.1125,0.075,
  1,0.75,0,
  1,0.875,0.5,
  0.65,0.4875,0,
  0.65,0.5688,0.325,
  0.5,0.375,0,
  0.5,0.4375,0.25,
  0.3,0.225,0,
  0.3,0.2625,0.15,
  0.15,0.1125,0,
  0.15,0.1313,0.075,
  1,1,0,
  1,1,0.5,
  0.65,0.65,0,
  0.65,0.65,0.325,
  0.5,0.5,0,
  0.5,0.5,0.25,
  0.3,0.3,0,
  0.3,0.3,0.15,
  0.15,0.15,0,
  0.15,0.15,0.075,
  0.75,1,0,
  0.875,1,0.5,
  0.4875,0.65,0,
  0.5688,0.65,0.325,
  0.375,0.5,0,
  0.4375,0.5,0.25,
  0.225,0.3,0,
  0.2625,0.3,0.15,
  0.1125,0.15,0,
  0.1313,0.15,0.075,
  0.5,1,0,
  0.75,1,0.5,
  0.325,0.65,0,
  0.4875,0.65,0.325,
  0.25,0.5,0,
  0.375,0.5,0.25,
  0.15,0.3,0,
  0.225,0.3,0.15,
  0.075,0.15,0,
  0.1125,0.15,0.075,
  0.25,1,0,
  0.625,1,0.5,
  0.1625,0.65,0,
  0.4063,0.65,0.325,
  0.125,0.5,0,
  0.3125,0.5,0.25,
  0.075,0.3,0,
  0.1875,0.3,0.15,
  0.0375,0.15,0,
  0.0938,0.15,0.075,
  0,1,0,
  0.5,1,0.5,
  0,0.65,0,
  0.325,0.65,0.325,
  0,0.5,0,
  0.25,0.5,0.25,
  0,0.3,0,
  0.15,0.3,0.15,
  0,0.15,0,
  0.075,0.15,0.075,
  0,1,0.25,
  0.5,1,0.625,
  0,0.65,0.1625,
  0.325,0.65,0.4063,
  0,0.5,0.125,
  0.25,0.5,0.3125,
  0,0.3,0.075,
  0.15,0.3,0.1875,
  0,0.15,0.0375,
  0.075,0.15,0.0938,
  0,1,0.5,
  0.5,1,0.75,
  0,0.65,0.325,
  0.325,0.65,0.4875,
  0,0.5,0.25,
  0.25,0.5,0.375,
  0,0.3,0.15,
  0.15,0.3,0.225,
  0,0.15,0.075,
  0.075,0.15,0.1125,
  0,1,0.75,
  0.5,1,0.875,
  0,0.65,0.4875,
  0.325,0.65,0.5688,
  0,0.5,0.375,
  0.25,0.5,0.4375,
  0,0.3,0.225,
  0.15,0.3,0.2625,
  0,0.15,0.1125,
  0.075,0.15,0.1313,
  0,1,1,
  0.5,1,1,
  0,0.65,0.65,
  0.325,0.65,0.65,
  0,0.5,0.5,
  0.25,0.5,0.5,
  0,0.3,0.3,
  0.15,0.3,0.3,
  0,0.15,0.15,
  0.075,0.15,0.15,
  0,0.75,1,
  0.5,0.875,1,
  0,0.4875,0.65,
  0.325,0.5688,0.65,
  0,0.375,0.5,
  0.25,0.4375,0.5,
  0,0.225,0.3,
  0.15,0.2625,0.3,
  0,0.1125,0.15,
  0.075,0.1313,0.15,
  0,0.5,1,
  0.5,0.75,1,
  0,0.325,0.65,
  0.325,0.4875,0.65,
  0,0.25,0.5,
  0.25,0.375,0.5,
  0,0.15,0.3,
  0.15,0.225,0.3,
  0,0.075,0.15,
  0.075,0.1125,0.15,
  0,0.25,1,
  0.5,0.625,1,
  0,0.1625,0.65,
  0.325,0.4063,0.65,
  0,0.125,0.5,
  0.25,0.3125,0.5,
  0,0.075,0.3,
  0.15,0.1875,0.3,
  0,0.0375,0.15,
  0.075,0.0938,0.15,
  0,0,1,
  0.5,0.5,1,
  0,0,0.65,
  0.325,0.325,0.65,
  0,0,0.5,
  0.25,0.25,0.5,
  0,0,0.3,
  0.15,0.15,0.3,
  0,0,0.15,
  0.075,0.075,0.15,
  0.25,0,1,
  0.625,0.5,1,
  0.1625,0,0.65,
  0.4063,0.325,0.65,
  0.125,0,0.5,
  0.3125,0.25,0.5,
  0.075,0,0.3,
  0.1875,0.15,0.3,
  0.0375,0,0.15,
  0.0938,0.075,0.15,
  0.5,0,1,
  0.75,0.5,1,
  0.325,0,0.65,
  0.4875,0.325,0.65,
  0.25,0,0.5,
  0.375,0.25,0.5,
  0.15,0,0.3,
  0.225,0.15,0.3,
  0.075,0,0.15,
  0.1125,0.075,0.15,
  0.75,0,1,
  0.875,0.5,1,
  0.4875,0,0.65,
  0.5688,0.325,0.65,
  0.375,0,0.5,
  0.4375,0.25,0.5,
  0.225,0,0.3,
  0.2625,0.15,0.3,
  0.1125,0,0.15,
  0.1313,0.075,0.15,
  1,0,1,
  1,0.5,1,
  0.65,0,0.65,
  0.65,0.325,0.65,
  0.5,0,0.5,
  0.5,0.25,0.5,
  0.3,0,0.3,
  0.3,0.15,0.3,
  0.15,0,0.15,
  0.15,0.075,0.15,
  1,0,0.75,
  1,0.5,0.875,
  0.65,0,0.4875,
  0.65,0.325,0.5688,
  0.5,0,0.375,
  0.5,0.25,0.4375,
  0.3,0,0.225,
  0.3,0.15,0.2625,
  0.15,0,0.1125,
  0.15,0.075,0.1313,
  1,0,0.5,
  1,0.5,0.75,
  0.65,0,0.325,
  0.65,0.325,0.4875,
  0.5,0,0.25,
  0.5,0.25,0.375,
  0.3,0,0.15,
  0.3,0.15,0.225,
  0.15,0,0.075,
  0.15,0.075,0.1125,
  1,0,0.25,
  1,0.5,0.625,
  0.65,0,0.1625,
  0.65,0.325,0.4063,
  0.5,0,0.125,
  0.5,0.25,0.3125,
  0.3,0,0.075,
  0.3,0.15,0.1875,
  0.15,0,0.0375,
  0.15,0.075,0.0938,
  0.33,0.33,0.33,
  0.464,0.464,0.464,
  0.598,0.598,0.598,
  0.732,0.732,0.732,
  0.866,0.866,0.866,
  1,1,1};


dimeLayer * dimeLayer::defaultLayer;

// 0 seems to be the default layer name in AutoCAD
static char defaultName[] = "0"; 

dimeLayer::dimeLayer()
  : layerName( NULL ), layerNum( -1 ), colorNum( -1 ), flags( 0 )
{
}

dimeLayer::dimeLayer(const char * const name, const int num, 
		     const int16 colnum, const int16 flagmask) 
  : layerName( name ), layerNum( num ), colorNum( colnum ), flags( flagmask )
{
}

/*!
  \fn static void colorToRGB(const int colornum, 
                             float &r, float &g, float &b)
  Returns the RGB values based on the color index. Legal color 
  numbers range from 1 through 255.
*/

void 
dimeLayer::colorToRGB(const int colornum, 
		      dxfdouble &r, dxfdouble &g, dxfdouble &b)
{
  int idx = 7*3; // default white
  if (colornum >= 1 && colornum <= 255) idx = colornum*3;
  idx -= 3;
  r = colortable[idx];
  g = colortable[idx+1];
  b = colortable[idx+2];
}


/*!
  \fn const char *dimeLayer::getLayerName() const
  Returns the layer name.
*/

/*!
  \fn int dimeLayer::getLayerNum() const
  Returns the layer number. This will be a unique number for
  this layer. The default layer will have number 0, and all other
  layer will get running number from 1 and up. This can be useful
  when extracting geometry from a DXF model, and you need to group
  the geometry by layer.

  \sa dimeModel::getNumLayers().
*/

/*!
  \fn int16 dimeLayer::getColorNumber() const
  Returns the color number for this layer.
  A negative value means that this layer is off.

  \sa dimeLayer::setColorNumber()
*/

/*!
  \fn void dimeLayer::setColorNumber(const int16 num)
  Sets the color number for this layer.

  \sa dimeLayer::getColorNumber()
*/

/*!
  \fn int16 dimeLayer::getFlags() const
  Returns the flags for this layer.
*/

/*!
  \fn void dimeLayer::setFlags(const int16 &flags)
  Sets the flags for this layer.
*/

/*!
  \fn bool dimeLayer::isDefaultLayer() const
  Returns true if this is the default layer.
*/


void 
dimeLayer::cleanup_default_layer(void)
{
  delete defaultLayer;
  defaultLayer = NULL;
}

/*!
  Returns a pointer to the default layer.
*/
const dimeLayer *
dimeLayer::getDefaultLayer()
{
  if (defaultLayer == NULL) {
    defaultLayer = new dimeLayer;
    defaultLayer->layerName = defaultName;
    defaultLayer->layerNum = 0;
    defaultLayer->colorNum = 7; // white...
    atexit(cleanup_default_layer);
  }
  return defaultLayer;
}





