// Michael Mohan 40020843
// 2D Physics Engine
#pragma region HEADER DECLARATIONS
#pragma once
#include "Headers.h"
#pragma endregion

// Header file initializes methods for the main class.
class Line
{
	float startX, startY, endX, endY;
public:
	Line(float sX, float sY, float eX, float eY);
	~Line();
	float GetStartX();
	float GetStartY();
	float GetEndX();
	float GetEndY();
	void SetAttributes(float sX, float sY, float eX, float eY);
};