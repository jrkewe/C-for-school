#include <iostream>
using namespace std;

template <typename T>
class MyClass 
{
	public:
		void display() 
		{
			cout << "General display for type : " << typeid (T).name() << endl;
		}
		
		void specializedMethod() 
		{
			cout << "General specializedMethod" << endl;
		}
};

//Specjalizacja metody dla typu int
template <>
void MyClass <int>::specializedMethod() 
{	
	cout << "Specialized specializedMethod for int" << endl;
}

//Dodatkowa specjalizacja metody dla typu bool
template <>
void MyClass <bool>::specializedMethod()
{
	cout << "Specialized specializedMethod for bool" << endl;
}

int main() 
{
	cout << "****************************************************************" << endl;
	cout << "Program demonstruje uzycie specjalizacji metod klasy szablonowej" << endl;
	cout << "****************************************************************" << endl << endl;

	MyClass <double> obj1;
	obj1.display(); //General display for type : double
	obj1.specializedMethod(); //General specializedMethod
	
	MyClass <int> obj2;
	obj2.display(); //General display for type : int
	obj2.specializedMethod(); //Specialized specializedMethod for int

	MyClass <bool> obj3;
	obj3.display(); //General display for type : bool
	obj3.specializedMethod(); //Specialized specializedMethod for bool


	cout << endl;
	cout << "Koniec programu." << endl;
	cout << "Ewelina Jurkiewicz, Gr. 5." << endl;
	return 0;
}/*Wynik analizy koduKod dziala poprawnie. Jednak warto zauwazyc ze dla zmiennych innego typu niz int i bool metoda specializedMethod()wyswietli jedynie komunikat "General specializedMethod". Nie poinformuje programisty o braku odpowiedniejspecjalizacji metody dla nowego typu.*/