// MyFirstConsoleApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma comment(lib, "rpcrt4.lib")  
#include "pch.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include "..\LibraryTest\LibraryTestClass.h"
#include "..\LibraryTest\LibraryTestClass.cpp"
#include <omp.h>
#include <boost/regex.hpp>

#define test "TestClass.h"
#define test2 "TestClass2.h"
#define multiply(a) a*a

#ifdef WIN16
#error "not 32"
#endif

constexpr int constA = 1;

// 
__declspec(selectany) int x1 = 1;

//const __declspec(selectany) int x2 = 2; wrong

extern const __declspec(selectany) int x3 = 3;

extern const int x4;
const __declspec(selectany) int x4 = 4;

extern __declspec(selectany) int x5;

constexpr float exponent(float base, int exponential) {
	if (exponential == 0) {
		return 1;
	}
	else if (exponential > 0) {
		if (exponential % 2 == 0) {
			return exponent(base*base, exponential / 2);
		}
		else {
			return exponent(base*base, (exponential - 1) / 2)*base;
		}
	}
	else {
		return 1 / exponent(base, exponential*(-1));
	}
}

#ifndef test
#	include test
#else
#	include test
#endif

#ifndef test2
#	include test2
#else
#	include test2
#endif
using namespace std;
void summm(int, int);

struct Person {
	int age;
	char name[50];
	int numberOfFinger;
};

struct Data {
	int data;
	Data* next = NULL;
};

struct __declspec(novtable) NovtableExaple {
	 virtual int getNovtable(int a,int b);
};

struct NovtableApply : NovtableExaple {
	int getNovtable(int a, int b) {
		return a + b;
	}
};

struct PropertyExample {
	int a;
	void putprop(int j) {
		a = j;
	}

	int getprop() {
		return a;
	}
	// Declare get set methods
	__declspec(property(get = getprop, put = putprop)) int the_prop;
};


int dataNum = 0;
Data* firstData = NULL;
Data* currentData = NULL;
Data* nextData = NULL;

void otherClassOperations() {
	TestClass testt = TestClass::TestClass();
	cout << "Sum = " << testt.sum(5, 6) << "\n";

	TestClass2 testt2 = TestClass2::TestClass2();
	testt2.sum();

	cout << test << "\n";
	cout << test2 << "\n";
}

void pointerOperations() {
	int a = 10;
	int *b = &a;

	cout << "value of a = " << a << "\n";
	cout << "value of b = " << *b << "\n";
	cout << "address of a = " << &a << "\n";
	cout << "address of b = " << b << "\n";
	*b = 33;
	cout << "*b values changed\n";
	cout << "new value of a = " << a << "\n";
	cout << "new value of b = " << *b << "\n";
}

void threadOperations() {
	try {
		thread thread_obj(summm, 5, 8);
		thread thread_obj2(summm, 5, 10);

		thread_obj.join();
		thread_obj2.join();
	}
	catch (exception& e) {
		cout << "exception: " << e.what() << endl;
	}
}

void libraryOperations() {
	LibraryTestClass classsss = LibraryTestClass();
	classsss.sum(2, 9);
}

void shiftOperations() {
	static int eea = INT_MAX;
	for (int i = 0; i < 10; i++) {
		if ((eea >> i) & 0x1) {
			cout << "true \n";
			cout << eea << "\n";
		}
		else {
			cout << "false\n";
			cout << eea << "\n";
		}
	}
}

void summm(int a, int b) {
	cout << "Sum in thread = " << a + b << "\n";
	this_thread::sleep_for(chrono::milliseconds(100));
	cout << "Sum in thread 2 = " << a + b << "\n";
}

extern "C"
{
	void testC() {
		int testVariable;
		printf("I am in C\n");
		printf("Enter integer value = ");
		scanf_s("%d", &testVariable);
		printf("\nTest variable = %d\n", testVariable);
	}
}

void findNumber() {
	int sayi = rand() % 100 + 1;
	int sayac = 0;
	int tahmin;
	do {
		sayac++;
		cout << sayac << ". guess\n";
		cin >> tahmin;

		if (tahmin < sayi) {
			cout << "\nUp\n";
		}
		if (tahmin > sayi) {
			cout << "\nDown\n";
		}
	} while (tahmin != sayi);

	cout << "Congrulations!!!\nYou know " << sayac << ". trial.";
}

