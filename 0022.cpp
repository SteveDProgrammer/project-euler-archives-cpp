#include<iostream>
#include<fstream>
#include <string>
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
    while(getline(iFile, name, ','))
    {
        cout<<name<<endl;
    }

    iFile.close();
    return 0;
}