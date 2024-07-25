# SPDX-License-Identifier: GPL-3.0-or-later
# Copyright (C) 2024-2024 astral
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

.POSIX:

include config.mk

.SUFFIXES:
.SUFFIXES: .c .o .sh

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<

.sh:
	cp $< $@
	chmod a+x $@

all: src/dpm src/dpm-pkg

src/dpm: \
	  src/dpm.o \
	  src/dpm-emerge.o \
	  src/dpm-remove.o \
	  src/dpm-update.o \
	  src/io-utils.o
	$(CC) $(CFLAGS) -o $@ \
	  src/dpm.o \
	  src/dpm-emerge.o \
	  src/dpm-remove.o \
	  src/dpm-update.o \
	  src/io-utils.o \
	  $(LDFLAGS)
src/dpm.o: src/dpm.c
src/dpm-emerge.o: src/dpm-emerge.c
src/dpm-remove.o: src/dpm-remove.c
src/dpm-update.o: src/dpm-update.c
src/io-utils.o: src/io-utils.c

src/dpm-pkg: src/dpm-pkg.sh

clean:
	@rm -f src/dpm
	@rm -f src/dpm.o
	@rm -f src/dpm-emerge.o
	@rm -f src/dpm-remove.o
	@rm -f src/dpm-update.o
	@rm -f src/io-utils.o
	@rm -f src/dpm-pkg

	@rm -f dpm-*.tar*

install:
	@mkdir -p $(BINDIR)

	@cp src/dpm $(BINDIR)
	@chmod 755 $(BINDIR)/dpm

	@cp src/dpm-pkg $(BINDIR)
	@chmod 755 $(BINDIR)/dpm-pkg

	@mkdir -p $(MANDIR)/man1

	@cp doc/dpm.1 $(MANDIR)/man1
	@chmod 644 $(MANDIR)/man1/dpm.1

	@cp doc/dpm-pkg.1 $(MANDIR)/man1
	@chmod 644 $(MANDIR)/man1/dpm-pkg.1

	@cp doc/dpm-emerge.1 $(MANDIR)/man1
	@chmod 644 $(MANDIR)/man1/dpm-emerge.1

	@cp doc/dpm-remove.1 $(MANDIR)/man1
	@chmod 644 $(MANDIR)/man1/dpm-remove.1

	@cp doc/dpm-update.1 $(MANDIR)/man1
	@chmod 644 $(MANDIR)/man1/dpm-update.1

uninstall:
	@rm -f $(BINDIR)/dpm
	@rm -f $(BINDIR)/dpm-pkg
	@rm -f $(MANDIR)/man1/dpm.1
	@rm -f $(MANDIR)/man1/dpm-pkg.1
	@rm -f $(MANDIR)/man1/dpm-emerge.1
	@rm -f $(MANDIR)/man1/dpm-remove.1
	@rm -f $(MANDIR)/man1/dpm-update.1

dist:
	git archive -o dpm-$(VERSION).tar HEAD
	gzip -k dpm-$(VERSION).tar
	xz dpm-$(VERSION).tar