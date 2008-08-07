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

AUTOMAKE_OPTIONS = no-dependencies

info_TEXINFOS = gnugo.texi

gnugo_TEXINFOS = analyze.texi api.texi board.texi copying.texi dfa.texi \
                 dragon.texi eyes.texi gnugo.texi gtp.texi gtp-commands.texi \
                 influence.texi introduction.texi move_generation.texi \
                 moyo.texi overview.texi owl.texi patterns.texi \
                 reading.texi regression.texi sgf.texi using.texi \
                 utils.texi install.texi 


man_MANS = gnugo.6

EPS = cdfa.eps dfa.eps dfa2.eps oldlogo.eps newlogo.eps \
	path.eps sync-prod1.eps sync-prod2.eps logo-34.eps \
	logo-32.eps logo-36.eps


FIG = cdfa.fig dfa.fig dfa2.fig path.fig sync-prod1.fig sync-prod2.fig

PNG = cdfa.png dfa.png dfa2.png path.png sync-prod1.png sync-prod2.png

JPG = cdfa.jpg dfa.jpg dfa2.jpg oldlogo.jpg path.jpg sync-prod1.jpg \
      sync-prod2.jpg newlogo.jpg logo-32.jpg logo-34.jpg logo-36.jpg


PDF = cdfa.pdf dfa2.pdf dfa.pdf logo-34.pdf path.pdf sync-prod1.pdf \
      sync-prod2.pdf logo-36.pdf


EXTRA_DIST = automake-1.4.patch gnugo.6 gnugo.pod gtp-commands.sed \
	$(EPS) $(FIG) $(PNG) $(JPG) $(PDF)


CLEANFILES = *.log *.dvi *.aux *.vr *.tp *.ky *.pg *.cps *.fns *.toc \
             *.fn *.cp *~


TEXI2PDF = texi2pdf
TEXI2HTML = texi2html

BUILT_SOURCES = gtp-commands.texi

cmdsrc = $(srcdir)/../interface/play_gtp.c
subdir = doc
mkinstalldirs = $(SHELL) $(top_srcdir)/mkinstalldirs
CONFIG_HEADER = $(top_builddir)/config.h
CONFIG_CLEAN_FILES =
depcomp =
DIST_SOURCES =
INFO_DEPS = gnugo.info
DVIS = gnugo.dvi
TEXINFOS = gnugo.texi

NROFF = nroff
MANS = $(man_MANS)
DIST_COMMON = $(gnugo_TEXINFOS) Makefile.am Makefile.in texinfo.tex
all: $(BUILT_SOURCES)
	$(MAKE) $(AM_MAKEFLAGS) all-am

.SUFFIXES:
.SUFFIXES: .dvi .info .ps .texi
$(srcdir)/Makefile.in: # Makefile.am  $(top_srcdir)/configure.in $(ACLOCAL_M4)
	cd $(top_srcdir) && \
	  $(AUTOMAKE) --gnu  doc/Makefile
Makefile: # $(srcdir)/Makefile.in  $(top_builddir)/config.status
	cd $(top_builddir) && \
	  CONFIG_HEADERS= CONFIG_LINKS= \
	  CONFIG_FILES=$(subdir)/$@ $(SHELL) ./config.status

gnugo.info: gnugo.texi $(gnugo_TEXINFOS)
gnugo.dvi: gnugo.texi $(gnugo_TEXINFOS)

.texi.info:
	@cd $(srcdir) && rm -f $@ $@-[0-9] $@-[0-9][0-9]
	cd $(srcdir) \
	  && $(MAKEINFO) $(AM_MAKEINFOFLAGS) $(MAKEINFOFLAGS) \
	       `echo $< | sed 's,.*/,,'`

.texi.dvi:
	TEXINPUTS=$(srcdir):$$TEXINPUTS \
	MAKEINFO='$(MAKEINFO) $(AM_MAKEINFOFLAGS) $(MAKEINFOFLAGS) -I $(srcdir)' \
	$(TEXI2DVI) $<

.texi:
	@cd $(srcdir) && rm -f $@ $@-[0-9] $@-[0-9][0-9]
	cd $(srcdir) \
	  && $(MAKEINFO) $(AM_MAKEINFOFLAGS) $(MAKEINFOFLAGS) \
	       `echo $< | sed 's,.*/,,'`