void stringOperations() {
	char dest[50] = "This is an example";
	char src[50] = " to show working of strncat() this is not added";

	strncat(dest, src, 13);
	cout << "\n\nUnsafe code\n\n";
	cout << "\n\strncat example = " << dest << "\n";

	char dest1[50] = "This is an";
	char src1[50] = " example";

	strcat(dest1, src1);
	cout << "\n\strcat example = " << dest1 << "\n";

	char dest2[50] = "bla bla bla";
	char src2[50] = "test";

	strcpy(dest2, src2);

	cout << "\n\strcpy example = " << dest2 << "\n";
}

void constOperations() {
	cout << "Const variable = " << constA << "\n";
	cout << "Const function exponent value 2^3 = " << exponent(2, 3) << "\n";
	cout << "Const function exponent value 5^0 = " << exponent(5, 0) << "\n";
	cout << "Const function exponent value 4.2^2= " << exponent(4.2, 3) << "\n";
	cout << "Const function exponent value 2^-3 = " << exponent(2, -3) << "\n";
	cout << "Const function exponent value 5^-2 = " << exponent(5, -2) << "\n";
}

void modOperations() {
	double param, fractpart, intpart;

	param = 3.14159265;
	fractpart = modf(param, &intpart);
	cout << "modf ->" << "param = " << param << " fractpart = " << fractpart << " intpart = " << intpart << "\n";

	param = -3.14159265;
	fractpart = modf(param, &intpart);
	cout << "modf ->" << "param = " << param << " fractpart = " << fractpart << " intpart = " << intpart << "\n";

	double modParam, result;
	param = 10;
	modParam = 3.3;

	cout << "\n\n";

	result = fmod(param, modParam);
	cout << "fmod ->" << "param = " << param << " modParam = " << modParam << " result = " << result << "\n";
	cout << "\n\n";

	result = fmodf(param, modParam);
	cout << "fmodf ->" << "param = " << param << " modParam = " << modParam << " result = " << result << "\n";
	cout << "\n\n";

	result = fmodl(param, modParam);
	cout << "fmodl ->" << "param = " << param << " modParam = " << modParam << " result = " << result << "\n";
	cout << "\n\n";

	int intParam, intModParam, intResult;

	intParam = 100;
	intModParam = 7;
	intResult = intParam % intModParam;
	cout << "intParam = " << intParam << " intModParam = " << intModParam << " intResult = " << intResult << "\n";

	intParam = -100;
	intModParam = 7;
	intResult = intParam % intModParam;
	cout << "intParam = " << intParam << " intModParam = " << intModParam << " intResult = " << intResult << "\n";

	intParam = 100;
	intModParam = -7;
	intResult = intParam % intModParam;
	cout << "intParam = " << intParam << " intModParam = " << intModParam << " intResult = " << intResult << "\n";

	intParam = -100;
	intModParam = -7;
	intResult = intParam % intModParam;
	cout << "intParam = " << intParam << " intModParam = " << intModParam << " intResult = " << intResult << "\n";
	cout << "\n\n";
}

void putsGetsOperation() {
	char variable[50];
	strcpy(variable, "Aslan beeee");
	puts(variable);

	gets_s(variable);
	puts(variable);
}

void memsetOperations() {
	char variable[50];
	strcpy(variable, "I am a test string");
	memset(variable, NULL, 5); // NULL
	cout << variable;
}

void sprintfOperations() {
	char buffer[50];
	int n, a = 5, b = 3;
	n = sprintf(buffer, "%d plus %d is %d", a, b, a + b);
	printf("[%s] is a string %d chars long\n", buffer, n);
}

void sscanfOperations() {
	char str[50] = "15 David 9";
	Person person;
	sscanf(str, "%d %s %d", &person.age, person.name, &person.numberOfFinger);
	cout << person.age << " " << person.name << " " << person.numberOfFinger << "\n";
}

void fprintfFile(FILE *file, Person person) {
	fprintf(file, "%d %s %d\n", person.age, person.name, person.numberOfFinger);
}

void fscanfFile(FILE *file) {
	Person person;
	while (fscanf(file, "%d %s %d\n", &person.age, person.name, &person.numberOfFinger) != EOF) {
		cout << person.age << " " << person.name << " " << person.numberOfFinger << "\n";
	}
}

void fwriteFile(FILE *file, Person *person) {
	fwrite(person, 1, sizeof(Person), file);
}

