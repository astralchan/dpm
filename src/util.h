/*
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * General utilities for dpm - header.
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

#ifndef UTIL_H
#define UTIL_H

#include "posix-config.h"

#include <stdarg.h>
#include <stdio.h>

enum asciiColor {
	BLACK   = 30,
	RED     = 31,
	GREEN   = 32,
	YELLOW  = 33,
	BLUE    = 34,
	MAGENTA = 35,
	CYAN    = 36,
	WHITE   = 37
};

void vfmsgf(FILE *restrict stream, enum asciiColor color,
    const char *restrict fmt, va_list ap);
void fmsgf(FILE *restrict stream, enum asciiColor color,
    const char *restrict fmt, ...);
void msgf(enum asciiColor color, const char *restrict fmt, ...);

#endif /* !UTIL_H */
