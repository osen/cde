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
/* $XConsortium: nocom.c /main/2 1996/05/08 19:40:06 drk $ */
/***************************************************************
*                                                              *
*                      AT&T - PROPRIETARY                      *
*                                                              *
*         THIS IS PROPRIETARY SOURCE CODE LICENSED BY          *
*                          AT&T CORP.                          *
*                                                              *
*                Copyright (c) 1995 AT&T Corp.                 *
*                     All Rights Reserved                      *
*                                                              *
*           This software is licensed by AT&T Corp.            *
*       under the terms and conditions of the license in       *
*       http://www.research.att.com/orgs/ssr/book/reuse        *
*                                                              *
*               This software was created by the               *
*           Software Engineering Research Department           *
*                    AT&T Bell Laboratories                    *
*                                                              *
*               For further information contact                *
*                     gsf@research.att.com                     *
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
static const char id[] = "\n@(#)nocom (AT&T Bell Laboratories) 08/11/94\0\n";

#include <ast.h>
#include <ctype.h>
#include <error.h>

#define DATA(c)	do							\
		{							\
			data = 1;					\
			if (line > prev)				\
			{						\
				if (sfsprintf(buf, sizeof(buf), "#%s %d\n", sync <= 0 ? "line" : "", line) <= line - prev)	\
				{					\
					sfputr(sfstdout, buf, -1);	\
					prev = line;			\
				}					\
				else while (prev++ < line)		\
					sfputc(sfstdout, '\n');		\
			}						\
			sfputc(sfstdout, c);				\
		} while (0)

/*
 * uncomment sp
 */