void freadFile(FILE *file) {
	Person person;
	do {
		fread(&person, sizeof(Person), 1, file);
		if (feof(file)) {
			break;
		}
		cout << person.age << " " << person.name << " " << person.numberOfFinger << "\n";
	} while (1);
}

void fileOperations() {

	Person person1;
	person1.age = 12;
	strcpy(person1.name, "Jack");
	person1.numberOfFinger = 7;

	Person person2;
	person2.age = 20;
	strcpy(person2.name, "John");
	person2.numberOfFinger = 3;

	Person person3;
	person3.age = 5;
	strcpy(person3.name, "Jessie");
	person3.numberOfFinger = 8;

	FILE *test1File;
	char test1FileName[] = "test1.txt";
	// Write file
	test1File = fopen(test1FileName, "w");
	if (test1File != NULL) {
		fwriteFile(test1File, &person1);
		fwriteFile(test1File, &person2);
		fwriteFile(test1File, &person3);/**/

		/*fprintfFile(test1File, person1);
		fprintfFile(test1File, person2);
		fprintfFile(test1File, person3);*/
		fclose(test1File);
	}

	FILE *test2File;
	char test2FileName[] = "test2.txt";
	test2File = fopen(test2FileName, "wb");
	if (test2File != NULL) {
		fwriteFile(test2File, &person1);
		fwriteFile(test2File, &person2);
		fwriteFile(test2File, &person3);/**/

		/*fprintfFile(test2File, person1);
		fprintfFile(test2File, person2);
		fprintfFile(test2File, person3);*/
		fclose(test2File);
	}

	// Read file
	test1File = fopen(test1FileName, "rb");
	if (test1File != NULL) {
		//fscanfFile(test1File);
		freadFile(test1File);
		fclose(test1File);
	}

	test2File = fopen(test2FileName, "r");
	if (test2File != NULL) {
		//fscanfFile(test2File);
		freadFile(test2File);
		fclose(test2File);
	}
}

void fileOperationsfstream() {
	Person person1;
	person1.age = 12;
	strcpy(person1.name, "Jack");
	person1.numberOfFinger = 7;

	Person person2;
	person2.age = 20;
	strcpy(person2.name, "John");
	person2.numberOfFinger = 3;

	Person person3;
	person3.age = 5;
	strcpy(person3.name, "Jessie");
	person3.numberOfFinger = 8;

	// write to file
	char test1FileName[] = "test1.txt";
	ofstream test1Fileout;
	test1Fileout.open(test1FileName);
	char buffer1[50];
	char buffer2[50];
	char buffer3[50];
	sprintf(buffer1, "%d %s %d\n", person1.age, person1.name, person1.numberOfFinger);
	sprintf(buffer2, "%d %s %d\n", person2.age, person2.name, person2.numberOfFinger);
	sprintf(buffer3, "%d %s %d\n", person3.age, person3.name, person3.numberOfFinger);
	test1Fileout << buffer1;
	test1Fileout << buffer2;
	test1Fileout << buffer3;
	test1Fileout.close();

	// read from file
	ifstream test1filein(test1FileName);
	char line[100];

	test1filein.getline(line, 100, '\n');
	cout << line << "\n";
	test1filein.getline(line, 100, '\n');
	cout << line << "\n";
	test1filein.getline(line, 100, '\n');
	cout << line << "\n";

	// write to file
	char test2FileName[] = "test2.txt";
	ofstream test2Fileout;
	test2Fileout.open(test2FileName);
	test2Fileout.write((char*)&person1, sizeof(Person));
	test2Fileout.write((char*)&person2, sizeof(Person));
	test2Fileout.write((char*)&person3, sizeof(Person));
	test2Fileout.close();

	// read from file
	Person person;
	ifstream test2filein(test2FileName);
	test2filein.read((char*)&person, sizeof(Person));
	cout << person.age << " " << person.name << " " << person.numberOfFinger << "\n";
	test2filein.read((char*)&person, sizeof(Person));
	cout << person.age << " " << person.name << " " << person.numberOfFinger << "\n";
	test2filein.read((char*)&person, sizeof(Person));
	cout << person.age << " " << person.name << " " << person.numberOfFinger << "\n";
}

