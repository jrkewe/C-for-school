#include <iostream>
#include <functional>
#include <vector>
#include "GeneratorLiczb.h"
using namespace std;

int addValue(int& x, int skladnik) {
	x += skladnik;
	 return x;
}

bool isGreaterThan(int& x, int prog) {
	return x >= prog;
}

void displayVector(vector<int> wektor) {
	cout << "Wektor: ";
	for (int i = 0; i < wektor.size();i++) {
		cout << wektor[i];
		if (i < wektor.size() - 1) { cout << ", "; }
		else { { cout << "." << endl << endl; } }
	}
}

void colectionSum(vector<int> wektor) {
	int suma = 0;
	cout << "Suma: ";
	for (int i = 0; i < wektor.size();i++) {
		suma += wektor[i];
	}
	cout << suma << endl << endl;
}


int main() {
	cout << "*********************************************" << endl;
	cout << "Program demonstruje zastosowanie funkcji bind " << endl;
	cout << "*********************************************" << endl << endl;
	//Deklaracja wektora
	vector<int> numbers;
	//Dlugosci wektora
	int dlugoscWektora = generujLosowaWartosc(5, 15);
	//Elementy wektora
	for (int i = 0; i < dlugoscWektora;i++) {
		numbers.push_back(generujLosowaWartosc(2, 15));
	}

	//Wyswietlenie wektora
	displayVector(numbers);

	//Modyfikacja wartosci w kolekcji
	for (int i = 0; i < dlugoscWektora;i++) {
		auto boundFunction = bind(addValue, ref(numbers[i]), placeholders::_1);
		//Wywolanie boundFunction z jednym brakujacym argumentem
		boundFunction(1);
	}

	//Wyswietlenie wektora
	cout << "addValue: (1)" << endl;
	displayVector(numbers);

	//Filtrowanie danych
	for (auto i = numbers.begin();i != numbers.end();) {
		auto boundFunction = bind(isGreaterThan, ref(*i), placeholders::_1);
		//Wywolanie boundFunction z jednym brakujacym argumentem
		if (!boundFunction(10)) {
			i = numbers.erase(i);
		}
		else {
			i++;
		}
	}

	//Wyswietlenie wektora
	cout << "isGreaterThan: (10)" << endl;
	displayVector(numbers);

	//Obliczanie wynikow
	cout << "agregacja:" << endl;
	colectionSum(numbers);

	cout << "Koniec programu." << endl;
	cout << "Ewelina Jurkiewicz, Gr. 5." << endl;
	return 0;
}