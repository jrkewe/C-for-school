#pragma once
#include <stdio.h>
#include <string>
using namespace std;

class UrzadzenieElektroniczne {
protected:
	string	marka;
	string	model;
	int		rokProdukcji;

public:
	//Konstruktor bezargumentowy;
	UrzadzenieElektroniczne() {
		marka = "Brak marki";
		model = "Brak modelu";
		rokProdukcji = 0000;
	};

	//Konstruktor parametryczny
	UrzadzenieElektroniczne(string firma, string typ, int rokFabrykacji) : marka(firma), model(typ), rokProdukcji(rokFabrykacji) {}

	//Wirtualny destruktor
	virtual ~UrzadzenieElektroniczne() {}

	//Wirtualna metode void wyswietlInformacje() – wyswietlajaca informacje o urzadzeniu elektrycznym
	virtual void wyswietlInformacje();

	//Setter pola marka
	void setMarka(string nazwaMarki);

	//Getter pola marka
	string getMarka();

	//Setter pola model
	void setModel(string nazwaModelu);

	//Getter pola model
	string getModel();

	//Setter pola rokProdukcji
	void setRokProdukcji(int rok);

	//Getter pola rokProdukcji
	int getRokProdukcji();
};