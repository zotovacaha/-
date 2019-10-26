#include "pch.h"
#include "student.h"
Student::Student(string name)
{
	this->groupCount = 0;
	this->name = name;
	this->min_grade = rand() % (5 - 2 + 1) + 2;
}
Student::Student()
{
	this->groupCount = 0;
	this->name = "";
	this->min_grade = 0;
}
void Student::increaseGroupCount()
{
	this->groupCount += 1;
}
void Student::decreaseGroupCount()
{
	this->groupCount -= 1;
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
	return this->groupCount;
}
vector<int> Student::getGroupNumbers()
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