static void
nocom __PARAM__((register Sfio_t* sp, char* file), (sp, file)) __OTORP__(register Sfio_t* sp; char* file;){
	register int	c = 0;
	register int	p;
	register int	data = 0;
	int		sync = 0;
	unsigned long	line = 0;
	unsigned long	prev = 0;
	unsigned long	directive = 0;
	int		quote;
	char*		s;
	char		buf[PATH_MAX];

	for (;;)
	{
	next:
		p = c;
		c = sfgetc(sp);
	check:
		switch (c)
		{
		case EOF:
			return;
		case 0:
			sfputc(sfstdout, c);
			sfmove(sp, sfstdout, SF_UNBOUND, -1);
			return;
		case '\\':
			DATA(c);
			switch (c = sfgetc(sp))
			{
			case EOF:
				return;
			case '\n':
				prev = ++line;
				break;
			}
			sfputc(sfstdout, c);
			break;
		case '\f':
		case '\t':
		case '\013':
			c = ' ';
			/*FALLTHROUGH*/
		case ' ':
			if (data) switch (p)
			{
			case ' ':
			case '\n':
			case '(':
			case '[':
			case ']':
			case '{':
			case '}':
			case ';':
			case ':':
			case '!':
			case '<':
			case '>':
			case '|':
			case ',':
			case '?':
			case '*':
				break;
			case ')':
				if (directive == line)
				{
					directive = 0;
					sfputc(sfstdout, ' ');
				}
				break;
			default:
				switch (c = sfgetc(sp))
				{
				case '\n':
				case ')':
				case '[':
				case ']':
				case '{':
				case '}':
				case ';':
				case ':':
				case '=':
				case '!':
				case '<':
				case '>':
				case '|':
				case ',':
				case '?':
					break;
				case '(':
					if (directive == line)
					{
						directive = 0;
						sfputc(sfstdout, ' ');
					}
					break;
				case '*':
					if (p == '/' || p == '=')
						sfputc(sfstdout, ' ');
					break;
				case '+':
				case '-':
				case '&':
					if (p == c || p == '=')
						sfputc(sfstdout, ' ');
					break;
				default:
					if (p != '=')
						sfputc(sfstdout, ' ');
					break;
				}
				p = ' ';
				goto check;
			}
			break;
		case '\n':
			line++;
			if (data)
			{
				data = 0;
				sfputc(sfstdout, '\n');
				prev = line;
			}
			break;
		case '#':
			if (sync >= 0 && !data)
			{
				if (s = sfgetr(sp, '\n', 1))
				{
					while (*s == ' ' && *s == '\t')
						s++;
					if (p = isdigit(*s))
					{
						sync = 1;
						line = strtol(s, NiL, 10);
					}
					else if (!sync)
					{
						if (!line && strneq(s, "pragma prototyped", 17))
						{
							sync = -1;
							s = "proto -ns";
							if (sp != sfstdin)
							{
								sfsprintf(buf, sizeof(buf), "proto -ns %s", file);
								s = buf;
							}
							else if (sfseek(sp, 0L, SEEK_SET))
							{
								error(2, "%s: must be seekable to run proto", file);
								return;
							}
							if (!(sp = sfpopen(sp, s, "r")))
							{
								error(2, "%s: cannot run proto", file);
								return;
							}
							c = 0;
							goto next;
						}
						if (!strneq(s, "ident", 5) && !strneq(s, "line", 4) && !strneq(s, "pragma", 6))
							sync = -1;
					}
					if (!p || strchr(s, '"'))
					{
						if (p) sfputc(sfstdout, c);
						else DATA(c);
						sfputr(sfstdout, s, '\n');
						prev = line;
					}
					c = '\n';
					break;
				}
				sync = -1;
			}
			directive = line;
			DATA(c);
			break;
		case '/':
			switch (c = sfgetc(sp))
			{
			case EOF:
				return;
			case '/':
				for (;;) switch (sfgetc(sp))
				{
				case EOF:
					return;
				case '\n':
					p = ' ';
					c = '\n';
					goto check;
				}
				break;
			case '*':
				for (;;) switch (sfgetc(sp))
				{
				case EOF:
					return;
				case '\n':
					line++;
					if (data)
					{
						data = 0;
						sfputc(sfstdout, '\n');
						prev = line;
					}
					break;
				case '*':
					for (;;)
					{
						switch (sfgetc(sp))
						{
						case EOF:
							return;
						case '\n':
							line++;
							if (data)
							{
								data = 0;
								sfputc(sfstdout, '\n');
								prev = line;
							}
							break;
						case '/':
							p = c = ' ';
							goto check;
						case '*':
							continue;
						}
						break;
					}
					break;
				}
				break;
			default:
				p = '/';
				DATA(p);
				goto check;
			}
			break;
		case '"':
		case '\'':
			DATA(c);
			quote = c;
			for (;;)
			{
				switch (c = sfgetc(sp))
				{
				case EOF:
					return;
				case '\\':
					sfputc(sfstdout, c);
					switch (c = sfgetc(sp))
					{
					case EOF:
						return;
					case '\n':
						prev = ++line;
						break;
					}
					break;
				case '"':
				case '\'':
					if (c == quote)
					{
						sfputc(sfstdout, c);
						goto next;
					}
					break;
				case '\n':
					p = ' ';
					goto check;
				}
				sfputc(sfstdout, c);
			}
			break;
		default:
			DATA(c);
			break;
		}
	}
	/*NOTREACHED*/
}

main __PARAM__((int argc, char** argv), (argc, argv)) __OTORP__(int argc; char** argv;){
	register int		c;
	register char*		s;
	register Sfio_t*	sp;

	NoP(argc);
	error_info.id = "nocom";
	while (c = optget(argv, " [file ...]")) switch (c)
	{
	case '?':
		error(ERROR_USAGE|4, opt_info.arg);
		break;
	case ':':
		error(2, opt_info.arg);
		break;
	}
	argv += opt_info.index;
	if (error_info.errors)
		error(ERROR_USAGE|4, optusage(NiL));
	if (!*argv) nocom(sfstdin, "/dev/stdin");
	else while (s = *argv++)
	{
		if (!(sp = sfopen(NiL, s, "r")))
			error(ERROR_SYSTEM|2, "%s: cannot read", s);
		else
		{
			nocom(sp, s);
			sfclose(sp);
		}
	}
	exit(error_info.errors != 0);
}
