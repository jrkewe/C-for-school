//#pragma once
//#include <iostream>
//#include <vector>
//#include <random>
//#include <string>
//#include "TablicaSzablonowa.h"
//#include "GeneratorLiczb.h"
//using namespace std;
//
////Wyswietlenie tablicy
//template <typename T>
//void TablicaSzablonowa<T>::wyswietl() {
//    for (int i = 0; i < rozmiar; ++i) {
//        cout << tablica[i] << " ";
//    }
//    cout << endl;
//}
//
////Getter dla rozmiaru
//template <typename T>
//int TablicaSzablonowa<T>::getSize() {
//    return rozmiar;
//}
//
////Getter dla tablicy
//template <typename T>
//T* TablicaSzablonowa<T>::getArray() {
//    return tablica;
//}
//
////Funkcja wypelniajaca tablice
//template <typename T>
//void TablicaSzablonowa<T>::specializedMethodUzupelnienie() {
//    for (int i = 0; i < rozmiar; ++i) {
//        tablica[i] = static_cast<T>(i);
//    }
//}
//
////Specjalizacja metody dla typu int
//template <>
//void TablicaSzablonowa <int>::specializedMethodUzupelnienie() {
//    int element = generujLosowaWartosc(0, 100);
//    for (int i = 0; i < rozmiar; ++i) {
//        tablica[i] = element;
//    }
//}
//
////Specjalizacja metody dla typu float
//template <>
//void TablicaSzablonowa <float>::specializedMethodUzupelnienie() {
//    float element = generujLosowaWartosc(0.0, 100.0);
//    for (int i = 0; i < rozmiar; ++i) {
//        tablica[i] = element;
//    }
//}
//
////Specjalizacja metody dla typu bool
//template <>
//void TablicaSzablonowa <bool>::specializedMethodUzupelnienie() {
//    int element = generujLosowaWartosc(0, 1);
//    for (int i = 0; i < rozmiar; ++i) {
//        tablica[i] = element;
//    }
//}
//
////Specjalizacja metody dla typu char
//template <>
//void TablicaSzablonowa <char>::specializedMethodUzupelnienie() {
//    random_device rd;
//    mt19937 gen(rd());
//    uniform_int_distribution<int> dist('a', 'z');
//    for (int i = 0; i < rozmiar; ++i) {
//        tablica[i] = static_cast<char>(dist(gen));
//    }
//}
//
////Specjalizacja metody dla typu string
//template <>
//void TablicaSzablonowa <string>::specializedMethodUzupelnienie() {
//    random_device rd;
//    mt19937 gen(rd());
//    uniform_int_distribution<int> lengthDist(3, 8); // Dlugosc stringow 3-8 znakow
//    uniform_int_distribution<int> charDist('a', 'z'); // Znaki od 'a' do 'z'
//
//    for (int i = 0; i < rozmiar; ++i) {
//        int length = lengthDist(gen);
//        string str;
//        for (int j = 0; j < length; ++j) {
//            str += static_cast<char>(charDist(gen));
//        }
//        tablica[i] = str;
//    }
//}
