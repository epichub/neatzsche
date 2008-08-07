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

EXTRA_DIST = engine.dsp board.dsp

# Remove these files here... they are created locally
DISTCLEANFILES = *~

INCLUDES = \
	-I../patterns \
	-I$(top_srcdir)/patterns \
	-I$(top_srcdir)/sgf \
	-I$(top_srcdir)/utils


noinst_HEADERS = cache.h gnugo.h hash.h clock.h readconnect.h \
                 influence.h liberty.h move_reasons.h board.h


# preconfigured settings for various configurations
noinst_LIBRARIES = libengine.a libboard.a

libengine_a_SOURCES = \
      aftermath.c \
      board.c \
      boardlib.c \
      breakin.c \
      cache.c \
      clock.c \
      combination.c \
      dragon.c \
      endgame.c \
      filllib.c \
      fuseki.c \
      genmove.c \
      globals.c \
      handicap.c \
      hash.c \
      influence.c \
      interface.c \
      matchpat.c \
      move_reasons.c \
      movelist.c \
      optics.c \
      oracle.c \
      owl.c \
      persistent.c \
      printutils.c \
      readconnect.c \
      reading.c \
      score.c \
      semeai.c \
      sgfdecide.c \
      sgffile.c \
      shapes.c \
      showbord.c \
      surround.c \
      unconditional.c \
      utils.c \
      value_moves.c \
      worm.c


libboard_a_SOURCES = \
      board.c \
      boardlib.c \
      hash.c \
      printutils.c

subdir = engine
mkinstalldirs = $(SHELL) $(top_srcdir)/mkinstalldirs
CONFIG_HEADER = $(top_builddir)/config.h
CONFIG_CLEAN_FILES =
LIBRARIES = $(noinst_LIBRARIES)

libboard_a_AR = $(AR) cru
libboard_a_LIBADD =
am_libboard_a_OBJECTS = board.$(OBJEXT) boardlib.$(OBJEXT) \
	hash.$(OBJEXT) printutils.$(OBJEXT)
libboard_a_OBJECTS = $(am_libboard_a_OBJECTS)
libengine_a_AR = $(AR) cru
libengine_a_LIBADD =
am_libengine_a_OBJECTS = aftermath.$(OBJEXT) board.$(OBJEXT) \
	boardlib.$(OBJEXT) breakin.$(OBJEXT) cache.$(OBJEXT) \
	clock.$(OBJEXT) combination.$(OBJEXT) dragon.$(OBJEXT) \
	endgame.$(OBJEXT) filllib.$(OBJEXT) fuseki.$(OBJEXT) \
	genmove.$(OBJEXT) globals.$(OBJEXT) handicap.$(OBJEXT) \
	hash.$(OBJEXT) influence.$(OBJEXT) interface.$(OBJEXT) \
	matchpat.$(OBJEXT) move_reasons.$(OBJEXT) movelist.$(OBJEXT) \
	optics.$(OBJEXT) oracle.$(OBJEXT) owl.$(OBJEXT) \
	persistent.$(OBJEXT) printutils.$(OBJEXT) readconnect.$(OBJEXT) \
	reading.$(OBJEXT) score.$(OBJEXT) semeai.$(OBJEXT) \
	sgfdecide.$(OBJEXT) sgffile.$(OBJEXT) shapes.$(OBJEXT) \
	showbord.$(OBJEXT) surround.$(OBJEXT) unconditional.$(OBJEXT) \
	utils.$(OBJEXT) value_moves.$(OBJEXT) worm.$(OBJEXT)
libengine_a_OBJECTS = $(am_libengine_a_OBJECTS)

