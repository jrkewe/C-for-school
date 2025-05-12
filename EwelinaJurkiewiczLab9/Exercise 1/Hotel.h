#pragma once
#include <iostream>
#include <map>
#include "Pokoj.h"
using namespace std;

class Hotel {
	map<int, Pokoj*> rezerwacje;
	string hotel_name;

public:
	//Konstruktor z nazwa szkoly
	Hotel(string name) : hotel_name(name) {}

	//Metoda dodajaca nowa rezerwacje
	void tworzenieRezerwacji(Pokoj* pokoj);

	//Metoda usuwajaca rezerwacje na podstawie numeru
	void usuwanieRezerwacjiPoNumerze(int numer);

	//Metoda wyswietlajaca wszystkie rezerwacje
	void wyswietlenieWszystkichRezerwacji();

	//Metoda zwracajaca liczbe zarezerwowanych apartamentow
	int getApartmentsCount();

	//Metoda zwracajaca najtanszy dostepny pokoj
	Pokoj* getNajtanszyPokoj();
};