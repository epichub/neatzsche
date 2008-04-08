all: opt
	
changedir:
	@ cd src;

dist:
	@ cd src ; make STYLE=RELEASE ;

opt:
	@ cd src ; make STYLE=OPTIMISED ;

profile:
	@ cd src ; make STYLE=PROFILE ;

noopt:
	@ cd src ; make STYLE=NOOPT ;

clean: 
	@ rm neatmaster neatslave test-xor test-go lightsim-viewer lightsim-test; cd src; rm *.o TAGS; cd lightsim; rm *.o;