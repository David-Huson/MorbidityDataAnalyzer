/**************************************
 * @file week-data.cpp
 * @author Dvid Huson(dph14@students.uwf.edu)
 * @brief defines the week data class
 * @date 2022-09-13
**************************************/

#include "week-data.hpp"
#include <iostream>

WeekData::WeekData(){
  allCauses = 0;
  date = "0000-00-00";
}

WeekData::WeekData(std::string data) {
  int delimiterIndex = data.find(',');  // find the delimiter index
  date = data.substr(0, delimiterIndex);  // separate the week start date from the death count and use it to set date
  allCauses = std::stoi(data.substr(delimiterIndex + 1));  // set the allCauses count to the death count from the data
}
std::string WeekData::GetDate() const {
  return date;
}
int WeekData::GetDeathCount() const {
  return allCauses;
}
std::ostream& operator << (std::ostream& out, const WeekData& week) {
  out << week.date << " - total deaths: " << week.GetDeathCount();    // build the output stream containing the week data and death count
  return out;
}