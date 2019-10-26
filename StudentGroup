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
			student->increaseGroupCount();
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
		student->decreaseGroupCount();
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
Student* StudentGroup::getStudentByName(string name)
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
	Student* tempStudent = new Student();
	//BUBBLE SORT
	if (listOfStudents.empty())
	{
		cout << "В группе " << this->groupNumber << "нет студентов." << endl;
		return tempVector;
	}
	else {
		for (int i = 0; i < tempVector.size() - 1; i++) {
			for (int j = 0; j < tempVector.size() - i - 1; j++) {
				if (tempVector[j]->getMinGrade() > tempVector[j + 1]->getMinGrade()) {
					tempStudent = tempVector[j];
					tempVector[j] = tempVector[j + 1];
					tempVector[j + 1] = tempStudent;
				}
			}
		}
		//BUBBLE SORT
		return tempVector;
	}
}



