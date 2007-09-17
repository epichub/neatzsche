# Makefile.am in directory 'feedback' 

include $(top_srcdir)/config/Makefile.am.include

noinst_PROGRAMS = test-feedback test-options test-mathutils test-misc-utils test-syncutils test-ref-ptr
# noinst_LTLIBRARIES = libutilities_dbg.la

# Automake makefile complains if we try to use feedback.cpp both
# directly and in the utilities library, so we must include
# libutilities instead of just linking directly to feedback.cpp.
test_feedback_SOURCES = test_feedback.cpp
test_feedback_LDADD = libutilities.la

test_options_SOURCES = test_options.cpp
test_options_LDADD = libutilities.la

test_ref_ptr_SOURCES = test_ref_ptr.cpp
test_ref_ptr_LDADD = libutilities.la

test_syncutils_SOURCES = test_syncutils.cpp
test_syncutils_LDADD = libutilities.la

test_misc_utils_SOURCES = test_misc_utils.cpp
test_misc_utils_LDADD = libutilities.la
# test_misc_utils_CPPFLAGS = $(AM_CPPFLAGS) -D_GLIBCXX_DEBUG

test_mathutils_LDADD = libutilities.la
test_mathutils_SOURCES = test_mathutils.cpp

lib_LTLIBRARIES = libutilities.la
libutilities_la_SOURCES = feedback.cpp syncutils.cpp options.cpp errorcodes_common.cpp errorcodes_thread.cpp misc_utils.cpp ziggurat.cpp

# libutilities_dbg_la_SOURCES = $(libutilities_la_SOURCES)
# libutilities_dbg_la_CPPFLAGS = $(AM_CPPFLAGS) -D_GLIBCXX_DEBUG