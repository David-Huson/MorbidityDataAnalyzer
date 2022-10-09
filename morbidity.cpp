/*********************************************************************
 * @file morbidity.cpp
 * @author David Huson(dph14@students.uwf.edu)
 * @brief a class to interpret and save weekly morbidity data for any state
 * @date 2022-09-13
**********************************************************************/
#include "morbidity.hpp"
#include <iostream>

Morbidity::Morbidity() {
  validInputFile = false;
  numberOfStates = 0;
  states = new State*[MAX_NUMBER_OF_STATES];
}

Morbidity::~Morbidity(){
  // delete each state in the states array
  for(int i = 0; i < numberOfStates; ++i)
    delete states[i];

  //delete the states array
  delete [] states;
}

bool Morbidity::SetInputFile(std::string filename){
    // try to open the file
    input.open(filename);
    if(input.is_open()){
      validInputFile = true;
    } else {
      validInputFile = false;
    }
    return validInputFile;
}

void Morbidity::LoadData(){
      std::string line = "";
      std::string name = "";
      std::string weekData = "";
      bool inStates = false;

      getline(input, line, '\n');     // read header (1st line of file)

      // keep reading the file while until we've reached the end of the file
      while(!input.eof()) {
        inStates = false;
        // get the next line in the file
        getline(input, line, '\n');
        // find the next comma or newline
        int delimIndex = line.find_first_of(",\n");

        // separate the states name form the rest of the data
        name = line.substr(0, delimIndex);
        // separate the week and deaths data from the name
        weekData = line.substr(delimIndex+1);

        // if there are at least 1 states in the array, check if the current state is in the states array
        if(numberOfStates > 0){
          for(int i = 0; i < numberOfStates; ++i) {
            // check if the state is in the states array, if true -> add week data to array
            if(states[i]->GetName() == name) {
              states[i]->AddWeek(weekData);
              inStates = true;
              break;
            }
          }
        }

        // if the current state is not in the states array AND the name is not empty, 
        // add the state to the array and add the week data to the state object
        if(!inStates && !name.empty()) {
          states[numberOfStates] = new State(name);
          states[numberOfStates]->AddWeek(weekData);
          numberOfStates++;
        }
      }
      input.close();
}

int Morbidity::GetIndexForState(std::string state) const{
  // loop through the states in the array
  for(int i = 0; i < numberOfStates; ++i) {
    // if the state exists in the array
    if(states[i]->GetName() == state){
      return i; // return the state index
    }
  }
  return -1; // return -1 if state not found
}

double Morbidity::GetMean(std::string state) const {
  // get the index for the state in the states array
  int stateIndex = GetIndexForState(state);
  // if the state was found
  if(stateIndex >= 0)
    return (states[stateIndex]->GetMeanDeaths()); // calculate the mean deaths for that state
  else
    return -1.0;  // return -1 if the state was not found
}

int Morbidity::GetOutlierCount(std::string state) const {
  // get the index for the state in the states array
  int stateIndex = GetIndexForState(state);
  // if the state was found in the array
  if(stateIndex >= 0){
    return (states[stateIndex]->GetOutlierCount());   // calculate the number of outliers in the array
    }
  else
    return -1;    // return -1 if state was not found
}

std::string* Morbidity::GetOutliers(std::string state) {
  // get the index for the state in the states array
  int stateIndex = GetIndexForState(state);
  // if the state was not found
  if(stateIndex == -1)
    return nullptr;   // return a null pointer
  else
    return (states[stateIndex]->GetOutliers()); // return the outliers for the states
}

std::string Morbidity::GetOutlierInfoForAllStates() const {
  std::string allOutliers = "";
  // loop through the states in the states array
  for(int i = 0; i < numberOfStates; ++i) {
    // add the outliers for the state to the allOutliers string
    allOutliers += states[i]->GetName() + ": " + std::to_string(states[i]->GetOutlierCount()) + " outlying weeks\n";
  }
  return allOutliers;
}