void fileOperationsMixed() {

	Person person1;
	person1.age = 12;
	strcpy(person1.name, "Jack");
	person1.numberOfFinger = 7;

	Person person2;
	person2.age = 20;
	strcpy(person2.name, "John");
	person2.numberOfFinger = 3;

	Person person3;
	person3.age = 5;
	strcpy(person3.name, "Jessie");
	person3.numberOfFinger = 8;

	FILE *test1File;
	char test1FileName[] = "test1.txt";
	// Write file
	test1File = fopen(test1FileName, "w");
	if (test1File != NULL) {
		fprintfFile(test1File, person1);
		fprintfFile(test1File, person2);
		fclose(test1File);
	}

	//test1File = fopen(test1FileName, "r");
	test1File = fopen(test1FileName, "a");
	if (test1File != NULL) {
		fprintfFile(test1File, person3);
		fclose(test1File);
	}
}

void memcpyOperations() {
	Person person1;
	person1.age = 12;
	strcpy(person1.name, "Donald");
	person1.numberOfFinger = 25;
	Person person2;

	// copy values
	memcpy(&person2, &person1, sizeof(Person));

	cout << person1.age << " " << person1.name << " " << person1.numberOfFinger << "\n";
	cout << person2.age << " " << person2.name << " " << person2.numberOfFinger << "\n";

	person2.age = 556;
	strcpy(person2.name, "Frank");
	person2.numberOfFinger = 3;
	cout << person1.age << " " << person1.name << " " << person1.numberOfFinger << "\n";
	cout << person2.age << " " << person2.name << " " << person2.numberOfFinger << "\n";
}

void writeData() {
	Data *data;
	data = firstData;
	printf("\n\n first Data\n\n");
	if (data != NULL) {
		do {
			printf("data = %d\n", data->data);
			data = data->next;
		} while (data != NULL);
	}

	data = nextData;
	printf("\n\n next Data\n\n");
	if (data != NULL) {
		do {
			printf("data = %d\n", data->data);
			data = data->next;
		} while (data != NULL);
	}

	data = currentData;
	printf("\n\n current Data\n\n");
	if (data != NULL) {
		do {
			printf("data = %d\n", data->data);
			data = data->next;
		} while (data != NULL);
	}
}

void nextValue(Data data) {
	if (dataNum == 0) {
		firstData = new Data;
		currentData = firstData;
		memcpy(firstData, &data, sizeof(Data));
	}
	memcpy(currentData, &data, sizeof(Data));
	nextData = new Data;
	currentData->next = (Data *)nextData;
	if (dataNum == 0) {
		firstData->next = (Data *)nextData;
	}
	dataNum++;
	currentData = nextData;
}

void addData() {
	for (int i = 1; i < 10; i++) {
		Data data;
		data.data = i;
		nextValue(data);
		writeData();
	}
}

void threadOperations1() {
	int x = 5;
#pragma omp parallel
	{
		x = x + 1;
		printf("shared: x is %d\n\n", x);
	}
}

void threadOperations2() {
	int x = 5;
#pragma omp parallel
	{
		int x; x = 3;
		printf("local: x is %d\n\n", x);
	}
}

void threadOperations3() {
	int x = 5;
#pragma omp parallel private(x)
	{
		x = x + 1; // dangerous
		printf("private: x is %d\n\n", x);
	}
	printf("after: x is %d\n\n", x);
}

void threadOperations4() {
	int h = 3;
	double a[10], b[10];
#pragma omp parallel for
	{
		for (int i = 0; i < 10; i++) {
			int x = i * h;
			double s = sin(x);
			double c = cos(x);
			a[i] = s + c;
			b[i] = s - c;
		}
	}
	for (int i = 0; i < 10; i++) {
		printf("a[%d] = %lf, b[%d] = %lf\n", i, a[i], i, b[i]);
	}
}

void threadOperations5() {
	//int p = 0;
#pragma omp parallel
	{
		// the value of p is undefined
		int p = omp_get_thread_num();
		// the value of p is defined
		printf("thread number = %d\n\n",p);
	}
}

void threadOperations6() {
#pragma omp parallel for
	{
		for (int i = 0; i < 10; i++) {
			printf("thread number = %d\n\n", omp_get_thread_num());
		}
	}
}

void threadOperations7() {
#pragma omp parallel for schedule (guided, 9)
	{
		for (int i = 0; i < 10; i++) {
			printf("\n\nschedule = %d", i);
		}
	}
	
}

void macroOperations() {
	printf("\n\nMacro multiply(5)  = %d", multiply(5));
	// Dont forget macro writes 2+3*2+3 No process priority
	printf("\n\nMacro multiply(2+3)  = %d", multiply(2+3));
}

// clear cache 
int __cdecl getCdecl(int a, int b) {
	return a + b;
}

