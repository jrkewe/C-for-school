#include <iostream>
#include <map>
#include <random>
#include "GeneratorLiczb.h"
using namespace std;

//Funkcja do znalezienia dodatkowej cyfry
int znajdzDodatkowaCyfre(int liczba1, int liczba2) {
   
    int liczbaWieksza = liczba1;
    int liczbaMniejsza = liczba2;

    //Znalezienie wiekszej liczby
    if (liczba2 > liczba1) {
        liczbaWieksza = liczba2;
        liczbaMniejsza = liczba1;
    }

    map<int, int> mapaWieksza;
    map<int, int> mapaMniejsza;

    //Mapowanie liczby wiekszej
    for (int i = 0; liczbaWieksza>0 ;i++) {
        int cyfra = liczbaWieksza % 10;
        mapaWieksza.insert(make_pair(i,cyfra));
        liczbaWieksza /= 10;
    }

    //Mapowanie liczby mniejszej
    for (int i = 0; liczbaMniejsza > 0;i++) {
        int cyfra = liczbaMniejsza % 10;
        mapaMniejsza.insert(make_pair(i, cyfra));
        liczbaMniejsza /= 10;
    }

    //Znalezienie dodatkowej liczby
    //Odnajduje kazda z cyfr mniejszej liczby w wiekszej i je usuwa
    for (auto i = mapaMniejsza.begin(); i != mapaMniejsza.end();i++) {
        for (auto j = mapaWieksza.begin(); j != mapaWieksza.end();j++) {
            if (i->second == j->second) {
                mapaWieksza.erase(j);
                break;
            }
        }
    }
    cout << "Cyfra ktora zostala dodana do drugiej liczby : " << endl;
    return mapaWieksza.begin()->second;
}

//Przemieszanie liczby 
int przemieszanieCyfr(int liczba) {

    int przemieszanaLiczba = 0;
    vector<int> cyfry;
    
    //Rozlozenie liczby na cyfry
    while (liczba>0) {
        cyfry.push_back(liczba % 10);
        liczba /= 10;
    }

    //Przemieszanie
    random_device rd;
    mt19937 gen(rd());
    shuffle(cyfry.begin(), cyfry.end(),gen);

    //Tworzenie nowej liczby
    for (int i = 0;i<cyfry.size();i++) {
        przemieszanaLiczba = przemieszanaLiczba * 10 + cyfry[i];
    }

    return przemieszanaLiczba;
}

//Losowe wartosci
int randomLiczbaMniejsza;
int randomLiczbaWieksza;

int main() {
    cout << "************************************************************" << endl;
    cout << "Program generuje losowe liczby i znajduje rozniace je liczby " << endl;
    cout << "************************************************************" << endl << endl;
    
    //Generowanie liczb
    int randomLiczbaWieksza = generujLosowaWartosc(10000,99999);
    int randomLiczbaMniejsza = przemieszanieCyfr(randomLiczbaWieksza);

    //Zwiekszenie wiekszej liczby
    randomLiczbaWieksza = randomLiczbaWieksza * 10 + generujLosowaWartosc(0,9);

    cout << "Wieksza liczba: " << randomLiczbaWieksza << endl;
    cout << "Mniejsza liczba: " << randomLiczbaMniejsza << endl << endl;

    //Znalezienie cyfry dodanej do drugiej liczby
    cout << znajdzDodatkowaCyfre(randomLiczbaWieksza, randomLiczbaMniejsza) << endl << endl;

    cout << "Koniec programu." << endl;
    cout << "Ewelina Jurkiewicz, Gr. 5." << endl;

    return 0;
}
