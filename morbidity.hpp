/*********************************************************************
 * @file morbidity.hpp
 * @author David Huson(dph14@students.uwf.edu)
 * @brief a class to provide classes for the
 *        computation of the mean and population standard deviation
 * @date 2022-09-13
**********************************************************************/
#ifndef MORBIDITY_HPP
#define MORBIDITY_HPP

#include "state.hpp"
#include <sstream>
#include <fstream>

/**
 * @brief a class to collect morbidity data for several states and do statistical analysis on that data
 */
class Morbidity {

  /**
   * @brief the input stream to get data from
   */
  std::ifstream input;

  /**
   * @brief the number of states in the states array
   * 
   */
  int numberOfStates;

  /**
   * @brief the max number of states in the states array
   * 
   */
  const int MAX_NUMBER_OF_STATES = 65;

  /**
   * @brief true only if the input file was able to be opened
   * 
   */
  bool validInputFile;

  /**
   * @brief the array of stats with morbidity data
   * 
   */
  State** states;

  /**
   * @brief return the index of teh state in the states array
   * 
   * @param state the state to search for in the states array
   * @return int the index of the state in the array
   */
  int GetIndexForState(std::string state) const;

  public:
    /**
     * @brief Construct a new Morbidity object
     */
    Morbidity();

    /**
     * @brief Destroy the Morbidity object and free its dynamically allocated memory
     */
    ~Morbidity();

    /**
     * @brief try to open the given file
     * 
     * @param filename the file to open
     * @return true if opened successfully
     * @return false if could not open
     */
    bool SetInputFile(std::string filename);

    /**
     * @brief Load the data from the given data file
     * 
     */
    void LoadData();

    /**
     * @brief Get the Mean of the morbidity data for the given state
     * 
     * @param state the state to getthe mean data for
     * @return double the mean of the state morbidity data
     */
    double GetMean(std::string state) const;

    /**
     * @brief Get the number of outliers in the state data
     * 
     * @param state the state to check for outliers
     * @return int the number of outliers in the state data
     */
    int GetOutlierCount(std::string state) const;

    /**
     * @brief Get the outliers from the state data
     * 
     * @param state the state to find outliers for
     * @return std::string* the array of strings representing the outliers in the data for state
     */
    std::string* GetOutliers(std::string state);

    /**
     * @brief Get the outliers from all states in the states array
     * 
     * @return std::string the array of outliers from all states
     */
    std::string GetOutlierInfoForAllStates() const;
};

#endif