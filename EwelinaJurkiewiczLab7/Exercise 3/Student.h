#pragma once
#include <iostream>
using namespace std;

class Student {
	string name;
	string surname;
	int age;
	char gender;
	float grade;

public:
	//Konstruktor bezargumentowy;
	Student() {};

	//Lista inicjalizacyjna konstruktora
	Student(string firstName, string secondName, int years, char sex, float mark)
		: name(firstName), surname(secondName), age(years), gender(sex), grade(mark) {}

	//Metoda void show() — wyswietla dane ucznia (imie, nazwisko, wiek, plec, srednia ocen)
	void show();

	//Getter pole name
	string getName();

	//Getter pole surname
	string getSurname() const;

	//Getter pole age
	int getAge() const;

	//Getter pole gender
	char getGender();

	//Getter pole grade
	float getGrade();
};