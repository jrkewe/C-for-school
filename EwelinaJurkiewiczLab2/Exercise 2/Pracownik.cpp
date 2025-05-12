#pragma once
#include <iostream>
#include "Pracownik.h"
using namespace std;

void Pracownik :: show() {
	cout << "Surname: " << surname << ", Age: " << age << ", Salary: " << salary << ".";
}

float Pracownik :: getSalary() {
	return salary;
}





	

