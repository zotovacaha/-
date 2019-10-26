#include "pch.h"
#include "studentGroup.h"

StudentGroup::StudentGroup(int number)
{
	this->groupNumber = number;
}

void StudentGroup::addStudent(Student* student)
{
	if (listOfStudents.size() < 20) {
		if (find(listOfStudents.begin(), listOfStudents.end(), student) != listOfStudents.end()) {
			cout << "Данный студент уже находится в группе" << endl;
		}
		else {
			listOfStudents.push_back(student);
			student->addGroupNumber(this->groupNumber);
		}
	}
	else {
		cout << "В группе не может быть больше 20 студентов" << endl;
	}
}
void StudentGroup::deleteStudent(Student* student)
{
	vector<Student*>::iterator position = find(listOfStudents.begin(), listOfStudents.end(), student);
	if (position != listOfStudents.end()) {
		student->deleteGroupNumber(this->groupNumber);
		listOfStudents.erase(position);
	}
	else
		cout << "Студент не найден" << endl;
}
//GETTERS
int StudentGroup::getGroupNumber()
{
	return this->groupNumber;
}
void StudentGroup::setGroupNumber(int groupNumber)
{
	this->groupNumber = groupNumber;
}
Student* StudentGroup::getStudentByName(string& name)
{
	int i = 0;
	for (i = 0; listOfStudents.size(); i++)
	{
		if (listOfStudents[i]->getName() == name) {
			return listOfStudents[i];
		}
	}
	return nullptr;
}
vector<Student*> StudentGroup::getListOfStudents()
{
	return listOfStudents;
}
vector<Student*> StudentGroup::getListOfStudentsSortedByGrades()
{
	vector<Student*> tempVector = listOfStudents;
	//SORT
	if (listOfStudents.empty())
	{
		cout << "В группе " << this->groupNumber << "нет студентов." << endl;
		return tempVector;
	}
	else {
		sort(tempVector.begin(), tempVector.end(), [](Student* a, Student* b)
		{
			return a->getMinGrade() < b->getMinGrade();
		});
	}

	return tempVector;
}



