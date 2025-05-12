#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Funkcja pomocnicza do wyswietlania zawartosci wektora
void wyswietlWektor(const vector <int>& wektor) {
	for (int element : wektor) {
		cout << element << " ";
	}
	cout << endl;
}

int main() {
	// Inicjalizacja wektora
	vector <int> liczby = { 3,5,2,8,7,1,4,9 };

	cout << "Oryginalne liczby: ";
	wyswietlWektor(liczby);

	// Sortowanie z uzyciem lambdy , sortowanie rosnaco
	sort(liczby.begin(), liczby.end(), [](int l, int r)->bool {
		return l < r; // Sortowanie rosnaco
		});
	cout << "Posortowane (rosnaco): ";
	wyswietlWektor(liczby);

	// Transformacja - potegowanie przez 2 (x^2)
	transform(liczby.begin(), liczby.end(), liczby.begin(), [](int element) {
		return element * element; // Potegowanie kazdego elementu przez 2
		});
	cout << "Liczby po podniesieniu do kwadratu: ";
	wyswietlWektor(liczby);

	// Uzycie for_each do wypisania elementow w formie " Element : x"
	cout << "Elementy w formie ’Element: x ’: " << endl;
	for_each(liczby.begin(), liczby.end(), [](int element) {
		cout << "Element: " << element << " "; // Wypisanie kazdego elementu
		});
	cout << endl;

	// Modyfikacja elementow - mnozenie przez 3
	for_each(liczby.begin(), liczby.end(), [](int& element) {
		element *= 3; // Mnozenie kazdego elementu przez 3
		});
	cout << "Liczby po pomnozeniu przez 3: ";
	wyswietlWektor(liczby);

	// Sumowanie wszystkich elementow
	int suma = 0;
	for_each(liczby.begin(), liczby.end(), [&suma](int element) {
		suma += element; // Sumowanie elementow
		});
	cout << "Suma liczb: " << suma << endl;

	// Sumowanie elementow mniejszych niz 50
	int prog = 50;
	suma = 0;

	for_each(liczby.begin(), liczby.end(), [&suma, prog](int element) {
		if (element < prog)
			suma += element; // Sumowanie elementow mniejszych niz 50
		});
	cout << " Suma liczb mniejszych niz 50: " << suma << endl;

	// Wywolanie lambdy bezposrednio - dodanie dwoch liczb
	cout << " Suma 5 i 10: " << [](int a, int b) {
		return a + b; // Dodanie dwoch liczb
		}(5, 10) << endl;

	// Lambda z okreslonym typem zwracanym - sprawdzanie , czy liczba jest parzysta
	auto czyParzysta = [](int a) -> bool {
		return a % 2 == 0; // Sprawdzanie , czy liczba jest parzysta
		};
	cout << "Czy 4 jest parzysta ? " << (czyParzysta(4) ? "Tak" : " Nie") <<
		endl;
	cout << "Czy 5 jest parzysta ? " << (czyParzysta(5) ? "Tak" : " Nie") <<
		endl;

	return 0;
}

//Program dziala poprawnie 