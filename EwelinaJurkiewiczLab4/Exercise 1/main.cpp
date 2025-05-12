# include <iostream>
# include <deque>
using namespace std;

int main() {
	//Tworzymy pusta kolejke dwukierunkowa przechowujaca liczby calkowite
	deque <int> dq;
	
	// Dodawanie elementow na poczatku i na koncu
	dq.push_back(10);
	dq.push_back(20);
	dq.push_front(5);
	dq.push_front(1);
	
	//Wyswietlenie elementow
	cout << "Elementy kolejki dwukierunkowej :" << endl;
	for (const auto& el : dq) {
		 cout << el << " ";
	}
	cout << endl;
	
	//Usuwanie elementow z obu koncow
	dq.pop_front();
	dq.pop_back();
	
	//Wyswietlenie aktualnej zawartosci kolejki
	cout << "\nPo usunieciu elementow z obu koncow :" << endl;
	for (const auto& el : dq) {
		 cout << el << " ";
	}
	cout << endl;
	
	//Dostep do elementow
	cout << "\nPierwszy element : " << dq.front() << endl;
	cout << " Ostatni element : " << dq.back() << endl;
	
	return 0;
}

//Wyniki analizy:
//Program wykonuje sie poprawnie.
//Uwagi: nie zostaly zachowane standardy nazewnictwa.
//Uzyte nazwy sa skrotowe i malo opisowe, co utrudnia zrozumienie kodu.