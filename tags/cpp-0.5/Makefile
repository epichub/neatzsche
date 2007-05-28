all: opt
	
changedir:
	@ cd src;

dist: changedir
	@ cd src ; make STYLE=RELEASE ;

opt: 
	@ cd src ; make STYLE=OPTIMISED ;

profile: changedir
	@ cd src ; make STYLE=PROFILE ;

clean: 
	@ rm neatmaster neatslave test-xor test-go ; cd src; rm *.o TAGS