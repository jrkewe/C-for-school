#include <iostream>
#include <map>
#include <utility> //Dla std :: pair

int main() {
//Tworzymy mape przechowujaca pary : (int, std::string )
 std::map <int, std::string > m;

 //Dodawanie elementow przy uzyciu std::pair
 m.insert(std::make_pair(1, "Apple"));
 m.insert(std::make_pair(2, "Banana"));
 m.insert(std::make_pair(3, "Cherry"));

 //Wyswietlanie elementow mapy za pomoca iteratora
	for (std::map <int, std::string >::iterator it = m.begin(); it != m.end(); ++it) {
		std::cout << "Klucz :" << it->first << ", Wartosc : " << it->second <<
		std::endl;
	}

	return 0;}//Kod wykonuje sie poprawnie.//Dolaczenie bibliotek - utility jest zbedne, gdyz make_pair znajduje sie juz w bibliotece map//Do wyswietlania obiektow mapy mozna zastosowac petle for-each