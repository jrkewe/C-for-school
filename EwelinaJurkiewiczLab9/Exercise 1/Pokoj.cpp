#pragma once
#include <iostream>
#include "Pokoj.h"
using namespace std;

//Wirtualna metoda double obliczCene(int liczbaDni) – metoda obliczajaca koszt pobytu
double Pokoj::obliczCene(int liczbaDni) const {
	return cena;
}

//Wirtualna metoda string opis() – metoda zwracajaca opis pokoju
string Pokoj::opis() const {
	return "Opis";
}

//Getter pole age
int Pokoj::getCena() const {
	return cena;
}