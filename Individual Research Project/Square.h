// Michael Mohan 40020843
// 2D Physics Engine
#pragma region HEADER DECLARATIONS
#pragma once
#include "Headers.h"
#pragma endregion

// Header file initializes methods for the main class.
class Square
{
	float centreX, centreY, halfLength, angle;
public:
	Square(float cX, float cY, float hL, float a);
	~Square();
	float GetCentreX();
	float GetCentreY();
	float GetHalfLength();
	float GetAngle();
	void SetAttributes(float cX, float cY, float hL, float a);

};