#pragma once
#include <iostream>
#include "Hotel.h"
#include "Pokoj.h"
#include "PokojStandard.h"
#include "Apartament.h"
using namespace std;

int main()
{
	cout << "************************************************" << endl;
	cout << "Program jest systemem do zarzadzaniarezerwacjami" << endl;
	cout << "************************************************" << endl << endl;

	Hotel hotel("Bukowina");

	Pokoj* pokoj1 = new PokojStandard();
	Pokoj* pokoj2 = new PokojStandard();
	Pokoj* pokoj3 = new PokojStandard();
	Pokoj* pokoj4 = new Apartament();
	Pokoj* pokoj5 = new Apartament();
	Pokoj* pokoj6 = new Apartament();
	Pokoj* pokoj7 = new Apartament();

	//Tworzenie rezerwacji
	cout << "Tworzenie rezerwacji..." << endl;
	hotel.tworzenieRezerwacji(pokoj1);
	hotel.tworzenieRezerwacji(pokoj2);
	cout << "----------------------------------------------------" << endl;

	cout << "Wszystkie rezerwacje:" << endl;
	hotel.wyswietlenieWszystkichRezerwacji();
	cout << "----------------------------------------------------" << endl;

	int apartamenty = hotel.getApartmentsCount();
	cout << "Liczba zarezerwowanych apartamentow: " << apartamenty << endl;
	cout << "----------------------------------------------------" << endl;

	//Znalezienie najtanszego pokoju
	Pokoj* najtanszy = hotel.getNajtanszyPokoj();
	cout << endl << "----------------------------------------------------" << endl;

	//Usuwanie rezerwacji
	cout << "Usuwanie rezerwacji o kluczu 2" << endl;
	hotel.usuwanieRezerwacjiPoNumerze(1);
	cout << "----------------------------------------------------" << endl;

	cout << "Wszystkie rezerwacje:" << endl;
	hotel.wyswietlenieWszystkichRezerwacji();
	cout << "----------------------------------------------------" << endl;

	cout << "Koniec programu." << endl;
	cout << "Ewelina Jurkiewicz, Gr. 5." << endl;
	return 0;
}