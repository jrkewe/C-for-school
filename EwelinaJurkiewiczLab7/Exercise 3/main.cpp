#pragma once
#include <iostream>
#include "Student.h"
#include "School.h"
using namespace std;

int main()
{
	cout << "***************************************" << endl;
	cout << "Program zarzadza statystykami szkolnymi" << endl;
	cout << "***************************************" << endl << endl;

	//1. Utworz obiekty uczniow:
	Student student1("Jan","Kowalski", 16, 'M', 4.2);
	Student student2("Anna", "Nowak", 15, 'F', 4.5);
	Student student3("Piotr", "Wojcik", 17, 'M', 5.0);
	Student student4("Zofia", "Kaczmarek", 18, 'F', 4.8);
	Student student5("Marek", "Wisniewski", 19, 'M', 3.9);

	//-----------------------------------------------------
	//2. Utworz obiekt szkoly:
	School school("Liceum Ogolnoksztalcace");

	//-----------------------------------------------------
	//3. Dodawanie uczniow do szkoly:
	school.addStudent(student1);
	school.addStudent(student2);
	school.addStudent(student3);
	school.addStudent(student4);
	school.addStudent(student5);

	//-----------------------------------------------------
	//4. Wyswietlanie informacji o szkole i uczniach :
	cout << "Wyswietlanie informacji o szkole i uczniach." << endl;
	school.showSchool();
	school.showStudents();

	cout << "-----------------------------------------------------" << endl;	
	//5. Analiza danych:
	cout << "Analiza danych." << endl;
	//Liczba uczniow w szkole
	cout << "Liczba uczniow w szkole: " << school.getStudentCount() << endl;
	//Liczba uczennic
	cout << "Liczba uczennic w szkole: " << school.getFemaleCount() << endl;
	//Srednia ocen w szkole
	cout << "Srednia ocen w szkole: " << school.getAverageGrade() << endl;
	//Uczen z najwyzsza srednia ocen w szkole
	cout << "Uczen z najwyzsza srednia ocen w szkole: " << endl;
	school.getTopStudent().show();

	cout << "-----------------------------------------------------" << endl;
	//6. Usuwanie danych:
	cout << "Usuwanie danych." << endl;
	//Usuwanie na podstawie nazwiska
	school.removeStudentBySecondname("Nowak");
	//Wyswietlenie aktualnej listy
	school.showStudents();

	//Usuwanie na podstawie wieku
	school.removeStudentBelowAge(18);
	//Wyswietlenie aktualnej listy
	school.showStudents();

	cout << "-----------------------------------------------------" << endl;

	//• Po zakonczeniu wszystkich operacji wyswietl podsumowanie danych, np. aktualna liste
	//uczniow oraz statystyki szkoly.
		//Srednia ocen w szkole
	cout << "Statystyki szkolne." << endl;
	//Aktualna lista uczniow
	school.showStudents();
	//Statystyki szkoly
	//Liczba uczennic
	cout << "Liczba uczennic w szkole: " << school.getFemaleCount() << endl;
	//Liczba uczniow w szkole
	cout << "Liczba uczniow w szkole: " << school.getStudentCount() << endl;
	//Srednia ocen w szkole
	cout << "Srednia ocen w szkole: " << school.getAverageGrade() << endl;
	//Uczen z najwyzsza srednia ocen w szkole
	cout << "Uczen z najwyzsza srednia ocen w szkole: " << endl;
	school.getTopStudent().show();
	cout << endl;

	cout << "Koniec programu." << endl;
	cout << "Ewelina Jurkiewicz, Gr. 5." << endl;
	return 0;
}