#pragma once
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//Szablonowa klasa kolejki
template <typename T>
class Queue {
    T* kolejka;
    int rozmiar;
    int poczatekKolejki;
    int koniecKolejki;

public:
    //Konstruktor z domyslnym rozmiarem 10
    Queue(int wielkosc = 10) : rozmiar(wielkosc), poczatekKolejki(0), koniecKolejki(-1) 
    {
        kolejka = new T[rozmiar];
        cout << "Utworzono kolejke typu:" << typeid(T).name() << endl << endl;
    }

    //Destruktor
    ~Queue() 
    {
        delete[] kolejka;
    }

    //Dodawanie elementu na koniec kolejki
    void enqueue(const T& element) 
    {
        //Sprawdza czy kolejka jest pelna
        if (isFull())
        {
            cout << "Kolejka pelna. Poszerzam rozmiar -> ";
            resize();
        }

        //Dodawanie elementu
        cout << "Dodaje element: " << element << " ";
        koniecKolejki++;
        kolejka[koniecKolejki] = element;
        display();
    }

    //Obliczanie liczby elementow w kolejce
    int size() const {
        return koniecKolejki + 1;
    }

    //Powiekszanie rozmiaru
    void resize() 
    {
        //Tablica chwilowa
        int nowyRozmiar = rozmiar * 2;
        T* nowaTablica = new T[nowyRozmiar];

        //Skopiowanie elementow starej tablicy do nowej tablicy
        for (int i = 0 ;i<size();i++) 
        {
            nowaTablica[i] = kolejka[i];
        }

        delete[] kolejka;
        kolejka = nowaTablica;
        rozmiar = nowyRozmiar;
        cout << " rozmiar: " << rozmiar << endl;
    }

    //Usuwanie pierwszego elementu kolejki
    T dequeue()
    {
        T element = kolejka[poczatekKolejki];

        //Sprawdza czy kolejka jest pusta
        if (isEmpty())
        {
            cout << endl;
            cout << "Kolejka jest pusta." << endl << endl;
            return 0;
        }

        //Gdy kolejka nie jest pusta
        if (!isEmpty())
        {
            element = kolejka[poczatekKolejki];
            kolejka[poczatekKolejki] = T();

            //Kolejka ma jeden element
            if (size()==1) 
            {
                cout << endl;
                cout << "Kolejka ma jeden element." << endl;
                poczatekKolejki = -1;
                koniecKolejki = -1;
            }

            //Kolejka ma wiecej niz jeden element
            else 
            {
                poczatekKolejki++;
                koniecKolejki--;
            }
        }
        cout << "Usuwam element: " << element << " ";
        display();
        return element;
    }

    //Getter pierwszego elementu w kolejce
    T peek() 
    {
        
            //Sprawdza czy kolejka jest pusta
            if (isEmpty())
            {
                throw underflow_error("Kolejka jest pusta! Nie mozna podejrzec elementu.");
            }
            else
            {
                T element = kolejka[poczatekKolejki];
                return element;
            }
        
    }

    //Sprawdzenie czy kolejka jest pusta
    bool isEmpty()
    {
        //Sprawdza czy kolejka jest pusta
        if (size() == 0)
        {
            return true;
        }
        else return false;
    }

    //Sprawdzenie czy kolejka jest pelna
    bool isFull()
    {
        //Sprawdza czy kolejka jest pusta
        if (size() == rozmiar)
        {
            return true;
        }
        else return false;
    }

    void display() 
    {
        cout << "Kolejka: ";

        for (int i = 0;i< size();i++)
        {
            cout << kolejka[poczatekKolejki + i] << " ";
        }
        cout << endl;
    }
};

template <>
class Queue<string> {
    string* kolejka;
    int rozmiar;
    int poczatekKolejki;
    int koniecKolejki;

public:
    //Konstruktor z domyslnym rozmiarem 10
    Queue(int wielkosc = 10) : rozmiar(wielkosc), poczatekKolejki(0), koniecKolejki(-1)
    {
        kolejka = new string[rozmiar];
        cout << "Utworzono kolejke typu: string" << endl;
    }

    //Destruktor
    ~Queue()
    {
        delete[] kolejka;
    }

    //Dodawanie elementu na koniec kolejki
    void enqueue(const string& element)
    {
        //Sprawdza czy kolejka jest pelna
        if (isFull())
        {
            cout << "Kolejka pelna. Poszerzam rozmiar -> ";
            resize();
        }

        //Dodawanie elementu
        koniecKolejki++;

        //String w odwrotnej kolejnosci
        string chwilowy = element;
        reverse(chwilowy.begin(), chwilowy.end());

        kolejka[koniecKolejki] = chwilowy;
        cout << "Dodaje odwrocony element: " << element << " ";
        display();
    }


    //Obliczanie liczby elementow w kolejce
    int size() const {
        return koniecKolejki + 1;
    }

    //Powiekszanie rozmiaru
    void resize()
    {
        //Tablica chwilowa
        int nowyRozmiar = rozmiar * 2;
        string* nowaTablica = new string[nowyRozmiar];

        //Skopiowanie elementow starej tablicy do nowej tablicy
        for (int i = 0;i < size();i++)
        {
            nowaTablica[i] = kolejka[i];
        }

        delete[] kolejka;
        kolejka = nowaTablica;
        rozmiar = nowyRozmiar;
        cout << " rozmiar: " << rozmiar << endl;
    }

    //Usuwanie pierwszego elementu kolejki
    string dequeue()
    {
        string element;

        //Sprawdza czy kolejka jest pusta
        if (isEmpty())
        {
            cout << endl;
            cout << "Kolejka jest pusta." << endl << endl;
        }

        //Gdy kolejka nie jest pusta
        if (!isEmpty())
        {
            element = kolejka[poczatekKolejki];
            kolejka[poczatekKolejki] = string();

            //Kolejka ma jeden element
            if (size() == 1)
            {
                cout << "Kolejka ma jeden element." << endl;
                poczatekKolejki = -1;
                koniecKolejki = -1;
            }

            //Kolejka ma wiecej niz jeden element
            else
            {
                poczatekKolejki++;
                koniecKolejki--;
            }

            string chwilowy = element;
            transform(chwilowy.begin(), chwilowy.end(), chwilowy.begin(), ::toupper);

            cout << "Usuwam element: " << chwilowy << " ";
            display();
            return chwilowy;
        }
    }

    //Getter pierwszego elementu w kolejce
    string peek()
    {
        //Sprawdza czy kolejka jest pusta
        if (isEmpty())
        {
            throw underflow_error("Kolejka jest pusta! Nie mozna podejrzec elementu.");
        }
        else
        {
            string element = kolejka[poczatekKolejki];
            return element;
        }
    }

    //Sprawdzenie czy kolejka jest pusta
    bool isEmpty()
    {
        //Sprawdza czy kolejka jest pusta
        if (size() == 0)
        {
            return true;
        }
        else return false;
    }

    //Sprawdzenie czy kolejka jest pelna
    bool isFull()
    {
        //Sprawdza czy kolejka jest pusta
        if (size() == rozmiar)
        {
            return true;
        }
        else return false;
    }

    void display()
    {
        cout << "Kolejka: ";

        for (int i = 0;i < size();i++)
        {
            cout << kolejka[poczatekKolejki + i] << " ";
        }
        cout << endl;
    }
};

