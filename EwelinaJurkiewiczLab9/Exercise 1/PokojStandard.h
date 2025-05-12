#pragma once
#include <iostream>
#include "Pokoj.h"
using namespace std;

class PokojStandard : public Pokoj
{
protected:
	double cena = 100.0f;

public:
	//Konstruktor 
	PokojStandard() : Pokoj(100) {}
	
	//Metoda double obliczCene(int liczbaDni) – metoda obliczajaca koszt pobytu
	double obliczCene(int liczbaDni) const override;

	//Metoda string opis() – metoda zwracajaca opis pokoju
	string opis() const override;

};