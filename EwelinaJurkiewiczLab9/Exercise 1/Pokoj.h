#pragma once
#include <stdio.h>
#include <string>
using namespace std;

class Pokoj {
protected:
	int cena;

public:
	//Konstruktor bezargumentowy;
	Pokoj(int koszt): cena(koszt){ };

	//Wirtualny destruktor
	virtual ~Pokoj() {}

	//Wirtualna metoda double obliczCene(int liczbaDni) – metoda obliczajaca koszt pobytu
	virtual double obliczCene(int liczbaDni) const;

	//Wirtualna metoda string opis() – metoda zwracajaca opis pokoju
	virtual string opis() const;

	//GetterCeny
	int getCena() const;
};