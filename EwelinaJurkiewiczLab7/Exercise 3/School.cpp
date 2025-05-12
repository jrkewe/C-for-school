#pragma once
#include <iostream>
#include <algorithm>
#include "Student.h"
#include "School.h"
using namespace std;

//Metoda umozliwiajaca dodanie ucznia do szkoly. Metoda powinna przyjmowac obiekt klasy Student
void School::addStudent(Student student){
	students.push_back(student);
}

//Metoda usuwajaca ucznia na podstawie nazwiska
void School::removeStudentBySecondname(string secondName){
 
    //Szukanie
    auto element = find_if(students.begin(), students.end(),
        [&secondName](const Student& student) {
            return student.getSurname() == secondName;
        });

    //Usuniecie
    if (element != students.end()) {
        cout << "Student " << element->getSurname() << " zostal usuniety." << endl;
        students.erase(element);
    }
    else {
        cout << "Nie znaleziono studenta do usuniecia." << endl;
    }
}

//Metoda usuwajaca ucznia na podstawie wieku
void School::removeStudentBelowAge(int age) {

    //Usuniecie studentow ponizej progu wiekego
    cout << "Usuniecie studentow ponizej " << age << " roku zycia." << endl;
    students.erase(
        remove_if(students.begin(), students.end(),
            [&age](const Student& student) {
                return student.getAge() < age; 
            }),
        students.end()
    );
}

//Metoda wyswietlajaca wszystkich uczniow w szkole
void School::showStudents(){
    cout << "Uczniowie: " << endl;
    for (Student i : students) {
         i.show();
    }
}

//Metoda wyswietlajaca nazwe szkoly
void School::showSchool(){
    cout << "Nazwa szkoly: " << school_name << endl;
}

//Metoda zwracajaca liczbe uczennic w szkole
int School::getFemaleCount(){

    // Liczenie uczennic
    int countFemale = count_if(students.begin(), students.end(),
        [](Student student) {
            return student.getGender() == 'F';
        });

    return countFemale;
}

//Metoda zwracajaca liczbe uczniow w szkole
int School::getStudentCount(){
    return students.size();
}

//Metoda zwracajaca srednia ocen wszystkich uczniow w szkole
int School::getAverageGrade(){
    float oceny = 0;
    for (auto student : students) {
        oceny += student.getGrade(); 
    }

    float srednia = oceny / students.size(); 
    return srednia;
}

//Metoda zwracajaca ucznia z najwyzsza srednia ocen
Student School::getTopStudent() {

    int bestStudent = 0;

    for (int i = 1;i < students.size(); i++) {
        if (students[i].getGrade() > students[bestStudent].getGrade()) {
            bestStudent = i;
        }
    }

    return students[bestStudent];
}