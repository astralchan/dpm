/*
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * General utilities for dpm.
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

#include "util.h"

#include <stdarg.h>
#include <stdio.h>

void
vfmsgf(FILE *restrict stream, enum asciiColor color, const char *restrict fmt,
    va_list ap)
{
	(void)fprintf(stream, "\033[1m=>\033[%dmdpm\033[0;1m:\033[0m ", color);
	(void)vfprintf(stream, fmt, ap);
}

void
fmsgf(FILE *restrict stream, enum asciiColor color, const char *restrict fmt,
    ...)
{
	va_list args;

	va_start(args, fmt);
	vfmsgf(stream, color, fmt, args);
	va_end(args);
}

void
msgf(enum asciiColor color, const char *restrict fmt, ...)
{
	va_list args;

	va_start(args, fmt);
	vfmsgf(stdout, color, fmt, args);
	va_end(args);
}
