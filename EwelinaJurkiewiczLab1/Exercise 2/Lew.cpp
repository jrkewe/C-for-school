#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include "Zwierze.h"
#include "Lew.h"
using namespace std;

//Setter pola poziomZagrozenia
void Lew::setPoziomZagrozenia(int poziom)
{
	poziomZagrozenia = poziom;
}

//Metoda void informacje() – wyswietlajaca wszystkie informacje o zwierzeciu
void Lew::informacje() const
{
	string czyChronioneText;
	czyChronioneText = czyChronione ? "tak" : "nie";
	cout << "Gatunek: " << gatunek << ", wiek: " << wiek << ", chronione: " << czyChronioneText
		<< ", poziom zagrozenia wyginieciem: " << poziomZagrozenia << ".";
}

//Setter pola czyChronione
void Lew::setCzyChronione(bool nowyStan)
{
	czyChronione = nowyStan;
}

//Getter pola czyChronione
bool Lew::getCzyChronione()
{
	return czyChronione;
}
