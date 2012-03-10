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
/* $XConsortium: int.c /main/3 1995/11/01 17:26:00 rswiston $ */
/***************************************************************
*                                                              *
*                      AT&T - PROPRIETARY                      *
*                                                              *
*        THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF        *
*                    AT&T BELL LABORATORIES                    *
*         AND IS NOT TO BE DISCLOSED OR USED EXCEPT IN         *
*            ACCORDANCE WITH APPLICABLE AGREEMENTS             *
*                                                              *
*          Copyright (c) 1994 AT&T Bell Laboratories           *
*              Unpublished & Not for Publication               *
*                     All Rights Reserved                      *
*                                                              *
*       The copyright notice above does not evidence any       *
*      actual or intended publication of such source code      *
*                                                              *
*               This software was created by the               *
*           Software Engineering Research Department           *
*                    AT&T Bell Laboratories                    *
*                                                              *
*               For further information contact                *
*                   advsoft@research.att.com                   *
*                 Randy Hackbarth 908-582-5245                 *
*                  Dave Belanger 908-582-7427                  *
*                                                              *
***************************************************************/

/* : : generated by proto : : */

#line 1

#if !defined(__PROTO__)
#if defined(__STDC__) || defined(__cplusplus) || defined(_proto) || defined(c_plusplus)
#if defined(__cplusplus)
#define __MANGLE__	"C"
#else
#define __MANGLE__
#endif
#define __STDARG__
#define __PROTO__(x)	x
#define __OTORP__(x)
#define __PARAM__(n,o)	n
#if !defined(__STDC__) && !defined(__cplusplus)
#if !defined(c_plusplus)
#define const
#endif
#define signed
#define void		int
#define volatile
#define __V_		char
#else
#define __V_		void
#endif
#else
#define __PROTO__(x)	()
#define __OTORP__(x)	x
#define __PARAM__(n,o)	o
#define __MANGLE__
#define __V_		char
#define const
#define signed
#define void		int
#define volatile
#endif
#if defined(__cplusplus) || defined(c_plusplus)
#define __VARARG__	...
#else
#define __VARARG__
#endif
#if defined(__STDARG__)
#define __VA_START__(p,a)	va_start(p,a)
#else
#define __VA_START__(p,a)	va_start(p)
#endif
#endif

#line 9
#include "FEATURE/types"

#define elementsof(x)	(sizeof(x)/sizeof(x[0]))

extern __MANGLE__ int		printf __PROTO__((const char*, ...));

static char		i_char = 1;
static short		i_short = 1;
static int		i_int = 1;
static long		i_long = 1;
#if _typ_long_long
static long long	i_long_long = 1;
#endif

static struct
{
	char*	name;
	int	size;
	char*	swap;
} type[] = 
{
	"char",		sizeof(char),		(char*)&i_char,
	"short",	sizeof(short),		(char*)&i_short,
	"int",		sizeof(int),		(char*)&i_int,
	"long",		sizeof(long),		(char*)&i_long,
#if _typ_long_long
	"long long",	sizeof(long long),	(char*)&i_long_long,
#endif
};

static int	size[] = { 1, 2, 4, 8 };

main()
{
	register int	t;
	register int	s;
	register int	m = 1;

	for (s = 0; s < elementsof(size); s++)
	{
		for (t = 0; t < elementsof(type) && type[t].size < size[s]; t++);
		if (t < elementsof(type))
		{
			m = size[s];
			printf("#ifndef int_%d\n", m);
			printf("#define int_%d		%s\n", m, type[t].name);
			printf("#endif\n");
		}
	}
	printf("#ifndef	int_max\n");
	printf("#define int_max		int_%d\n", m);
	printf("#endif\n");
	for (t = 0; t < elementsof(type) - 1 && *type[t + 1].swap; t++);
	printf("#ifndef	int_swap\n");
	printf("#define int_swap	%d\n", t ? type[t].size : 0);
	printf("#endif\n");
	return(0);
}
