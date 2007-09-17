# Makefile.am in directory 'dist' 

include $(top_srcdir)/config/Makefile.am.include

bin_PROGRAMS = distributor

# noinst_PROGRAMS = pvmslavetester
noinst_PROGRAMS = test-messages test-slave test-master test-testers

test_messages_SOURCES = test_messages.cpp 
test_messages_LDADD = libdisteval.la 

test_master_SOURCES = test_master.cpp test_master.h
test_slave_SOURCES = test_slave.cpp test_slave.h

test_testers_SOURCES = test_testers.cpp
test_testers_LDADD = libdisteval.la 

# pvmslavetester_SOURCES = pvm_slave_tester.cpp

# slavestub_SOURCES = slave_stdio.cpp
# slavestub_LDADD = libdisteval.la 

# masterstub_SOURCES = master_stdio.cpp
# masterstub_LDADD = libdisteval.la 

distributor_SOURCES = frontend.cpp slave_stdio.cpp slave_stdio.h master_stdio.cpp master_stdio.h
distributor_LDADD = libdisteval.la 
# distributor_CPPFLAGS = $(AM_CPPFLAGS) -D_GLIBCXX_DEBUG

lib_LTLIBRARIES     = libdisteval.la
libdisteval_la_SOURCES = slave.cpp slave.h jobqueue.cpp jobqueue.h master.cpp master.h \
			 messages.cpp messages.h slave_channel.cpp slave_channel.h \
			 slave_mpi.cpp slave_mpi.h utils.cpp utils.h
# libdisteval_la_CPPFLAGS = $(AM_CPPFLAGS) -D_GLIBCXX_DEBUG

if enable_pvm
  libdisteval_la_SOURCES += slave_pvm.cpp slave_pvm.h
endif
