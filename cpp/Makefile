all: opt

changedir:
	@ cd src;

lightsim-viewer:
	@ cd src; $(MAKE) STYLE=OPTIMISED ;

dist:
	@ cd src ; $(MAKE) STYLE=RELEASE ;

no-qt:
	@ cd src ; $(MAKE) no-qt STYLE=OPTIMISED ;

no-qt-debug:
	@ cd src ; $(MAKE) no-qt STYLE=DEBUG ;

opt:
	@ cd src ; $(MAKE) STYLE=OPTIMISED ;

profile:
	@ cd src ; $(MAKE) STYLE=PROFILE ;

noopt:
	@ cd src ; $(MAKE) STYLE=NOOPT ;

debug:
	@ cd src ; $(MAKE) STYLE=DEBUG ;

clean: 
	@ rm neatmaster neatslave test-xor test-go lightsim-viewer lightsim-test test-eye; cd src; rm *.o TAGS; cd lightsim; rm *.o;