/******************************************************************
 * @file state.cpp
 * @author David Huson(dph14@students.uwf.edu)
 * @brief a class to store weekly morbidity 
 *        data for a state and statistaical analysis on the data
 * @date 2022-09-13
******************************************************************/

#include "state.hpp"
#include "stats.hpp"
#include <sstream>
#include <iostream>

State::State(std::string name): name(name) {
  numberOfDataPoints = 0;
  weeks = new WeekData[MAX_NUMBER_OF_WEEKS];
}

int State::getNumberOfWeeks() {
  return numberOfDataPoints;
}

State::~State() {
  delete [] weeks;
}

std::string State::GetName() const {
  return name;
}

void State::AddWeek(std::string data){
  weeks[numberOfDataPoints] = WeekData(data);
  numberOfDataPoints++;
}

double State::GetMeanDeaths() const {
  double meanDeaths = Stats::GetMean(weeks, numberOfDataPoints); 
  return meanDeaths;
}

int State::GetOutlierCount() const {
  int count = 0;
  for (int i = 0; i < numberOfDataPoints; ++i){   // check each week to see if it is an outlier
    if(checkIfOutlier(weeks[i].GetDeathCount()))  // if a week is an outlier, incremet the outlier count
      count++;
  }
  return count;
}

double State::Stdev() const{
  return Stats::StDev(weeks, numberOfDataPoints);
}

std::string* State::GetOutliers() const{
  std::string* outliers = new std::string[GetOutlierCount()]; // construct an array to store the outliers
  int numOutliersRec = 0;

  // check each week to see if it is an outlier
  for (int i = 0; i < numberOfDataPoints; ++i) {
    if(checkIfOutlier(weeks[i].GetDeathCount())) {    // if the week data is an outlier, add ti to the outliers array
        std::ostringstream outlier;
        outlier << weeks[i];
        outliers[numOutliersRec] = outlier.str();
        numOutliersRec++;
      }
    }
    return outliers;
}

bool State::checkIfOutlier(int deathCount) const{
  double stDev = Stdev();
  double mean = GetMeanDeaths();
  // find the deathCounts deviation from the mean
  double dev = abs(mean - deathCount);

  // return true if the deviation is more than 2 standard deviations from the
  return(dev > 2 * stDev);
}
