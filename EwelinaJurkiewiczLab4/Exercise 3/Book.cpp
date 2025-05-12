#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include "Book.h"
using namespace std;

//Metoda void show() – wyswietlajaca informacje o ksiazce
void Book::show() {
	cout << "Title: " << title << ", author: " << author << ", year: " << year << ", is available: " << is_available << ".";
}

//Metoda void borrow() – zmienia dostepnosc ksiazki na false
void Book::borrow() {
	is_available = false;
}

//Metoda void returnBook() – zmienia dostepnosc ksiazki na true
void Book::returnBook() {
	is_available = true;
}

//Getter pola title
string Book::getTitle() const {
	return title;
}

//Getter pola author
string Book::getAuthor() {
	return author;
}

//Getter pola year
int Book::getYear() {
	return year;
}

//Getter pola is_available
bool Book::getIs_available() {
	return is_available;
}
