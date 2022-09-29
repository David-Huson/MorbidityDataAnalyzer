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

State::State(const State& copyState): name(copyState.name), numberOfDataPoints(copyState.numberOfDataPoints){
  weeks = new WeekData[MAX_NUMBER_OF_WEEKS];
  for(int i = 0; i < numberOfDataPoints; ++i)
    weeks[i] = copyState.weeks[i];
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
  for (int i = 0; i < numberOfDataPoints; ++i){
    if(checkIfOutlier(weeks[i].GetDeathCount()))
      count++;
  }
  return count;
}

double State::Stdev() const{
  return Stats::StDev(weeks, numberOfDataPoints);
}

std::string* State::GetOutliers() const{
  std::string* outliers = new std::string[GetOutlierCount()];
  int numOutliersRec = 0;


  for (int i = 0; i < numberOfDataPoints; ++i){
    if(checkIfOutlier(weeks[i].GetDeathCount())) {
      // std::cout << "after Check" << std::endl;
        std::ostringstream outlier;
        outlier << weeks[i];
        outliers[numOutliersRec] = outlier.str();
        // std::cout << "outlier" << outlier.str() << std::endl;
        numOutliersRec++;
      }
    }
    return outliers;
}

bool State::checkIfOutlier(int deathCount) const{
  double stDev = Stdev();
  double mean = GetMeanDeaths();
  double dev = abs(mean - deathCount);

  return(dev > 2 * stDev);
}
