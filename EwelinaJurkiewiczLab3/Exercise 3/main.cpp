#include <iostream>
#include "DynamicznaKolejka.h"
#include "GeneratorLiczb.h"

//Losowe wartosci
int randomTyp=4;
int randomSize=10;

int main() {
    cout << "***********************************************" << endl;
    cout << "Program demonstruje uzycie dynamicznej kolejki" << endl;
    cout << "***********************************************" << endl << endl;

    for (int i = 0;i<=randomTyp;i++) {

        //Testowanie wszystkich kolejek
        switch (i) {
        case 0:
        {
            cout << "---------------------------------------------------------------" << endl;
            cout << "Kolejka typu: int" << endl << endl;
            Queue<int> kolejka(randomSize);

            cout << "Sprawdzam czy kolejka jest pusta: ";

            try {
                kolejka.peek();
            }
            catch (const underflow_error& e) {
                cout << "Blad: " << e.what() << endl;
            }
            cout << endl;

            //Dodawanie elementow
            for (int j = 0;j < 12;j++) {
                kolejka.enqueue(generujLosowaWartosc(0, 100));
            }
            cout << endl;
            //Usuwanie elementow
            for (int j = 0;j < 13;j++) {
                kolejka.dequeue();
            }
            break;
        }
        case 1:
        {
            cout << "---------------------------------------------------------------" << endl;
            cout << "Kolejka typu: float" << endl << endl;
            Queue<float> kolejka(randomSize);

            cout << "Sprawdzam czy kolejka jest pusta: ";
            try {
                kolejka.peek();
            }
            catch (const underflow_error& e) {
                cout << "Blad: " << e.what() << endl;
            }
            cout << endl;

            //Dodawanie elementow
            for (int j = 0;j < 12;j++) {
                kolejka.enqueue(generujLosowaWartosc(0.0f, 100.0f));
            }
            cout << endl;
            //Usuwanie elementow
            for (int j = 0;j < 13;j++) {
                kolejka.dequeue();
            }
            break;
        }
        case 2:
        {
            cout << "---------------------------------------------------------------" << endl;
            cout << "Kolejka typu: bool" << endl << endl;
            Queue<bool> kolejka(randomSize);

            cout << "Sprawdzam czy kolejka jest pusta: ";
            try {
                kolejka.peek();
            }
            catch (const underflow_error& e) {
                cout << "Blad: " << e.what() << endl;
            }
            cout << endl;

            //Dodawanie elementow
            for (int j = 0;j < 12;j++) {
                kolejka.enqueue(generujLosowaWartosc(0, 1));
            }
            cout << endl;
            //Usuwanie elementow
            for (int j = 0;j < 13;j++) {
                kolejka.dequeue();
            }
            break;
        }
        case 3:
        {
            cout << "---------------------------------------------------------------" << endl;
            cout << "Kolejka typu: char" << endl << endl;
            Queue<char> kolejka(randomSize);

            cout << "Sprawdzam czy kolejka jest pusta: ";
            try {
                kolejka.peek();
            }
            catch (const underflow_error& e) {
                cout << "Blad: " << e.what() << endl;
            }
            cout << endl;

            //Dodawanie elementow
            for (int j = 0;j < 12;j++) {
                kolejka.enqueue(generujLosowaWartosc('a', 'z'));
            }
            cout << endl;
            //Usuwanie elementow
            for (int j = 0;j < 13;j++) {
                kolejka.dequeue();
            }
            break;
        }
        case 4:
        {
            cout << "---------------------------------------------------------------" << endl;
            cout << "Kolejka typu: string" << endl << endl;
            Queue<string> kolejka(randomSize);

            cout << "Sprawdzam czy kolejka jest pusta: ";
            try {
                kolejka.peek();
            }
            catch (const underflow_error& e) {
                cout << "Blad: " << e.what() << endl;
            }
            cout << endl;

            //Dodawanie elementow
            for (int j = 0;j < 12;j++) {
                string ciagZnakow = generujLosowaWartosc<string>(" ", " ");
                kolejka.enqueue(ciagZnakow);
            }
            cout << endl;
            //Usuwanie elementow
            for (int j = 0;j < 13;j++) {
                kolejka.dequeue();
            }
            cout << "---------------------------------------------------------------" << endl;
            break;
        }
        default:
            cout << "Nieprawidlowy typ!" << endl;
            break;
        }
    }

    cout << endl << "Koniec programu." << endl;
    cout << "Ewelina Jurkiewicz, Gr. 5." << endl;
    
    return 0;
}
