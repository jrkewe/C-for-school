#pragma once
#include <iostream>
#include "Pokoj.h"
#include "Apartament.h"
using namespace std;

class Apartament : public Pokoj
{
protected:
	double cena = 200.0f;

public:
	//Konstruktor 
	Apartament() : Pokoj(200) {}

	//Metoda double obliczCene(int liczbaDni) – metoda obliczajaca koszt pobytu
	double obliczCene(int liczbaDni) const override;

	//Metoda string opis() – metoda zwracajaca opis pokoju
	string opis() const override;

};