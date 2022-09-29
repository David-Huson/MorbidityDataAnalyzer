#include "morbidity.hpp"
#include <iostream>

Morbidity::Morbidity() {
  validInputFile = false;
  numberOfStates = 0;
  states = new State*[MAX_NUMBER_OF_STATES];
  validInputFile = false;
}

Morbidity::~Morbidity(){
  for(int i = 0; i < numberOfStates; ++i)
    delete states[i];
  delete [] states;
}

bool Morbidity::SetInputFile(std::string filename){
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

      getline(input, line, '\n');     // read header
      while(!input.eof()) {
        inStates = false;
        getline(input, line, '\n');
        int delimIndex = line.find_first_of(",\n");

        name = line.substr(0, delimIndex);
        weekData = line.substr(delimIndex+1);

        if(numberOfStates > 0){
          for(int i = 0; i < numberOfStates; ++i) {
            if(states[i]->GetName() == name) {
              // std::cout << "Adding week :" << weekData << " to state: " << name << std::endl;  
              states[i]->AddWeek(weekData);
              inStates = true;
              break;
            }
          }

        }

        if(!inStates && !name.empty()) {
          // std::cout << "==> Adding state " << numberOfStates << ": " << name << " to states array." << std::endl;
          states[numberOfStates] = new State(name);
          states[numberOfStates]->AddWeek(weekData);
          numberOfStates++;
        }
      }
      input.close();

}

int Morbidity::GetIndexForState(std::string state) const{
  for(int i = 0; i < numberOfStates; ++i) {
    if(states[i]->GetName() == state){
      return i;
    }
  }
  return -1;
}

double Morbidity::GetMean(std::string state) const {
  int stateIndex = GetIndexForState(state);
  if(stateIndex >= 0)
    return (states[stateIndex]->GetMeanDeaths());
  else
    return -1.0;
}

int Morbidity::GetOutlierCount(std::string state) const {
  int stateIndex = GetIndexForState(state);
  if(stateIndex <= 0){
    return (states[stateIndex]->GetOutlierCount());
    }
  else
    return -1;
}

std::string* Morbidity::GetOutliers(std::string state) {
  int stateIndex = GetIndexForState(state);
  if(stateIndex == -1)
    return nullptr;
  else
    return (states[stateIndex]->GetOutliers());
}
std::string Morbidity::GetOutlierInfoForAllStates() const {
  std::string allOutliers = "";

  for(int i = 0; i < numberOfStates; ++i) {
    allOutliers += states[i]->GetName() + ": " + std::to_string(states[i]->GetOutlierCount()) + '\n';
  }

  // std::cout << allOutliers << std::endl;
  return allOutliers;
}
