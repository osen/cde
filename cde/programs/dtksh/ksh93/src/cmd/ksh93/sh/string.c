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
/* $XConsortium: string.c /main/3 1995/11/01 16:51:19 rswiston $ */
/***************************************************************
*                                                              *
*                      AT&T - PROPRIETARY                      *
*                                                              *
*        THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF        *
*                    AT&T BELL LABORATORIES                    *
*         AND IS NOT TO BE DISCLOSED OR USED EXCEPT IN         *
*            ACCORDANCE WITH APPLICABLE AGREEMENTS             *
*                                                              *
*                Copyright (c) 1995 AT&T Corp.                 *
*              Unpublished & Not for Publication               *
*                     All Rights Reserved                      *
*                                                              *
*       The copyright notice above does not evidence any       *
*      actual or intended publication of such source code      *
*                                                              *
*               This software was created by the               *
*           Advanced Software Technology Department            *
*                    AT&T Bell Laboratories                    *
*                                                              *
*               For further information contact                *
*                    {research,attmail}!dgk                    *
*                                                              *
***************************************************************/

/* : : generated by proto : : */

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
#include	<ast.h>
#include	"defs.h"
#include	<stak.h>
#include	<ctype.h>
#include	"shtable.h"
#include	"lexstates.h"
#include	"national.h"

/*
 *  Table lookup routine
 *  <table> is searched for string <sp> and corresponding value is returned
 *  This is only used for small tables and is used to save non-sharable memory 
 */

int sh_locate __PARAM__((register const char *sp,const Shtable_t *table,int size), (sp, table, size)) __OTORP__(register const char *sp;const Shtable_t *table;int size;){
	register int first;
	register const Shtable_t	*tp;
	register int c;
	if(sp==0 || (first= *sp)==0)
		return(0);
	tp=table;
	while((c= *tp->sh_name) && c <= first)
	{
		if(first == c && strcmp(sp,tp->sh_name)==0)
			return(tp->sh_number);
		tp = (Shtable_t*)((char*)tp+size);
	}
	return(0);
}

/*
 * look for the substring <oldsp> in <string> and replace with <newsp>
 * The new string is put on top of the stack
 */
char *sh_substitute __PARAM__((const char *string,const char *oldsp,char *newsp), (string, oldsp, newsp)) __OTORP__(const char *string;const char *oldsp;char *newsp;){
	register const char *sp = string;
	register const char *cp;
	const char *savesp = 0;
	stakseek(0);
	if(*sp==0)
		return((char*)0);
	if(*(cp=oldsp) == 0)
		goto found;
#ifdef SHOPT_MULTIBYTE
	mblen(NIL(char*),MB_CUR_MAX);
#endif /* SHOPT_MULTIBYTE */
	do
	{
	/* skip to first character which matches start of oldsp */
		while(*sp && (savesp==sp || *sp != *cp))
		{
#ifdef SHOPT_MULTIBYTE
			/* skip a whole character at a time */
			int c = mblen(sp,MB_CUR_MAX);
			if(c < 0)
				sp++;
			while(c-- > 0)
#endif /* SHOPT_MULTIBYTE */
			stakputc(*sp++);
		}
		if(*sp == 0)
			return((char*)0);
		savesp = sp;
	        for(;*cp;cp++)
		{
			if(*cp != *sp++)
				break;
		}
		if(*cp==0)
		/* match found */
			goto found;
		sp = savesp;
		cp = oldsp;
	}
	while(*sp);
	return((char*)0);

found:
	/* copy new */
	stakputs(newsp);
	/* copy rest of string */
	stakputs(sp);
	return(stakfreeze(1));
}

/*
 * TRIM(sp)
 * Remove escape characters from characters in <sp> and eliminate quoted nulls.
 */

void	sh_trim __PARAM__((register char *sp), (sp)) __OTORP__(register char *sp;){
	register char *dp;
	register int c;
	if(sp)
	{
		dp = sp;
		while(c= *sp++)
		{
			if(c == '\\')
				c = *sp++;
			if(c)
				*dp++ = c;
		}
		*dp = 0;
	}
}

/*
 * print <str> qouting chars so that it can be read by the shell
 * puts null terminated result on stack, but doesn't freeze it
 */
char	*sh_fmtq __PARAM__((const char *string), (string)) __OTORP__(const char *string;){
	register const char *cp = string;
	register int c, state;
	int offset;
	if(!cp)
		return((char*)0);
	offset = staktell();
	state = ((c= *cp)==0);
	if(isaletter(c))
	{
		while((c = *++cp),isaname(c));
		if(c==0)
			return((char*)string);
		if(c=='=')
		{
			c = ++cp - string;
			if(*cp==0)
				return((char*)string);
			stakwrite(string,c);
			c = *(string=cp);
		}
	}
	if(c==0 || c=='#' || c=='~')
		state = 1;
	while(c= *(unsigned char*)cp++)
	{
#ifdef SHOPT_MULTIBYTE
		int s;
		if((s=mblen(cp-1,MB_CUR_MAX)) > 1)
		{
			cp += (s-1);
			continue;
		}
#endif /* SHOPT_MULTIBYTE */
		if(c=='\'' || !isprint(c))
			state = 2;
		else if(c==']' || (c!=':' && (c=sh_lexstates[ST_NORM][c]) && c!=S_EPAT))
			state |=1;
	}
	if(state<2)
	{
		if(state==1)
			stakputc('\'');
		if(c = --cp - string)
			stakwrite(string,c);
		if(state==1)
			stakputc('\'');
	}
	else
	{
		stakwrite("$'",2);
		cp = string;
		while(c= *(unsigned char*)cp++)
		{
			state=1;
			switch(c)
			{
			    case '\033':
				c = 'E';
				break;
			    case '\n':
				c = 'n';
				break;
			    case '\r':
				c = 'r';
				break;
			    case '\t':
				c = 't';
				break;
			    case '\f':
				c = 'f';
				break;
			    case '\b':
				c = 'b';
				break;
			    case '\007':
				c = 'a';
				break;
			    case '\\':	case '\'':
				break;
			    default:
				if(!isprint(c))
				{
					sfprintf(staksp,"\\%.3o",c);
					continue;
				}
				state=0;
				break;
			}
			if(state)
				stakputc('\\');
			stakputc(c);
		}
		stakputc('\'');
	}
	stakputc(0);
	return(stakptr(offset));
}

#ifdef SHOPT_MULTIBYTE
	int sh_strchr __PARAM__((const char *string, register const char *dp), (string, dp)) __OTORP__(const char *string; register const char *dp;){
		wchar_t c,d; 
		register int m;
		register const char *cp=string;
		int n = mbtowc(&d,dp,MB_CUR_MAX);
		while((m=mbtowc(&c,cp,MB_CUR_MAX)) && c)
		{
			if(c==d)
				return(cp-string);
			cp+=m;
		}
		return(-1);
	}
#   ifndef _lib_wcwidth
	/*
	 * only works for EUC
	 */
	int	wcwidth __PARAM__((const wchar_t w), (w)) __OTORP__(const wchar_t w;){
		int c;
		unsigned char buff[ESS_MAXCHAR+1];
		wctomb((char*)buff,w);
		c = echarset(*buff);
		return(out_csize(c));
	}
#   endif /* _lib_wcwidth */
#endif /* SHOPT_MULTIBYTE */
