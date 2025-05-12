#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include "Book.h"
#include "Library.h"
using namespace std;

//Wyswietla nazwe kazdej biblioteki oraz liczbe ksiazek w niej przechowywanych
void showLibraries(vector<Library*>& libraries) {
	cout << endl;
	cout << "Wszystkie biblioteki : ";
	for (int i=0; i<libraries.size(); i++) {
		cout << libraries[i]->getName() << endl;
		libraries[i]->statistics("available");
	}
	cout << endl;
}

//Funckja
Library& findLibraryWithMostBooks(vector<Library*>& libraries) {
	Library* najwiekszaBiblioteka = nullptr; 
	int max = 0;

	for (auto* library : libraries) {
		int wszystkieKsiazki = library->statistics("total");

		if (wszystkieKsiazki > max) {
			max = wszystkieKsiazki;
			najwiekszaBiblioteka = library;
		}
	}
	cout << endl;
	cout << "Najwieksza biblioteka: " << najwiekszaBiblioteka->getName()
		 << ", ilosc ksiazek: " << max << endl << endl;
	return *najwiekszaBiblioteka;
}

//Sortuje biblioteki rosnaco pod wzgledem liczby ksiazek
void sortLibrariesByBooks(vector<Library*>& libraries) {

	for (int i = 0; i < libraries.size() - 1; i++) {
		for (int j = i + 1;j < libraries.size();j++) {
			if (libraries[i]->statistics("total") > libraries[j]->statistics("total")) {
				//Zamien
				Library* chwilowa;
				chwilowa = libraries[i];
				libraries[i] = libraries[j];
				libraries[j] = chwilowa;
			}
		}

	}
	cout << "Biblioteki posortowane rosnaco:" << endl;
	for (int i = 0;i<libraries.size();i++) {
		cout << i+1 << ". " << libraries[i]->getName() << ", ilosc ksiazek: " 
			<< libraries[i]->statistics("total") << endl;
	}
	cout << endl;
}

