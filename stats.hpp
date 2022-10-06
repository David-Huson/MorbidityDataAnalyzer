/**************************************************
 * @file stats.hpp
 * @author David Huson(dph14@students.uwf.edu)
 * @brief declares the static methods to calculate
 *        the mean and standard deviation
 * @date 2022-09-13
**************************************************/
#ifndef STATS_HPP
#define STATS_HPP

#include "week-data.hpp"

/**
 * @brief a class to provide static methods to find the mean and standard deviation of some week data
 * 
 */
class Stats {
  public:
  /**
   * @brief calculate the mean of the data passed in dataset
   * 
   * @param dataset the data to find the mean for
   * @param numDataPoints the size of the dataset
   * @return double the mean (Average)  of the data
   */
    static double GetMean(WeekData dataset[], int numDataPoints);

    /**
     * @brief calcualte the standard deviation of the data passed in dataset
     * 
     * @param dataset the data to find the stadard deviation for
     * @param numDataPoints the size of the dataset
     * @return double the standard deviation of the data
     */
    static double StDev(WeekData dataset[], int numDataPoints);
};

#endif