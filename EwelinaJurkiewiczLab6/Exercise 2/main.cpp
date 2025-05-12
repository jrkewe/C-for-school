#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include "GeneratorLiczb.h"
using namespace std;

class IsPrime {
protected:
	map <int, int> liczbyPierwsze;
public:
	//Przeciazanie operatora()
	bool operator() (int x) {

		//Warunki dla liczb pierwszych
		if (x>1) 
		{

			//Dzielenie przez liczby mniejsze od pierwiastka kwadratowego tej liczby
			int pierwiastekKwadratowy = static_cast<int>(sqrt(x));
			for (int i = 2;i<=pierwiastekKwadratowy;i++) {
				if (x%i==0) {
					return false;
				}
			}

			//Dodawanie liczby pierwszej do mapy lub zwiekszenie jej wystapien
			liczbyPierwsze[x]++;
			return true;
		}
		else 
		{
			return false;
		}
	}

	void wswietlMape() {
		for (auto i = liczbyPierwsze.begin(); i != liczbyPierwsze.end(); i++) {
			cout << "Liczba: " << i->first << ", Wystapienia: " << i->second << endl;
		}
		cout << endl;
	}


};

int main() 
{
	cout << "*************************************************" << endl;
	cout << "Program szuka liczb pierwszy przy uzyciu funktora " << endl;
	cout << "*************************************************" << endl << endl;
	
	vector<int> numbers;

	//Generowanie dlugosci wektora
	int dlugoscWektora = generujLosowaWartosc(5,15);
	//Generowanie liczb
	for (int i = 0; i<dlugoscWektora ;i++) {
		numbers.push_back(generujLosowaWartosc(2,15));
	}
	//Wyswietlenie wektora
	cout << "Wektor: ";
	for (int i = 0; i < dlugoscWektora;i++) {
		cout << numbers[i];
		if (i < dlugoscWektora -1) { cout << ", "; }
		else { { cout << "." << endl << endl; } }
	}

	IsPrime isPrime;

	for (auto i : numbers) {
		isPrime(i);
	}

	isPrime.wswietlMape();

	cout << "Koniec programu." << endl;
	cout << "Ewelina Jurkiewicz, Gr. 5." << endl;
	return 0;
}