#pragma once
#include <iostream>
#include "Pokoj.h"
#include "Apartament.h"
using namespace std;

//Metoda double obliczCene(int liczbaDni) – metoda obliczajaca koszt pobytu
double Apartament::obliczCene(int liczbaDni) const
{
	return liczbaDni * cena;
}

//Metoda string opis() – metoda zwracajaca opis pokoju
string Apartament::opis() const
{
	return "Apartament: Cena za noc: " + to_string(cena);
}