#include <iostream>
#include <string>

int main() {

	// 1. Konstruktory
	std::string str1; // Domyslny konstruktor
	std::string str2("Hello"); // Z lancucha znakow
	std::string str3(5, 'A'); // Powielenie znaku : " AAAAA "

	// 2. Metody manipulacji
	str1.append("World"); // Dodawanie
	str1 += "World"; // Alternatywne dodawanie
	str2.insert(5, "C++"); // Wstawianie
	str2.erase(5, 3); // Usuwanie
	str2.replace(5, 5, "World"); // Zamiana

	// 3. Dostep do znakow
	char c1 = str2[0]; // Indeksowanie
	char c2 = str2.at(0); // Bezpieczny dostep

	// 4. Rozmiar i zarzadzanie
	size_t len = str2.size(); // Dlugosc
	size_t len2 = str2.length(); // Alternatywna dlugosc
	str2.resize(10); // Zmiana rozmiaru
	str2.clear(); // Oproznienie
	bool isEmpty = str2.empty(); // Sprawdzenie czy pusty


	// 5. Operacje wyszukiwania
	size_t pos1 = str1.find("World"); // Znalezienie podciagu
	size_t pos2 = str1.rfind("World"); // Ostatnie wystapienie
	size_t pos3 = str1.find_first_of("aeiou"); // Szukanie jednego z znakow

	// 6. Konwersja
	const char* cstr = str1.c_str(); // Do tablicy znakow
	std::string str4 = std::to_string(123); // Ze znakow

	// 7. Porownywanie
	if (str1 == str2) {
		std::cout << " str1 i str2 sa rowne \n";

	}

	if (str1 != str2) {
		std::cout << " str1 i str2 nie sa rowne \n";

	}	return 0;}//Program nie moze sie wykonac z powodu:// - braku nawiasu prawostronnego w warunku if (str1 != str2)// - braku zakonczenia funkcji main() - return 0;// - blad w konstruktorze obiektu str3, zamiast ’A’ -> 'A'// - str2.replace(6, 5, "World"); // Zamiana - polecenie wychodzi poza zakres obiektu str2