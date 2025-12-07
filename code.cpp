#include <iostream>
#include <fstream>
#include <map>
#include <list>
using namespace std;

int gen_hash_index(string);
void display(map <int, list<string>>);

int main() {
    map <int, list<string>> hash_table;

    //File open
	ifstream file;
	file.open("data.txt");
	if (!file.is_open()) {
	    cout << "Failed to open file" << endl;
	    return 1;
	}
    //File Populating
    string line;
    while (file >> line) {
        int hashindex = gen_hash_index(line);
        hash_table[hashindex].push_back(line);
    }
    
    return 0;
}
/*
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/

int gen_hash_index(string str) {
    int sum = 0;
    for (char c : str) {
        sum += (int) c;
    }
    return sum;
}

void display(map <int, list<string>> data, int numOfEntries) {
    int count = 1;
    for (auto pair : data) { //Loops through each map data
        cout << "Hash index: " << pair.first; 
        for (auto value : pair.second) { //Loops through the list

        }

        if (count == numOfEntries)
            return;
        count++;
    }
    cout << endl;
}