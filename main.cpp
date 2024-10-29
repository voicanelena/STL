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

    for (auto index1 = begin(vec1); index1 != end(vec1); index1++) {
        bool accepted = false;
        for (auto index2 = begin(vec2); index2 != end(vec2); index2++) {
            if ((*index1).second == (*index2).second)
                accepted = true;


        }
        if (accepted == true)
            cout << (*index1).first << " " << "Acceptat" << endl;
        else
            cout << (*index1).first << " " << "Respins" << endl;
    }

    return 0;
}