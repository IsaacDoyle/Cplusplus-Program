// Isaac Doyle
// 06-23-24

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <utility>

using namespace std;

class itemFrequency {
private:
    string item;
    int itemFreq = 0;
    ifstream inFS;
    ofstream outFS;
    string currItem;

public:

    // Read text file and write to output file
    void BackUpFile() {
        inFS.open("CS210_Project_Three_Input_File.txt");
        outFS.open("frequency.txt");
        map<string, int> productFrequency;
        while (getline(inFS, item)) {
            ++productFrequency[item];
        }

        for (const auto& pair : productFrequency) {
            if (pair.second > 1) {
                outFS << pair.first << " " << pair.second << endl;
            }
        }
        inFS.close();
        outFS.close();
    }

    // Get user input for item and print frequency of item
    void FrequencyCounter() {
        inFS.open("CS210_Project_Three_Input_File.txt");
        cout << "Enter an item: " << endl;
        cin >> item;
        while (!inFS.eof()) {
            inFS >> currItem;
            if (!inFS.fail()) {
                if (currItem == item) {
                    ++itemFreq;
                }
            }
        }
        cout << item << ": " << itemFreq << endl;
        inFS.close();
    }

    // Print frequency list
    void FrequencyList() {
        inFS.open("CS210_Project_Three_Input_File.txt");
        map<string, int> productFrequency;
        while (getline(inFS, item)) {
            ++productFrequency[item];
        }
        for (const auto& pair : productFrequency) {
            if (pair.second > 1) {
                cout << pair.first << " " << pair.second << endl;
            }
        }
        inFS.close();
    }

    // Print histogram
    void FrequencyHistgram() {
        inFS.open("CS210_Project_Three_Input_File.txt");
        map<string, int> productFrequency;
        while (getline(inFS, item)) {
            ++productFrequency[item];
        }
        for (const auto& pair : productFrequency) {
            cout << pair.first;
            for (int i = 0; i < pair.second; i++) {
                cout << "*";
            }
            cout << endl;
        }
        inFS.close();
    }

};


int main() {
    itemFrequency file;
    file.BackUpFile();

    itemFrequency counter;
    itemFrequency list;
    itemFrequency histogram;

    int choice;

    // Menu loop
    while (true) { 
        cout << "Menu Options:" << endl;
        cout << "1. Search for item frequency" << endl;
        cout << "2. Print frequency list" << endl;
        cout << "3. Print histogram" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << endl;
            counter.FrequencyCounter();  
            cout << endl;
        }
            break;
        case 2: {
            cout << endl;
            list.FrequencyList();
            cout << endl;
        }
            break;
        case 3: {
            cout << endl;
            histogram.FrequencyHistgram();
            cout << endl;
        }
            break;
        case 4:
            return 0;
        default:
            cout << endl;
            cout << "Invalid choice. Please try again." << endl;
            cout << endl;
        }
    }
}