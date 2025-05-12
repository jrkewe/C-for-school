#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include "UrzadzenieElektroniczne.h"
using namespace std;

//Wirtualna metode void wyswietlInformacje() – wyswietlajaca informacje o urzadzeniu elektrycznym
void UrzadzenieElektroniczne::wyswietlInformacje() 
{
	cout << "Marka: " << marka << ", model: " << model << ", rok produkcji: " << rokProdukcji << ".";
}

//Setter pola marka
void UrzadzenieElektroniczne::setMarka(string nazwaMarki) 
{
	marka = nazwaMarki;
}

//Getter pola marka
string UrzadzenieElektroniczne::getMarka() 
{
	return marka;
}

//Setter pola model
void UrzadzenieElektroniczne::setModel(string nazwaModelu)
{
	model = nazwaModelu;
}

//Getter pola model
string UrzadzenieElektroniczne::getModel()
{
	return model;
}

//Setter pola rokProdukcji
void UrzadzenieElektroniczne::setRokProdukcji(int rok)
{
	rokProdukcji = rok;
}

//Getter pola rokProdukcji
int UrzadzenieElektroniczne::getRokProdukcji()
{
	return rokProdukcji;
}
