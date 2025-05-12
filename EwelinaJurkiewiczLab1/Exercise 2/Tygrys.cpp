#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include "Zwierze.h"
#include "Tygrys.h"
using namespace std;

//Setter pola poziomLeniwosci
void Tygrys::setPoziomLeniwosci(int poziom)
{
	poziomLeniwosci = poziom;
}

//Getter pola poziomLeniwosci
int Tygrys::getPoziomLeniwosci()
{
	return poziomLeniwosci;
}

//Metoda void informacje() – wyswietlajaca wszystkie informacje o zwierzeciu
void Tygrys::informacje() const
{
	string czyChronioneText;
	czyChronioneText = czyChronione ? "tak" : "nie";
	cout << "Gatunek: " << gatunek << ", wiek: " << wiek << ", chronione: " << czyChronioneText
		<< ", poziom lenistwa: " << poziomLeniwosci << ".";
}

//Setter pola czyChronione
void Tygrys::setCzyChronione(bool nowyStan)
{
	czyChronione = nowyStan;
}

//Getter pola czyChronione
bool Tygrys::getCzyChronione()
{
	return czyChronione;
}