DEFS = -DHAVE_CONFIG_H
DEFAULT_INCLUDES =  -I. -I$(srcdir) -I$(top_builddir)
CPPFLAGS = 
LDFLAGS = 
LIBS = -lncurses 
depcomp = $(SHELL) $(top_srcdir)/depcomp
DEP_FILES = $(DEPDIR)/aftermath.Po $(DEPDIR)/board.Po \
	$(DEPDIR)/boardlib.Po $(DEPDIR)/breakin.Po \
	$(DEPDIR)/cache.Po $(DEPDIR)/clock.Po \
	$(DEPDIR)/combination.Po $(DEPDIR)/dragon.Po \
	$(DEPDIR)/endgame.Po $(DEPDIR)/filllib.Po \
	$(DEPDIR)/fuseki.Po $(DEPDIR)/genmove.Po \
	$(DEPDIR)/globals.Po $(DEPDIR)/handicap.Po \
	$(DEPDIR)/hash.Po $(DEPDIR)/influence.Po \
	$(DEPDIR)/interface.Po $(DEPDIR)/matchpat.Po \
	$(DEPDIR)/move_reasons.Po $(DEPDIR)/movelist.Po \
	$(DEPDIR)/optics.Po $(DEPDIR)/oracle.Po \
	$(DEPDIR)/owl.Po $(DEPDIR)/persistent.Po \
	$(DEPDIR)/printutils.Po $(DEPDIR)/readconnect.Po \
	$(DEPDIR)/reading.Po $(DEPDIR)/score.Po \
	$(DEPDIR)/semeai.Po $(DEPDIR)/sgfdecide.Po \
	$(DEPDIR)/sgffile.Po $(DEPDIR)/shapes.Po \
	$(DEPDIR)/showbord.Po $(DEPDIR)/surround.Po \
	$(DEPDIR)/unconditional.Po $(DEPDIR)/utils.Po \
	$(DEPDIR)/value_moves.Po $(DEPDIR)/worm.Po
COMPILE = $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) \
	$(CPPFLAGS) $(AM_CFLAGS) $(CFLAGS)
CCLD = $(CC)
LINK = $(CCLD) $(AM_CFLAGS) $(CFLAGS) $(AM_LDFLAGS) $(LDFLAGS) -o $@
CFLAGS = -g -O2 -Wall -W -Wpointer-arith -Wbad-function-cast -Wcast-qual -Wcast-align -Wwrite-strings -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wundef
DIST_SOURCES = $(libboard_a_SOURCES) $(libengine_a_SOURCES)
HEADERS = $(noinst_HEADERS)

DIST_COMMON = $(noinst_HEADERS) Makefile.am Makefile.in
SOURCES = $(libboard_a_SOURCES) $(libengine_a_SOURCES)

all: all-am

.SUFFIXES:
.SUFFIXES: .c .o .obj
$(srcdir)/Makefile.in: # Makefile.am  $(top_srcdir)/configure.in $(ACLOCAL_M4)
	cd $(top_srcdir) && \
	  $(AUTOMAKE) --gnu  engine/Makefile
Makefile: # $(srcdir)/Makefile.in  $(top_builddir)/config.status
	cd $(top_builddir) && \
	  CONFIG_HEADERS= CONFIG_LINKS= \
	  CONFIG_FILES=$(subdir)/$@ $(SHELL) ./config.status

AR = ar

clean-noinstLIBRARIES:
	-test -z "$(noinst_LIBRARIES)" || rm -f $(noinst_LIBRARIES)
libboard.a: $(libboard_a_OBJECTS) $(libboard_a_DEPENDENCIES) 
	-rm -f libboard.a
	$(libboard_a_AR) libboard.a $(libboard_a_OBJECTS) $(libboard_a_LIBADD)
	$(RANLIB) libboard.a
libengine.a: $(libengine_a_OBJECTS) $(libengine_a_DEPENDENCIES) 
	-rm -f libengine.a
	$(libengine_a_AR) libengine.a $(libengine_a_OBJECTS) $(libengine_a_LIBADD)
	$(RANLIB) libengine.a

mostlyclean-compile:
	-rm -f *.$(OBJEXT) core *.core

distclean-compile:
	-rm -f *.tab.c

