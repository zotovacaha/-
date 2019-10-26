#include "pch.h"
#include "Student.h"
Student::Student(string name)
{
	
	this->name = name;
	this->min_grade = rand() % (5 - 2 + 1) + 2;
}
Student::Student()
{
	
	this->name = "";
	this->min_grade = 0;
}

void Student::addGroupNumber(int groupNumber)
{
	groupNumbers.push_back(groupNumber);
}
void Student::deleteGroupNumber(int groupNumber)
{
	vector<int>::iterator position = find(groupNumbers.begin(), groupNumbers.end(), groupNumber);
	if (position != groupNumbers.end()) {
		groupNumbers.erase(position);
	}
}

//GETTERS
string Student::getName()
{
	return this->name;
}
int Student::getMinGrade()
{
	return this->min_grade;
}
int Student::getGroupCount()
{
	return this->groupNumbers.size();
}
const vector<int>& Student::getGroupNumbers()
{
	return this->groupNumbers;
}

//SETTERS
void Student::setName(string name)
{
	this->name = name;
}
void Student::setMinGrade(int minGrade)
{
	this->min_grade = minGrade;
}
