#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include "UrzadzenieElektroniczne.h"
#include "Laptop.h"
using namespace std;

void Laptop::wyswietlInformacje()
{
	cout << "Marka: " << marka << ", model: " << model << ", rok produkcji: " << rokProdukcji 
		<< ", procesor: " << procesor << ", ram: " << ram << ".";
}
