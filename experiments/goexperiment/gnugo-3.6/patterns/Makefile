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

noinst_PROGRAMS = mkpat joseki mkeyes
EXTRA_PROGRAMS = extract_fuseki transpat

DSP = dfa.dsp patterns.dsp joseki.dsp mkeyes.dsp mkpat.dsp fuseki.dsp
DTR = aa_attackpats.dtr owl_attackpats.dtr owl_defendpats.dtr \
       owl_vital_apats.dtr


EXTRA_DIST = $(DSP)\
        $(DTR)\
	dfa.c\
	gnugo-db.el\
	hoshi_keima.sgf\
	hoshi_other.sgf\
	komoku.sgf\
	mokuhazushi.sgf\
	sansan.sgf\
	takamoku.sgf\
	patterns.db\
	patterns2.db\
	attack.db\
	defense.db\
	endgame.db\
	aa_attackpats.db\
	owl_attackpats.db\
	owl_vital_apats.db\
	owl_defendpats.db\
	eyes.db\
	conn.db\
	influence.db\
	barriers.db\
	fuseki.db\
	fuseki9.db\
	fuseki13.db\
	fuseki19.db\
	handicap.db\
	read_attack.db\
	read_defend.db


mkpat_SOURCES = mkpat.c transform.c dfa.c

mkpat_LDADD = ../utils/libutils.a

DFAFLAGS = -D -m
#DFAFLAGS = 

transpat_SOURCES = transpat.c patlib.c transform.c
transpat_LDADD = 
joseki_SOURCES = joseki.c 
joseki_LDADD = ../engine/libboard.a ../sgf/libsgf.a ../utils/libutils.a 
joseki_INCLUDES = -I$(top_srcdir)/sgf
mkeyes_SOURCES = mkeyes.c
extract_fuseki_SOURCES = extract_fuseki.c
# Yes, we currently need duplicate libengine.a and libpatterns.a.
extract_fuseki_LDADD = ../engine/libengine.a libpatterns.a\
		       ../engine/libengine.a libpatterns.a\
                       ../sgf/libsgf.a ../utils/libutils.a

extract_fuseki_INCLUDES = -I$(top_srcdir)/sgf

noinst_HEADERS = patterns.h eyes.h patlib.h dfa.h dfa-mkpat.h

GGBUILTSOURCES = conn.c patterns.c apatterns.c dpatterns.c eyes.c\
                 influence.c barriers.c endgame.c aa_attackpat.c\
                 owl_attackpat.c\
		 owl_vital_apat.c owl_defendpat.c fusekipat.c\
                 fuseki9.c fuseki13.c fuseki19.c josekidb.c\
		 read_attack.c read_defend.c handipat.c


DBBUILT = hoshi_keima.db hoshi_other.db komoku.db sansan.db \
	  mokuhazushi.db takamoku.db


DBBUILT_INPUT = -i hoshi_keima.db -i hoshi_other.db -i komoku.db \
               -i sansan.db -i mokuhazushi.db -i takamoku.db


DB_TO_TAG = aa_attackpats.db attack.db barriers.db conn.db defense.db\
	    endgame.db eyes.db fuseki.db fuseki9.db fuseki13.db fuseki19.db\
	    handicap.db influence.db owl_attackpats.db\
	    owl_defendpats.db owl_vital_apats.db patterns.db patterns2.db\
	    read_attack.db read_defend.db $(DBBUILT)


# Remove these files here... they are created locally
DISTCLEANFILES = $(GGBUILTSOURCES) $(DBBUILT) *~

# source files in this directory get access to private prototypes
INCLUDES = -I$(top_srcdir)/engine -I$(top_srcdir)/utils -I$(top_srcdir)/sgf

noinst_LIBRARIES = libpatterns.a

libpatterns_a_SOURCES = connections.c helpers.c transform.c $(GGBUILTSOURCES)

ETAGS_ARGS = --language none --regex '/^Pattern[ \t]+[a-zA-Z0-9]+/' $(DB_TO_TAG)\
	     --language auto --no-regex

TAGS_DEPENDENCIES = $(DB_TO_TAG)
subdir = patterns
mkinstalldirs = $(SHELL) $(top_srcdir)/mkinstalldirs
CONFIG_HEADER = $(top_builddir)/config.h
CONFIG_CLEAN_FILES =
LIBRARIES = $(noinst_LIBRARIES)

