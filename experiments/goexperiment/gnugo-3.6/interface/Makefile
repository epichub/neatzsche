# Makefile.in generated automatically by automake 1.5 from Makefile.am.

# Copyright 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2001
# Free Software Foundation, Inc.
# This Makefile.in is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY, to the extent permitted by law; without
# even the implied warranty of MERCHANTABILITY or FITNESS FOR A
# PARTICULAR PURPOSE.



SHELL = /bin/sh

srcdir = .
top_srcdir = ..

prefix = /usr/local
exec_prefix = ${prefix}

bindir = ${exec_prefix}/bin
sbindir = ${exec_prefix}/sbin
libexecdir = ${exec_prefix}/libexec
datadir = ${prefix}/share
sysconfdir = ${prefix}/etc
sharedstatedir = ${prefix}/com
localstatedir = ${prefix}/var
libdir = ${exec_prefix}/lib
infodir = ${prefix}/info
mandir = ${prefix}/man
includedir = ${prefix}/include
oldincludedir = /usr/include
pkgdatadir = $(datadir)/gnugo
pkglibdir = $(libdir)/gnugo
pkgincludedir = $(includedir)/gnugo
top_builddir = ..

ACLOCAL = ${SHELL} /Users/epic/Documents/svn/neatzsche/3rdparty/gnugo-3.6/missing --run aclocal
AUTOCONF = ${SHELL} /Users/epic/Documents/svn/neatzsche/3rdparty/gnugo-3.6/missing --run autoconf
AUTOMAKE = ${SHELL} /Users/epic/Documents/svn/neatzsche/3rdparty/gnugo-3.6/missing --run automake
AUTOHEADER = ${SHELL} /Users/epic/Documents/svn/neatzsche/3rdparty/gnugo-3.6/missing --run autoheader

INSTALL = /usr/bin/install -c
INSTALL_PROGRAM = ${INSTALL}
INSTALL_DATA = ${INSTALL} -m 644
INSTALL_SCRIPT = ${INSTALL}
INSTALL_HEADER = $(INSTALL_DATA)
transform = s,x,x,
NORMAL_INSTALL = :
PRE_INSTALL = :
POST_INSTALL = :
NORMAL_UNINSTALL = :
PRE_UNINSTALL = :
POST_UNINSTALL = :
AMTAR = ${SHELL} /Users/epic/Documents/svn/neatzsche/3rdparty/gnugo-3.6/missing --run tar
AWK = awk
CC = gcc
CPP = gcc -E
DEPDIR = .deps
EXEEXT = 
GCC_ONLY = 
GNUGO_ALL_WARNINGS = 
GNUGO_SOME_WARNINGS = CFLAGS=-g -O2 -Wall -W -Wpointer-arith -Wbad-function-cast -Wcast-qual -Wcast-align -Wwrite-strings -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wundef
INSTALL_STRIP_PROGRAM = ${SHELL} $(install_sh) -c -s
MAINT = #
NO_WARNINGS = CFLAGS=-g -O2
OBJEXT = o
PACKAGE = gnugo
RANLIB = ranlib
VERSION = 3.6
am__include = include
am__quote = 
glibconfig = 
install_sh = /Users/epic/Documents/svn/neatzsche/3rdparty/gnugo-3.6/install-sh

bin_PROGRAMS = gnugo

SUBDIRS = debugboard

EXTRA_DIST = gtp_examples gnugo.dsp gnugo.el make-xpms-file.el GoImage xpms

GGBUILTSOURCES = gnugo-xpms.el

noinst_HEADERS = interface.h gmp.h gtp.h

# Remove these files here... they are created locally
DISTCLEANFILES = *~

INCLUDES = \
	-I$(top_srcdir)/sgf \
	-I$(top_srcdir)/engine \
	-I$(top_srcdir)/utils


LDADD = \
	../engine/libengine.a \
	../patterns/libpatterns.a \
	../sgf/libsgf.a \
	../utils/libutils.a


