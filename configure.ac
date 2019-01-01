#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.63])
AC_INIT([libtimer], [1.00], [J.Yamamoto.Tech@gmail.com], [libtimer])
AM_INIT_AUTOMAKE([no-dist-gzip dist-bzip2])
AC_CONFIG_SRCDIR([src/Timer.h])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
AC_PROG_FC
AC_PROG_RANLIB
AC_FC_WRAPPERS

# Checks for libraries.
AC_CHECK_LIB([rt],[timer_gettime])

# Checks for header files.
AC_CHECK_HEADERS([sys/resource.h unistd.h])
AC_CHECK_HEADERS([time.h])
AC_CHECK_HEADERS([sys/time.h],[],[],
               [#ifdef HAVE_TIME_H
                #include <time.h>
                #endif
                ])
AC_CHECK_HEADERS([linux/time.h],[],[],
               [#ifdef HAVE_TIME_H
                #include <time.h>
                #endif
                #ifdef HAVE_SYS_TIME_H
                #include <sys/time.h>
                #endif
                ])
AC_CHECK_HEADERS([sys/times.h])
AC_CHECK_HEADERS([linux/times.h],[],[],
               [#ifdef HAVE_SYS_TIMES_H
                #include <sys/times.h>
                #endif
                ])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_TYPES([clock_t],[],[],
               [#ifdef HAVE_TIME_H
                #include <time.h>
                #endif
                #ifdef HAVE_SYS_TIME_H
                #include <sys/time.h>
                #endif
                #ifdef HAVE_LINUX_TIME_H
                #include <linux/time.h>
                #endif
                ])

AC_CHECK_MEMBERS([struct timespec.tv_nsec, struct tms.tms_utime, struct rusage.ru_utime, struct timeval.tv_usec],[],[],
               [#ifdef HAVE_UNISTD_H
                #include <unistd.h>
                #endif
                #ifdef HAVE_TIME_H
                #include <time.h>
                #endif
                #ifdef HAVE_SYS_TIME_H
                #include <sys/time.h>
                #endif
                #ifdef HAVE_LINUX_TIME_H
                #include <linux/time.h>
                #endif
                #ifdef HAVE_SYS_TIMES_H
                #include <sys/times.h>
                #endif
                #ifdef HAVE_LINUX_TIMES_H
                #include <linux/times.h>
                #endif
                #ifdef HAVE_SYS_RESOURCE_H
                #include <sys/resource.h>
                #endif
                ])

# Checks for library functions.
AC_CHECK_FUNCS([clock times getrusage gettimeofday clock_gettime])

AC_OUTPUT([Makefile src/Makefile])