libpatterns_a_AR = $(AR) cru
libpatterns_a_LIBADD =
am_libpatterns_a_OBJECTS = connections.$(OBJEXT) helpers.$(OBJEXT) \
	transform.$(OBJEXT) conn.$(OBJEXT) patterns.$(OBJEXT) \
	apatterns.$(OBJEXT) dpatterns.$(OBJEXT) eyes.$(OBJEXT) \
	influence.$(OBJEXT) barriers.$(OBJEXT) endgame.$(OBJEXT) \
	aa_attackpat.$(OBJEXT) owl_attackpat.$(OBJEXT) \
	owl_vital_apat.$(OBJEXT) owl_defendpat.$(OBJEXT) \
	fusekipat.$(OBJEXT) fuseki9.$(OBJEXT) fuseki13.$(OBJEXT) \
	fuseki19.$(OBJEXT) josekidb.$(OBJEXT) read_attack.$(OBJEXT) \
	read_defend.$(OBJEXT) handipat.$(OBJEXT)
libpatterns_a_OBJECTS = $(am_libpatterns_a_OBJECTS)
EXTRA_PROGRAMS = extract_fuseki$(EXEEXT) transpat$(EXEEXT)
noinst_PROGRAMS = mkpat$(EXEEXT) joseki$(EXEEXT) mkeyes$(EXEEXT)
PROGRAMS = $(noinst_PROGRAMS)

am_extract_fuseki_OBJECTS = extract_fuseki.$(OBJEXT)
extract_fuseki_OBJECTS = $(am_extract_fuseki_OBJECTS)
extract_fuseki_DEPENDENCIES = ../engine/libengine.a libpatterns.a \
	../engine/libengine.a libpatterns.a ../sgf/libsgf.a \
	../utils/libutils.a
extract_fuseki_LDFLAGS =
am_joseki_OBJECTS = joseki.$(OBJEXT)
joseki_OBJECTS = $(am_joseki_OBJECTS)
joseki_DEPENDENCIES = ../engine/libboard.a ../sgf/libsgf.a \
	../utils/libutils.a
joseki_LDFLAGS =
am_mkeyes_OBJECTS = mkeyes.$(OBJEXT)
mkeyes_OBJECTS = $(am_mkeyes_OBJECTS)
mkeyes_LDADD = $(LDADD)
mkeyes_DEPENDENCIES =
mkeyes_LDFLAGS =
am_mkpat_OBJECTS = mkpat.$(OBJEXT) transform.$(OBJEXT) dfa.$(OBJEXT)
mkpat_OBJECTS = $(am_mkpat_OBJECTS)
mkpat_DEPENDENCIES = ../utils/libutils.a
mkpat_LDFLAGS =
am_transpat_OBJECTS = transpat.$(OBJEXT) patlib.$(OBJEXT) \
	transform.$(OBJEXT)
transpat_OBJECTS = $(am_transpat_OBJECTS)
transpat_DEPENDENCIES =
transpat_LDFLAGS =

DEFS = -DHAVE_CONFIG_H
DEFAULT_INCLUDES =  -I. -I$(srcdir) -I$(top_builddir)
CPPFLAGS = 
LDFLAGS = 
LIBS = -lncurses 
depcomp = $(SHELL) $(top_srcdir)/depcomp
DEP_FILES = $(DEPDIR)/aa_attackpat.Po $(DEPDIR)/apatterns.Po \
	$(DEPDIR)/barriers.Po $(DEPDIR)/conn.Po \
	$(DEPDIR)/connections.Po $(DEPDIR)/dfa.Po \
	$(DEPDIR)/dpatterns.Po $(DEPDIR)/endgame.Po \
	$(DEPDIR)/extract_fuseki.Po $(DEPDIR)/eyes.Po \
	$(DEPDIR)/fuseki13.Po $(DEPDIR)/fuseki19.Po \
	$(DEPDIR)/fuseki9.Po $(DEPDIR)/fusekipat.Po \
	$(DEPDIR)/handipat.Po $(DEPDIR)/helpers.Po \
	$(DEPDIR)/influence.Po $(DEPDIR)/joseki.Po \
	$(DEPDIR)/josekidb.Po $(DEPDIR)/mkeyes.Po \
	$(DEPDIR)/mkpat.Po $(DEPDIR)/owl_attackpat.Po \
	$(DEPDIR)/owl_defendpat.Po \
	$(DEPDIR)/owl_vital_apat.Po $(DEPDIR)/patlib.Po \
	$(DEPDIR)/patterns.Po $(DEPDIR)/read_attack.Po \
	$(DEPDIR)/read_defend.Po $(DEPDIR)/transform.Po \
	$(DEPDIR)/transpat.Po
