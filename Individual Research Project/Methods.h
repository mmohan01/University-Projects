// Michael Mohan 40020843
// 2D Physics Engine
#pragma region HEADER DECLARATIONS
#include "Headers.h"
#include <windows.h>
#pragma endregion

int Max(int a, int b, int c, int d);
float SquaredMagnitude(float x, float y);
float DotProduct(float x1, float y1, float x2, float y2);
float Random(float min, float max);
void Validate(int value, int upperLimit);
FILE* CreateTextFile(char *fileName);
void StartCounter();
double GetCounter();