/*int __thiscall getThiscall(int a, int b) {
	return a + b;
}*/

// 
int __fastcall getFastcall(int a, int b) {
	return a + b;
}

int __stdcall getStdcall(int a, int b) {
	return a + b;
}

__declspec(noalias) int getNoalias(int a, int b) {
	return a + b;
}

/* related to code compile if we use only spesific operation it could be slow */
__declspec(noinline) int getNoinline(int a, int b) {
	return a + b;
}

// it is used for error messages but it can return value :D Here C++ 
__declspec(noreturn) int getNoreturn(int a, int b) {
	return a + b;
}

// Never throw exceptions
 __declspec(nothrow)  int getNothrow(int a, int b) {
	return a + b;
} 
 
 /*__declspec(process) int getProcess(int a, int b) { only running with clr
	return a + b;
}*/

 __declspec(restrict) int * getRestrict(int a, int b) {
	 int *returnValue;
	 returnValue= (int*)malloc (sizeof(int));
	 *returnValue = a + b;
	 return returnValue;
 }

 //buffer overruns security check
 __declspec(safebuffers) int getSafebuffers(int a, int b) {
	 return a + b;
 }
 // provide more protection on /Qspectre 
 /*__declspec(spectre(nomitigation)) int noSpectreIssues(int a, int b) {
	 return a + b;
 }*/

#if WIN32
__declspec(naked) int getDeclspectNakedFunction(int a, int b) { // it runs only win32
	__asm {
		push ebp
		mov ebp, esp
		sub esp, __LOCAL_SIZE
		// store ECX and EDX into stack locations allocated for a and b
		// mov a, ecx
		// mov b, edx
	}

	{
		int k = a+b;   // return value
		__asm {
			mov eax, k
		};
	}

	__asm {
		mov esp, ebp
		pop ebp
		ret
	}
}
#endif
__declspec(thread) class ThreadClass1 {
public:
	int data = 5;
}threadClass1;

class ThreadClass2 {
public:
	int data = 5;
};
__declspec(thread) ThreadClass2 threadClass2;


void callSpecificFunctions() {
	printf("\n\ngetCdecl = %d\n\n",getCdecl(5,23));
	printf("getFastcall = %d\n\n", getFastcall(5,23));
	printf("getStdcall = %d\n\n", getStdcall(5,23));
	printf("getNoalias = %d\n\n", getNoalias(5,23));
	printf("getNoinline = %d\n\n", getNoinline(5,23));
	printf("getNoreturn = %d\n\n", getNoreturn(5,23));
	printf("getNothrow = %d\n\n", getNothrow(5,23));
	printf("getRestrict = %d\n\n", *getRestrict(5,23));
	printf("getSafebuffers = %d\n\n", getSafebuffers(5,23));
	printf("selectany variables x1 = %d x3 = %d x4 = %d x5 = %d\n\n", x1, x3, x4, x5);
	printf("thread class1 variable data = %d \n\n", threadClass1.data);
	printf("thread class2 variable data = %d \n\n", threadClass2.data);
	printf("thread class2 variable data =  \n\n");

	// NovtableExaple *novtableExaple = new NovtableExaple();
	// printf("novtableExaple->getNovtable = %d\n\n", novtableExaple->getNovtable(5, 23)); // throws null pointer
	NovtableApply *novtableApply = new NovtableApply();;
	printf("novtableApply->getNovtable = %d\n\n", novtableApply->getNovtable(5, 23));
	PropertyExample propertyExample;
	propertyExample.the_prop = 5 + 23;
	printf("propertyExample.the_prop = %d\n\n", propertyExample.the_prop);
#if WIN32
	printf("declspectNakedFunction = %d\n\n", getDeclspectNakedFunction(5,23));
#endif
}


int main()
{
	/*pointerOperations();
	otherClassOperations();
	threadOperations();
	libraryOperations();
	shiftOperations();
	constOperations();
	findNumber();
	stringOperations();
	modOperations();
	putsGetsOperation();
	memsetOperations();
	sprintfOperations();
	fileOperations();
	fileOperationsfstream();
	sscanfOperations();
	fileOperationsMixed();
	memcpyOperations();
	addData();
	threadOperations1();
	threadOperations2();
	threadOperations3();
	threadOperations4();
	threadOperations5();
	threadOperations6();
	threadOperations7();
	macroOperations();
	callSpecificFunctions();*/
	system("pause");
}





