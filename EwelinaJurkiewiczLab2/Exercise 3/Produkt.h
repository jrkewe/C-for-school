#pragma once
#include <stdio.h>
#include <string>
using namespace std;

class Produkt {
protected:
	string nazwa;
	float ilosc;
	float cena;

public:
	//Konstruktor bezargumentowy;
	Produkt() {
		nazwa = "Pusta pozycja";
		ilosc = 0.0f;
		cena = 0.0f;
	};


	//Konstruktor argumentowy do inicjalizacji atrybutow
	Produkt(string etykieta, float zasob, float naleznosc) : nazwa(etykieta), ilosc(zasob), cena(naleznosc) {}

	//Wirtualny destruktor
	virtual ~Produkt() {}

	//Wirtualna metoda void wyswietl() – wyswietlajaca informacje o produkcie(nazwa, ilosc, cena)
	virtual void wyswietl();

	//Getter pola nazwa
	string getNazwa();

	//Getter pola ilosc
	float getIlosc();

	//Getter pola cena
	float getCena();

};
