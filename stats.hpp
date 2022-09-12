#ifndef STATS_HPP
#define STATS_HPP

#include "week-data.hpp"

class Stats {
  public:
    static double GetMean(WeekData dataset[], int numDataPoints);
    static double StdDev(WeekData dataset[], int numDataPoints);
};

#endif