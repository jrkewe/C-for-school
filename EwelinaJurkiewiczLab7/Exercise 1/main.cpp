#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // std :: accumulate

// Funktor: Wyswietla elementy wieksze niz 10
class Wyswietlacz {
public:
	void operator () (int val) const {
		if (val > 10) {
			std::cout << val << " ";

		}

	}

};

// Funkcja: Mnozy wartosc przez 2
int mnozPrzezDwa(int x) {
	return x * 2;
}

int main() {
	// Inicjalizacja wektora
	std::vector <int > vec = {1,2,3,4,5,3,7};

	//1. Przeszukiwanie: std :: find z wartoscia 3
	auto it = std::find(vec.begin(), vec.end(), 3);
	if (it != vec.end()) {
		std::cout << " Znaleziono wartosc: " << *it << std::endl;

	}
	else {
		std::cout << " Wartosc nie zostala znaleziona." << std::endl;

	}

	//2. Modyfikacja: std :: replace zamienia wszystkie wystapienia 3 na 99 -
	//uzycie lambdy jako predykatu
	std::replace(vec.begin(), vec.end(), 3, 99);

	std::cout << "Po zamianie: ";
	std::for_each(vec.begin(), vec.end(), [](int val) {
		std::cout << val << " ";
		});
	std::cout << std::endl;

	//3. Wyswietlanie: std :: for_each z funktorem
	std::cout << " Elementy wieksze niz 10: ";
	std::for_each(vec.begin(), vec.end(), Wyswietlacz());
	std::cout << std::endl;

	//4. Sumowanie: std :: accumulate sumuje elementy wektora
	int suma = std::accumulate(vec.begin(), vec.end(), 0);
	std::cout << " Suma elementow: " << suma << std::endl;

	//5. Transformacja: std :: transform mnozy kazdy element przez 2 przy
	//uzyciu funkcji
	std::vector <int > wynik(vec.size());
	std::transform(vec.begin(), vec.end(), wynik.begin(), mnozPrzezDwa);
	std::cout << "Po transformacji (mnozenie przez 2): ";
	for (int val : wynik) {
		std::cout << val << " ";

	}
	std::cout << std::endl;

	//6. Wyswietlanie: std :: for_each z lambda
	std::cout << " Elementy wieksze niz 5 (lambda): ";
	std::for_each(vec.begin(), vec.end(), [](int val) {
		if (val > 5) {
			std::cout << val << " ";

		}
		});
	std::cout << std::endl;

	return 0;
}

//Program wykonuje sie poprawnie