gnugo_SOURCES = \
	main.c \
	play_ascii.c \
	play_gmp.c \
	play_gtp.c \
	play_solo.c \
	play_test.c \
	gmp.c \
	gtp.c


AIXOPTS = -O -qmaxmem=16384 -qro -qroconst -qinfo
subdir = interface
mkinstalldirs = $(SHELL) $(top_srcdir)/mkinstalldirs
CONFIG_HEADER = $(top_builddir)/config.h
CONFIG_CLEAN_FILES =
bin_PROGRAMS = gnugo$(EXEEXT)
PROGRAMS = $(bin_PROGRAMS)

am_gnugo_OBJECTS = main.$(OBJEXT) play_ascii.$(OBJEXT) \
	play_gmp.$(OBJEXT) play_gtp.$(OBJEXT) play_solo.$(OBJEXT) \
	play_test.$(OBJEXT) gmp.$(OBJEXT) gtp.$(OBJEXT)
gnugo_OBJECTS = $(am_gnugo_OBJECTS)
gnugo_LDADD = $(LDADD)
gnugo_DEPENDENCIES = ../engine/libengine.a ../patterns/libpatterns.a \
	../sgf/libsgf.a ../utils/libutils.a
gnugo_LDFLAGS =

DEFS = -DHAVE_CONFIG_H
DEFAULT_INCLUDES =  -I. -I$(srcdir) -I$(top_builddir)
CPPFLAGS = 
LDFLAGS = 
LIBS = -lncurses 
depcomp = $(SHELL) $(top_srcdir)/depcomp
DEP_FILES = $(DEPDIR)/gmp.Po $(DEPDIR)/gtp.Po \
	$(DEPDIR)/main.Po $(DEPDIR)/play_ascii.Po \
	$(DEPDIR)/play_gmp.Po $(DEPDIR)/play_gtp.Po \
	$(DEPDIR)/play_solo.Po $(DEPDIR)/play_test.Po
COMPILE = $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) \
	$(CPPFLAGS) $(AM_CFLAGS) $(CFLAGS)
CCLD = $(CC)
LINK = $(CCLD) $(AM_CFLAGS) $(CFLAGS) $(AM_LDFLAGS) $(LDFLAGS) -o $@
CFLAGS = -g -O2 -Wall -W -Wpointer-arith -Wbad-function-cast -Wcast-qual -Wcast-align -Wwrite-strings -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wundef
DIST_SOURCES = $(gnugo_SOURCES)
HEADERS = $(noinst_HEADERS)


RECURSIVE_TARGETS = info-recursive dvi-recursive install-info-recursive \
	uninstall-info-recursive all-recursive install-data-recursive \
	install-exec-recursive installdirs-recursive install-recursive \
	uninstall-recursive check-recursive installcheck-recursive
DIST_COMMON = $(noinst_HEADERS) Makefile.am Makefile.in
DIST_SUBDIRS = $(SUBDIRS)
SOURCES = $(gnugo_SOURCES)

all: all-recursive

.SUFFIXES:
.SUFFIXES: .c .o .obj
$(srcdir)/Makefile.in: # Makefile.am  $(top_srcdir)/configure.in $(ACLOCAL_M4)
	cd $(top_srcdir) && \
	  $(AUTOMAKE) --gnu  interface/Makefile
Makefile: # $(srcdir)/Makefile.in  $(top_builddir)/config.status
	cd $(top_builddir) && \
	  CONFIG_HEADERS= CONFIG_LINKS= \
	  CONFIG_FILES=$(subdir)/$@ $(SHELL) ./config.status
