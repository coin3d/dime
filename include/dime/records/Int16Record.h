/**************************************************************************\
 * 
 *  FILE: Int16Record.h
 *
 *  This source file is part of DIME.
 *  Copyright (C) 1998-1999 by Systems In Motion.  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License, version 2, as
 *  published by the Free Software Foundation.  DO NOT MISTAKE THIS LICENSE
 *  FOR THE GNU LGPL LICENSE.
 *
 *  This library is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  General Public License (the accompanying file named COPYING) for more
 *  details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 **************************************************************************
 *
 *  If you need DIME for commercial purposes, you can contact Systems In
 *  Motion about acquiring a commercial license.
 *
 *  Systems In Motion                                   http://www.sim.no/
 *  Prof. Brochs gate 6                                       sales@sim.no
 *  N-7030 Trondheim                                   Voice: +47 22114160
 *  NORWAY                                               Fax: +47 67172912
 *
\**************************************************************************/

#ifndef DIME_INT16RECORD_H
#define DIME_INT16RECORD_H

#include <dime/records/Record.h>

class dimeInt16Record : public dimeRecord
{
public:
  dimeInt16Record(const int group_code = 60, const int16 val = 0);

  virtual dimeRecord *copy(dimeMemHandler * const mh) const;
  virtual void setValue(const dimeParam &param, dimeMemHandler * const memhandler = NULL);
  virtual void getValue(dimeParam &param) const;
  
  int16 getValue() const;
  void setValue(const int16 val);

public:
  int typeId() const;
  bool read(dimeInput * const in);
  bool write(dimeOutput * const out);

private:
  int16 value;
  
}; // class dimeInt16Record

#endif // ! DIME_INT16RECORD_H

