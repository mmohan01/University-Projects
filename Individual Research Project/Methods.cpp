// Michael Mohan 40020843
// 2D Physics Engine
#pragma region HEADER DECLARATIONS
#include "StdAfx.h"
#include "Methods.h"
#pragma endregion

// Global variables definitions for
// QueryPerformanceManager.
double PCFreq = 0.0;
__int64 CounterStart = 0;

// Method finds and returns the maximum of 4 values.
// This is used when data alignment is turned off to 
// allow for all the shapes to be declared in the same loop.
int Max(int a, int b, int c, int d)
{
	int max;
	max = ((a > b) ? a : b);
	max = ((max > c) ? max : c);
	max = ((max > d) ? max : d);
	return max;
}

// Method finds the squared size of a vector.
float SquaredMagnitude(float x, float y)
{
	return (pow(x, 2) + pow(y, 2));
}

// Method finds the dot product of a vector.
float DotProduct(float x1, float y1, float x2, float y2)
{
	return ((x1*x2) + (y1*y2));
}

// Method used to create a random 
// number between a specific range.
float Random(float min, float max)
{
	float range = max - min;
	return ((range)*((float)rand() / RAND_MAX)) + min;
}

// Method use to check whether an input 
// for which type of code to use is a 
// valid value between 1 and 3.
void Validate(int input, int upperLimit)
{
	#undef max

	while ((input < 1) || (input > upperLimit))
	{
		cout << "Not valid. Please try again: ";
		std::cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> input;
	}
}

// Creates a file to write to using the 
// file name entered as a parameter.
FILE* CreateTextFile(char *fileName)
{

	FILE *fw;
	fw = fopen(fileName, "w");
	if (fw == NULL)
		return 0;

	return fw;
}

// Used to start timer with "QueryPerformanceManager".
void StartCounter()
{
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
		cout << "QueryPerformanceFrequency failed!\n";

	PCFreq = double(li.QuadPart) / 1000.0;

	QueryPerformanceCounter(&li);
	CounterStart = li.QuadPart;
}

// Used in conjunction with "StartCounter" to get time.
double GetCounter()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return double(li.QuadPart - CounterStart) / PCFreq;
}