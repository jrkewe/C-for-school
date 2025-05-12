#pragma once
#include <iostream>
#include "Produkt.h"
using namespace std;

void Produkt::wyswietl() {
	if (ilosc !=0) {
		cout << "Nazwa: " << nazwa << ", ilosc: " << ilosc << ", cena: " << cena << ".";
	}
}

string Produkt::getNazwa() {
	return nazwa;
}

float Produkt::getIlosc() {
	return ilosc;
}

float Produkt::getCena() {
	return cena;
}
