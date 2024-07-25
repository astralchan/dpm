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

#ifndef _IO_UTILS_H
#define _IO_UTILS_H

#include <stdarg.h>
#include <stdio.h>

enum color {
	BLACK  = 30,
	RED    = 31,
	GREEN  = 32,
	YELLOW = 33,
	BLUE   = 34,
	PURPLE = 35,
	CYAN   = 36,
	WHITE  = 37,
};

void vfmsgf(enum color col, FILE *stream, const char *fmt, va_list ap);
void fmsgf(enum color col, FILE *stream, const char *fmt, ...);
void msgf(enum color col, const char *fmt, ...);

#endif /* !_IO_UTILS_H */