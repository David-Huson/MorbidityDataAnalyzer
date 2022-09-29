#include "morbidity.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

void printMenu() {
	cout << "Enter the file name with the morbidity data: data.csv\n1 - Output the mean for a state\n2 - Get a list of outliers for a state\n3 - List all states with statistically significant data points anything other than 1-3 will end the application.\nPlease choose an option from the above menu: ";
}

void printSpacer() {
	for(int i = 0; i < 75; ++i)
		cout << "-";
	cout << endl;
}

int main() {
	string fileName = "";
	Morbidity morbidityData;
	cout << "Welcome to the somber data viewer. Enter the file name with the morbidity data: ";
	cin >> fileName;
	cout << endl;

	while(!morbidityData.SetInputFile(fileName)) {
		ifstream input(fileName);
		cout << "Unable to read input file!" << endl;
		cout << "Enter the file name with the morbidity data: ";
		getline(cin, fileName);
		cout << endl;
	} 

	morbidityData.LoadData();
	// cout << "success" << endl;


	char choice;
	bool isValidChoice = true;
	while (isValidChoice){
		printMenu();
		cin >> choice;
		string state;

		switch(choice) {
			case '1':
				cout << choice << endl;
				while (true) {
					getline(cin, state);
					if(!state.empty())
						break;
				}

			printSpacer();
			cout << "The mean deaths for Texas is 4" ;
			cout << fixed << setprecision(2) << morbidityData.GetMean(state) << endl;
			printSpacer();

			break;
			case '2':
				cout << choice << endl;
				break;
			case '3':
				cout << choice << endl;
				break;
			default:
				isValidChoice = false;
				break;
		}
	}

	return 0;
}