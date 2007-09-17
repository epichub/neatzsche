# Makefile.am in directory 'feedback' 

include $(top_srcdir)/config/Makefile.am.include

noinst_PROGRAMS = test-feedback test-options


# Automake makefile complains if we try to use feedback.cpp both
# directly and in the utilities library, so we must include
# libutilities instead of just linking directly to feedback.cpp.
test_feedback_LDADD = libutilities.la
test_feedback_SOURCES = test_feedback.cpp

test_options_SOURCES = test_options.cpp
test_options_LDADD = libutilities.la

lib_LTLIBRARIES = libutilities.la
libutilities_la_SOURCES = feedback.cpp syncutils.cpp options.cpp errorcodes_common.cpp errorcodes_thread.cpp misc_utils.cpp

