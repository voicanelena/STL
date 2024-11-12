#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector < pair < string, string >>vec1;
vector < pair < string, string >>vec2;



int main()
{
    ifstream inFile("input.txt");

    int no_problems, no_doctors;
    string name, speciality;

    inFile >> no_problems;

    for (int i = 0; i < no_problems; i++)
    {
        inFile >> name;
        inFile >> speciality;
        vec1.push_back(make_pair(name, speciality));
    }

    inFile >> no_doctors;

    for (int i = 0; i < no_doctors; i++)
    {
        inFile >> name;
        inFile >> speciality;
        vec2.push_back(make_pair(name, speciality));
    }
    
    for (auto problem= begin(vec1);  problem!= end(vec1); problem++) {
        auto doctor = find_if(vec2.begin(), vec2.end(), [=](pair<string, string>n) {return problem->second == n.second; });
        
        if (doctor != vec2.end()){
            cout << doctor->first << " " << problem->first << '\n';
            vec2.erase(doctor);
        }
   
    }


    return 0;
}