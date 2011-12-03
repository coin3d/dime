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
  \class dimeLayerTable dime/tables/LayerTable.h
  \brief The dimeLayerTable class reads and writes LAYER \e tables.
*/

#include <dime/tables/LayerTable.h>
#include <dime/Input.h>
#include <dime/Output.h>
#include <dime/util/MemHandler.h>
#include <dime/Model.h>
#include <dime/records/Record.h>
#include <string.h>

static const char tableName[] = "LAYER";

/*!
  Constructor.
*/

dimeLayerTable::dimeLayerTable()
  : colorNumber( 0 ), layerName( NULL ), layerInfo( NULL )
{
}

dimeLayerTable::~dimeLayerTable()
{
  delete [] this->layerName;
}

//!

dimeTableEntry *
dimeLayerTable::copy(dimeModel * const model) const
{
  dimeMemHandler *memh = model->getMemHandler();
  dimeLayerTable *l = new(memh) dimeLayerTable;
  l->colorNumber = this->colorNumber;
  if (this->layerName) {
    DXF_STRCPY(memh, l->layerName, this->layerName);
  }
  if (this->layerInfo) {
    l->layerInfo = (dimeLayer*)model->addLayer(this->layerInfo->getLayerName(), 
                                               DXFABS(this->colorNumber));
  }
  if (!copyRecords(l, model)) {
    // check if allocated on heap.
    if (!memh) delete l;
    l = NULL;
  }
  return l;
}

//!

const char *
dimeLayerTable::getTableName() const
{
  return tableName;
}

//!

bool 
dimeLayerTable::read(dimeInput * const file)
{
  bool ret = dimeTableEntry::read(file);
  if (ret) {
    this->registerLayer(file->getModel());
  }
  return ret;
}

//!

bool 
dimeLayerTable::write(dimeOutput * const file)
{
  bool ret = dimeTableEntry::preWrite(file);
  
  if (this->layerName) { 
    ret = file->writeGroupCode(2); 
    file->writeString(this->layerName);
  }
  file->writeGroupCode(62);
  file->writeInt16(this->colorNumber);
  
  ret = dimeTableEntry::write(file);
  return ret;
}

//!

int 
dimeLayerTable::typeId() const
{
  return dimeBase::dimeLayerTableType;
}

//!

bool 
dimeLayerTable::handleRecord(const int groupcode,
			    const dimeParam &param,
			    dimeMemHandler * const memhandler)
{
  switch(groupcode) {
  case 2:
    this->setLayerName(param.string_data, memhandler);
    return true;
  case 62:
    this->setColorNumber(param.int16_data);
    return true;
  }
  return dimeTableEntry::handleRecord(groupcode, param, memhandler);
}

//!

int
dimeLayerTable::countRecords() const
{
  int cnt = 1; // header
  if (this->layerInfo) cnt++;
  cnt++; // colorNumber
  return cnt + dimeTableEntry::countRecords();
}

/*!
  Sets the layer name.
*/
void 
dimeLayerTable::setLayerName(const char * name, dimeMemHandler * const memhandler)
{
  if (this->layerName && memhandler == NULL) {
    delete this->layerName;
  }
  DXF_STRCPY(memhandler, this->layerName, name);
}

/*!
  Returns the layer name.
 */
const char * 
dimeLayerTable::getLayerName(void) const
{
  return this->layerName;
}

/*!
  Sets the color number.
 */
void 
dimeLayerTable::setColorNumber(const int16 colnum)
{
  this->colorNumber = colnum;
  if (this->layerInfo) this->layerInfo->setColorNumber(DXFABS(this->colorNumber));
}

/*!
  Returns the color number.
 */
int16 
dimeLayerTable::getColorNumber(void) const
{
  return this->colorNumber;
}

/*!  
  Should be called _once_ after you've finished setting up your
  layer (name and color number).  Calling this method more than once
  for a layer might lead to hard-to-find bugs. After calling this
  method, the layer information (color number) will be available to
  entities using this layer.  
*/
void 
dimeLayerTable::registerLayer(dimeModel * model)
{
  if (this->layerInfo == NULL && this->layerName != NULL) {
    this->layerInfo = (dimeLayer*) 
      model->addLayer(this->layerName, DXFABS(this->colorNumber));    
  }
}




