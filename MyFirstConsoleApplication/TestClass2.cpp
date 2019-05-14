#include "pch.h"
#include "TestClass2.h"


using namespace std;

TestClass2::TestClass2()
{
}


TestClass2::~TestClass2()
{
}

void TestClass2::sum() {
	TestClass testr = TestClass::TestClass();
	cout << "Sum = " << testr.sum(5, 11) << "\n";
	cout << write << "\n";
}