install-binPROGRAMS: $(bin_PROGRAMS)
	@$(NORMAL_INSTALL)
	$(mkinstalldirs) $(DESTDIR)$(bindir)
	@list='$(bin_PROGRAMS)'; for p in $$list; do \
	  p1=`echo $$p|sed 's/$(EXEEXT)$$//'`; \
	  if test -f $$p \
	  ; then \
	    f=`echo $$p1|sed '$(transform);s/$$/$(EXEEXT)/'`; \
	   echo " $(INSTALL_PROGRAM_ENV) $(INSTALL_PROGRAM) $$p $(DESTDIR)$(bindir)/$$f"; \
	   $(INSTALL_PROGRAM_ENV) $(INSTALL_PROGRAM) $$p $(DESTDIR)$(bindir)/$$f; \
	  else :; fi; \
	done

uninstall-binPROGRAMS:
	@$(NORMAL_UNINSTALL)
	@list='$(bin_PROGRAMS)'; for p in $$list; do \
	  f=`echo $$p|sed 's/$(EXEEXT)$$//;$(transform);s/$$/$(EXEEXT)/'`; \
	  echo " rm -f $(DESTDIR)$(bindir)/$$f"; \
	  rm -f $(DESTDIR)$(bindir)/$$f; \
	done

clean-binPROGRAMS:
	-test -z "$(bin_PROGRAMS)" || rm -f $(bin_PROGRAMS)
gnugo$(EXEEXT): $(gnugo_OBJECTS) $(gnugo_DEPENDENCIES) 
	@rm -f gnugo$(EXEEXT)
	$(LINK) $(gnugo_LDFLAGS) $(gnugo_OBJECTS) $(gnugo_LDADD) $(LIBS)

mostlyclean-compile:
	-rm -f *.$(OBJEXT) core *.core

distclean-compile:
	-rm -f *.tab.c

include $(DEPDIR)/gmp.Po
include $(DEPDIR)/gtp.Po
include $(DEPDIR)/main.Po
include $(DEPDIR)/play_ascii.Po
include $(DEPDIR)/play_gmp.Po
include $(DEPDIR)/play_gtp.Po
include $(DEPDIR)/play_solo.Po
include $(DEPDIR)/play_test.Po

distclean-depend:
	-rm -rf $(DEPDIR)

.c.o:
	source='$<' object='$@' libtool=no \
	depfile='$(DEPDIR)/$*.Po' tmpdepfile='$(DEPDIR)/$*.TPo' \
	$(CCDEPMODE) $(depcomp) \
	$(COMPILE) -c `test -f $< || echo '$(srcdir)/'`$<

.c.obj:
	source='$<' object='$@' libtool=no \
	depfile='$(DEPDIR)/$*.Po' tmpdepfile='$(DEPDIR)/$*.TPo' \
	$(CCDEPMODE) $(depcomp) \
	$(COMPILE) -c `cygpath -w $<`
CCDEPMODE = depmode=gcc3
uninstall-info-am:

# This directory's subdirectories are mostly independent; you can cd
# into them and run `make' without going through this Makefile.
# To change the values of `make' variables: instead of editing Makefiles,
# (1) if the variable is set in `config.status', edit `config.status'
#     (which will cause the Makefiles to be regenerated when you run `make');
# (2) otherwise, pass the desired values on the `make' command line.
$(RECURSIVE_TARGETS):
	@set fnord $(MAKEFLAGS); amf=$$2; \
	dot_seen=no; \
	target=`echo $@ | sed s/-recursive//`; \
	list='$(SUBDIRS)'; for subdir in $$list; do \
	  echo "Making $$target in $$subdir"; \
	  if test "$$subdir" = "."; then \
	    dot_seen=yes; \
	    local_target="$$target-am"; \
	  else \
	    local_target="$$target"; \
	  fi; \
	  (cd $$subdir && $(MAKE) $(AM_MAKEFLAGS) $$local_target) \
	   || case "$$amf" in *=*) exit 1;; *k*) fail=yes;; *) exit 1;; esac; \
	done; \
	if test "$$dot_seen" = "no"; then \
	  $(MAKE) $(AM_MAKEFLAGS) "$$target-am" || exit 1; \
	fi; test -z "$$fail"

