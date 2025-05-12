#pragma once
#include <stdio.h>
#include <string>
#include "Zwierze.h"
using namespace std;

class Lew : public Zwierze
{
protected:
	int poziomZagrozenia;

public:

	//Konstruktor z parametrami
	Lew(string rodzaj, int lat, bool jestChronione, bool zaginiecie, int zagrozenie)
		: Zwierze(rodzaj, lat, jestChronione, zaginiecie)
	{
		if (zagrozenie >= 1 && zagrozenie <= 10)
		{
			poziomZagrozenia = zagrozenie;
		}
		else 
		{
			poziomZagrozenia = 1;
		}

		cout << "Tworzenie lwa: " << gatunek
			<< ", wiek: " << wiek
			<< ", czy chronione: " << (czyChronione ? "true" : "false")
			<< ", czy zaginelo: " << (czyZaginelo ? "true" : "false")
			<< ", poziom zagrozenia: " << poziomZagrozenia << endl;
	}

	//Wirtualny destruktor
	virtual ~Lew() {}

	//Setter pola poziomZagrozenia
	void setPoziomZagrozenia(int poziom);

	//Metoda void informacje() – wyswietlajaca wszystkie informacje o zwierzeciu
	void informacje() const override;

	//Setter pola czyChronione
	void setCzyChronione(bool nowyStan);

	//Getter pola czyChronione
	bool getCzyChronione();
};