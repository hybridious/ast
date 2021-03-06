/***********************************************************************
 *                                                                      *
 *               This software is part of the ast package               *
 *          Copyright (c) 1999-2011 AT&T Intellectual Property          *
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
#include "config_ast.h"  // IWYU pragma: keep

#include "dttest.h"

Dtdisc_t Disc = {0, sizeof(long), -1, newint, NULL, compare, hashint, NULL, NULL};

tmain() {
    Dt_t *dt;

    /* testing Dtstack */
    if (!(dt = dtopen(&Disc, Dtstack))) terror("dtopen stack");
    if ((long)dtinsert(dt, 1L) != 1) terror("Dtstack insert 1");
    if ((long)dtinsert(dt, 3L) != 3) terror("Dtstack insert 3.1");
    if ((long)dtinsert(dt, 2L) != 2) terror("Dtstack insert 2.1");
    if ((long)dtinsert(dt, 3L) != 3) terror("Dtstack insert 3.2");
    if ((long)dtinsert(dt, 2L) != 2) terror("Dtstack insert 2.2");
    if ((long)dtinsert(dt, 3L) != 3) terror("Dtstack insert 3.3");

    if ((long)dtlast(dt) != 1) terror("Dtstack dtlast");
    if ((long)dtprev(dt, 1L) != 3) terror("Dtstack dtprev 1");
    if ((long)dtprev(dt, 3L) != 2) terror("Dtstack dtprev 3.1");
    if ((long)dtprev(dt, 2L) != 3) terror("Dtstack dtprev 2.1");
    if ((long)dtprev(dt, 3L) != 2) terror("Dtstack dtprev 3.2");
    if ((long)dtprev(dt, 2L) != 3) terror("Dtstack dtprev 2.2");
    if ((long)dtprev(dt, 3L) != 0) terror("Dtstack dtprev 3.2");

    if ((long)dtdelete(dt, NULL) != 3) terror("Dtstack pop 3.3");

    /* search to one of the 3 */
    if ((long)dtsearch(dt, 3L) != 3) terror("Dtstack search 3.2");
    if ((long)dtdelete(dt, 3L) != 3) terror("Dtstack delete 3.2");

    if ((long)dtdelete(dt, NULL) != 2) terror("Dtstack pop 2.2");
    if ((long)dtdelete(dt, NULL) != 2) terror("Dtstack pop 2.1");
    if ((long)dtdelete(dt, NULL) != 3) terror("Dtstack pop 3.1");
    if ((long)dtdelete(dt, NULL) != 1) terror("Dtstack pop 1");

    if (dtsize(dt) != 0) terror("Dtstack size");

    texit(0);
}
