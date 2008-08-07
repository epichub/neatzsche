/* config.h.  Generated automatically by configure.  */
/* config.h.in.  Generated automatically from configure.in by autoheader.  */

/* Define to use ansi escape sequences for color debugging */
/* #undef ANSI_COLOR */

/* Ruleset. Default Japanese */
#define CHINESE_RULES 0

/* Center oriented influence. Disabled by default. */
#define COSMIC_GNUGO 0

/* Define to use curses for color debugging */
#define CURSES 1

/* Default level (strength). Up to 10 supported */
#define DEFAULT_LEVEL 10

/* Default hash table size in megabytes */
#define DEFAULT_MEMORY 8

/* Give the directory where gnugo was compiled */
#define GNUGO_PATH "/Users/epic/Documents/svn/neatzsche/3rdparty/gnugo-3.6"

/* The concatenation of the strings "GNU ", and PACKAGE. */
#define GNU_PACKAGE "GNU gnugo"

/* Define if the curses headers defines KEY_{UP,DOWN,LEFT,RIGHT} */
#define HAVE_CURSES_ARROWS 1

/* Define if you have the <curses.h> header file. */
#define HAVE_CURSES_H 1

/* Define if you have the `gettimeofday' function. */
#define HAVE_GETTIMEOFDAY 1

/* Define if you have the <glib.h> header file. */
/* #undef HAVE_GLIB_H */

/* Define if you have the `g_vsnprintf' function. */
/* #undef HAVE_G_VSNPRINTF */

/* Define if you have the `keypad' function. */
#define HAVE_KEYPAD 1

/* Define if you have the <ncurses/curses.h> header file. */
/* #undef HAVE_NCURSES_CURSES_H */

/* Define if you have the <ncurses/term.h> header file. */
/* #undef HAVE_NCURSES_TERM_H */

/* Define if you have the <sys/times.h> header file. */
#define HAVE_SYS_TIMES_H 1

/* Define if you have the <sys/time.h> header file. */
#define HAVE_SYS_TIME_H 1

/* Define if you have the <term.h> header file. */
#define HAVE_TERM_H 1

/* Define if you have the `times' function. */
#define HAVE_TIMES 1

/* Define if your compiler supports transparent unions */
#define HAVE_TRANSPARENT_UNIONS 1

/* Define if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define if you have the `usleep' function. */
#define HAVE_USLEEP 1

/* Define if #define can take a variable number of arguments */
#define HAVE_VARIADIC_DEFINE 1

/* Define if you have the `vsnprintf' function. */
#define HAVE_VSNPRINTF 1

/* Define if you have the `vwprintw' function. */
#define HAVE_VWPRINTW 1

/* Large Scale Captures. Disabled by default. */
#define LARGE_SCALE 0

/* Define if `major', `minor', and `makedev' are declared in <mkdev.h>. */
/* #undef MAJOR_IN_MKDEV */

/* Define if `major', `minor', and `makedev' are declared in <sysmacros.h>. */
/* #undef MAJOR_IN_SYSMACROS */

/* Metamachine. Default not enabled. */
#define ORACLE 0

/* Owl Node Limit */
#define OWL_NODE_LIMIT 1000

/* Name of package */
#define PACKAGE "gnugo"

/* Allow resignation. Default enabled */
#define RESIGNATION_ALLOWED 1

/* Semeai Variations. 500 default */
#define SEMEAI_NODE_LIMIT 500

/* The size of a `long', as computed by sizeof. */
#define SIZEOF_LONG 4

/* Define to 1 if termcap/terminfo is available. */
#define TERMINFO 1

/* Define if you can safely include both <sys/time.h> and <time.h>. */
#define TIME_WITH_SYS_TIME 1

/* Break-in module. Enabled by default. */
#define USE_BREAK_IN 1

/* Define special valgrind macros. */
#define USE_VALGRIND 0

/* Version number of package */
#define VERSION "3.6"

/* Define to empty if `const' does not conform to ANSI C. */
/* #undef const */
