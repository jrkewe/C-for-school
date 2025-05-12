#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <deque>
#include "Book.h"
using namespace std;

class Library {
protected:
	vector <Book> listOfBooks;
	deque<string> borrowList;
	string name;

public:
	//Konstruktor bezargumentowy
	Library() {}

	//Destruktor
	~Library() {}

	//Metoda void addBook() – dodaje ksiazke do listy
	void addBook(const Book& book);

	//Metoda void borrow() – usuwa ksiake o podanym tytule
	void removeBook(const string& title);

	//Metoda void borrow() – oznacza ksiazke jako wypozyczona i dodaje jej nazwe do kolejki
	void borrowBook(const string& title);
	
	//Metoda void borrow() – oznacza ksiazke jako zwrocona i usuwa jej nazwe z kolejki
	void returnBook(const string& title);

	//Metoda void returnBook() – wyswietla wszystkie dostepne ksiazki
	void showAvailableBooks();

	//Metoda void returnBook() – wyswietla kolejke wypozyczen
	void showBorrowQueue();

	//Metoda void returnBook() – wyszukuje i wyswietla ksiazki danego autora
	void findBooksByAuthor(const string& author);

	//Metoda void returnBook() – podaje liczbe dostepnych ksiazek, wypozyczonych ksiazek i calkowita liczbe ksiazek
	void statistics();

	//Metoda int returnBook() – zwraca liczbe calkowita ksiazek
	int statistics(const string& wariant) const;
	
	//Nadaje nazwe bibliotece
	void setName(string nazwa);

	//Getter nazwy biblioteki
	string getName() const;
};
