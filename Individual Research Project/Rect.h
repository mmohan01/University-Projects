// Michael Mohan 40020843
// 2D Physics Engine
#pragma region HEADER DECLARATIONS
#pragma once
#include "Headers.h"
#pragma endregion

// Header file initializes methods for the main class.
class Rect
{
	float centreX, centreY, halfLength, halfWidth, angle;
public:
	Rect(float cX, float cY, float hL, float hW, float angle);
	~Rect();
	float GetCentreX();
	float GetCentreY();
	float GetHalfLength();
	float GetHalfWidth();
	float GetAngle();
	void SetAttributes(float cX, float cY, float hL, float hW, float angle);
};