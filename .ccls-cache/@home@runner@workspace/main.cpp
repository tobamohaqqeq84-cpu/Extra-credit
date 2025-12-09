//Toba Mohaqqeq ʕ•ᴥ•ʔ
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
    map<string, vector<int>> movieRatings; //map to store movie ratings

    ifstream inFile("210-xc2-FA25.txt"); //open the file
    if (!inFile){
        cout << "Error opening file." << endl; 
        return 1;
    }
    string line;
    int ratings;

    while (inFile >> line >> ratings){
        movieRatings[line].push_back(ratings); //add the rating to the vector of ratings for the movie
        
    }
    //Milestone 1: 
    cout << "💫 Milestone 1: Movie ratings 💫" << endl;
    for (const auto &entry : movieRatings){
        cout << entry.first << " ";
        for (int r : entry.second){
            cout << r << " ";
        }
        cout << endl;
    }
    cout << endl;

    //Milestone 2:
cout << "💫 Milestone 2: Averages 💫" << endl;
    
    for (const auto &entry : movieRatings){
        cout << entry.first << " ";
        int sum = 0;
        for (int r : entry.second){
            cout << r << " ";
            sum += r;
        }
        double average = static_cast<double>(sum) / entry.second.size(); //calculate the average rating
        cout << "Average = " << fixed << setprecision(2) << average << endl;
    }
    cout << "\nTotal number of movies: " << movieRatings.size() << endl;
cout << endl;
    
    //Milestone 3:
    cout << "💫 Milestone 3: Best rated 💫" << endl;
    
    double bestAverage = 0.0;

    for (const auto &entry : movieRatings){
        int sum = 0;
        for (int r : entry.second){
            sum += r;
        }
        double average = static_cast<double>(sum) / entry.second.size();
        if (average > bestAverage){
          
            bestAverage = average;
        }
    }
    cout << "Best average rating: " << fixed << setprecision(2) << bestAverage << endl;
    cout << "Movies with this rating: ";

    for (const auto &entry : movieRatings){
        int sum = 0;
        for (int r : entry.second){
            sum += r;
        }
        double average =static_cast<double>(sum)/entry.second.size();
        if (average == bestAverage){
            cout << entry.first << endl;
        } 
    }
    return 0;
}
//I hope this assignment helps me geet a good grade.⛄(˶˃ ᵕ ˂˶)
