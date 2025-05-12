#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <deque>
#include "Book.h"
#include "Library.h"
using namespace std;

//Metoda void addBook() – dodaje ksiazke do listy
void Library::addBook(const Book& book){
	listOfBooks.push_back(book);
    cout << "Do biblioteki: " << getName() << ", ";
    cout << "dodano ksiazke: " << book.getTitle() << endl;
}

//Metoda void removeBook() – usuwa ksiake o podanym tytule
void Library::removeBook(const string& title){

    cout << endl << "Usunieto ksiazke: ";
    int index = 0;

    //Przeszukanie elementow
    for (auto element = listOfBooks.begin(); element != listOfBooks.end();) {

        if (element->getTitle() == title)
        {
            cout << element->getTitle() << endl;
            element = listOfBooks.erase(element);
        }
        else 
        {
            element++;
            index++;
        }
    }
}

//Metoda void borrowBook() – oznacza ksiazke jako wypozyczona i dodaje jej nazwe do kolejki
void Library::borrowBook(const string& title){
    cout << "Wypozyczono: ";
    int index = 0;

    //Przeszukanie elementow
    for (auto element = listOfBooks.begin(); element != listOfBooks.end();element++) {
        if (element->getTitle() == title)
        {
            element->borrow();
            cout << element->getTitle();
            //Dodaj ja do kolejki
            borrowList.push_back(element->getTitle());
        }
        index++;
        
    }
    cout << endl;
}

//Metoda void returnBook() – oznacza ksiazke jako zwrocona i usuwa jej nazwe z kolejki
void Library::returnBook(const string& title){

    int index = 0;

    //Przeszukanie elementow
    for (auto element = listOfBooks.begin(); element != listOfBooks.end();element++) {
        if (element->getTitle() == title)
        {
            cout << "Oddano ksiazke: " << element->getTitle() << endl;
            element->returnBook();

            //Usun ja z kolejki wypozyczonych
            for (int i = 0;i<borrowList.size();i++) {
                if (borrowList[i] == element->getTitle()) {
                    borrowList.erase(borrowList.begin() + i);
                }
            }
        }
        index++;

    }
}

//Metoda void returnBook() – wyswietla wszystkie dostepne ksiazki
void Library::showAvailableBooks(){
    cout << "Dostepne: " << endl;
    //Wyswietlenie elementow
    for (int i =0 ; i<listOfBooks.size();i++) {

        if (listOfBooks[i].getIs_available()) {
            cout << listOfBooks[i].getTitle() << endl;
        }
    }
}

//Metoda void returnBook() – wyswietla kolejke wypozyczen
void Library::showBorrowQueue() {
    cout << "Aktualnie wypozyczone: ";
    //Wyswietl liste wypozyczonych ksiazek
    for (int i = 0;i < borrowList.size();i++)
    {
        cout << borrowList[i] << endl << endl;
    }
    if (borrowList.size() == 0) { cout << "-" << endl;}
}

//Metoda void returnBook() – wyszukuje i wyswietla ksiazki danego autora
void Library::findBooksByAuthor(const string& author){

    bool toggle = true;
    cout << "W bibliotece: " << getName() << ", znaleziono nastepujace ksiazki autora: ";

    //Przeszukanie elementow
    for (auto element = listOfBooks.begin(); element != listOfBooks.end();element++) {

        if (element->getAuthor() == author)
        {
            if (toggle)
            {
                cout << element->getAuthor() << " " << endl;
                toggle = false;
            }
            cout << element->getTitle() << endl;
        }
    }
    cout << endl;
}

//Metoda void returnBook() – podaje liczbe dostepnych ksiazek, wypozyczonych ksiazek i calkowita liczbe ksiazek
void Library::statistics() {
    cout << endl;
    cout << getName() << " ma nastepujace statystyki:" << endl;
    cout << "Liczba dostepnych ksiazek: " << listOfBooks.size() << endl;
    cout << "Liczba wypozyczonych ksiazek: " << borrowList.size() << endl;
    cout << "Calkowita liczba ksiazek: " << listOfBooks.size() + borrowList.size() << endl << endl;
}

//Metoda int returnBook() – zwraca liczbe calkowita ksiazek
int Library::statistics(const string& wariant) const {
    if (wariant == "available") return listOfBooks.size();
    else if (wariant == "borrowed") return borrowList.size();
    else if (wariant == "total") return listOfBooks.size() + borrowList.size();
}

//Nadaje nazwe bibliotece
void Library::setName(string nazwa) {

    cout << "Powstala biblioteka :" << nazwa << endl;
    name = nazwa;
}

//Getter nazwy biblioteki
string Library::getName() const {
    return name;
}


