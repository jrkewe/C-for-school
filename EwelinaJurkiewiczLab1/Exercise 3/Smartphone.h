#pragma once
#include <stdio.h>
#include <string>
#include "UrzadzenieElektroniczne.h"
using namespace std;

class Smartphone : public UrzadzenieElektroniczne
{
protected:
	string systemOperacyjny;
	int pojemnoscBaterii;

public:
	//Konstruktor bezargumentowy;
	Smartphone() {
		marka = "Brak marki";
		model = "Brak modelu";
		rokProdukcji = 0000;
		systemOperacyjny = "";
		pojemnoscBaterii = 0;
	};

	//Konstruktor parametryczny
	Smartphone(string firma, string typ, int rokFabrykacji, string so, int bateria)
		: UrzadzenieElektroniczne(firma, typ, rokFabrykacji), systemOperacyjny(so), pojemnoscBaterii(bateria) {
	}

	//Wirtualny destruktor
	virtual ~Smartphone() {}

	//Wirtualna metode void wyswietlInformacje() – wyswietlajaca informacje o urzadzeniu elektrycznym
	void wyswietlInformacje();
};