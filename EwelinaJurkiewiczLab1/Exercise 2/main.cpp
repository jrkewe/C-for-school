#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include "Zwierze.h"
#include "Lew.h"
#include "Tygrys.h"
using namespace std;

//• iloscChronionychZwierzat, przyjmujaca tablice obiektow klasy Zwierze i jej rozmiar.Funkcja
//ma policzyc, ile zwierzat jest chronionych;
void iloscChronionychZwierzat(Zwierze* zwierzeta[], int liczbaZwierzat)
{
	int count = 0;

	for (int i = 0 ;i<liczbaZwierzat;i++) 
	{
		if (zwierzeta[i]->getCzyChronione())
		{
			count++;
		}
	}

	cout << "Ilosc chronionych zwierzat: " << count << endl;
}

//• zwierzetaWZwierzyncu, przyjmujaca tablice obiektow klasy Zwierze i jej rozmiar.Funkcja ma
//wyswietlic informacje o wszystkich zwierzetach w ogrodzie zoologicznym;
void zwierzetaWZwierzyncu(Zwierze* zwierzeta[], int liczbaZwierzat)
{
	cout << "---------------------------------------------------------------" << endl;
	cout << "Lwy" << endl;
	for (int i = 0;i < liczbaZwierzat;i++)
	{
		zwierzeta[i]->informacje();
		cout << endl;
		if (i == 4) 
		{
			cout << "---------------------------------------------------------------" << endl;
			cout << "Tygrysy" << endl;
		}
	}
}

//• zaginioneZwierze, przyjmujaca tablice obiektow klasy Zwierze i jej rozmiar.Funkcja ma wyswietlic 
// informacje o zwierzeciu, ktore zaginelo. W funkcji main przetestuj dzialanie wszystkich klas oraz funkcji.
void zaginioneZwierze(Zwierze* zwierzeta[], int liczbaZwierzat)
{
	cout << "---------------------------------------------------------------" << endl;
	cout << "Zwierzeta ktore zaginely" << endl;
	for (int i = 0;i < liczbaZwierzat;i++)
	{
		if (zwierzeta[i]->getCzyZaginelo())
		{
			zwierzeta[i]->informacje();
			cout << endl;
		}
	}

}

//Tablica gatunkow lwow
string gatunkiLwow[5] = {"afrykanski", "azjatycki", "berberyjski", "jaskiniowy", "kapski"};

//Tablica gatunkow tygrysow
string gatunkiTygrysow[6] = {"bengalski", "syberyjski", "sumatrzanski", "indochinski", "malajski", "poludniowochinski"};

//Pod ochrona
//Lwy pod ochrona: afrykanski - tak, azjatycki - tak
//Tygrysy pod ochrona: wszystkie

//Skala zagrozenia wymarciem
//Lwy:		afrykanski - 5/10, azjatycki - 9/10, berberyjski - 10/10, jaskiniowy - 10/10, kapski - 10/10
//Skala leniwosci
//Tygrysy:	bengalski - 5/10, syberyjski - 3/10, sumatrzanski - 6/10, indochinski - 5/10, malajski - 7/10
//			poludniowochinski - 4/10

//Wiek
int maxWiekLew = 25;
int maxWiekTygrys = 20;

//Losowe wartosci
int randomAge;

//Losowy wiek lwa
int setWiekLwa() 
{
	return randomAge = (rand() % (maxWiekLew + 1));
}

int setWiekTygrysa()
{
	return randomAge = (rand() % (maxWiekLew + 1));
}

//Stan zaginiecia
bool setStanZaginiecia()
{
	bool stanZaginiecia = rand() % 2;
	return stanZaginiecia;
}

//Liczba zwierzat
const int liczbaTygrysow = 5;
const int liczbaLwow = 6;
int liczbaZwierzat;

int main()
{
	cout << "************************************************************" << endl;
	cout << "Program wyswietla dane dotyczace zwierzat w ogrodzie zoologicznym" << endl;
	cout << "************************************************************" << endl << endl;

	//Tablica obiektow klasy Zwierze
	Zwierze* zwierzeta[liczbaTygrysow + liczbaLwow];
	liczbaZwierzat = liczbaTygrysow;
	liczbaZwierzat += liczbaLwow;

	//Rozpoczecie sekwencji losowania
	srand(static_cast<unsigned>(time(0)));

	//Tablica Zwierzat
	//Lwy
	zwierzeta[0] = new Lew(gatunkiLwow[0], setWiekLwa(), true, setStanZaginiecia(), 5);
	zwierzeta[1] = new Lew(gatunkiLwow[1], setWiekLwa(), true, setStanZaginiecia(), 9);
	zwierzeta[2] = new Lew(gatunkiLwow[2], setWiekLwa(), false, setStanZaginiecia(), 10);
	zwierzeta[3] = new Lew(gatunkiLwow[3], setWiekLwa(), false, setStanZaginiecia(), 10);
	zwierzeta[4] = new Lew(gatunkiLwow[4], setWiekLwa(), false, setStanZaginiecia(), 10);

	//Tablica Zwierzat
	//Tygrysy
	zwierzeta[5] = new Tygrys(gatunkiTygrysow[0], setWiekTygrysa(), true, setStanZaginiecia(), 5);
	zwierzeta[6] = new Tygrys(gatunkiTygrysow[1], setWiekTygrysa(), true, setStanZaginiecia(), 3);
	zwierzeta[7] = new Tygrys(gatunkiTygrysow[2], setWiekTygrysa(), true, setStanZaginiecia(), 6);
	zwierzeta[8] = new Tygrys(gatunkiTygrysow[3], setWiekTygrysa(), true, setStanZaginiecia(), 5);
	zwierzeta[9] = new Tygrys(gatunkiTygrysow[4], setWiekTygrysa(), true, setStanZaginiecia(), 7);
	zwierzeta[10] = new Tygrys(gatunkiTygrysow[5], setWiekTygrysa(), true, setStanZaginiecia(), 4);

	iloscChronionychZwierzat(zwierzeta, liczbaZwierzat);

	zwierzetaWZwierzyncu(zwierzeta, liczbaZwierzat);

	zaginioneZwierze(zwierzeta, liczbaZwierzat);

}