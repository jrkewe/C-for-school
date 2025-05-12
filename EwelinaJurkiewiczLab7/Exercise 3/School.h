#pragma once
#include <iostream>
#include <vector>
#include "Student.h"
using namespace std;

class School {
	vector<Student> students;
	string school_name;

public:
	//Konstruktor z nazwa szkoly
	School(string name) : school_name(name) {}

	//Metoda umozliwiajaca dodanie ucznia do szkoly. Metoda powinna przyjmowac obiekt klasy Student
	void addStudent(Student student);

	//Metoda usuwajaca ucznia na podstawie nazwiska
	void removeStudentBySecondname(string secondName);

	//Metoda usuwajaca ucznia na podstawie wieku
	void removeStudentBelowAge(int age);

	//Metoda wyswietlajaca wszystkich uczniow w szkole
	void showStudents();

	//Metoda wyswietlajaca nazwe szkoly
	void showSchool(); 

	//Metoda zwracajaca liczbe uczennic w szkole
	int getFemaleCount();

	//Metoda zwracajaca liczbe uczniow w szkole
	int getStudentCount();

	//Metoda zwracajaca srednia ocen wszystkich uczniow w szkole
	int getAverageGrade();

	//Metoda zwracajaca ucznia z najwyzsza srednia ocen
	Student getTopStudent();
};