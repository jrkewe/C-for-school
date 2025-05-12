#pragma once
#include <stdio.h>
#include <string>
#include <map>
#include <vector>
#include <list>
using namespace std;

class MovieRatingSystem {
protected:
	map <string, vector<double>> movieRatings;

public:
	//Konstruktor bezargumentowy;
	MovieRatingSystem() {};

	//Metoda void addMovie(string& movieName, double rating) – dodaje film z poczatkowa ocena
	void addMovie(const string& movieName, double rating);

	//Metoda void addRating(string& movieName) – dodaje nowa ocene do filmu
	void addRating(const string& movieName, double rating);

	//Metoda void removeMovie(const std::string& movieName) — usuwa film z systemu
	void removeMovie(const string& movieName);

	//Metoda void getMovieRatting(const std::string& movieName) — zwraca srednia ocene filmu
	double getMovieRatting(const std::string& movieName);

	//Metoda void getMovieCount(const string& movieName) — zwraca liczbe ocen dla filmu
	int getMovieCount(const string& movieName);

	//Metoda void showAllMovies() — wyswietla wszystkie filmy i ich srednie oceny
	void showAllMovies();

	//Metoda void getHighestRatedMovie() — zwraca film o najwyzszej sredniej ocenie
	pair <string, double> getHighestRatedMovie();

	//Metoda void getLowestRatedMovie() — zwraca film o najnizszej sredniej ocenie
	pair <string, double> getLowestRatedMovie();

	//Metoda void showSortedMoviesByRating() — wyswietla filmy posortowane wedlug ocen
	//(od nijwyzszej do najnizszej)
	void showSortedMoviesByRating();

	//Metoda void getAverageRating() — zwraca srednia ocene wszystkich filmow w systemie
	double getAverageRating();

	//Metoda void getMoviesWithRatingAbove(double threshold) — zwraca liste filmow z ocena
	//wyzsza niz podany prog
	list<string> getMoviesWithRatingAbove(double threshold);
};