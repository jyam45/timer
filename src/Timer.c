#include "config.h"
#include "Timer.h"

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#ifdef HAVE_TIME_H
#include <time.h>
#endif

#ifdef HAVE_SYS_TIME_H
#include <sys/time.h>
#endif

#ifdef HAVE_SYS_TIMES_H
#include <sys/times.h>
#endif

#ifdef HAVE_SYS_RESOURCE_H
#include <sys/resource.h>
#endif

#ifdef HAVE_LINUX_TIME_H
#include <linux/time.h>
#endif

#ifdef HAVE_LINUX_TIMES_H
#include <linux/times.h>
#endif


#if defined(HAVE_STRUCT_TIMESPEC_TV_NSEC) && \
    defined(HAVE_CLOCK_GETTIME)

/* nano sec */
double get_cputime(void)
{
  struct timespec t;
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&t);
  //clock_gettime(CLOCK_THREAD_CPUTIME_ID,&t);
  return t.tv_sec + (double)t.tv_nsec*1e-9;
}
double get_realtime(void)
{
  struct timespec t;
  clock_gettime(CLOCK_REALTIME,&t);
  return t.tv_sec + (double)t.tv_nsec*1e-9;
}
double get_tick(void){ return (double)1e-9; }

#elif  defined(HAVE_STRUCT_RUSAGE_RU_UTIME) && \
       defined(HAVE_STRUCT_TIMEVAL_TV_USEC) && \
       defined(HAVE_GETRUSAGE) && \
       defined(HAVE_GETTIMEOFDAY)

/* micro sec */
double get_cputime(void)
{
  struct rusage r;
  struct timeval t;
  getrusage(RUSAGE_SELF,&r);
  t = r.ru_utime; // user time
  //t = r.ru_stime; // system time
  return t.tv_sec + (double)t.tv_usec*1e-6;
}
double get_realtime(void)
{
  struct timeval t;
  gettimeofday(&t,NULL);
  return t.tv_sec + (double)t.tv_usec*1e-6;
}
double get_tick(void){ return (double)1e-6; }

#elif defined(HAVE_CLOCK_T) && \
      defined(HAVE_STRUCT_TMS_TMS_UTIME) && \
      defined(HAVE_CLOCK) && \
      defined(HAVE_TIMES)

double get_cputime(void)
{
  clock_t t=clock();
  return (double)t/(double)CLOCKS_PER_SEC;
}
double get_realtime(void)
{
  struct tms m;
  clock_t t=times(&m);
  return (double)t/(double)sysconf(_SC_CLK_TCK);
}
double get_tick(void){ return (double)1e-2; }

#else

#error cannot define timer

#endif


