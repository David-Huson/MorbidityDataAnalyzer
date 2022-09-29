#include "week-data.hpp"
#include <iostream>

WeekData::WeekData(){
  allCauses = 0;
  naturalCauses = 0;
  date = "0000-00-00";
}

WeekData::WeekData(std::string data) {
  int delimiterIndex = data.find(',');
  date = data.substr(0, delimiterIndex);
  allCauses = std::stoi(data.substr(delimiterIndex + 1));
  // std::cout << allCauses << ' ' << date << std::endl;
  naturalCauses = 0;
}
std::string WeekData::GetDate() const {
  return date;
}
int WeekData::GetDeathCount() const {
  return this->allCauses;
}
std::ostream& operator << (std::ostream& out, const WeekData& week) {
  out << week.date << " - total deaths: " << week.GetDeathCount();
  return out;
}