COMPILE = $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) \
	$(CPPFLAGS) $(AM_CFLAGS) $(CFLAGS)
CCLD = $(CC)
LINK = $(CCLD) $(AM_CFLAGS) $(CFLAGS) $(AM_LDFLAGS) $(LDFLAGS) -o $@
CFLAGS = -g -O2 -Wall -W -Wpointer-arith -Wbad-function-cast -Wcast-qual -Wcast-align -Wwrite-strings -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wundef
DIST_SOURCES = $(libpatterns_a_SOURCES) $(extract_fuseki_SOURCES) \
	$(joseki_SOURCES) $(mkeyes_SOURCES) $(mkpat_SOURCES) \
	$(transpat_SOURCES)
HEADERS = $(noinst_HEADERS)

DIST_COMMON = README $(noinst_HEADERS) Makefile.am Makefile.in
SOURCES = $(libpatterns_a_SOURCES) $(extract_fuseki_SOURCES) $(joseki_SOURCES) $(mkeyes_SOURCES) $(mkpat_SOURCES) $(transpat_SOURCES)

all: all-am

.SUFFIXES:
.SUFFIXES: .c .o .obj
$(srcdir)/Makefile.in: # Makefile.am  $(top_srcdir)/configure.in $(ACLOCAL_M4)
	cd $(top_srcdir) && \
	  $(AUTOMAKE) --gnu  patterns/Makefile
Makefile: # $(srcdir)/Makefile.in  $(top_builddir)/config.status
	cd $(top_builddir) && \
	  CONFIG_HEADERS= CONFIG_LINKS= \
	  CONFIG_FILES=$(subdir)/$@ $(SHELL) ./config.status

AR = ar

clean-noinstLIBRARIES:
	-test -z "$(noinst_LIBRARIES)" || rm -f $(noinst_LIBRARIES)
libpatterns.a: $(libpatterns_a_OBJECTS) $(libpatterns_a_DEPENDENCIES) 
	-rm -f libpatterns.a
	$(libpatterns_a_AR) libpatterns.a $(libpatterns_a_OBJECTS) $(libpatterns_a_LIBADD)
	$(RANLIB) libpatterns.a

clean-noinstPROGRAMS:
	-test -z "$(noinst_PROGRAMS)" || rm -f $(noinst_PROGRAMS)
extract_fuseki$(EXEEXT): $(extract_fuseki_OBJECTS) $(extract_fuseki_DEPENDENCIES) 
	@rm -f extract_fuseki$(EXEEXT)
	$(LINK) $(extract_fuseki_LDFLAGS) $(extract_fuseki_OBJECTS) $(extract_fuseki_LDADD) $(LIBS)
joseki$(EXEEXT): $(joseki_OBJECTS) $(joseki_DEPENDENCIES) 
	@rm -f joseki$(EXEEXT)
	$(LINK) $(joseki_LDFLAGS) $(joseki_OBJECTS) $(joseki_LDADD) $(LIBS)
mkeyes$(EXEEXT): $(mkeyes_OBJECTS) $(mkeyes_DEPENDENCIES) 
	@rm -f mkeyes$(EXEEXT)
	$(LINK) $(mkeyes_LDFLAGS) $(mkeyes_OBJECTS) $(mkeyes_LDADD) $(LIBS)
mkpat$(EXEEXT): $(mkpat_OBJECTS) $(mkpat_DEPENDENCIES) 
	@rm -f mkpat$(EXEEXT)
	$(LINK) $(mkpat_LDFLAGS) $(mkpat_OBJECTS) $(mkpat_LDADD) $(LIBS)