mostlyclean-recursive clean-recursive distclean-recursive \
maintainer-clean-recursive:
	@set fnord $(MAKEFLAGS); amf=$$2; \
	dot_seen=no; \
	case "$@" in \
	  distclean-* | maintainer-clean-*) list='$(DIST_SUBDIRS)' ;; \
	  *) list='$(SUBDIRS)' ;; \
	esac; \
	rev=''; for subdir in $$list; do \
	  if test "$$subdir" = "."; then :; else \
	    rev="$$subdir $$rev"; \
	  fi; \
	done; \
	rev="$$rev ."; \
	target=`echo $@ | sed s/-recursive//`; \
	for subdir in $$rev; do \
	  echo "Making $$target in $$subdir"; \
	  if test "$$subdir" = "."; then \
	    local_target="$$target-am"; \
	  else \
	    local_target="$$target"; \
	  fi; \
	  (cd $$subdir && $(MAKE) $(AM_MAKEFLAGS) $$local_target) \
	   || case "$$amf" in *=*) exit 1;; *k*) fail=yes;; *) exit 1;; esac; \
	done && test -z "$$fail"
tags-recursive:
	list='$(SUBDIRS)'; for subdir in $$list; do \
	  test "$$subdir" = . || (cd $$subdir && $(MAKE) $(AM_MAKEFLAGS) tags); \
	done

tags: TAGS

ID: $(HEADERS) $(SOURCES) $(LISP) $(TAGS_FILES)
	list='$(SOURCES) $(HEADERS) $(TAGS_FILES)'; \
	unique=`for i in $$list; do \
	    if test -f "$$i"; then echo $$i; else echo $(srcdir)/$$i; fi; \
	  done | \
	  $(AWK) '    { files[$$0] = 1; } \
	       END { for (i in files) print i; }'`; \
	mkid -fID $$unique $(LISP)

TAGS: tags-recursive $(HEADERS) $(SOURCES)  $(TAGS_DEPENDENCIES) \
		$(TAGS_FILES) $(LISP)
	tags=; \
	here=`pwd`; \
	list='$(SUBDIRS)'; for subdir in $$list; do \
	  if test "$$subdir" = .; then :; else \
	    test -f $$subdir/TAGS && tags="$$tags -i $$here/$$subdir/TAGS"; \
	  fi; \
	done; \
	list='$(SOURCES) $(HEADERS) $(TAGS_FILES)'; \
	unique=`for i in $$list; do \
	    if test -f "$$i"; then echo $$i; else echo $(srcdir)/$$i; fi; \
	  done | \
	  $(AWK) '    { files[$$0] = 1; } \
	       END { for (i in files) print i; }'`; \
	test -z "$(ETAGS_ARGS)$$unique$(LISP)$$tags" \
	  || etags $(ETAGS_ARGS) $$tags  $$unique $(LISP)

GTAGS:
	here=`CDPATH=: && cd $(top_builddir) && pwd` \
	  && cd $(top_srcdir) \
	  && gtags -i $(GTAGS_ARGS) $$here

distclean-tags:
	-rm -f TAGS ID GTAGS GRTAGS GSYMS GPATH

DISTFILES = $(DIST_COMMON) $(DIST_SOURCES) $(TEXINFOS) $(EXTRA_DIST)

top_distdir = ..
distdir = $(top_distdir)/$(PACKAGE)-$(VERSION)