include $(DEPDIR)/aftermath.Po
include $(DEPDIR)/board.Po
include $(DEPDIR)/boardlib.Po
include $(DEPDIR)/breakin.Po
include $(DEPDIR)/cache.Po
include $(DEPDIR)/clock.Po
include $(DEPDIR)/combination.Po
include $(DEPDIR)/dragon.Po
include $(DEPDIR)/endgame.Po
include $(DEPDIR)/filllib.Po
include $(DEPDIR)/fuseki.Po
include $(DEPDIR)/genmove.Po
include $(DEPDIR)/globals.Po
include $(DEPDIR)/handicap.Po
include $(DEPDIR)/hash.Po
include $(DEPDIR)/influence.Po
include $(DEPDIR)/interface.Po
include $(DEPDIR)/matchpat.Po
include $(DEPDIR)/move_reasons.Po
include $(DEPDIR)/movelist.Po
include $(DEPDIR)/optics.Po
include $(DEPDIR)/oracle.Po
include $(DEPDIR)/owl.Po
include $(DEPDIR)/persistent.Po
include $(DEPDIR)/printutils.Po
include $(DEPDIR)/readconnect.Po
include $(DEPDIR)/reading.Po
include $(DEPDIR)/score.Po
include $(DEPDIR)/semeai.Po
include $(DEPDIR)/sgfdecide.Po
include $(DEPDIR)/sgffile.Po
include $(DEPDIR)/shapes.Po
include $(DEPDIR)/showbord.Po
include $(DEPDIR)/surround.Po
include $(DEPDIR)/unconditional.Po
include $(DEPDIR)/utils.Po
include $(DEPDIR)/value_moves.Po
include $(DEPDIR)/worm.Po

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

tags: TAGS

ID: $(HEADERS) $(SOURCES) $(LISP) $(TAGS_FILES)
	list='$(SOURCES) $(HEADERS) $(TAGS_FILES)'; \
	unique=`for i in $$list; do \
	    if test -f "$$i"; then echo $$i; else echo $(srcdir)/$$i; fi; \
	  done | \
	  $(AWK) '    { files[$$0] = 1; } \
	       END { for (i in files) print i; }'`; \
	mkid -fID $$unique $(LISP)

TAGS:  $(HEADERS) $(SOURCES)  $(TAGS_DEPENDENCIES) \
		$(TAGS_FILES) $(LISP)
	tags=; \
	here=`pwd`; \
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
check-am: all-am
check: check-am
all-am: Makefile $(LIBRARIES) $(HEADERS)

installdirs:

install: install-am
install-exec: install-exec-am
install-data: install-data-am
uninstall: uninstall-am

install-am: all-am
	@$(MAKE) $(AM_MAKEFLAGS) install-exec-am install-data-am

installcheck: installcheck-am
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
clean: clean-am

clean-am: clean-generic clean-noinstLIBRARIES mostlyclean-am

distclean: distclean-am

distclean-am: clean-am distclean-compile distclean-depend \
	distclean-generic distclean-tags

dvi: dvi-am

dvi-am:

info: info-am

info-am:

install-data-am:

install-exec-am:

install-info: install-info-am

install-man:

installcheck-am:

maintainer-clean: maintainer-clean-am

maintainer-clean-am: distclean-am maintainer-clean-generic

mostlyclean: mostlyclean-am

mostlyclean-am: mostlyclean-compile mostlyclean-generic

uninstall-am: uninstall-info-am

.PHONY: GTAGS all all-am check check-am clean clean-generic \
	clean-noinstLIBRARIES distclean distclean-compile \
	distclean-depend distclean-generic distclean-tags distdir dvi \
	dvi-am info info-am install install-am install-data \
	install-data-am install-exec install-exec-am install-info \
	install-info-am install-man install-strip installcheck \
	installcheck-am installdirs maintainer-clean \
	maintainer-clean-generic mostlyclean mostlyclean-compile \
	mostlyclean-generic tags uninstall uninstall-am \
	uninstall-info-am

# Tell versions [3.59,3.63) of GNU make to not export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
