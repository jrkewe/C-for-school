#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include "Pracownik.h"
#include "Assistant.h"
#include "Manager.h"
using namespace std;

//Tablica nazwisk
string nazwiska[10] = { "Fraczkowski", "Kubis", "Bocian", "Rejman", "Teodorczyk", "Bugala", "Marczewski", "Buczkowski", "Polus", "Piotrowicz" };

//Liczba pracownikow
const int liczbaAsystentow = 5;
const int liczbaManagerow = 5;
int liczbaPracownikow;

//Wiek
int minWiek = 20;
int maxWiek = 64;

//Wyplata
float minWyplata = 5000;
float maxWyplata = 10000;

//Losowe wartosci
int randomAge;
float randomSalary;

//Generator losowy
float generujLosowaLiczbe(float min, float max) 
{
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<float> dist(min, max);
	return dist(gen);
}

//Funkcja showTopEarners
void showTopEarners(Pracownik* pracownicy[], int liczbaPracownikow) 
{
	int tymczasowyIndex = 1;
	cout << "Pracownicy z premia wieksza niz srednia: " << endl;

	//Srednia premia
	float wszystkiePremie = 0.0f;
	float bonus = 0.0f;
	for (int i = 0; i < liczbaPracownikow; i++)
	{
		bonus = pracownicy[i]->calculateBonus(pracownicy[i]->getSalary());
		wszystkiePremie += bonus;
	}

	float sredniaPremia = wszystkiePremie / liczbaPracownikow;

	for (int i = 0; i < liczbaPracownikow; i++)
	{
		bonus = pracownicy[i]->calculateBonus(pracownicy[i]->getSalary());
		if (bonus > sredniaPremia)
		{
			cout << tymczasowyIndex << ". ";
			pracownicy[i]->show();
			cout << endl;
			tymczasowyIndex++;
		}
	}
	cout << endl;
}

//Funkcja averageSalary
void averageSalary(Pracownik* pracownicy[], int liczbaPracownikow)
{
	cout << "Sredni placa pracownikow: ";

	//Srednia placa
	float wszystkieWyplaty = 0.0f;
	float wyplata = 0.0f;
	for (int i = 0; i < liczbaPracownikow; i++)
	{
		wyplata = pracownicy[i]->getSalary();
		wszystkieWyplaty += wyplata;
	}

	float sredniaWyplata = wszystkieWyplaty / liczbaPracownikow;

	cout << sredniaWyplata << endl << endl;
}

//W funkcji main stworz tablice pracownikow i zaprezentuj polimorficzne wywolanie metod
int main() 
{
	cout << "************************************************************" << endl;
	cout << "Program oblicza dane dotyczace wyplat dla asystentow" << endl; 
	cout << "i menadzerow w firmie." << endl;
	cout << "************************************************************" << endl << endl;

	//Tablica pracownikow
	Pracownik* pracownicy[liczbaAsystentow + liczbaAsystentow];
	liczbaPracownikow = liczbaAsystentow;
	liczbaPracownikow += liczbaManagerow;

	//Rozpoczecie sekwencji losowania
	srand(static_cast<unsigned>(time(0))); 

	//Tablica pracownikow
	for (int i = 0;i < liczbaPracownikow;i++)
	{
		//Losowa liczba dla wieku
		randomAge = minWiek + (rand() % (maxWiek - minWiek + 1));
		//Losowa liczba dla wyplaty
		randomSalary = generujLosowaLiczbe(minWyplata, maxWyplata);

		if (i<liczbaAsystentow) 
		{
			pracownicy[i] = new Assistant(nazwiska[i], randomAge, randomSalary);
		}

		else if (i>=liczbaAsystentow) 
		{
			pracownicy[i] = new Manager(nazwiska[i], randomAge, randomSalary);
		}

		// Sprawdzenie, czy alokacja zakonczyla się sukcesem
		if (pracownicy[i] == nullptr) {
			cerr << "Blad: Nie udalo sie zaalokowac pamieci dla pracownika o indeksie " << i << "." << endl;
			return -1;
		}

	}

	//•showTopEarners, ktora wyswietli pracownikow z premia wieksza niz srednia
	
	showTopEarners(pracownicy, liczbaPracownikow);

	//•averageSalary, ktora obliczy srednia place z listy pracownikow

	averageSalary(pracownicy, liczbaPracownikow);

	//Dealokacja
	for (int i = 0; i < liczbaPracownikow; i++) {
		delete pracownicy[i];
	}

	cout << "Koniec programu." << endl;
	cout << "Ewelina Jurkiewicz, Gr. 5." << endl;
	return 0;
}
	