#include "morbidity.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

void printMenu() {
	cout << "\t1 - Output the mean for a state\n\t2 - Get a list of outliers for a state\n\t3 - List all states with statistically significant data points anything other than 1-3 will end the application.\n\tPlease choose an option from the above menu: ";
}

void printSpacer() {
	for(int i = 0; i < 75; ++i)
		cout << "-";
	cout << endl;
}

void printAllOutliers(string allOutliers) {
	printSpacer();
	cout << "All Outliers:" << endl;
	printSpacer();
	cout << allOutliers;
	printSpacer();
}

void printOutliers(Morbidity& data, string& state) {
	string* outliers = data.GetOutliers(state);
	int numOutliers = data.GetOutlierCount(state);
	printSpacer();
	cout << state << " outliers:"<< endl;
	printSpacer();
	for(int i = 0; i < numOutliers; ++i)
		cout << outliers[i] << endl;
	printSpacer();
}

void start(Morbidity& data) {
	int choice;
	bool isValidChoice = true;
	while (isValidChoice){
		printMenu();
		cin >> choice;
		string state;

		switch(choice) {
			// Output the mean for a state
			case 1:
				cout << choice << endl;
				while (true) {
					getline(cin, state);
					if(!state.empty())
						break;
				}

				printSpacer();
				cout << "The mean deaths for Texas is " ;
				cout << fixed << setprecision(2) << data.GetMean(state) << endl;
				printSpacer();
				break;

			// Get a list of outliers for a state
			case 2:
				cout << choice << endl;
				while (true) {
					getline(cin, state);
					if(!state.empty())
						break;
				}

				printOutliers(data, state);
				break;

			// List all states with statistically significant data points
			case 3:
				cout << choice << endl;
				printAllOutliers(data.GetOutlierInfoForAllStates());
				break;
			default:
				cout << choice << endl;
				isValidChoice = false;
				break;
		}

	}

}

void getInputFile(Morbidity& data) {
	string fileName = "";
	cout << "Welcome to the somber data viewer. Enter the file name with the morbidity data: ";
	cin >> fileName;
	cout << fileName << endl;

	while(!data.SetInputFile(fileName)) {
		cout << "Unable to read input file!" << endl;
		cout << "Enter the file name with the morbidity data: ";
		getline(cin, fileName);
		cout << fileName << endl;
	} 
}

void end() {
	cout << "Goodbye!" << endl;
	exit(0);
}

int main() {
	Morbidity morbidityData;

	getInputFile(morbidityData);
	morbidityData.LoadData();
	start(morbidityData);
	end();

	return 0;
}