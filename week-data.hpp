#ifndef WEEK_DATA_HPP
#define WEEK_DATA_HPP

#include <ostream>

class WeekData{
  std::string date;
  int allCauses;
  int naturalCauses;

  public:
    WeekData();
    WeekData(std::string date);
    const int GetDeathCount();
    friend std::ostream& operator << (std::ostream& out, const WeekData& week);
};

#endif