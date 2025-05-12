#pragma once
#include <iostream>
#include "Pracownik.h"
using namespace std;

class Assistant : public Pracownik
{

public:
	//Konstruktor bezargumentowy;
	Assistant() {
		surname = "secondname";
		age = 0;
		salary = 0;
	};

	//Konstruktor argumentowy pozwalajacy na zainicjalizowanie pol klasy
	Assistant(string secondname, int years, float wage) : Pracownik(secondname, years, wage){}

	float calculateBonus(float salary) const override;
};

//Nastepnie, stworz dwie klasy dziedziczace:
	//  • Manager, ktory implementuje metode calculateBonus() jako salary * 0.1,
	//	• Assistant, ktory implementuje metode calculateBonus() jako salary * 0.05.