#ifndef studentgroup_h
#define studentgroup_h

#include "pch.h"
#include <stdio.h>
#include <algorithm>
#include <vector>
#include "Student.h"

using namespace std;

class StudentGroup
{
private:
	int groupNumber;
	vector<Student*> listOfStudents;
public:
	void addStudent(Student* student);
	Student* getStudentByName(string &name);
	void deleteStudent(Student* student);
	int getGroupNumber();
	void setGroupNumber(int groupNumber);
	vector<Student*> getListOfStudents();
	vector<Student*> getListOfStudentsSortedByGrades();
	StudentGroup(int number);
};
#endif 
