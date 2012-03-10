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
/* $XConsortium: apollo.c /main/4 1996/10/04 15:52:17 drk $ */
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
#include        "defs.h"
#include	<errno.h>

#ifdef apollo
#include "/sys/ins/base.ins.c"
#include "/sys/ins/pad.ins.c"
#include "/sys/ins/error.ins.c"
#include <sys/param.h>	/* for maximum pathname length */
#include <apollo/sys/ubase.h>
#include <apollo/sys/name.h>
#include <apollo/error.h>

int pad_create __PARAM__((char *fname), (fname)) __OTORP__(char *fname;){
	short oldfd = 1;
	short newfd;
        short size = 25;
	long st;

	pad_$create (*fname, (short)strlen(fname), pad_$edit, oldfd, 
	    pad_$bottom, 0, size, newfd, st);
        if (st != 0)
		error(ERROR_system(1),e_open,"dm pad");
	return(newfd);
}

pad_wait __PARAM__((int fd), (fd)) __OTORP__(int fd;){
	long st;

	pad_$edit_wait((stream_$id_t)fd, st);

        return (st == 0 ? 0 : 1);

}

char *apollo_error __PARAM__((void), ()){
	extern __MANGLE__ long unix_proc_$status;
        char subsys[80], module[80], code[80];
        short slen, mlen, clen;
        static char retstr[256];

        error_$get_text (unix_proc_$status, subsys, slen, 
        	module, mlen, code, clen);
	subsys[slen] = module[mlen] = code[clen] = 0;
	if (clen == 0)
		sprintf (code, "status 0x%08lx", unix_proc_$status);
	if ( mlen )
		sprintf(retstr, "%s (%s/%s)", code, subsys, module );
	else
		sprintf(retstr, "%s (%s)", code, subsys );		

        return (retstr);
}

/*
 * declarations to support the apollo builtin commands 
 * rootnode, inlib, and ver.
 */

static char last_rootnode[MAXPATHLEN] = "/";
static char do_ver;
static char *preval = NULL, *sysval, *sysid = "SYSTYPE";

/* 
 * code to support the apollo builtin functions rootnode, 
 * inlib, and ver.
 */

int	b_rootnode __PARAM__((int argn,char *argv[]), (argn, argv)) __OTORP__(int argn;char *argv[];){
	if (argn == 1) 
	{ 	/* report current setting */
		sfprintf(sfstdout,"%s\n",last_rootnode);
			return(0);
	}
	if (!is_valid_rootnode(argv[1])) 
		sh_cfail(e_rootnode);
	if (rootnode(argv[1]) != 0) 
	{
		perror("rootnode: ");	/* ? */
		sh_cfail(e_rootnode);
	}
	if (argn == 2)
		strcpy(last_rootnode, argv[1]);
	else 
	{
		sysval = argv[1];
		sh_eval(sh_sfeval(argv),0);
		if (rootnode(last_rootnode) != 0) 
			sh_cfail(e_rootnode);
	}
	return(0);
}

int	b_ver __PARAM__((int argn,char *argv[]), (argn, argv)) __OTORP__(int argn;char *argv[];){
	char *oldver;
	short i1, i2;
	std_$call unsigned char	c_$decode_version(__VARARG__);

	oldver = SYSTYPENOD->namval.cp;
	if (argn == 1 || argn > 2) 
	{
		sysval = NULL;
		if (oldver)
			preval = sysval = oldver;
	}
	if (argn == 1) 
	{
		if (!oldver || !sysval)
			sh_cfail(e_nover);
		else 
		{
			sfprintf(sfstdout,"%s\n",sysval);
		}
	}
	else 
	{
		if (!c_$decode_version (*argv[1], (short) strlen (argv[1]), i1, i2))
			sh_cfail(e_badver);
		else 
		{
			if (argn == 2) 
			{
				short namlen = strlen(sysid);
				short arglen = strlen(argv[1]);
				 
				nv_unset(SYSTYPENOD);
				nv_putval(SYSTYPENOD, argv[1],NV_RDONLY);
				nv_onattr(SYSTYPENOD, NV_EXPORT | NV_NOFREE);
				ev_$set_var (sysid, &namlen, argv[1], &arglen);
			}
			else 
			{
				int fd;
				short namlen = strlen(sysid);
				short arglen = strlen(argv[1]);

				sysval = argv[1];
				argv = &argv[2];
				sh_eval(sh_sfeval(argv),0);
				ev_$set_var(sysid, &namlen, sysval, &arglen);
				if((fd=path_open(argv[0],path_get(argv[0]))) < 0)
				{
					arglen = (short)strlen(preval);
					ev_$set_var (sysid, &namlen, preval, &arglen);
					error(ERROR_system(1),e_open,argv[0]);
				}
				close(fd);
				sh_eval(sfopen(argv[0],"s"),0);
				arglen = (short)strlen(preval);
				ev_$set_var (sysid, &namlen, preval, &arglen);
			}
		}
	 }
	return(sh.exitval);
}

/*
 * rootnode.c - a chroot call which doesn't require you to be root...
 */

/*
 *  Changes:
	01/24/88 brian	Initial coding
 */
                  

#ifndef NULL
# define	NULL	((__V_ *) 0)
#endif

extern __MANGLE__ boolean
unix_fio_$status_to_errno __PROTO__((
		status_$t	& status,
		char		* pn,
		short		& pnlen                  
));

is_valid_rootnode __PARAM__((const char *path), (path)) __OTORP__(const char *path;){
	if (geteuid() == 0)
		return 1;
	return (path[0] == '/' && path[1] == '/' && path[2] != '\0' &&
		strchr(&path[2], '/') == NULL);
}

rootnode __PARAM__((char * path), (path)) __OTORP__(char * path;){
        uid_$t		dir_uid, rtn_uid;
	name_$pname_t	new_root_name, rest_path;
	name_$name_t	leaf;
	short		rest_len, leaf_len, err;
	status_$t	status;
        
	strcpy(new_root_name, path);

	name_$resolve_afayc(new_root_name, (short)strlen(new_root_name), 
		&dir_uid, &rtn_uid, rest_path, &rest_len, leaf, &leaf_len, &err, &status);

       	if (status.all != status_$ok) {
		unix_fio_$status_to_errno(status, path, strlen(path));
		return (-1);
	}

	name_$set_diru(rtn_uid, rest_path, (short) rest_len, name_$node_dir_type, &status);
         
       	if (status.all != status_$ok) {
		unix_fio_$status_to_errno(status, path, strlen(path));
		return(-1);
	}
	return(0);
}

#endif /* apollo */

/*
 *  Apollo system support library loads into the virtual address space
 */

int	b_inlib(argc,argv)
char **argv;
{
	register char *a1 = argv[1];
	int status;
	short len;
	std_$call void loader_$inlib(__VARARG__);
	if(sh.subshell)
		sh_subfork();
	if(a1)
	{
		len = strlen(a1);
		loader_$inlib(*a1, len, status);
		if(status!=0)
			error(3, e_badinlib);
	}
	return(0);
}
