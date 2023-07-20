#include "stats.h"

struct Stats compute_statistics(const float* numberset, int setlength) {
   static struct Stats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;

    int sum = 0;
    int i = 0;

    for(i=0;i<setlength;i++)
    {
        sum = sum+numberset[i];
    }

    s.average = sum/setlength;
    return s;
}
