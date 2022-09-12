#ifndef STATE_HPP
#define STATE_HPP

#include "week-data.hpp"

class State {
  std::string name;
  WeekData* weeks;
  int numberOfDataPoints;

  public:
    const int MAX_NUMBER_OF_WEEKS = 500;
    State();
    State(std::string name);
    State(const State& copyState);
    ~State();
    const std::string GetName();
    void AddWeek(std::string);
    const double GetMeanDeaths();
    const std::string* GetOutliers();
    const double Stdev(double mean);
    State operator = (const State& rhs);
};

#endif