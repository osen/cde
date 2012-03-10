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
/* $XConsortium: alarm.c /main/3 1995/11/01 16:27:14 rswiston $ */
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
#include	"defs.h"
#include	<error.h>
#include	<stak.h>
#include	"builtins.h"
#include	"FEATURE/time"

#define R_FLAG	1
#define L_FLAG	2

struct	tevent
{
	Namfun_t	fun;
	Namval_t	*node;
	Namval_t	*action;
	struct tevent	*next;
	long		milli;
	int		flags;
	__V_            *timeout;
};

static const char ALARM[] = "alarm";

static void	trap_timeout __PROTO__((__V_*));

/*
 * insert timeout item on current given list in sorted order
 */
static __V_ *time_add __PARAM__((struct tevent *item, __V_ *list), (item, list)) __OTORP__(struct tevent *item; __V_ *list;){
	register struct tevent *tp = (struct tevent*)list;
	if(!tp || item->milli < tp->milli)
	{
		item->next = tp;
		list = (__V_*)item;
	}
	else
	{
		while(tp->next && item->milli > tp->next->milli)
			tp = tp->next;
		item->next = tp->next;
		tp->next = item;
	}
	tp = item;
	tp->timeout = (__V_*)timeradd(tp->milli,tp->flags&R_FLAG,trap_timeout,(__V_*)tp);
	return(list);
}

/*
 * delete timeout item from current given list, delete timer
 */
static 	__V_ *time_delete __PARAM__((register struct tevent *item, __V_ *list), (item, list)) __OTORP__(register struct tevent *item; __V_ *list;){
	register struct tevent *tp = (struct tevent*)list;
	if(item==tp)
		list = (__V_*)tp->next;
	else
	{
		while(tp && tp->next != item)
			tp = tp->next;
		if(tp)
			tp->next = item->next;
	}
	if(item->timeout)
		timerdel((__V_*)item->timeout);
	return(list);
}

static void	print_alarms __PARAM__((__V_ *list), (list)) __OTORP__(__V_ *list;){
	register struct tevent *tp = (struct tevent*)list;
	while(tp)
	{
		if(tp->timeout)
		{
			register char *name = nv_name(tp->node);
			if(tp->flags&R_FLAG)
			{
				double d = tp->milli;
				sfprintf(sfstdout,e_alrm1,name,d/1000.);
			}
			else
				sfprintf(sfstdout,e_alrm2,name,nv_getnum(tp->node));
		}
		tp = tp->next;
	}
}

static void	trap_timeout __PARAM__((__V_* handle), (handle)) __OTORP__(__V_* handle;){
	register struct tevent *tp = (struct tevent*)handle;
	sh.trapnote |= SH_SIGTRAP;
	if(!(tp->flags&R_FLAG))
		tp->timeout = 0;
	tp->flags |= L_FLAG;
	sh.sigflag[SIGALRM] |= SH_SIGTRAP;
	if(sh_isstate(SH_TTYWAIT))
		sh_timetraps();
}

void	sh_timetraps __PARAM__((void), ()){
	register struct tevent *tp, *tpnext;
	register struct tevent *tptop;
	while(1)
	{
		sh.sigflag[SIGALRM] &= ~SH_SIGTRAP;
		tptop= (struct tevent*)sh.st.timetrap;
		for(tp=tptop;tp;tp=tpnext)
		{
			tpnext = tp->next;
			if(tp->flags&L_FLAG)
			{
				tp->flags &= ~L_FLAG;
				if(tp->action)
					sh_fun(tp->action,tp->node);
				tp->flags &= ~L_FLAG;
				if(!tp->flags)
				{
					nv_unset(tp->node);
					nv_close(tp->node);
				}
			}
		}
		if(!(sh.sigflag[SIGALRM]&SH_SIGTRAP))
			break;
	}
}


/*
 * This trap function catches "alarm" actions only
 */
static char *setdisc __PARAM__((Namval_t *np, const char *event, Namval_t* action, Namfun_t
 *fp), (np, event, action, fp)) __OTORP__(Namval_t *np; const char *event; Namval_t* action; Namfun_t
 *fp;){
        register struct tevent *tp = (struct tevent*)fp;
	if(!event)
		return(action?"":(char*)ALARM);
	if(strcmp(event,ALARM)!=0)
	{
		/* try the next level */
		return(nv_setdisc(np, event, action, fp));
	}
	if(action==np)
		action = tp->action;
	else
		tp->action = action;
	return(action?(char*)action:"");
}

/*
 * catch assignments and set alarm traps
 */
static void putval __PARAM__((Namval_t* np, const char* val, int flag, Namfun_t* fp), (np, val, flag, fp)) __OTORP__(Namval_t* np; const char* val; int flag; Namfun_t* fp;){
	register struct tevent *tp;
	register double d;
	if(val)
	{
		double now;
#ifdef _lib_gettimeofday
		struct timeval tmp;
		gettimeofday(&tmp,NIL(void *));
		now = tmp.tv_sec + 1.e-6*tmp.tv_usec;
#else
		now = (double)time(NIL(time_t*));
#endif /*_lib_gettimeofday */
		nv_putv(np,val,flag,fp);
		d = nv_getnum(np);
		tp = (struct tevent*)fp;
		if(*val=='+')
		{
			double x = d + now;
			nv_putv(np,(char*)&x,NV_INTEGER,fp);
		}
		else
			d -= now;
		tp->milli = 1000*(d+.0005);
		if(tp->timeout)
			sh.st.timetrap = time_delete(tp,sh.st.timetrap);
		if(tp->milli > 0)
			sh.st.timetrap = time_add(tp,sh.st.timetrap);
	}
	else
	{
		tp = (struct tevent*)nv_stack(np, (Namfun_t*)0);
		sh.st.timetrap = time_delete(tp,sh.st.timetrap);
		if(tp->action)
			nv_close(tp->action);
		nv_unset(np);
		free((__V_*)fp);
	}
}

static const Namdisc_t alarmdisc =
{
	sizeof(struct tevent),
	putval,
	0,
	0,
	setdisc,
};

int	b_alarm __PARAM__((int argc,char *argv[],__V_ *extra), (argc, argv, extra)) __OTORP__(int argc;char *argv[];__V_ *extra;){
	register int n,rflag=0;
	register Namval_t *np;
	register struct tevent *tp;
	NOT_USED(extra);
	while (n = optget(argv, sh_optalarm)) switch (n)
	{
	    case 'r':
		rflag = R_FLAG;
		break;
	    case ':':
		error(2, opt_arg);
		break;
	    case '?':
		error(ERROR_usage(2), opt_arg);
		break;
	}
	argc -= opt_index;
	argv += opt_index;
	if(error_info.errors)
		error(ERROR_usage(2),optusage((char*)0));
	if(argc==0)
	{
		print_alarms(sh.st.timetrap);
		return(0);
	}
	if(argc!=2)
		error(ERROR_usage(2),optusage((char*)0));
	np = nv_open(argv[0],sh.var_tree,NV_ARRAY|NV_VARNAME|NV_NOASSIGN);
	if(!nv_isnull(np))
		nv_unset(np);
	nv_setattr(np, NV_INTEGER|NV_DOUBLE);
	if(!(tp = newof(NIL(struct tevent*),struct tevent,1,0)))
		error(ERROR_exit(1),e_nospace);
	tp->fun.disc = &alarmdisc;
	tp->flags = rflag;
	tp->node = np;
	nv_stack(np,(Namfun_t*)tp);
	nv_putval(np, argv[1], 0);
	return(0);
}