transpat$(EXEEXT): $(transpat_OBJECTS) $(transpat_DEPENDENCIES) 
	@rm -f transpat$(EXEEXT)
	$(LINK) $(transpat_LDFLAGS) $(transpat_OBJECTS) $(transpat_LDADD) $(LIBS)

mostlyclean-compile:
	-rm -f *.$(OBJEXT) core *.core

distclean-compile:
	-rm -f *.tab.c

include $(DEPDIR)/aa_attackpat.Po
include $(DEPDIR)/apatterns.Po
include $(DEPDIR)/barriers.Po
include $(DEPDIR)/conn.Po
include $(DEPDIR)/connections.Po
include $(DEPDIR)/dfa.Po
include $(DEPDIR)/dpatterns.Po
include $(DEPDIR)/endgame.Po
include $(DEPDIR)/extract_fuseki.Po
include $(DEPDIR)/eyes.Po
include $(DEPDIR)/fuseki13.Po
include $(DEPDIR)/fuseki19.Po
include $(DEPDIR)/fuseki9.Po
include $(DEPDIR)/fusekipat.Po
include $(DEPDIR)/handipat.Po
include $(DEPDIR)/helpers.Po
include $(DEPDIR)/influence.Po
include $(DEPDIR)/joseki.Po
include $(DEPDIR)/josekidb.Po
include $(DEPDIR)/mkeyes.Po
include $(DEPDIR)/mkpat.Po
include $(DEPDIR)/owl_attackpat.Po
include $(DEPDIR)/owl_defendpat.Po
include $(DEPDIR)/owl_vital_apat.Po
include $(DEPDIR)/patlib.Po
include $(DEPDIR)/patterns.Po
include $(DEPDIR)/read_attack.Po
include $(DEPDIR)/read_defend.Po
include $(DEPDIR)/transform.Po
include $(DEPDIR)/transpat.Po

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
	$(MAKE) $(AM_MAKEFLAGS) \
	  top_distdir="${top_distdir}" distdir="$(distdir)" \
	  dist-hook
check-am: all-am
check: check-am
all-am: Makefile $(LIBRARIES) $(PROGRAMS) $(HEADERS)

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

clean-am: clean-generic clean-noinstLIBRARIES clean-noinstPROGRAMS \
	mostlyclean-am

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
	clean-noinstLIBRARIES clean-noinstPROGRAMS distclean \
	distclean-compile distclean-depend distclean-generic \
	distclean-tags distdir dvi dvi-am info info-am install \
	install-am install-data install-data-am install-exec \
	install-exec-am install-info install-info-am install-man \
	install-strip installcheck installcheck-am installdirs \
	maintainer-clean maintainer-clean-generic mostlyclean \
	mostlyclean-compile mostlyclean-generic tags uninstall \
	uninstall-am uninstall-info-am


dist-hook:
	cd $(distdir) && rm $(GGBUILTSOURCES)

hoshi_keima.db : $(srcdir)/hoshi_keima.sgf joseki$(EXEEXT)
	./joseki JHK $(srcdir)/hoshi_keima.sgf >hoshi_keima.db

hoshi_other.db : $(srcdir)/hoshi_other.sgf joseki$(EXEEXT)
	./joseki JHO $(srcdir)/hoshi_other.sgf >hoshi_other.db

komoku.db : $(srcdir)/komoku.sgf joseki$(EXEEXT)
	./joseki JK $(srcdir)/komoku.sgf >komoku.db

sansan.db : $(srcdir)/sansan.sgf joseki$(EXEEXT)
	./joseki JS $(srcdir)/sansan.sgf >sansan.db

mokuhazushi.db : $(srcdir)/mokuhazushi.sgf joseki$(EXEEXT)
	./joseki JM $(srcdir)/mokuhazushi.sgf >mokuhazushi.db

takamoku.db : $(srcdir)/takamoku.sgf joseki$(EXEEXT)
	./joseki JT $(srcdir)/takamoku.sgf >takamoku.db

patterns.c : $(srcdir)/patterns.db $(srcdir)/patterns2.db mkpat$(EXEEXT)
	./mkpat -b pat -i $(srcdir)/patterns.db -i$(srcdir)/patterns2.db \
               -o patterns.c