distdir: $(DISTFILES)
	@for file in $(DISTFILES); do \
	  if test -f $$file; then d=.; else d=$(srcdir); fi; \
	  dir=`echo "$$file" | sed -e 's,/[^/]*$$,,'`; \
	  if test "$$dir" != "$$file" && test "$$dir" != "."; then \
	    $(mkinstalldirs) "$(distdir)/$$dir"; \
	  fi; \
	  if test -d $$d/$$file; then \
	    cp -pR $$d/$$file $(distdir) \
	    || exit 1; \
	  else \
	    test -f $(distdir)/$$file \
	    || cp -p $$d/$$file $(distdir)/$$file \
	    || exit 1; \
	  fi; \
	done
	for subdir in $(SUBDIRS); do \
	  if test "$$subdir" = .; then :; else \
	    test -d $(distdir)/$$subdir \
	    || mkdir $(distdir)/$$subdir \
	    || exit 1; \
	    (cd $$subdir && \
	      $(MAKE) $(AM_MAKEFLAGS) \
	        top_distdir="$(top_distdir)" \
	        distdir=../$(distdir)/$$subdir \
	        distdir) \
	      || exit 1; \
	  fi; \
	done
check-am: all-am
check: check-recursive
all-am: Makefile $(PROGRAMS) $(HEADERS)
installdirs: installdirs-recursive
installdirs-am:
	$(mkinstalldirs) $(DESTDIR)$(bindir)

install: install-recursive
install-exec: install-exec-recursive
install-data: install-data-recursive
uninstall: uninstall-recursive

install-am: all-am
	@$(MAKE) $(AM_MAKEFLAGS) install-exec-am install-data-am

installcheck: installcheck-recursive
install-strip:
	$(MAKE) $(AM_MAKEFLAGS) INSTALL_PROGRAM="$(INSTALL_STRIP_PROGRAM)" \
	  `test -z '$(STRIP)' || \
	    echo "INSTALL_PROGRAM_ENV=STRIPPROG='$(STRIP)'"` install
mostlyclean-generic:

clean-generic:

distclean-generic:
	-rm -f Makefile $(CONFIG_CLEAN_FILES) stamp-h stamp-h[0-9]*
	-test -z "$(DISTCLEANFILES)" || rm -f $(DISTCLEANFILES)

maintainer-clean-generic:
	@echo "This command is intended for maintainers to use"
	@echo "it deletes files that may require special tools to rebuild."
clean: clean-recursive

clean-am: clean-binPROGRAMS clean-generic mostlyclean-am

distclean: distclean-recursive

distclean-am: clean-am distclean-compile distclean-depend \
	distclean-generic distclean-tags

dvi: dvi-recursive

dvi-am:

info: info-recursive

info-am:

install-data-am:

install-exec-am: install-binPROGRAMS

install-info: install-info-recursive

install-man:

installcheck-am:

maintainer-clean: maintainer-clean-recursive

maintainer-clean-am: distclean-am maintainer-clean-generic

mostlyclean: mostlyclean-recursive

mostlyclean-am: mostlyclean-compile mostlyclean-generic

uninstall-am: uninstall-binPROGRAMS uninstall-info-am

uninstall-info: uninstall-info-recursive

.PHONY: $(RECURSIVE_TARGETS) GTAGS all all-am check check-am clean \
	clean-binPROGRAMS clean-generic clean-recursive distclean \
	distclean-compile distclean-depend distclean-generic \
	distclean-recursive distclean-tags distdir dvi dvi-am \
	dvi-recursive info info-am info-recursive install install-am \
	install-binPROGRAMS install-data install-data-am \
	install-data-recursive install-exec install-exec-am \
	install-exec-recursive install-info install-info-am \
	install-info-recursive install-man install-recursive \
	install-strip installcheck installcheck-am installdirs \
	installdirs-am installdirs-recursive maintainer-clean \
	maintainer-clean-generic maintainer-clean-recursive mostlyclean \
	mostlyclean-compile mostlyclean-generic mostlyclean-recursive \
	tags tags-recursive uninstall uninstall-am \
	uninstall-binPROGRAMS uninstall-info-am \
	uninstall-info-recursive uninstall-recursive


gnugo-xpms.el : $(shell ls xpms/*.xpm)
	emacs -batch --no-site-file -l make-xpms-file.el -f make-xpms-file $@ $(shell ls xpms/*.xpm)

# OPTIONS=$(AIXOPTS)
# Tell versions [3.59,3.63) of GNU make to not export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
