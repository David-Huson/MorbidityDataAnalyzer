/*****************************************************************
 * @file state.cpp
 * @author David Huson(dph14@students.uwf.edu)
 * @brief declares the state class and its member methods / fields
 * @date 2022-09-13
******************************************************************/

#ifndef STATE_HPP
#define STATE_HPP

#include "week-data.hpp"
#include <vector>

/**
 * @brief a class to store weekly morbidity data for a state
 * 
 */
class State {
  /**
   * @brief the state name
   * 
   */
  std::string name;

  /**
   * @brief the array of week data
   * 
   */
  WeekData* weeks;

  /**
   * @brief the number of weeks in the weeks array
   * 
   */
  int numberOfDataPoints;

  public:
  /**
   * @brief the maximum number of datapoints in the weeks array
   * 
   */
    const int MAX_NUMBER_OF_WEEKS = 500;

    /**
     * @brief Construct a new empty State object
     * 
     */
    State();

    /**
     * @brief Construct a new State object given a name
     * 
     * @param name 
     */
    State(std::string name);

    /**
     * @brief Destroy the State object and free any dynamically allocated memory
     * 
     */
    ~State();

    /**
     * @brief Get the  state's name
     * 
     * @return std::string the name of the state
     */
    std::string GetName() const;

    /**
     * @brief add the data for a week to the weeks array
     */
    void AddWeek(std::string);

    /**
     * @brief Get the mean of the mean of the morbidity data in the weeks array
     * 
     * @return double the mean of the morbidity data for the state
     */
    double GetMeanDeaths() const;

    /**
     * @brief Get the number of outliers in the weeks array
     * 
     * @return int the number of outliers in the dataset
     */
    int GetOutlierCount() const;
    
    /**
     * @brief Get a string array with all the outliers
     * 
     * @return std::string* 
     */
    std::string* GetOutliers() const ; 

    /**
     * @brief calcualte the standard deviation for the dataset (weeks array)
     * 
     * @return double the standard deviation of the data in the weeks array
     */
    double Stdev() const;

    /**
     * @brief get the number of weeks in the weeks array
     * 
     * @return int the number of weeks in the array
     */
    int getNumberOfWeeks();

    /**
     * @brief check if a data point is an outlier
     * 
     * @param deathCount the number of deaths for a week
     * @return true if is an outlier in the dataset
     * @return false if not an outlier in the dataset
     */
    bool checkIfOutlier(int deathCount) const;
};

#endif