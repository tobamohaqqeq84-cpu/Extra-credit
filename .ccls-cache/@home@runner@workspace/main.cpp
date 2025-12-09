//Toba Mohaqqeq 
//Extra credit 
//COMSC-210

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>

using namespace std;

int main(){
    map<string, vector<int>> movieRatings;

    ifstream inFile("210-xc2-FA25.txt");
    if (!inFile){
        cout << "Error opening file." << endl;
        return 1;
    }
    string line;
    int ratings;

    while (inFile >> line >> ratings){
        movieRatings[line].push_back(ratings);
    }
    for (const auto &entry : movieRatings){
        cout << entry.first << " ";
        for (int r : entry.second){
            cout << r << " ";
        }
        cout << endl;
    }
    return 0;
}