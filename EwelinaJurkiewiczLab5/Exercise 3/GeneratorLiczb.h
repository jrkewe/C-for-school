#pragma once
#include <iostream>
#include <random>
using namespace std;

// Szablon funkcji generujacej losowe wartosci
template <typename T>
T generujLosowaWartosc(T min, T max) {
    random_device rd;
    mt19937 gen(rd());

    //Integer
    if constexpr (is_integral<T>::value && !is_same<T, bool>::value)
    {
        uniform_int_distribution<T> dist(min, max);
        return dist(gen);
    }
    //Float
    else if constexpr (is_floating_point<T>::value)
    {
        uniform_real_distribution<T> dist(min, nextafter(max, std::numeric_limits<T>::max()));
        return round(dist(gen) * 100.0f) / 100.0f;
    }
    //Nieprzewidzane
    else {
        throw invalid_argument("Nieobslugiwany typ dla generowania losowych wartosci.");
    }
}

// Specjalizacja dla typu bool
template <>
bool generujLosowaWartosc<bool>(bool, bool)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, 1);
    return static_cast<bool>(dist(gen));
}

// Specjalizacja dla typu char
template <>
char generujLosowaWartosc<char>(char min, char max)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(static_cast<int>(min), static_cast<int>(max));
    return static_cast<char>(dist(gen));
}

// Specjalizacja dla typu string
template <>
string generujLosowaWartosc<string>(string, string)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dlugosc(2, 5);
    uniform_int_distribution<int> znak('a', 'z');

    int iloscZnakow = dlugosc(gen);
    string ciagZnakow;
    for (int i = 0; i < iloscZnakow; ++i) {
        ciagZnakow += static_cast<char>(znak(gen));
    }
    return ciagZnakow;
}
