#pragma once

#ifndef studentGroup_h
#define studentGroup_h

#include "pch.h"
#include <stdio.h>
#include <vector>
#include "student.h"

using namespace std;

class StudentGroup
{
private:
	int groupNumber;
	vector<Student*> listOfStudents;
public:
	void addStudent(Student* student);
	Student* getStudentByName(string name);
	void deleteStudent(Student* student);
	int getGroupNumber();
	void setGroupNumber(int groupNumber);
	vector<Student*> getListOfStudents();
	vector<Student*> getListOfStudentsSortedByGrades();
	StudentGroup(int number);
};
#endif /* studentGroup_h */
