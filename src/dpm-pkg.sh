#!/bin/sh

# SPDX-License-Identifier: GPL-3.0-or-later
#
# Package builder for dpm.
# Copyright (C) 2024 astral
#
# This file is a part of dpm.
#
# dpm is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# dpm is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with dpm. If not, see <https://www.gnu.org/licenses/>.

# Unused colors are okay
# shellcheck disable=SC2034
{
	BLACK=30
	RED=31
	GREEN=32
	YELLOW=33
	BLUE=34
	MAGENTA=35
	CYAN=36
	WHITE=37
}

# printf expansion is desired here
# shellcheck disable=SC2059
msgf() {
	printf "\033[1m=>\033[%dmdpm\033[0;1m:\033[0m " "$1"
	shift
	printf "$@"
}

errflg=
hflg=
rflg=
vflg=

repo=

while getopts ":hr:v" c
do
	case $c in
	h)
		hflg=1
		;;
	r)
		rflg=1
		repo=$OPTARG
		;;
	v)
		vflg=1
		;;
	:)
		errflg=1
		msgf >&2 $RED "Option -%c requires an operand\n" "$OPTARG"
		;;
	?)
		errflg=1
		msgf >&2 $RED "Unrecognized option: -%c\n" "$OPTARG"
		;;
	esac
done
shift $((OPTIND - 1))

if [ "$errflg" ]
then
	msgf >&2 $YELLOW "Usage: dpm pkg [-hv -r <repo>] ...\n"
	exit 1
fi

if [ "$hflg" ]
then
	msgf $GREEN "h flag set\n"
fi

if [ "$rflg" ]
then
	msgf $GREEN "repo: %s\n" "$repo"
fi

if [ "$vflg" ]
then
	msgf $GREEN "v flag set\n"
fi

msgf $BLUE "Packages: "
for arg
do
	printf "%s " "$arg"
done
printf "\b\n"

exit 0
