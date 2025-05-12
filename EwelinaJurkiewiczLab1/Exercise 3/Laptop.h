#pragma once
#include <stdio.h>
#include <string>
#include "UrzadzenieElektroniczne.h"
using namespace std;

class Laptop : public UrzadzenieElektroniczne
{
protected:
	string procesor;
	int ram;

public:
	//Konstruktor bezargumentowy;
	Laptop() {
		marka = "Brak marki";
		model = "Brak modelu";
		rokProdukcji = 0000;
		procesor = "";
		ram = 00;
	};

	//Konstruktor parametryczny
	Laptop(string firma, string typ, int rokFabrykacji, string cpu, int pamiec)
		: UrzadzenieElektroniczne(firma, typ, rokFabrykacji), procesor(cpu), ram(pamiec) {}

	//Wirtualny destruktor
	virtual ~Laptop() {}

	void wyswietlInformacje();
};