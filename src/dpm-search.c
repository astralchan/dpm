/*
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Main entry point for dpm-search.
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

#include "dpm-search.h"

#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

#include "util.h"

int
dpm_search(int argc, char *argv[])
{
	int errflg, hflg, rflg;
	errflg = hflg = rflg = 0;

	char *repo;

	for (int c; (c = getopt(argc, argv, ":hr:")) != -1;) {
		switch (c) {
		case 'h':
			++hflg;
			break;
		case 'r':
			++rflg;
			repo = optarg;
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
		    "Usage: dpm search [-h -r <repo>] ...\n");
		return EXIT_FAILURE;
	}

	if (hflg)
		msgf(GREEN, "h flag set\n");

	if (rflg)
		msgf(GREEN, "repo: %s\n", repo);

	msgf(BLUE, "Packages: ");
	for (int i = optind; i < argc; ++i)
		(void)printf("%s ", argv[i]);
	(void)printf("\b\n");

	return EXIT_SUCCESS;
}
