#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include "UrzadzenieElektroniczne.h"
#include "Laptop.h"
#include "Smartphone.h"
using namespace std;

//Liczba pracownikow
const int liczbaSmartphonow = 5;
const int liczbaLaptopow = 5;
int liczbaUrzadzen;

//W funkcji main przetestuj wszystkie klasy i metody. Stworz tablice obiektow klasy UrzadzenieElektroniczne
//i sprawdz, jak dziala dynamiczna alokacja pamieci dla obiektow tej klasy oraz jej dziedziczacych klas.

int main()
{
	cout << "************************************************************" << endl;
	cout << "Program testuje wszystkie klasy i metody dla obiektow klasy" << endl;
	cout << "UrzadzeniaElektroniczne." << endl;
	cout << "************************************************************" << endl << endl;

	//Tablica urzadzen elektronicznych
	UrzadzenieElektroniczne* urzadzenia[liczbaLaptopow + liczbaSmartphonow];
	liczbaUrzadzen = liczbaLaptopow;
	liczbaUrzadzen += liczbaSmartphonow;

	//Tablica urzadzen elektronicznych
	urzadzenia[0] = new Laptop("Lenovo", "JHGGJ", 2000, "Intel", 5);



	//Dealokacja
	delete[] urzadzenia;
	
	cout << "Koniec programu." << endl;
	cout << "Ewelina Jurkiewicz, Gr. 5." << endl;
	return 0;
}
