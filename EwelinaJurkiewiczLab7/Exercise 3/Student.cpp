#pragma once
#include <iostream>
#include "Student.h"
using namespace std;

//Metoda void show() — wyswietla dane ucznia (imie, nazwisko, wiek, plec, srednia ocen)
void Student::show(){
	cout << "Name: " << name << ", Surname: " << surname << ", Age: " << age
		<< ", Gender: " << gender << ", Grade: " << grade << "." << endl;
}

//Getter pole name
string Student::getName() {
	return name;
}

//Getter pole surname
string Student::getSurname() const {
	return surname;
}

//Getter pole age
int Student::getAge() const {
	return age;
}

//Getter pole gender
char Student::getGender() {
	return gender;
}

//Getter pole grade
float Student::getGrade() {
	return grade;
}