MAKEINFO = ${SHELL} /Users/epic/Documents/svn/neatzsche/3rdparty/gnugo-3.6/missing --run makeinfo
TEXI2DVI = texi2dvi
DVIPS = dvips
.dvi.ps:
	$(DVIPS) $< -o $@

uninstall-info-am:
	$(PRE_UNINSTALL)
	@if (install-info --version && \
	     install-info --version | fgrep -i -v debian) >/dev/null 2>&1; then \
	  list='$(INFO_DEPS)'; \
	  for file in $$list; do \
	    echo " install-info --info-dir=$(DESTDIR)$(infodir) --remove $(DESTDIR)$(infodir)/$$file"; \
	    install-info --info-dir=$(DESTDIR)$(infodir) --remove $(DESTDIR)$(infodir)/$$file; \
	  done; \
	else :; fi
	@$(NORMAL_UNINSTALL)
	@list='$(INFO_DEPS)'; \
	for file in $$list; do \
	  (if cd $(DESTDIR)$(infodir); then \
	     echo " rm -f $$file $$file-[0-9] $$file-[0-9][0-9])"; \
	     rm -f $$file $$file-[0-9] $$file-[0-9][0-9]; \
	   else :; fi); \
	done

dist-info: $(INFO_DEPS)
	list='$(INFO_DEPS)'; \
	for base in $$list; do \
	  d=$(srcdir); \
	  for file in `CDPATH=: && cd $$d && eval echo $$base*`; do \
	    test -f $(distdir)/$$file \
	    || cp -p $$d/$$file $(distdir)/$$file; \
	  done; \
	done

mostlyclean-aminfo:
	-rm -f gnugo.aux gnugo.cp gnugo.dvi gnugo.fn gnugo.ky gnugo.log gnugo.pg \
	  gnugo.ps gnugo.toc gnugo.tp gnugo.vr

maintainer-clean-aminfo:
	cd $(srcdir) && \
	for i in $(INFO_DEPS); do \
	  rm -f $$i; \
	  if test "`echo $$i-[0-9]*`" != "$$i-[0-9]*"; then \
	    rm -f $$i-[0-9]*; \
	  fi; \
	done

man6dir = $(mandir)/man6
install-man6: $(man6_MANS) $(man_MANS)
	@$(NORMAL_INSTALL)
	$(mkinstalldirs) $(DESTDIR)$(man6dir)
	@list='$(man6_MANS) $(dist_man6_MANS) $(nodist_man6_MANS)'; \
	l2='$(man_MANS) $(dist_man_MANS) $(nodist_man_MANS)'; \
	for i in $$l2; do \
	  case "$$i" in \
	    *.6*) list="$$list $$i" ;; \
	  esac; \
	done; \
	for i in $$list; do \
	  if test -f $(srcdir)/$$i; then file=$(srcdir)/$$i; \
	  else file=$$i; fi; \
	  ext=`echo $$i | sed -e 's/^.*\\.//'`; \
	  inst=`echo $$i | sed -e 's/\\.[0-9a-z]*$$//'`; \
	  inst=`echo $$inst | sed -e 's/^.*\///'`; \
	  inst=`echo $$inst | sed '$(transform)'`.$$ext; \
	  echo " $(INSTALL_DATA) $$file $(DESTDIR)$(man6dir)/$$inst"; \
	  $(INSTALL_DATA) $$file $(DESTDIR)$(man6dir)/$$inst; \
	done
uninstall-man6:
	@$(NORMAL_UNINSTALL)
	@list='$(man6_MANS) $(dist_man6_MANS) $(nodist_man6_MANS)'; \
	l2='$(man_MANS) $(dist_man_MANS) $(nodist_man_MANS)'; \
	for i in $$l2; do \
	  case "$$i" in \
	    *.6*) list="$$list $$i" ;; \
	  esac; \
	done; \
	for i in $$list; do \
	  ext=`echo $$i | sed -e 's/^.*\\.//'`; \
	  inst=`echo $$i | sed -e 's/\\.[0-9a-z]*$$//'`; \
	  inst=`echo $$inst | sed -e 's/^.*\///'`; \
	  inst=`echo $$inst | sed '$(transform)'`.$$ext; \
	  echo " rm -f $(DESTDIR)$(man6dir)/$$inst"; \
	  rm -f $(DESTDIR)$(man6dir)/$$inst; \
	done
