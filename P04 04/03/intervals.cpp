#include "interval.h"

// Function to convert time_of_day to minutes
int time_to_minutes(time_of_day t) {
    return t.h * 60 + t.m;
}

// Function to convert minutes to time_of_day
time_of_day minutes_to_time(int minutes) {
    time_of_day t;
    t.h = minutes / 60;
    t.m = minutes % 60;
    return t;
}

// Function to compute the duration of an interval in minutes
int interval_duration(interval il) {
    int start_minutes = time_to_minutes(il.start);
    int end_minutes = time_to_minutes(il.end);
    return end_minutes - start_minutes;
}

// Function to check if a time is within an interval
bool is_within_interval(time_of_day t, interval il) {
    int time_minutes = time_to_minutes(t);
    int start_minutes = time_to_minutes(il.start);
    int end_minutes = time_to_minutes(il.end);
    return time_minutes >= start_minutes && time_minutes < end_minutes;
}

// Function to find the union of intervals containing the given time
int search_intervals(time_of_day t, const interval a[], int n, interval& u) {
    int total_duration = 0;
    bool found = false;
    time_of_day earliest_start = {23, 59};  // Initialize earliest start time to maximum possible
    time_of_day latest_end = {0, 0};        // Initialize latest end time to minimum possible

    for (int i = 0; i < n; ++i) {
        if (is_within_interval(t, a[i])) {
            found = true;
            int duration = interval_duration(a[i]);
            total_duration += duration;
            earliest_start = minutes_to_time(std::min(time_to_minutes(earliest_start), time_to_minutes(a[i].start)));
            latest_end = minutes_to_time(std::max(time_to_minutes(latest_end), time_to_minutes(a[i].end)));
        }
    }

    if (!found) {
        u.start = t;
        u.end = t;
        return 0;
    }

    u.start = earliest_start;
    u.end = latest_end;
    return total_duration;
}


int main() {
    { const int n = 1;
  const time_of_day t = { 13, 00 };
  const interval a[n] { { { 12, 30 }, { 14, 30 } } };
  interval u;
  int d = search_intervals(t, a, n, u);
  cout << d << ' ' << u << '\n'; }

    { const int n = 2;
  const time_of_day t = { 14, 30 };
  const interval a[n] { { { 12, 30 }, { 14, 30 } }, 
                  { { 14, 30 }, { 15, 30 } } };
  interval u;
  int d = search_intervals(t, a, n, u);
  cout << d << ' ' << u << '\n'; }

    { const int n = 2;
  const time_of_day t = { 12, 30 };
  const interval a[n] { { { 12, 30 }, { 14, 30 } }, 
                  { { 14, 30 }, { 15, 30 } } };
  interval u;
  int d = search_intervals(t, a, n, u);
  cout << d << ' ' << u << '\n'; }

    { const int n = 2;
  const time_of_day t = { 15, 30 };
  const interval a[n] { { { 12, 30 }, { 14, 30 } }, 
                  { { 14, 30 }, { 15, 30 } } };
  interval u;
  int d = search_intervals(t, a, n, u);
  cout << d << ' ' << u << '\n'; }

    { const int n = 5;
  const time_of_day t = { 15, 15 };
  const interval a[n] { { { 12, 30 }, { 14, 30 } }, 
                  { { 14, 30 }, { 15, 30 } }, 
                  { { 15, 10 }, { 16, 10 } }, 
                  { {  9, 30 }, { 15, 15 } }, 
                  { {  9, 45 }, { 15, 16 } } };
  interval u;
  int d = search_intervals(t, a, n, u);
  cout << d << ' ' << u << '\n'; } 

    return 0;
}
