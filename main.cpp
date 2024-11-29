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

    Problem(string& name, string& speciality, int necessary_time,int severity) {
        this->name = name;
        this->speciality = speciality;
        this->necessary_time = necessary_time;
        this->severity = severity;
    }

    bool operator<(Problem const other)const {
        return this->severity < other.severity;
    }
};

struct Doctor {
    string name;
    string speciality;
    int time;

    vector<Problem>problems;

    //ca sa asignam din declarare
    Doctor(string& name, string& speciality, int time) {
        this->name = name;
        this->speciality = speciality;
        this->time = time;
    }

};

priority_queue <Problem>vec1;
vector <Doctor>vec2;

int main()
{
    ifstream inFile("input.txt");

    int no_problems, no_doctors,time,severity;
    string name, speciality;
    
    inFile >> no_problems;

    for (int i = 0; i < no_problems; i++)
    {
        inFile >> name;
        inFile >> speciality;
        inFile >> time;
        inFile >> severity;
        vec1.push(Problem(name,speciality,time,severity));
    }

    inFile >> no_doctors;

    for (int i = 0; i < no_doctors; i++)
    {
        inFile >> name;
        inFile >> speciality;
        vec2.push_back(Doctor(name,speciality,8));
    }
    
    while(!vec1.empty()) {
        auto problem = vec1.top();
        vec1.pop();
        auto doctor = find_if(vec2.begin(), vec2.end(), [=](Doctor current) {
            return problem.speciality == current.speciality && problem.necessary_time <= current.time;});
        
        if (doctor != vec2.end()){
            doctor->time -= problem.necessary_time;
            doctor->problems.push_back(problem);
        }
   
    }

    for (int i = 0; i < no_doctors; i++) {
        cout << vec2[i].name << " " << vec2[i].problems.size() << " ";
        for (auto problem : vec2[i].problems) {
            cout << problem.name << " ";
        }
        cout << endl;
    }
  
    return 0;
}