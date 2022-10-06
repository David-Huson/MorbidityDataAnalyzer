/**************************************
 * @file week-data.hpp
 * @author David Huson(dph14@students.uwf.edu)
 * @brief decleres the week data class
 * @date 2022-09-13
**************************************/
#ifndef WEEK_DATA_HPP
#define WEEK_DATA_HPP

#include <ostream>

/**
 * @brief 
 * 
 */
class WeekData{
  /**
   * @brief the date that the week starts
   * 
   */
  std::string date;
  
  /**
   * @brief the number of deaths due to all causes
   * 
   */
  int allCauses;

  public:
  /**
   * @brief Construct a new empty Week Data object
   */
    WeekData();

    /**
     * @brief Construct a new Week Data object with a start date
     *
     * @param date the date the week starts on
     */
    WeekData(std::string date);

    /**
     * @brief Get the week start date
     * 
     * @return std::string the week start date
     */
    std::string GetDate() const;

    /**
     * @brief Get the number of deaths for the week
     * 
     * @return int the number of deaths in that week
     */
    int GetDeathCount() const;
    
    /**
     * @brief 
     * 
     * @param out the formatted week data string
     * @param week the week data to format and output
     * @return std::ostream& the output stream for the data string
     */
    friend std::ostream& operator << (std::ostream& out, const WeekData& week);
};

#endif