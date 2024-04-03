#include "interval.h"
#include <iostream>

using namespace std;

interval largest(const interval a[], int n) {
    int maxDuration = -1;
    interval largestInterval;

    // Iterate through all intervals
    for (int i = 0; i < n; ++i) {
        // Calculate the duration of the current interval
        int startMinutes = a[i].start.h * 60 + a[i].start.m;
        int endMinutes = a[i].end.h * 60 + a[i].end.m;
        int duration = endMinutes - startMinutes;

        // If the duration of the current interval is greater than the maximum duration so far, update largestInterval
        if (duration > maxDuration) {
            maxDuration = duration;
            largestInterval = a[i];
        }
    }

    return largestInterval;
}

int main() {

    { const int n = 1;
  interval a[n] = {  { { 12, 30 }, { 12, 55 } }  };
  cout << largest(a, n) << '\n'; }

    { const int n = 4;
  interval a[n] = {  { { 0,  0  },   { 0,  1 }  }, 
                     { { 0,  0  },   { 23, 59 } },
                     { { 23, 57 },   { 23, 59 } },
                     { { 0,  1  },   { 23, 59 } } };
  cout << largest(a, n) << '\n'; }
    { const int n = 5;
  interval a[n] = {  { { 12,  59 }, { 13, 4  } }, 
                     { { 0,   0  }, { 0,  4  } },
                     { { 23,  56 }, { 23, 59 } },
                     { { 13,  30 }, { 13, 32 } },
                     { { 18,  59 }, { 19, 0  } } };
  cout << largest(a, n) << '\n'; }

    { const int n = 5;
  interval a[n] = {  { { 12,  59 }, { 13, 4  } }, 
                     { { 0,   0  }, { 0,  4  } },
                     { { 23,  53 }, { 23, 59 } },
                     { { 13,  29 }, { 13, 31 } },
                     { { 18,  59 }, { 19, 0  } } };
  cout << largest(a, n) << '\n'; }

    { const int n = 5;
  interval a[n] = {  { { 12,  59 }, { 13, 4  } }, 
                     { { 0,   0  }, { 0,  4  } },
                     { { 23,  53 }, { 23, 59 } },
                     { { 13,  29 }, { 13, 31 } },
                     { { 18,  58 }, { 19, 5  } } };
  cout << largest(a, n) << '\n'; }

    return 0;
}