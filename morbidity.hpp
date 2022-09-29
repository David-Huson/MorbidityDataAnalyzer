#ifndef MORBIDITY_HPP
#define MORBIDITY_HPP

#include "state.hpp"
#include <sstream>
#include <fstream>

class Morbidity {

  std::ifstream input;
  std::stringstream dataStream;
  int numberOfStates;
  const int MAX_NUMBER_OF_STATES = 65;
  bool validInputFile;
  State** states;
  int GetIndexForState(std::string state) const;

  public:
    Morbidity();
    ~Morbidity();
    void LoadData();
    double GetMean(std::string state) const;
    int GetOutlierCount(std::string state) const;
    std::string* GetOutliers(std::string state);
    bool SetInputFile(std::string filename);
    std::string GetOutlierInfoForAllStates() const;
};

#endif