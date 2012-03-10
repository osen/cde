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
/* $XConsortium: try.c /main/3 1996/06/19 17:13:58 drk $ */
/*
 * Simple test program for regexp(3) stuff.  Knows about debugging hooks.
 *
 *	Copyright (c) 1986 by University of Toronto.
 *	Written by Henry Spencer.  Not derived from licensed software.
 *
 *	Permission is granted to anyone to use this software for any
 *	purpose on any computer system, and to redistribute it freely,
 *	subject to the following restrictions:
 *
 *	1. The author is not responsible for the consequences of use of
 *		this software, no matter how awful, even if they arise
 *		from defects in it.
 *
 *	2. The origin of this software must not be misrepresented, either
 *		by explicit claim or by omission.
 *
 *	3. Altered versions must be plainly marked as such, and must not
 *		be misrepresented as being the original software.
 *
 * Usage: try re [string [output [-]]]
 * The re is compiled and dumped, regexeced against the string, the result
 * is applied to output using regsub().  The - triggers a running narrative
 * from regexec().  Dumping and narrative don't happen unless DEBUG.
 *
 * If there are no arguments, stdin is assumed to be a stream of lines with
 * five fields:  a r.e., a string to match it against, a result code, a
 * source string for regsub, and the proper result.  Result codes are 'c'
 * for compile failure, 'y' for match success, 'n' for match failure.
 * Field separator is tab.
 */
#include <stdio.h>
#include <tptregexp.h>

#ifdef ERRAVAIL
char *progname;
extern char *mkprogname();
#endif

#ifdef DEBUG
extern int regnarrate;
#endif

char buf[BUFSIZ];

int errreport = 0;		/* Report errors via errseen? */
char *errseen = NULL;		/* Error message. */
int status = 0;			/* Exit status. */

/* ARGSUSED */
main(argc, argv)
int argc;
char *argv[];
{
	regexp *r;
	int i;

#ifdef ERRAVAIL
	progname = mkprogname(argv[0]);
#endif

	if (argc == 1) {
		multiple();
		exit(status);
	}

	r = tpt_regcomp(argv[1]);
	if (r == NULL)
		error("tpt_regcomp failure", "");
#ifdef DEBUG
	regdump(r);
	if (argc > 4)
		regnarrate++;
#endif
	if (argc > 2) {
		i = tpt_regexec(r, argv[2]);
		printf("%d", i);
		for (i = 1; i < NSUBEXP; i++)
			if (r->startp[i] != NULL && r->endp[i] != NULL)
				printf(" \\%d", i);
		printf("\n");
	}
	if (argc > 3) {
		tpt_regsub(r, argv[3], buf);
		printf("%s\n", buf);
	}
	exit(status);
}

void
tpt_regerror(s)
char *s;
{
	if (errreport)
		errseen = s;
	else
		error(s, "");
}

#ifndef ERRAVAIL
error(s1, s2)
char *s1;
char *s2;
{
	fprintf(stderr, "regexp: ");
	fprintf(stderr, s1, s2);
	fprintf(stderr, "\n");
	exit(1);
}
#endif

int lineno;

regexp badregexp;		/* Implicit init to 0. */

multiple()
{
	char rbuf[BUFSIZ];
	char *field[5];
	char *scan;
	int i;
	regexp *r;
	extern char *strchr();

	errreport = 1;
	lineno = 0;
	while (fgets(rbuf, sizeof(rbuf), stdin) != NULL) {
		rbuf[strlen(rbuf)-1] = '\0';	/* Dispense with \n. */
		lineno++;
		scan = rbuf;
		for (i = 0; i < 5; i++) {
			field[i] = scan;
			if (field[i] == NULL) {
				complain("bad testfile format", "");
				exit(1);
			}
			scan = strchr(scan, '\t');
			if (scan != NULL)
				*scan++ = '\0';
		}
		try(field);
	}

	/* And finish up with some internal testing... */
	lineno = 9990;
	errseen = NULL;
	if (tpt_regcomp((char *)NULL) != NULL || errseen == NULL)
		complain("tpt_regcomp(NULL) doesn't complain", "");
	lineno = 9991;
	errseen = NULL;
	if (tpt_regexec((regexp *)NULL, "foo") || errseen == NULL)
		complain("tpt_regexec(NULL, ...) doesn't complain", "");
	lineno = 9992;
	r = tpt_regcomp("foo");
	if (r == NULL) {
		complain("tpt_regcomp(\"foo\") fails", "");
		return;
	}
	lineno = 9993;
	errseen = NULL;
	if (tpt_regexec(r, (char *)NULL) || errseen == NULL)
		complain("tpt_regexec(..., NULL) doesn't complain", "");
	lineno = 9994;
	errseen = NULL;
	tpt_regsub((regexp *)NULL, "foo", rbuf);
	if (errseen == NULL)
		complain("tpt_regsub(NULL, ..., ...) doesn't complain", "");
	lineno = 9995;
	errseen = NULL;
	tpt_regsub(r, (char *)NULL, rbuf);
	if (errseen == NULL)
		complain("tpt_regsub(..., NULL, ...) doesn't complain", "");
	lineno = 9996;
	errseen = NULL;
	tpt_regsub(r, "foo", (char *)NULL);
	if (errseen == NULL)
		complain("tpt_regsub(..., ..., NULL) doesn't complain", "");
	lineno = 9997;
	errseen = NULL;
	if (tpt_regexec(&badregexp, "foo") || errseen == NULL)
		complain("tpt_regexec(nonsense, ...) doesn't complain", "");
	lineno = 9998;
	errseen = NULL;
	tpt_regsub(&badregexp, "foo", rbuf);
	if (errseen == NULL)
		complain("tpt_regsub(nonsense, ..., ...) doesn't complain", "");
}

try(fields)
char **fields;
{
	regexp *r;
	char dbuf[BUFSIZ];

	errseen = NULL;
	r = tpt_regcomp(fields[0]);
	if (r == NULL) {
		if (*fields[2] != 'c')
			complain("tpt_regcomp failure in `%s'", fields[0]);
		return;
	}
	if (*fields[2] == 'c') {
		complain("unexpected tpt_regcomp success in `%s'", fields[0]);
		free((char *)r);
		return;
	}
	if (!tpt_regexec(r, fields[1])) {
		if (*fields[2] != 'n')
			complain("tpt_regexec failure in `%s'", "");
		free((char *)r);
		return;
	}
	if (*fields[2] == 'n') {
		complain("unexpected tpt_regexec success", "");
		free((char *)r);
		return;
	}
	errseen = NULL;
	tpt_regsub(r, fields[3], dbuf);
	if (errseen != NULL) {
		complain("tpt_regsub complaint", "");
		free((char *)r);
		return;
	}
	if (strcmp(dbuf, fields[4]) != 0)
		complain("tpt_regsub result `%s' wrong", dbuf);
	free((char *)r);
}

complain(s1, s2)
char *s1;
char *s2;
{
	fprintf(stderr, "try: %d: ", lineno);
	fprintf(stderr, s1, s2);
	fprintf(stderr, " (%s)\n", (errseen != NULL) ? errseen : "");
	status = 1;
}
