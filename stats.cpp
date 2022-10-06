/**************************************
 * @file stats.cpp
 * @author David Huson(dph14@students.uwf.edu)
 * @brief a class to provide methods for the 
 *        computation of the mean and population standard deviation
 * @date 2022-09-13
**************************************/
#include "stats.hpp"
#include <math.h>

double Stats::GetMean(WeekData dataset[], int numDataPoints) {
  // edge case - no data to analyze
  if(numDataPoints <= 0){
    return 0.0;
  }

  double sum = 0;
  for(int i = 0; i < numDataPoints; ++i)  // loop through all the data points and sum them up
    sum += dataset[i].GetDeathCount();
  
  return sum / numDataPoints; // return the mean ( mean = sum / populationSize)
}

double Stats::StDev(WeekData dataset[], int populationSize) {

  // edge case - no data
  if(populationSize <= 0){
    return 0.0;
  }

  double variance = 0;
  double mean = GetMean(dataset, populationSize);  // get the mean

  for (int i = 0; i < populationSize; ++i){  // loop through the data to calculate the variance
    variance += pow((dataset[i].GetDeathCount() - mean), 2);
  }

  return sqrt(variance / populationSize);  // get the standard deviation from the variance

}