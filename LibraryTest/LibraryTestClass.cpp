#include "stdafx.h"
#include "LibraryTestClass.h"

#include <iostream>

using namespace std;
LibraryTestClass::LibraryTestClass()
{
}


LibraryTestClass::~LibraryTestClass()
{
}

void LibraryTestClass::sum(int a, int b) {
	cout << "\nIn Library Test Class Sum = " << a + b << "\n";
}
