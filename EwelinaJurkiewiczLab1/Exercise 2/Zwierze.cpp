#pragma once
#include <iostream>
#include "Zwierze.h"
using namespace std;

void Zwierze::setCzyChronione(bool nowyStan) {
	czyChronione = nowyStan;
}

bool Zwierze::getCzyChronione() {
	return czyChronione;
}

bool Zwierze::getCzyZaginelo() {
	return czyZaginelo;
}






