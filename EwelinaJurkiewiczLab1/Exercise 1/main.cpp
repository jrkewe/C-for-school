# include <iostream>
# include <string>
using namespace std;

class Pojazd {
protected:
	string marka;
	int rokProdukcji;
	public:
	// Konstruktor
	Pojazd(string m, int r) : marka(m), rokProdukcji(r) 
	{
		cout << "---------------------------------------------------------------" << endl;
		cout << "Konstruktor klasy Pojazd." << endl;
	}

	//Wirtualny destruktor
	virtual ~Pojazd() {}

		// Metoda do wyswietlania informacji o pojezdzie
		void wyswietlInformacje() const
		{
		cout << " Marka : " << marka << ", Rok produkcji : " << rokProdukcji << endl;
		}

};

class Samochod : public Pojazd {
private:
	int liczbaDrzwi;

public:
	// Konstruktor
	Samochod(string m, int r, int drzwi) : Pojazd(m, r), liczbaDrzwi(drzwi) {}

	// Metoda do wyswietlania informacji o samochodzie
	void wyswietlInformacje() const {
		Pojazd::wyswietlInformacje(); // Wywolanie metody z klasy bazowej
		cout << " Liczba drzwi : " << liczbaDrzwi << endl;
	}
};

class Motor : public Pojazd {
private:
	string typSilnika;

public:
	// Konstruktor domyslny
	Motor() : Pojazd("Nieznana marka", 0), typSilnika("Nieznany typ") {}

	// Konstruktor inicjalizujacy korzystajacy z parametrycznego konstruktora klasy bazowej
	Motor(string m, int r, string silnik) : Pojazd(m, r), typSilnika(silnik) 
	{
		cout << "Konstruktor klasy Motor." << endl;
		cout << "---------------------------------------------------------------" << endl;
	}
	
	// Metoda do wyswietlania informacji o motorze
	void wyswietlInformacje() const {
		//Pojazd::wyswietlInformacje(); // Wywolanie metody z klasy bazowej
		//pelne przesloniecie
		cout << "Marka: " << marka << ", rok produkcji: " << rokProdukcji << ", typSilnika: " 
			<< typSilnika << endl;
	}

	//Setter przypisujacy wartosc pola - typSilnika
	void setTypSilnika(string silnik) {
		typSilnika = silnik;
	}

	//Getter zwracajacy wartosc pola - typSilnika
	string getTypSilnika(string silnik) {
		return typSilnika;
	}
};

//Liczba motorow
const int liczbaMotorow = 3;

int main() {
	cout << "************************************************************" << endl;
	cout << "Program alokuje statycznie i dynamicznie obiekty klasy Motor" << endl;
	cout << "************************************************************" << endl << endl;

	//Alokacja statyczna
	cout << "Przyklad alokacji statycznej" << endl;
	cout << endl;

	// Tworzenie obiektow klas pochodnych
	cout << "Samochod mojSamochod" << endl;
	Samochod mojSamochod(" Toyota ", 2020, 5);
	
	// Wyswietlanie informacji o obiektach
	cout << " Informacje o samochodzie :" << endl << endl;
	mojSamochod.wyswietlInformacje();
	cout << endl;
	//------------------------------------------------
	//• Stworzyc tablice statycznych obiektow klasy Motor i zainicjalizowac ja przykladowymi danymi.
	Motor motoryStatyczne[liczbaMotorow] = 
	{
		Motor("Yamaha", 2019, "Spalinowy"),
		Motor("Honda", 2021, "Elektryczny"),
		Motor("Suzuki", 2020, "Elektryczny"),
	};

	//------------------------------------------------
	//• Stworzyc dynamiczna tablice obiektow klasy Motor i zainicjalizowac ja w petli, odczytujcc dane
	//od uzytkownika.
	
	//Alokacja dynamiczna
	cout << "---------------------------------------------------------------" << endl;
	cout << "Przyklad alokacji dynamicznej" << endl;
	cout << endl;

	//Dynamiczna alokacja tablicy obiektow klasy Motor
	Motor* motoryDynamiczne = new Motor[liczbaMotorow];
	for (int i = 0; i < liczbaMotorow; i++) 
	{
		string marka;
		string typSilnika;
		int rokProdukcji;
		cout << "---------------------------------------------------------------" << endl;
		cout << "Wprowadz dane dla motoru " << i + 1 << ": " << endl;
		cout << "Marka: ";
		cin >> marka;
		cout << "Rok produkcji: ";
		cin >> rokProdukcji;
		cout << "Typ silnika: ";
		cin >> typSilnika;
		cout << endl;

		//Tworzenie obiektu i przypisanie do tablicy
		motoryDynamiczne[i] = Motor(marka, rokProdukcji, typSilnika);
	}
	//------------------------------------------------
	//• Przetestowac metode wyswietlInformacje() dla roznych obiektow klasy Motor.
	cout << "---------------------------------------------------------------" << endl;
	cout << "Test metody wyswietlInformacje()" << endl;
	cout << "- dla obiektow alokowanych statycznie" << endl;
	for (int i=0;i<liczbaMotorow;i++) 
	{
		motoryStatyczne[i].wyswietlInformacje();
		cout << endl;
	}
	cout << endl;
	cout << "- dla obiektow alokowanych dynamicznie" << endl;
	for (int i = 0;i < liczbaMotorow;i++)
	{
		motoryDynamiczne[i].wyswietlInformacje();
		cout << endl;
	}

	//------------------------------------------------
	//• Dodatkowo przetestowac mechanizm dziedziczenia metody klasy bazowej Pojazd.
	cout << "---------------------------------------------------------------" << endl;
	cout << "Test dziedziczenia metody klasy bazowej Pojazd" << endl;
	cout << "- dla obiektow alokowanych statycznie" << endl;
	
	//Obiekt moj samochod
	mojSamochod.Pojazd::wyswietlInformacje();
	cout << endl;

	//Obiekty statyczne
	for (int i = 0;i < liczbaMotorow;i++)
	{
		motoryStatyczne[i].Pojazd::wyswietlInformacje();
		cout << endl;
	}
	cout << endl;
	cout << "- dla obiektow alokowanych dynamicznie" << endl;

	//Obiekty dynamiczne
	for (int i = 0;i < liczbaMotorow;i++)
	{
		motoryDynamiczne[i].Pojazd::wyswietlInformacje();
		cout << endl;
	}

	//Dealokacja
	delete[] motoryDynamiczne;
	
	cout << "---------------------------------------------------------------" << endl;

	cout << "Koniec programu." << endl;
	cout << "Ewelina Jurkiewicz, Gr. 5." << endl;
	
	return 0;
}