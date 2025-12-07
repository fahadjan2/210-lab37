// COMSC-210 | Lab 37 | Fahad Fawad Ahmad 
// IDE used: Visual Studio
#include <iostream>
#include <fstream>
#include <map>
#include <list>
using namespace std;

const int NUM_DISPLAY = 100;

int gen_hash_index(string);
void display(map <int, list<string>>&, int);

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
    
    display(hash_table, NUM_DISPLAY);
    return 0;
}

int gen_hash_index(string str) {
    int sum = 0;
    for (char c : str) {
        sum += (int) c;
    }
    return sum;
}

void display(map <int, list<string>> &data, int numOfEntries) {
    int count = 0;
    for (auto pair : data) { //Loops through each map data
        if (count == numOfEntries) {
            cout << "End" << endl;
            break;
        }
        count++;
        
        cout << "Hash index: " << pair.first << endl; 
        for (auto value : pair.second) { //Loops through the list
            cout << "\t" << value << endl;
        }
    }

    cout << endl;
}