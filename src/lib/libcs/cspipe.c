/***********************************************************************
 *                                                                      *
 *               This software is part of the ast package               *
 *          Copyright (c) 1990-2011 AT&T Intellectual Property          *
 *                      and is licensed under the                       *
 *                 Eclipse Public License, Version 1.0                  *
 *                    by AT&T Intellectual Property                     *
 *                                                                      *
 *                A copy of the License is available at                 *
 *          http://www.eclipse.org/org/documents/epl-v10.html           *
 *         (with md5 checksum b35adb5213ca9657e911e9befb180842)         *
 *                                                                      *
 *              Information and Software Systems Research               *
 *                            AT&T Research                             *
 *                           Florham Park NJ                            *
 *                                                                      *
 *               Glenn Fowler <glenn.s.fowler@gmail.com>                *
 *                                                                      *
 ***********************************************************************/
/*
 * Glenn Fowler
 * AT&T Research
 *
 * create bi-directional local pipe
 */
#include "config_ast.h"  // IWYU pragma: keep

#include "cslib.h"

int cspipe(Cs_t *state, int *fds) {
    csprotect(&cs);

#if CS_LIB_SOCKET_UN

    return socketpair(AF_UNIX, SOCK_STREAM, 0, fds);

#else

    return pipe(fds);

#endif
}

int _cs_pipe(int *fds) { return cspipe(&cs, fds); }
