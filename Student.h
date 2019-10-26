#pragma once

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
	int groupCount;
	vector<int> groupNumbers;
public:
	void increaseGroupCount();
	void decreaseGroupCount();
	void addGroupNumber(int groupNumber);
	void deleteGroupNumber(int groupNumber);
	string getName();
	void setName(string name);
	void setMinGrade(int minGrade);
	int getGroupCount();
	int getMinGrade();
	vector<int> getGroupNumbers();
	Student(string name);
	Student();
};
#endif /* student_h */