int main()
{
	cout << "***************************" << endl;
	cout << "Program zarzadza biblioteka" << endl;
	cout << "***************************" << endl << endl;

	//Wszystkie biblioteki
	vector<Library*> libraries;

	//Stworz kilka bibliotek i dodaj do nich ksiazki
	Library library1;
	library1.setName("Biblioteka w Niniwie");
	Library library2;
	library2.setName("Biblioteka Aleksandryjska");
	Library library3;
	library3.setName("Biblioteka Pergamonska");
	Library library4;
	library4.setName("Biblioteka Serapeum");
	cout << "---------------------------------------------------------------" << endl;

	//Dodanie ksiazek do wektora bibliotek
	libraries.push_back(&library1);
	libraries.push_back(&library2);
	libraries.push_back(&library3);
	libraries.push_back(&library4);

	//Utworz kilka obiektow klasy book
	Book book1 = Book("Epos o Gilgameszu", "Nieznany", -2100, true);
	Book book2 = Book("Zbior praw Hammurabiego", "Hammurabi", -1754, true);
	Book book3 = Book("Rytualy swiatynne Mezopotamii", "Nieznany", -1800, true);

	Book book4 = Book("Geografia", "Eratostenes", -240, true);
	Book book5 = Book("Historia Grecji", "Manetho", -280, true);
	Book book6 = Book("O mechanice", "Archimedes", -250, true);
	Book book7 = Book("Fizyka", "Arystoteles", -330, true);
	Book book8 = Book("Logika", "Arystoteles", -335, true);
	Book book9 = Book("Mapy Ptolemeusza", "Klaudiusz Ptolemeusz", 150, true);
	Book book10 = Book("Kosmologia hellenska", "Nieznany", -200, true);
	Book book11 = Book("O sztuce wojennej", "Polibiusz", -150, true);
	Book book12 = Book("Medycyna Hipokratesa", "Hipokrates", -400, true);
	Book book13 = Book("O astronomii", "Hipparchos", -190, true);

	Book book14 = Book("O sztuce medycznej", "Herofilos", -280, true);
	Book book15 = Book("Mitologia hellenistyczna", "Nieznany", -200, true);
	Book book16 = Book("Sztuka retoryki", "Hermagoras", -150, true);
	Book book17 = Book("Pergamin i jego zastosowanie", "Kaplani z Pergamonu", -190, true);
	Book book18 = Book("O sztuce dramatycznej", "Menander", -300, true);
	Book book19 = Book("Historia Pergamonu", "Eumenes II", -160, true);

	Book book20 = Book("Ksiega Ozyrysa", "Nieznany", -300, true);
	Book book21 = Book("Astrologia starozytnego Egiptu", "Nieznany", -280, true);
	Book book22 = Book("Rytualy swiatyni Serapisa", "Kaplani Serapeum", -250, true);
	Book book23 = Book("Kaplani i ich role", "Nieznany", -200, true);

	//Dodawanie ksiazek do bibliotek
	library1.addBook(book1);
	library1.addBook(book2);
	library1.addBook(book3);
	cout << endl;
	library2.addBook(book4);
	library2.addBook(book5);
	library2.addBook(book6);
	library2.addBook(book7);
	library2.addBook(book8);
	library2.addBook(book9);
	library2.addBook(book10);
	library2.addBook(book11);
	library2.addBook(book12);
	library2.addBook(book13);
	cout << endl;
	library3.addBook(book14);
	library3.addBook(book15);
	library3.addBook(book16);
	library3.addBook(book17);
	library3.addBook(book18);
	library3.addBook(book19);
	cout << endl;
	library4.addBook(book20);
	library4.addBook(book21);
	library4.addBook(book22);
	library4.addBook(book23);
	cout << "---------------------------------------------------------------" << endl;
	//Wypozycz kilka ksiazek, sprawdz kolejke wypozyczen i wyswietl statystyki
	library1.statistics();
	library1.borrowBook("Zbior praw Hammurabiego");
	library1.showAvailableBooks();
	library1.showBorrowQueue();
	library1.returnBook("Zbior praw Hammurabiego");
	library1.showAvailableBooks();
	library1.showBorrowQueue();
	library1.removeBook("Zbior praw Hammurabiego");
	library1.showAvailableBooks();
	library1.statistics();
	cout << "---------------------------------------------------------------" << endl;
	//Wypozycz kilka ksiazek, sprawdz kolejke wypozyczen i wyswietl statystyki
	library2.statistics();
	library2.borrowBook("O sztuce wojennej");
	library2.showAvailableBooks();
	library2.showBorrowQueue();
	library2.returnBook("O sztuce wojennej");
	library2.showAvailableBooks();
	library2.showBorrowQueue();
	library2.removeBook("O sztuce wojennej");
	library2.showAvailableBooks();
	library2.statistics();
    cout << "---------------------------------------------------------------" << endl;
	//Wypozycz kilka ksiazek, sprawdz kolejke wypozyczen i wyswietl statystyki
	library3.statistics();
	library3.borrowBook("O sztuce dramatycznej");
	library3.showAvailableBooks();
	library3.showBorrowQueue();
	library3.returnBook("O sztuce dramatycznej");
	library3.showAvailableBooks();
	library3.showBorrowQueue();
	library3.removeBook("O sztuce dramatycznej");
	library3.showAvailableBooks();
	library3.statistics();
	cout << "---------------------------------------------------------------" << endl;	
	//Wypozycz kilka ksiazek, sprawdz kolejke wypozyczen i wyswietl statystyki
	library4.statistics();
	library4.borrowBook("Rytualy swiatyni Serapisa");
	library4.showAvailableBooks();
	library4.showBorrowQueue();
	library4.returnBook("Rytualy swiatyni Serapisa");
	library4.showAvailableBooks();
	library4.showBorrowQueue();
	library4.removeBook("Rytualy swiatyni Serapisa");
	library4.showAvailableBooks();
	library4.statistics();
	cout << "---------------------------------------------------------------" << endl;
	//Przeprowadz operacje globalne: wyszukaj biblioteke z najwieksza liczba ksiazek oraz posortuj biblioteki
	//Wyswietl wyniki dzialania funkcji i metod

	//Szukanie po autorze
	cout << endl;
	library1.findBooksByAuthor("Nieznany");
	library2.findBooksByAuthor("Arystoteles");
	library3.findBooksByAuthor("Nieznany");
	library4.findBooksByAuthor("Nieznany");
	cout << "---------------------------------------------------------------" << endl;

	//Wyswietl wszystkie biblioteki i ilosc ksiazek
	showLibraries(libraries);
	cout << "---------------------------------------------------------------" << endl;

	//Wyswietl liblioteke z najwieksza liczba ksiazek
	findLibraryWithMostBooks(libraries);

	//Sortuj biblioteki 
	sortLibrariesByBooks(libraries);

	cout << "Koniec programu." << endl;
	cout << "Ewelina Jurkiewicz, Gr. 5." << endl;
	return 0;
}