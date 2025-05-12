#pragma
# include <iostream>
using namespace std;

//Klasa bazowa (abstrakcyjna)
class Pojazd {
public:
	//Czysto wirtualna metoda - musi byc zaimplementowana w klasach pochodnych

	//Czysto wirtualna funkcja (brak implementacji)
	virtual void opis() const = 0;

	//Wirtualny destruktor
	virtual ~Pojazd() {}

	//Zmodyfikuj klase Pojazd, dodajac czysto wirtualna metode liczbaKol(), ktora zwroci liczbe
	//kol pojazdu. Kazda klasa pochodna musi zaimplementowac te metode, aby zwrocic liczbe kol
	//specyficzna dla danego pojazdu.
	//Zaktualizowana definicja klasy Pojazd powinna zawierac metode virtual int liczbaKol()
	//const = 0;.
	virtual int liczbaKol() const = 0;

};

//Klasa pochodna : Samochod
class Samochod : public Pojazd {
public:
	//Nadpisanie czysto wirtualnej metody
	void opis() const override {
		cout << "To jest samochod ." << endl;
	}

	int liczbaKol() const override
	{
		return 4;
	}

};

//Klasa pochodna : Rower
class Rower : public Pojazd {
public:
	//Nadpisanie czysto wirtualnej metody
	void opis() const override {
		cout << "To jest rower ." << endl;
	}

	int liczbaKol() const override
	{
		return 2;
	}

};

//Dodaj klase Motocykl, dziedziczaca po klasie Pojazd, ktora zawiera:
//– konstruktor inicjalizujacy sk?ldowe klasy Motocykl oraz korzystajacy z parametrycznego
//  konstruktora klasy bazowej Pojazd,
//– metode opis(), ktora bedzie implementowac unikalny opis motocyklu (np. "To jest motocykl."),
//– metod? liczbaKol(), ktora zwroci liczbe kol w motocyklu(zwykle 2).

//Klasa pochodna : Motocykl
class Motocykl : public Pojazd {
public:
	//Konstruktor argumentowy pozwalajacy na zainicjalizowanie pol klasy
	Motocykl() : Pojazd() {}

	//Nadpisanie czysto wirtualnej metody
	void opis() const override {
		cout << "To jest motocykl ." << endl;
	}

	int liczbaKol() const override
	{
		return 2;
	}

};

//Funkcja glowna
int main() {

	cout << "************************************************************" << endl;
	cout << "Program demonstruje uzycie polimorfizmu dynamicznego" << endl;
	cout << "************************************************************" << endl << endl;

	//Wskazniki do klasy bazowej (Pojazd), ale tworzymy obiekty klas pochodnych
	//Wskaznik na Samochod
	Pojazd* pojazd1 = new Samochod();
	// Wskaznik na Rower
	Pojazd* pojazd2 = new Rower();
	// Wskaznik na Rower
	Pojazd* pojazd3 = new Motocykl();

	//Wprowadz tablice wskaznikow do klasy Pojazd, w ktorej przechowywane beda obiekty roznych
	//klas pochodnych

	Pojazd* pojazdy[3];

	for (int i = 0;i<3;i++)
	{
		if (i==0) {
			pojazdy[i] = pojazd1;
			//Sprawdzenie, czy alokacja zakonczyla sie sukcesem
			if (pojazdy[i] == nullptr) {
				cerr << "Blad: Nie udalo sie zaalokowac pamieci dla pojazdu o indeksie " << i << "." << endl;
				return -1;
			}
		}
		else if (i == 1) {
			pojazdy[i] = pojazd2;
			//Sprawdzenie, czy alokacja zakonczyla sie sukcesem
			if (pojazdy[i] == nullptr) {
				cerr << "Blad: Nie udalo sie zaalokowac pamieci dla pojazdu o indeksie " << i << "." << endl;
				return -1;
			}
		}
		else if (i == 2) {
			pojazdy[i] = pojazd3;
			//Sprawdzenie, czy alokacja zakonczyla sie sukcesem
			if (pojazdy[i] == nullptr) {
				cerr << "Blad: Nie udalo sie zaalokowac pamieci dla pojazdu o indeksie " << i << "." << endl;
				return -1;
			}
		}
	}

	//Zastosuj polimorfizm, wywolujac odpowiednia metode opis() oraz liczbaKol()
	//dla kazdego obiektu w tablicy

	//Polimorfizm dynamiczny (wirtualne metody)
	cout << "Polimorfizm dynamiczny (metoda wirtualna):" << endl;

	//Szkoda nie skorzystac z tablicy 
	for (int i = 0;i<3;i++)
	{
		pojazdy[i]->opis();
		delete pojazdy[i];
	}

	//Wywolanie metody z klasy Samochod
	//pojazd1 -> opis();
	////Wywolanie metody z klasy Samochod
	//pojazd1->opis();
	////Wywolanie metody z klasy Motocykl
	//pojazd3->opis();

	//Zwolnienie pamieci
	//delete pojazd1;
	//delete pojazd2;
	//delete pojazd3;

	cout << endl;
	cout << "Koniec programu." << endl;
	cout << "Ewelina Jurkiewicz, Gr. 5." << endl;

	return 0;
}
