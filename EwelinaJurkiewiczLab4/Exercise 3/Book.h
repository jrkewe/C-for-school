#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

class Book {
protected:
	string title;
	string author;
	int year;
	bool is_available;

public:
	//Konstruktor bezargumentowy
	Book() {
		title = "heading";
		author = "name";
		year = 0;
		is_available = true;
	};

	//Lista inicjalizacyjna konstruktora
	Book(string heading, string name, int years, bool accessible) : title(heading), author(name), year(years), is_available(accessible){}

	//Destruktor
	~Book() {}

	//Metoda void show() – wyswietlajaca informacje o ksiazce
	void show();

	//Metoda void borrow() – zmienia dostepnosc ksiazki na false
	void borrow();

	//Metoda void returnBook() – zmienia dostepnosc ksiazki na true
	void returnBook();

	//Getter pola title
	string getTitle() const;

	//Getter pola author
	string getAuthor();

	//Getter pola year
	int getYear();

	//Getter pola is_available
	bool getIs_available();
};