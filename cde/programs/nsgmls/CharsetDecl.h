/*
 * CDE - Common Desktop Environment
 *
 * Copyright (c) 1993-2012, The Open Group. All rights reserved.
 *
 * These libraries and programs are free software; you can
 * redistribute them and/or modify them under the terms of the GNU
 * Lesser General Public License as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * These libraries and programs are distributed in the hope that
 * they will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE. See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with these librararies and programs; if not, write
 * to the Free Software Foundation, Inc., 51 Franklin Street, Fifth
 * Floor, Boston, MA 02110-1301 USA
 */
/* $XConsortium: CharsetDecl.h /main/1 1996/07/29 16:47:13 cde-hp $ */
// Copyright (c) 1994 James Clark
// See the file COPYING for copying permission.

#ifndef CharsetDecl_INCLUDED
#define CharsetDecl_INCLUDED 1
#ifdef __GNUG__
#pragma interface
#endif

#include "types.h"
#include "Vector.h"
#include "ExternalId.h"
#include "ISet.h"
#include "Boolean.h"

#ifdef SP_NAMESPACE
namespace SP_NAMESPACE {
#endif

class SP_API CharsetDeclRange {
public:
  enum Type {
    number,
    string,
    unused
    };
  CharsetDeclRange();
  CharsetDeclRange(WideChar, Number, WideChar);
  CharsetDeclRange(WideChar, Number);
  CharsetDeclRange(WideChar, Number, const StringC &);
  void rangeDeclared(WideChar min, Number count,
		     ISet<WideChar> &declared) const;
  void usedSet(ISet<Char> &) const;
  Boolean getCharInfo(WideChar fromChar,
		      CharsetDeclRange::Type &type,
		      Number &n,
		      StringC &str,
		      Number &count) const;
  void stringToChar(const StringC &str, ISet<WideChar> &to) const;
  void numberToChar(Number n, ISet<WideChar> &to, Number &count) const;
private:
  WideChar descMin_;
  Number count_;
  WideChar baseMin_;
  Type type_;
  StringC str_;
};

class SP_API CharsetDeclSection {
public:
  CharsetDeclSection();
  void setPublicId(const PublicId &);
  void addRange(const CharsetDeclRange &);
  void rangeDeclared(WideChar min, Number count,
		     ISet<WideChar> &declared) const;
  void usedSet(ISet<Char> &) const;
  Boolean getCharInfo(WideChar fromChar,
		      const PublicId *&id,
		      CharsetDeclRange::Type &type,
		      Number &n,
		      StringC &str,
		      Number &cout) const;
  void stringToChar(const StringC &str, ISet<WideChar> &to) const;
  void numberToChar(const PublicId *id, Number n,
		    ISet<WideChar> &to, Number &count) const;
private:
  PublicId baseset_;
  Vector<CharsetDeclRange> ranges_;
};

class SP_API CharsetDecl {
public:
  CharsetDecl();
  void addSection(const PublicId &);
  void swap(CharsetDecl &);
  void clear();
  void usedSet(ISet<Char> &) const;
  void declaredSet(ISet<WideChar> &set) const;
  Boolean charDeclared(WideChar) const;
  void rangeDeclared(WideChar min, Number count,
		     ISet<WideChar> &declared) const;
  void addRange(WideChar, Number, WideChar);
  void addRange(WideChar, Number);
  void addRange(WideChar, Number, const StringC &);
  Boolean getCharInfo(WideChar fromChar,
		      const PublicId *&id,
		      CharsetDeclRange::Type &type,
		      Number &n,
		      StringC &str) const;
  Boolean getCharInfo(WideChar fromChar,
		      const PublicId *&id,
		      CharsetDeclRange::Type &type,
		      Number &n,
		      StringC &str,
		      Number &count) const;
  void stringToChar(const StringC &str, ISet<WideChar> &to) const;
  void numberToChar(const PublicId *id, Number n,
		    ISet<WideChar> &to, Number &count) const;
  void numberToChar(const PublicId *id, Number n, ISet<WideChar> &to) const;
private:
  Vector<CharsetDeclSection> sections_;
  ISet<WideChar> declaredSet_;
};

inline
Boolean CharsetDecl::getCharInfo(WideChar fromChar,
				 const PublicId *&id,
				 CharsetDeclRange::Type &type,
				 Number &n,
				 StringC &str) const
{
  Number tem;
  return getCharInfo(fromChar, id, type, n, str, tem);
}

inline
void CharsetDecl::numberToChar(const PublicId *id, Number n,
			       ISet<WideChar> &to) const
{
  Number tem;
  numberToChar(id, n, to, tem);
}

inline
void CharsetDecl::declaredSet(ISet<WideChar> &set) const
{
  set = declaredSet_;
}

inline
Boolean CharsetDecl::charDeclared(WideChar c) const
{
  return declaredSet_.contains(c);
}

#ifdef SP_NAMESPACE
}
#endif

#endif /* not CharsetDecl_INCLUDED */
