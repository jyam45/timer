#include "config.h"
#include "Timer.h"

#define GETCPUTIME  FC_FUNC(getcputime,GETCPUTIME)
#define GETREALTIME FC_FUNC(getrealtime,GETREALTIME)
#define GETTICK     FC_FUNC(gettick,GETTICK)

double GETCPUTIME() { return get_cputime() ; }
double GETREALTIME(){ return get_realtime(); }
double GETTICK()    { return get_tick();     }

