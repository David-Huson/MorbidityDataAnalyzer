/**************************************
 * @file stats.cpp
 * @author Dvid Huson(dph14@students.uwf.edu)
 * @brief a class to provide classes for the computation of the mean and population standard deviation
 * @version 0.1
 * @date 2022-09-13
**************************************/
#include "stats.hpp"
#include <math.h>

double Stats::GetMean(WeekData dataset[], int numDataPoints) {
  // edge cases
  if(numDataPoints <= 0){
    return 0.0;
  }

  double sum = 0;
  for(int i = 0; i < numDataPoints; ++i) 
    sum += dataset[i].GetDeathCount();
  
  return sum / numDataPoints;
}

double Stats::StDev(WeekData dataset[], int populationSize) {

  // edge cases
  if(populationSize <= 0){
    return 0.0;
  }

  double variance = 0;
  double mean = GetMean(dataset, populationSize);
  for (int i = 0; i < populationSize; ++i){
    variance += pow((dataset[i].GetDeathCount() - mean), 2);
  }

  double popStandardDeviation = sqrt(variance / populationSize);
  return popStandardDeviation;

}