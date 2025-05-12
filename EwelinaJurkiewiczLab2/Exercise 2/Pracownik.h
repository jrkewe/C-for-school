#pragma once
#include <stdio.h>
#include <string>
using namespace std;

class Pracownik {
protected:
	string surname;
	int age;
	float salary;

public:
	//Konstruktor bezargumentowy;
	Pracownik() {
		surname = "secondname";
		age = 0;
		salary = 0.0f;
	};

	//Lista inicjalizacyjna konstruktora
	Pracownik(string secondname, int years, float wage) : surname(secondname), age(years), salary(wage) {}

	//Wirtualny destruktor
	virtual ~Pracownik() {}

	//Wirtualna metodę void show() – wyświetlajaca informacje o pracowniku
	virtual void show();

	//Czysto wirtualna metoda calculateBonus() – obliczajaca premie
	virtual float calculateBonus(float salary) const = 0;

	//Getter pola salary
	float getSalary();
};