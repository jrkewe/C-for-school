#pragma once
#include <iostream>
#include "Pracownik.h"
#include "Assistant.h"
using namespace std;

float Assistant::calculateBonus(float salary) const
	{
		return salary * 0.05f;
	}


//Nastepnie, stworz dwie klasy dziedziczace:
	//  • Manager, ktory implementuje metode calculateBonus() jako salary * 0.1,
	//	• Assistant, ktory implementuje metode calculateBonus() jako salary * 0.05.