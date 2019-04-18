// Michael Mohan 40020843
// 2D Physics Engine
#pragma region HEADER DECLARATIONS
#pragma once
#include "Headers.h"
#pragma endregion

// Header file initializes methods for the main class.
class Circle
{
	float centreX, centreY, radius;
public:
	Circle(float cX, float cY, float r);
	~Circle();
	float GetCentreX();
	float GetCentreY();
	float GetRadius();
	void SetAttributes(float cX, float cY, float r);
};

