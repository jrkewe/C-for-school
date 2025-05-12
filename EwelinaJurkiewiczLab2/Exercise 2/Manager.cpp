#pragma once
#include <iostream>
#include "Pracownik.h"
#include "Manager.h"
using namespace std;

float Manager::calculateBonus(float salary) const
{
	return (salary * 0.1f);
}


//Nastepnie, stworz dwie klasy dziedziczace:
	//  • Manager, ktory implementuje metode calculateBonus() jako salary * 0.1,
	//	• Assistant, ktory implementuje metode calculateBonus() jako salary * 0.05.