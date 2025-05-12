#include <iostream>
#include <functional>
#include <vector>
#include <map>
#include "GeneratorLiczb.h"
using namespace std;

int main() {
	cout << "****************************************************" << endl;
	cout << "Program demonstruje sortowanie z uzyciem komparatora" << endl;
	cout << "****************************************************" << endl << endl;
	//Deklaracja wektora
	vector<int> numbers;
	//Dlugosci wektora
	int dlugoscWektora = generujLosowaWartosc(5, 15);
	//Elementy wektora
	for (int i = 0; i < dlugoscWektora;i++) {
		numbers.push_back(generujLosowaWartosc(1, 999));
	}

	//Wyswietlenie wektora z uzyciem lambda
	cout << "Wektor: ";
	for_each(numbers.begin(), numbers.end(), [](int element) {
		cout << element << " ";
		});
	cout << endl << endl;

	//Lambda dla countDigits
	auto countDigits = [](int n) -> int {
		int iloscCyfr = 0;
		while (n > 0) {
			iloscCyfr++;
			n /= 10;
		}
		return iloscCyfr;
	};

	//Lambda dla sumDigits
	auto sumDigits = [&countDigits](int n) -> int {
		int suma = 0;
		while (n > 0) {
			suma += n % 10;
			n /= 10;
		}
		return suma;
	};

	//Sortowanie rosnaco wg sumy cyfr liczby
	cout << "Sortowanie rosnaco" << endl;
	sort(numbers.begin(), numbers.end(), [&sumDigits](int a, int b) {
		return sumDigits(a) < sumDigits(b);
		});

	//Wyswietlenie wektora z uzyciem lambda
	cout << "Wynik:  ";
	for_each(numbers.begin(), numbers.end(), [](int element) {
		cout << element << " ";
		});
	cout << endl << endl;

	//Sortowanie malejaco wg sumy cyfr liczby
	cout << "Sortowanie malejaco" << endl;
	sort(numbers.begin(), numbers.end(), [&sumDigits](int a, int b) {
		return sumDigits(a) > sumDigits(b);
		});

	//Wyswietlenie wektora z uzyciem lambda
	cout << "Wynik:  ";
	for_each(numbers.begin(), numbers.end(), [](int element) {
		cout << element << " ";
		});
	cout << endl << endl;

	cout << "Koniec programu." << endl;
	cout << "Ewelina Jurkiewicz, Gr. 5." << endl;
	return 0;
}