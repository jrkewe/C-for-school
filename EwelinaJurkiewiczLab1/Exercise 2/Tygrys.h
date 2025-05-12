#pragma once
#include <stdio.h>
#include <string>
#include "Zwierze.h"
using namespace std;

class Tygrys : public Zwierze
{
protected:
	int poziomLeniwosci;

public:

	//Konstruktor z parametrami
	Tygrys(string rodzaj, int lat, bool jestChronione, bool zaginiecie, int leniwosc)
		: Zwierze(rodzaj, lat, jestChronione, zaginiecie)
	{
		if (leniwosc >= 1 && leniwosc <= 10)
		{
			poziomLeniwosci = leniwosc;
		}
		else
		{
			poziomLeniwosci = 1;
		}

		cout << "Tworzenie lwa: " << gatunek
			<< ", wiek: " << wiek
			<< ", czy chronione: " << (czyChronione ? "true" : "false")
			<< ", czy zaginelo: " << (czyZaginelo ? "true" : "false")
			<< ", poziom lenistwa: " << poziomLeniwosci << endl;
	}

	//Wirtualny destruktor
	virtual ~Tygrys() {}

	//Setter pola poziomLeniwosci
	void setPoziomLeniwosci(int poziom);

	//Getter pola poziomLeniwosci
	int getPoziomLeniwosci();

	//Metoda void informacje() – wyswietlajaca wszystkie informacje o zwierzeciu
	void informacje() const override;

	//Setter pola czyChronione
	void setCzyChronione(bool nowyStan);

	//Getter pola czyChronione
	bool getCzyChronione();
};
