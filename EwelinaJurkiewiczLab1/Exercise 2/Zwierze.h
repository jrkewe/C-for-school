#pragma once
#include <stdio.h>
#include <string>
using namespace std;

class Zwierze {
protected:
	string gatunek;
	int wiek;
	bool czyChronione;
	//Dodatkowe pole, dla funkcji zaginioneZwiere()
	bool czyZaginelo;

public:

	//Konstruktor z parametrami
	Zwierze(string rodzaj, int years, bool jestChronione, bool zaginiecie) 
		: gatunek(rodzaj), wiek(years), czyChronione(jestChronione), czyZaginelo(zaginiecie){}

	//Wirtualny destruktor
	virtual ~Zwierze() {}

	//Metoda void informacje() – wyswietlajaca wszystkie informacje o zwierzeciu
	virtual void informacje() const = 0;

	//Setter pola czyChronione
	void setCzyChronione(bool nowyStan);

	//Getter pola czyChronione
	bool getCzyChronione();

	//Getter pola czyChronione
	bool getCzyZaginelo();
};