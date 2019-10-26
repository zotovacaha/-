#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <locale>
#include <ctime>
#include "student.h"
#include "studentGroup.h"
#include "windows.h"
using namespace std;

void printStudentsToFile(vector<Student*> ListOfStudents, int groupNumber);

int main(int argc, const char * argv[]) {

	setlocale(LC_ALL, "Russian");
        srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Student* listOfAllStudents[10];
	StudentGroup* listOfAllGroups[5];
	string names[10] = { "Иванов Иван Иванович",
		"Смирнов Игорь Вадимович",
		"Кузнецов Семен Алексеевич",
		"Ахматова Анна Александровна",
		"Соловьева Елена Петровна",
		"Козлова Татьяна Станиславовна",
		"Васнецов Станислав Григорьевич",
		"Воробьев Григорий Вячеславович",
		"Архипова Инна Дмитриевна",
		"Журавлева Анастасия Викторовна"
	};
	int groups[5] = { 111,222,333,444,555 };
	for (int i = 0; i < 10; i++)
	{
		Student* student = new Student(names[i]);
		listOfAllStudents[i] = student;
	}
	for (int i = 0; i < 5; i++)
	{
		StudentGroup* studentGroup = new StudentGroup(groups[i]);
		listOfAllGroups[i] = studentGroup;
	}
	cout << "Список всех студентов: " << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << i + 1 << "." << listOfAllStudents[i]->getName() << endl;
	}
	for (int i = 0; i < 10; i++)
	{
		int indGroup = rand() % 5;
		int indStud = rand() % 10;
		//cout<<indStud<<"----"<<endl;
	   //listOfAllGroups[indGroup]->addStudent(listOfAllStudents[i]);
		listOfAllGroups[indGroup]->addStudent(listOfAllStudents[indStud]);

	}
	// listOfAllGroups[0]->addStudent(listOfAllStudents[0]);
	cout << "Группы были заполнены студентами." << endl;
	//Вывод в ostream
	filebuf fb;
	fb.open("test.txt", ios::out);
	ostream os(&fb);
	for (int i = 0; i < 5; i++)
	{
		//Отсортирован по возрастанию минимальной оценки
		vector<Student*> tempVector = listOfAllGroups[i]->getListOfStudentsSortedByGrades();
		if (tempVector.empty())
		{
			os << "В группе " << listOfAllGroups[i]->getGroupNumber() << " нет студентов." << endl;
		}
		else {
			os << "Студенты группы " << listOfAllGroups[i]->getGroupNumber() << ":" << endl;
			for (int i = 0; i < tempVector.size(); i++)
			{
				os << i + 1 << "." << tempVector[i]->getName() << endl << "Минимальная оценка: " << tempVector[i]->getMinGrade() << endl << "Кол-во групп: ";
				os << tempVector[i]->getGroupCount() << endl << "Группы: ";
				for (int j = 0; j < tempVector[i]->getGroupCount(); j++)
				{
					os << tempVector[i]->getGroupNumbers()[j] << " ";
				}
				os << endl;
			}
		}
	}
	fb.close();
	cout << "Список студентов всех групп был выведен в файл." << endl;
	cout << "Список групп: ";
	for (int i = 0; i < 5; i++)
	{
		cout << listOfAllGroups[i]->getGroupNumber() << ", ";
	}
	while (true) {
		cout << endl << "Введите номер группы для вывода студентов: " << endl;
		cout << "Для завершения работы введите '0'" << endl;
		int inputGroup;
		cin >> inputGroup;
		if (inputGroup == 0)
		{
			break;
		}
		int tempGroupInd = 0;
		while (tempGroupInd < 5)
		{
			if (listOfAllGroups[tempGroupInd]->getGroupNumber() == inputGroup) {
				break;
			}
			tempGroupInd++;
		}
		if (tempGroupInd == 5)
		{
			cout << "Неверный номер группы.";
			continue;
		}
		else
		{
			vector<Student*> tempStudents = listOfAllGroups[tempGroupInd]->getListOfStudents();
			if (tempStudents.empty())
			{
				cout << "В данной группе нет студентов" << endl;
				continue;
			}
			for (int i = 0; i < tempStudents.size(); i++)
			{
				cout << i + 1 << "." << tempStudents[i]->getName() << endl;
			}
		}
		cout << "Введите ФИО студента, которого вы хотите удалить из группы: " << endl;
		cout << "Либо введите '0' для возврата." << endl;
		string strNameInput;
		cin.ignore();
		getline(cin, strNameInput);
		if (strNameInput == "0")
		{
			continue;
		}
		cout << strNameInput << endl;
		//Получение студента группы по ФИО
		for (int i = 0; i < 10; i++)
		{
			if (strNameInput == names[i])
			{
				listOfAllGroups[tempGroupInd]->deleteStudent(listOfAllGroups[tempGroupInd]->getStudentByName(strNameInput));
				cout << "Студент был удален из группы" << endl;
				break;
			}
			if (i == 9)
			{
				cout << "Неверно введено имя студента." << endl;;
			}
		}
	}
	return 0;
}