josekidb.c : $(DBBUILT) mkpat$(EXEEXT)
	./mkpat -C joseki $(DBBUILT_INPUT) -o josekidb.c

apatterns.c : $(srcdir)/attack.db mkpat$(EXEEXT)
	./mkpat -X attpat -i $(srcdir)/attack.db -o apatterns.c

dpatterns.c : $(srcdir)/defense.db mkpat$(EXEEXT)
	./mkpat defpat -i $(srcdir)/defense.db -o dpatterns.c

conn.c : $(srcdir)/conn.db mkpat$(EXEEXT)
	./mkpat -c conn -i $(srcdir)/conn.db -o conn.c

endgame.c : $(srcdir)/endgame.db mkpat$(EXEEXT)
	./mkpat -b endpat -i $(srcdir)/endgame.db -o endgame.c

eyes.c: $(srcdir)/eyes.db mkeyes$(EXEEXT)
	./mkeyes < $(srcdir)/eyes.db >eyes.c

influence.c : $(srcdir)/influence.db mkpat$(EXEEXT)
	./mkpat -c influencepat -i $(srcdir)/influence.db -o influence.c

barriers.c : $(srcdir)/barriers.db mkpat$(EXEEXT)
	./mkpat -c -b barrierspat -i $(srcdir)/barriers.db -o barriers.c

aa_attackpat.c : $(srcdir)/aa_attackpats.db $(srcdir)/aa_attackpats.dtr mkpat$(EXEEXT)
	./mkpat $(DFAFLAGS) -b -t $(srcdir)/aa_attackpats.dtr aa_attackpat \
               -i $(srcdir)/aa_attackpats.db -o aa_attackpat.c

owl_attackpat.c : $(srcdir)/owl_attackpats.db $(srcdir)/owl_attackpats.dtr mkpat$(EXEEXT)
	./mkpat $(DFAFLAGS) -b -t $(srcdir)/owl_attackpats.dtr owl_attackpat \
               -i $(srcdir)/owl_attackpats.db -o owl_attackpat.c

owl_vital_apat.c : $(srcdir)/owl_vital_apats.db $(srcdir)/owl_vital_apats.dtr mkpat$(EXEEXT)
	./mkpat $(DFAFLAGS) -b -t $(srcdir)/owl_vital_apats.dtr owl_vital_apat \
               -i $(srcdir)/owl_vital_apats.db -o owl_vital_apat.c

owl_defendpat.c : $(srcdir)/owl_defendpats.db $(srcdir)/owl_defendpats.dtr mkpat$(EXEEXT)
	./mkpat $(DFAFLAGS) -b -t $(srcdir)/owl_defendpats.dtr owl_defendpat \
               -i $(srcdir)/owl_defendpats.db -o owl_defendpat.c

fusekipat.c : $(srcdir)/fuseki.db mkpat$(EXEEXT)
	./mkpat -b fusekipat -i $(srcdir)/fuseki.db -o fusekipat.c

fuseki9.c : $(srcdir)/fuseki9.db mkpat$(EXEEXT)
	./mkpat -b -f fuseki9 -i $(srcdir)/fuseki9.db -o fuseki9.c

fuseki13.c : $(srcdir)/fuseki13.db mkpat$(EXEEXT)
	./mkpat -b -f fuseki13 -i $(srcdir)/fuseki13.db -o fuseki13.c

fuseki19.c : $(srcdir)/fuseki19.db mkpat$(EXEEXT)
	./mkpat -b -f fuseki19 -i $(srcdir)/fuseki19.db -o fuseki19.c

handipat.c : $(srcdir)/handicap.db mkpat$(EXEEXT)
	./mkpat -b handipat -i $(srcdir)/handicap.db -o handipat.c

read_attack.c : $(srcdir)/read_attack.db mkpat$(EXEEXT)
	./mkpat -b read_attack -i $(srcdir)/read_attack.db -o read_attack.c

read_defend.c : $(srcdir)/read_defend.db mkpat$(EXEEXT)
	./mkpat -b read_defend -i $(srcdir)/read_defend.db -o read_defend.c
# Tell versions [3.59,3.63) of GNU make to not export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
