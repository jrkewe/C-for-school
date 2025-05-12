#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include "UrzadzenieElektroniczne.h"
#include "Smartphone.h"
using namespace std;

void Smartphone::wyswietlInformacje()
{
	cout << "Marka: " << marka << ", model: " << model << ", rok produkcji: " << rokProdukcji
		<< ", system operacyjny: " << systemOperacyjny << ", pojemnosc baterii: " << pojemnoscBaterii << ".";
}
