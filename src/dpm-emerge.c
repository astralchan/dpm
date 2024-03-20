/*
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Entry point for dpm-emerge.
 * Copyright (C) 2024 astral
 *
 * This file is a part of dpm.
 *
 * dpm is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * dpm is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with dpm. If not, see <https://www.gnu.org/licenses/>.
 */

#include "posix-config.h"

#include "dpm-emerge.h"

#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

#include "util.h"

int
dpm_emerge(int argc, char *argv[])
{
	int errflg, hflg, rflg, vflg;
	errflg = hflg = rflg = vflg = 0;

	char *repo;

	for (int c; (c = getopt(argc, argv, ":hr:v")) != -1;) {
		switch (c) {
		case 'h':
			++hflg;
			break;
		case 'r':
			++rflg;
			repo = optarg;
			break;
		case 'v':
			++vflg;
			break;
		case ':':
			++errflg;
			fmsgf(stderr, RED, "Option -%c requires an operand\n",
			    optopt);
			break;
		case '?':
			++errflg;
			fmsgf(stderr, RED, "Unrecognized option: -%c\n",
			    optopt);
		}
	}

	if (errflg) {
		fmsgf(stderr, YELLOW,
		    "Usage: dpm emerge [-hv -r <repo>] ...\n");
		return EXIT_FAILURE;
	}

	if (hflg)
		msgf(GREEN, "h flag set\n");
	
	if (rflg)
		msgf(GREEN, "repo: %s\n", repo);

	if (vflg)
		msgf(GREEN, "v flag set\n");

	msgf(BLUE, "Packages: ");
	for (int i = optind; i < argc; ++i)
		(void)printf("%s ", argv[i]);
	(void)printf("\b\n");

	return EXIT_SUCCESS;
}
