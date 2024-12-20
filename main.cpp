#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
using namespace std;



struct Problem {
    string name;
    string speciality;
    int necessary_time;
    int severity;
    int arrival_hour;

    Problem(string& name, string& speciality, int necessary_time,int severity,int arrival_hour) {
        this->name = name;
        this->speciality = speciality;
        this->necessary_time = necessary_time;
        this->severity = severity;
        this->arrival_hour = arrival_hour;
    }

    bool operator<(Problem const other)const {
        if (this->arrival_hour != other.arrival_hour)
            return this->arrival_hour > other.arrival_hour;

        return this->severity < other.severity;
    }
};

struct Doctor {
    string name;
    vector<string> specialities;
    int time;

    vector<Problem>problems;

    //ca sa asignam din declarare
    Doctor(string& name, vector<string>& specialities, int time) {
        this->name = name;
        this->specialities = specialities;
        this->time = time;
    }

};

priority_queue <Problem>vec1;
vector <Doctor>vec2;

int main()
{
    ifstream inFile("input2.txt");

    int no_problems, no_doctors,time,severity,arrival_hour,no_specialities;
    string name, speciality;
    
    inFile >> no_problems;

    for (int i = 0; i < no_problems; i++)
    {
        inFile >> name;
        inFile >> speciality;
        inFile >> arrival_hour;
        inFile >> time;
        inFile >> severity;
        vec1.push(Problem(name,speciality,time,severity,arrival_hour));
    }

    inFile >> no_doctors;

    for (int i = 0; i < no_doctors; i++)
    {
        inFile >> name;
        inFile >> no_specialities;

        vector<string>specialities;
        for (int i = 0; i < no_specialities; i++)
        {
            inFile >> speciality;
            specialities.push_back(speciality);
        }
        vec2.push_back(Doctor(name,specialities,8));
    }
    
    while(!vec1.empty()) {
        auto problem = vec1.top();
        vec1.pop();
        auto doctor = find_if(vec2.begin(), vec2.end(), [=](Doctor current) {
            bool has_speciality = false;
            for (string& current_speciality : current.specialities)
                if (current_speciality == problem.speciality)
                {
                    has_speciality = true;
                    break;
                }

            bool is_available = true;
            if (8 - current.time > problem.arrival_hour - 9)
                is_available = false;

            if (problem.necessary_time + problem.arrival_hour - 9 > 8)
                is_available = false;

            return has_speciality && is_available;
            });
        
        if (doctor != vec2.end()){
            doctor->time = 8 - (problem.arrival_hour - 9) - problem.necessary_time;
            doctor->problems.push_back(problem);
        }
   
    }

    for (int i = 0; i < no_doctors; i++) {
        cout << vec2[i].name << " " << vec2[i].problems.size() << " ";
        for (auto problem : vec2[i].problems) {
            cout << problem.name << " " << problem.arrival_hour << " ";
        }
        cout << endl;
    }
  
    return 0;
}