

#ifndef student_h
#define student_h

#include "pch.h"
#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

class Student
{
private:
    string name;
    int min_grade;
    vector<int> groupNumbers;
public:
  
    void addGroupNumber(int groupNumber);
    void deleteGroupNumber(int groupNumber);
    string getName();
    void setName(string name);
    void setMinGrade(int minGrade);
    int getGroupCount();
    int getMinGrade();
    const vector<int>& getGroupNumbers();
    Student(string name);
    Student();
};
#endif 
