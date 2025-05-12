#pragma once
#include <iostream>
#include <list>
#include "MovieRatingSystem.h"
using namespace std;

//Metoda void addMovie(string& movieName, double rating) – dodaje film z poczatkowa ocena
void MovieRatingSystem::addMovie(const string& movieName, double rating){
	movieRatings[movieName].push_back(rating);
	cout << "Dodano film: " << movieName << endl;
}

//Metoda void addRating(string& movieName) – dodaje nowa ocene do filmu
void MovieRatingSystem::addRating(const string& movieName, double rating){
	movieRatings[movieName].push_back(rating);
	cout << "Dodano ocene filmu: " << movieName << ", ocena: " << rating << endl;
}	

//Metoda void removeMovie(const std::string& movieName) — usuwa film z systemu
void MovieRatingSystem::removeMovie(const string& movieName){
	movieRatings.erase(movieName);
	cout << "Usunieto film: " << movieName << endl;
}

//Metoda void getMovieRatting(const std::string& movieName) — zwraca srednia ocen filmu
double MovieRatingSystem::getMovieRatting(const std::string& movieName){

	double sredniaOcen = 0;

	for (int i = 0;i < movieRatings[movieName].size();i++) {
		sredniaOcen += movieRatings[movieName][i];
	}
	sredniaOcen /= movieRatings[movieName].size();
	sredniaOcen = round(sredniaOcen * 100) / 100;
	return sredniaOcen;
}

//Metoda void getMovieCount(const string& movieName) — zwraca liczbe ocen dla filmu
int MovieRatingSystem::getMovieCount(const string& movieName){

	int iloscOcen = 0;

	for (int i = 0;i < movieRatings[movieName].size();i++) {
		iloscOcen ++;
	}
	cout << "Liczba ocen: " << iloscOcen << endl;
	return iloscOcen;
}

//Metoda void showAllMovies() — wyswietla wszystkie filmy i ich srednie oceny
void MovieRatingSystem::showAllMovies(){
	cout << "Wszystkie filmy i ich srednie oceny: " << endl;
	for (auto it = movieRatings.begin(); it != movieRatings.end(); ++it) {
		cout << it->first << ": " << getMovieRatting(it->first) << endl;
	}
}

//Metoda void getHighestRatedMovie() — zwraca film o najwyzszej sredniej ocenie
pair <string,double> MovieRatingSystem::getHighestRatedMovie(){
	cout << "Najwyzej oceniony film: " << endl;

	double najwyzszaOcena = movieRatings.begin()->second[0];
	string kluczOceny = movieRatings.begin()->first;

	for (map <string, vector<double>>::iterator it = movieRatings.begin(); it != movieRatings.end
	(); ++it) {
		if (najwyzszaOcena < getMovieRatting(it->first)) {
			najwyzszaOcena = getMovieRatting(it->first);
			kluczOceny = it->first;
		}
	}
	auto it = movieRatings.find(kluczOceny);
	cout << it->first << ": " << najwyzszaOcena << endl;
	return {it->first,najwyzszaOcena};
}

//Metoda void getLowestRatedMovie() — zwraca film o najnizszej sredniej ocenie
pair <string, double> MovieRatingSystem::getLowestRatedMovie(){
	cout << "Najnizesz oceniony film: " << endl;

	double najnizszaOcena = 10;
	string kluczOceny = movieRatings.begin()->first;

	for (map <string, vector<double>>::iterator it = movieRatings.begin(); it != movieRatings.end
	(); ++it) {
		if (najnizszaOcena > getMovieRatting(it->first)) {
			najnizszaOcena = getMovieRatting(it->first);
			kluczOceny = it->first;
		}
	}
	auto it = movieRatings.find(kluczOceny);
	cout << it->first << ": " << najnizszaOcena << endl;
	return {it->first,najnizszaOcena};
}

//Metoda void showSortedMoviesByRating() — wyswietla filmy posortowane wedlug ocen
//(od najwyzszej do najnizszej)
void MovieRatingSystem::showSortedMoviesByRating(){
	cout << "Filmy posortowane malejaco: " << endl;

	multimap <double, string> filmyPosortowaneOcenami;
	int index = 1;

	//Przepisanie map do multimap wg oceny jako klucz
	for (auto it = movieRatings.begin(); it != movieRatings.end(); ++it) {
		filmyPosortowaneOcenami.insert({ getMovieRatting(it->first), it->first });
	}

	//Wyswietlenie odwroconego multimap
	for (auto it = filmyPosortowaneOcenami.rbegin(); it != filmyPosortowaneOcenami.rend(); ++it) {
		cout << index <<". " << it->second << ", srednia ocena : " << it->first << endl;
		index++;
	}
}

//Metoda void getAverageRating() — zwraca srednia ocene wszystkich filmow w systemie
double MovieRatingSystem::getAverageRating(){

	double sredniaOcenaWszystkichFilmow = 0;
	int iloscFilmow=0;

	for (auto it = movieRatings.begin(); it != movieRatings.end(); ++it) {
		iloscFilmow++;
		sredniaOcenaWszystkichFilmow += getMovieRatting(it->first);
	}
	sredniaOcenaWszystkichFilmow /= iloscFilmow;
	return sredniaOcenaWszystkichFilmow;
}

//Metoda void getMoviesWithRatingAbove(double threshold) — zwraca liste filmow z ocena
//wyzsza niz podany prog
list<string> MovieRatingSystem::getMoviesWithRatingAbove(double threshold){
	list <string> filmyPowyzejProgu;

	for (auto it = movieRatings.begin(); it != movieRatings.end(); ++it) {
		if (threshold < getMovieRatting(it->first)) {
			filmyPowyzejProgu.push_back(it->first);
		}
	}
	return filmyPowyzejProgu;
}

