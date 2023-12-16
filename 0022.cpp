#include<iostream>
#include<fstream>
#include<string>
#include<set>

using namespace std;

int main()
{
    ifstream iFile("G:/PersonalProjects/project-euler-archives-cpp/0022_names.txt");

    if(!iFile.is_open())
    {
        cerr<<"File is not opened";
        return 1;
    }

    string name;
    set<string> nameSet;
    while(getline(iFile, name, ','))
    {
        nameSet.insert(name.substr(1, name.size()-2));
    }
    
    iFile.close();

    int multiplier = 1;
    int totalSum = 0;
    for(string name: nameSet)
    {
        int sum = 0;
        for(char c: name) sum += (c-'A')+1;
        totalSum += multiplier * sum;
        multiplier++;        
    }

    cout<<totalSum;
    
    return 0;
}