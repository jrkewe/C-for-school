#pragma once
#include <iostream>
#include "Pokoj.h"
#include "PokojStandard.h"
using namespace std;

//Metoda double obliczCene(int liczbaDni) – metoda obliczajaca koszt pobytu
double PokojStandard::obliczCene(int liczbaDni) const 
{
	return liczbaDni * cena;
}

//Metoda string opis() – metoda zwracajaca opis pokoju
string PokojStandard::opis() const 
{
	double cenaZaokraglona = round(cena * 100) / 100;
	string cenaString = to_string(cenaZaokraglona);

	//Znajdz pozycje kropki i przytnij ciag do dwoch miejsc po przecinku
	size_t dotPos = cenaString.find('.');
	if (dotPos != string::npos) {
		cenaString = cenaString.substr(0, dotPos + 3);
	}

	string opisPokoju = "Pokoj standardowy: 1 lozko, Wi-Fi, lazienka w pokoju, telewizor.\n";

	return opisPokoju + "Cena za noc: " + cenaString;
}