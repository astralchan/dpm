/*
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright (C) 2024-2024 astral
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

#include <stdlib.h>
#include <string.h>

#include "dpm-emerge.h"
#include "dpm-remove.h"
#include "dpm-update.h"
#include "io-utils.h"

int
main(int argc, char *argv[])
{
	int ret = EXIT_SUCCESS;

	if (argc < 2) {
		fmsgf(RED, stderr, "Usage: %s <command> [option]... "
		  "[package]...\n", argv[0]);
		return EXIT_FAILURE;
	}

	++argv, --argc;

	if (!strcmp(argv[0], "emerge") || !strcmp(argv[0], "em")) {
		ret = dpm_emerge(argc, argv);
	} else if (!strcmp(argv[0], "remove") || !strcmp(argv[0], "rm")) {
		ret = dpm_remove(argc, argv);
	} else if (!strcmp(argv[0], "update") || !strcmp(argv[0], "up")) {
		ret = dpm_update(argc, argv);
	} else {
		fmsgf(RED, stderr, "Unknown command: %s\n", argv[0]);
		return EXIT_FAILURE;
	}

	return ret;
}