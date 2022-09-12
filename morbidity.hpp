#ifndef MORBIDITY_HPP
#define MORBIDITY_HPP

#include "state.hpp"
#include <sstream>
#include <fstream>

class Morbidity {

  std::ifstream input;
  std::stringstream dataStream;
  int numberOfStates;
  const int MAX_NUMBER_OF_STATES;
  bool validateInputFile;
  const int GetIndexForState(std::string);
  State** states;

  public:
    Morbidity();
    ~Morbidity();
    void LoadData();
    void ReadHeader();
    const double GetMean(std::string data);
    const int GetOutlier(std::string data);
    std::string* GetOutliers(std::string data);
    const bool HasValidInputFile();
    bool setInputFile(std::string filename);
    const std::string GetOutlierInfoForAllStates();
};

#endif