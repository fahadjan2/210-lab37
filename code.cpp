#include <iostream>
#include <fstream>
using namespace std;

int sum_ascii(string);

int main() {
    int sum = 0;
    //File open
	ifstream file;
	file.open("data.txt");
	if (!file.is_open()) {
	    cout << "Failed to open file" << endl;
	    return 1;
	}
    string line;
    while (file >> line) {
        sum += sum_ascii(line);
    }
    string c = "bazingalingaling";
    cout << sum_ascii(c) << endl; 
    cout << "SUM: " << sum << endl;
    
    
    return 0;
}
/*
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/

int sum_ascii(string str) {
    int sum = 0;
    for (char c : str) {
        sum += (int) c;
    }
    return sum;
}