tags: TAGS
TAGS:


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
	  dist-info
check-am: all-am
check: check-am
all-am: Makefile $(INFO_DEPS) $(MANS)

installdirs:
	$(mkinstalldirs) $(DESTDIR)$(infodir) $(DESTDIR)$(man6dir)

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
	-test -z "$(CLEANFILES)" || rm -f $(CLEANFILES)

distclean-generic:
	-rm -f Makefile $(CONFIG_CLEAN_FILES) stamp-h stamp-h[0-9]*

maintainer-clean-generic:
	@echo "This command is intended for maintainers to use"
	@echo "it deletes files that may require special tools to rebuild."
	-test -z "$(BUILT_SOURCES)" || rm -f $(BUILT_SOURCES)
clean: clean-am

clean-am: clean-generic mostlyclean-am

distclean: distclean-am

distclean-am: clean-am distclean-generic

dvi: dvi-am

dvi-am: $(DVIS)

info: info-am

info-am: $(INFO_DEPS)

install-data-am: install-info-am install-man

install-exec-am:

install-info: install-info-am

install-info-am: $(INFO_DEPS)
	@$(NORMAL_INSTALL)
	$(mkinstalldirs) $(DESTDIR)$(infodir)
	@list='$(INFO_DEPS)'; \
	for file in $$list; do \
	  d=$(srcdir); \
	  for ifile in `CDPATH=: && cd $$d && echo $$file $$file-[0-9] $$file-[0-9][0-9]`; do \
	    if test -f $$d/$$ifile; then \
	      echo " $(INSTALL_DATA) $$d/$$ifile $(DESTDIR)$(infodir)/$$ifile"; \
	      $(INSTALL_DATA) $$d/$$ifile $(DESTDIR)$(infodir)/$$ifile; \
	    else : ; fi; \
	  done; \
	done
	@$(POST_INSTALL)
	@if (install-info --version && \
	     install-info --version | fgrep -i -v debian) >/dev/null 2>&1; then \
	  list='$(INFO_DEPS)'; \
	  for file in $$list; do \
	    echo " install-info --info-dir=$(DESTDIR)$(infodir) $(DESTDIR)$(infodir)/$$file";\
	    install-info --info-dir=$(DESTDIR)$(infodir) $(DESTDIR)$(infodir)/$$file || :;\
	  done; \
	else : ; fi
install-man: install-man6

installcheck-am:

maintainer-clean: maintainer-clean-am

maintainer-clean-am: distclean-am maintainer-clean-aminfo \
	maintainer-clean-generic

mostlyclean: mostlyclean-am

mostlyclean-am: mostlyclean-aminfo mostlyclean-generic

uninstall-am: uninstall-info-am uninstall-man

uninstall-man: uninstall-man6

.PHONY: all all-am check check-am clean clean-generic dist-info \
	distclean distclean-generic distdir dvi dvi-am info info-am \
	install install-am install-data install-data-am install-exec \
	install-exec-am install-info install-info-am install-man \
	install-man6 install-strip installcheck installcheck-am \
	installdirs maintainer-clean maintainer-clean-aminfo \
	maintainer-clean-generic mostlyclean mostlyclean-aminfo \
	mostlyclean-generic uninstall uninstall-am uninstall-info-am \
	uninstall-man uninstall-man6


gnugo.6: $(srcdir)/gnugo.pod
	pod2man $(srcdir)/gnugo.pod --section 6 --release 3.6 > gnugo.6

gnugo.pdf: gnugo.texi $(gnugo_TEXINFOS)
	$(TEXI2PDF) $<

gnugo.html: gnugo.texi $(gnugo_TEXINFOS)
	$(TEXI2HTML) -split=chapter -nosec_nav -expand=tex $<

gtp-commands.texi: $(cmdsrc)
	cat $(srcdir)/gtp-commands.sed > TMP.sed
	sed -e '/static struct gtp_command commands/,/^}/!d'		\
	    -e '/^ /!d' -e '/NULL/d'					\
	    -e 's/ *{"\(.*\)"[^a-z]*\(gtp_[a-z_]*\)}.*/s,\2,\1,g/'	\
	    $(cmdsrc) >> TMP.sed
	sed -f TMP.sed $(cmdsrc) > $(srcdir)/gtp-commands.texi
	rm -f TMP.sed
# Tell versions [3.59,3.63) of GNU make to not export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
