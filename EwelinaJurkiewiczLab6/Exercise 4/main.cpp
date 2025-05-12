#include <iostream>
#include <functional>
#include <vector>
#include "GeneratorLiczb.h"
using namespace std;

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
	cout << "Wektor: " << endl;
	for_each(numbers.begin(), numbers.end(), [](int element) {
			cout << element << " ";
		});
	cout << endl;
	
	//Modyfikacja wartosci w kolekcji z uzyciem lambda
	int skladnik = 1;
	transform(numbers.begin(), numbers.end(), numbers.begin(), [skladnik](int element)-> int
		{
			return element + skladnik;
		}
	);

	//Wyswietlenie wektora
	cout << "Lambda addValue: (1)" << endl;
	for_each(numbers.begin(), numbers.end(), [](int element) {
		cout << element << " ";
		});
	cout << endl;

	//Filtrowanie danych z uzyciem lambda
	int prog = 10;
	for (auto i = numbers.begin(); i != numbers.end();) 
	{
		if (![prog](int& x){ return x >= prog; }(*i))
		{
			i = numbers.erase(i);
		}
		else { i++; }
	}

	//Wyswietlenie wektora z uzyciem lambda
	cout << "Lambda isGreaterThan: (10)" << endl;
	for_each(numbers.begin(), numbers.end(), [](int element) {
		cout << element << " ";
		});
	cout << endl;

	//Obliczanie sumy z uzyciem lambda
	int suma = 0;
	for (int element : numbers) {
		[&suma](int x)-> int {return suma += x;} (element);
	}

	//Obliczanie wynikow
	cout << "Lambda agregacja: " << suma << endl << endl;

	cout << "Koniec programu." << endl;
	cout << "Ewelina Jurkiewicz, Gr. 5." << endl;
	return 0;
}