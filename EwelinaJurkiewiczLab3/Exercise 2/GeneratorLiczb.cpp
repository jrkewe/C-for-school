//#pragma once
//#include <iostream>
//#include <vector>
//#include <random>
//#include <string>
//#include "GeneratorLiczb.h"
//using namespace std;
//
////Generator losowy - szablon
//template <typename T>
//T generujLosowaWartosc(T min, T max) {
//    random_device rd;
//    mt19937 gen(rd());
//    //Dla int i bool
//    if (is_integral<T>::value) {
//        // Dla liczb calkowitych (int, char)
//        uniform_int_distribution<T> dist(min, max);
//        return dist(gen);
//    }
//    else if (is_floating_point<T>::value) {
//        // Dla liczb zmiennoprzecinkowych (float, double)
//        uniform_real_distribution<T> dist(min, max);
//        return dist(gen);
//    }
//}
//
//// Specjalizacja dla typu char
//template <>
//char generujLosowaWartosc<char>(char min, char max) {
//    random_device rd;
//    mt19937 gen(rd());
//    uniform_int_distribution<int> dist(static_cast<int>(min), static_cast<int>(max));
//    return static_cast<char>(dist(gen));
//}
//
//// Specjalizacja dla typu string
//template <>
//string generujLosowaWartosc<string>(string min, string max) {
//    random_device rd;
//    mt19937 gen(rd());
//    uniform_int_distribution<int> lengthDist(3, 8); // Losowa dlugosc stringow
//    uniform_int_distribution<int> charDist('a', 'z'); // Losowe znaki od 'a' do 'z'
//
//    int length = lengthDist(gen);
//    string result;
//    for (int i = 0; i < length; ++i) {
//        result += static_cast<char>(charDist(gen));
//    }
//    return result;
//}