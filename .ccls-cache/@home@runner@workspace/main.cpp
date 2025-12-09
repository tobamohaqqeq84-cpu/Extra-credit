//Toba Mohaqqeq 
//Extra credit 
//COMSC-210

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <iomanip>

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

    for (const auto &entry : movieRatings){
        cout << entry.first << " ";
        int sum = 0;
        for (int r : entry.second){
            cout << r << " ";
            sum += r;
        }
        double average = static_cast<double>(sum) / entry.second.size();
        cout << "Average = " << fixed << setprecision(2) << average << endl;
    }
    cout << "\nTotal number of movies: " << movieRatings.size() << endl;
    return 0;
}//milestone 1