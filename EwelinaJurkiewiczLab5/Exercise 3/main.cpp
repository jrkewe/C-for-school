#pragma once
#include <iostream>
#include "MovieRatingSystem.h"
#include "GeneratorLiczb.h"
using namespace std;

vector<tuple<string, double, double, int>> listaFilmow = {
	{"Ojciec chrzestny", 8.9, 9.5, 7},
	{"Skazani na Shawshank", 9.0, 9.6, 10},
	{"Pulp Fiction", 8.4, 9.4, 8},
	{"Forrest Gump", 8.3, 9.3, 8},
	{"Incepcja", 8.3, 9.3, 9},
	{"Matrix", 8.2, 9.2, 7},
	{"Lista Schindlera", 8.5, 9.5, 5},
	{"Gwiezdne wojny: Czesc V - Imperium kontratakuje", 8.2, 9.2, 5},
	{"Wladca Pierscieni: Powrot Krola", 8.4, 9.4, 7},
	{"Podziemny krag", 8.3, 9.3, 8}
};

int main()
{
	cout << "**************************************" << endl;
	cout << "Program zarzadza systemem oceny filmow" << endl;
	cout << "**************************************" << endl << endl;

	//Utworz obiekt klasy MovieRatingSystem
	MovieRatingSystem movieRatings;

	////Dodaj filmy do systemu oraz ocen je
	//Dodano filmy
	for (int i = 0; i<listaFilmow.size() ;i++) {
		movieRatings.addMovie(get<0>(listaFilmow[i]), 0.00);
	}
	cout << "---------------------------------------------------------------" << endl;

	//Dodano oceny
	for (int i = 0; i < listaFilmow.size();i++) {

		int iloscOcen = get<3>(listaFilmow[i])/2;

		for (int j = 0; j < iloscOcen;j++) {

			string tytul = get<0>(listaFilmow[i]);
			double dolnyProg = get<1>(listaFilmow[i]);
			double gornyProg = get<2>(listaFilmow[i]);
			double ocena = generujLosowaWartosc(dolnyProg, gornyProg);

			movieRatings.addRating(tytul, ocena);
		}
	}
	cout << "---------------------------------------------------------------" << endl;

	//Srednia ocena dla wybranego filmu - Skazani na Shawshank
	cout << "Srednia wybranego filmu: " << get<0>(listaFilmow[1]) << endl;
	cout << movieRatings.getMovieRatting(get<0>(listaFilmow[1])) << endl;
	cout << "---------------------------------------------------------------" << endl;

	////Dodaj kolejne oceny i wyswietl wszystkie filmy oraz ich srednie oceny
	//Dodano kolejne oceny
	for (int i = 0; i < listaFilmow.size();i++) {

		int iloscOcen = get<3>(listaFilmow[i]) / 2;

		for (int j = 0; j < iloscOcen;j++) {

			string tytul = get<0>(listaFilmow[i]);
			double dolnyProg = get<1>(listaFilmow[i]);
			double gornyProg = get<2>(listaFilmow[i]);
			double ocena = generujLosowaWartosc(dolnyProg, gornyProg);

			movieRatings.addRating(tytul, ocena);
		}
	}
	cout << "---------------------------------------------------------------" << endl;

	//Wyswietlenie wszystkich filmow
	movieRatings.showAllMovies();
	cout << "---------------------------------------------------------------" << endl;

	//Wyswietlenie ich srednich ocena
	for (int i = 0; i < listaFilmow.size();i++) {
		cout << "Srednia ocen filmu: " << get<0>(listaFilmow[i]) << " - ";
		cout << movieRatings.getMovieRatting(get<0>(listaFilmow[i])) << endl;
		//Liczbe ocen dla filmu
		movieRatings.getMovieCount(get<0>(listaFilmow[i]));
	}
	cout << "---------------------------------------------------------------" << endl;

	////Wyszukano filmy o najwyzszej oraz najnizszej sredniej ocen
	//Film o najwyzszej sredniej ocenie
	movieRatings.getHighestRatedMovie();

	//Film o najwyzszej sredniej ocenie
	movieRatings.getLowestRatedMovie();
	cout << "---------------------------------------------------------------" << endl;

	//Wyswietlono filmy posortowane rosnaco wedlug ocen
	movieRatings.showSortedMoviesByRating();
	cout << "---------------------------------------------------------------" << endl;

	//Przeprowadzono operacje na ocenach filmow, takie jak obliczanie sredniej ocen dla wszystkich
	//filmow oraz filtrowanie filmow z ocena powyzej okreslonego progu
	//Srednia ocena wszystkich filmow w systemie
	cout << "Srednia ocena wszystkich filmow w systemie: ";
	cout << movieRatings.getAverageRating() << endl;

	//Filmy ocenione powyzej progu
	int prog = 8;
	cout << "Filmy powyzej progu " << prog << ": " << endl;
	list <string> listaFilmowPowyzejProgu = movieRatings.getMoviesWithRatingAbove(prog);
	for (auto i : listaFilmowPowyzejProgu) {
		cout << i << endl;
	}
	cout << "---------------------------------------------------------------" << endl;

	//Usunieto filmy
	for (int i = 0; i < listaFilmow.size();i++) {
		movieRatings.removeMovie(get<0>(listaFilmow[i]));
	}
	cout << "---------------------------------------------------------------" << endl;

	cout << "Koniec programu." << endl;
	cout << "Ewelina Jurkiewicz, Gr. 5." << endl;
	return 0;
}