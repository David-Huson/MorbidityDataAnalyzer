#ifndef STATE_HPP
#define STATE_HPP

#include "week-data.hpp"
#include <vector>

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
    std::string GetName() const;
    void AddWeek(std::string);
    double GetMeanDeaths() const;
    int GetOutlierCount() const ;
    std::string* GetOutliers() const ; 
    double Stdev() const;
    State operator = (const State& rhs);
    int getNumberOfWeeks();
    bool checkIfOutlier(int deathCount) const;
};

#endif