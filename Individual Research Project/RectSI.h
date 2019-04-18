// Michael Mohan 40020843
// 2D Physics Engine
#pragma region HEADER DECLARATIONS
#pragma once
#include "ShapeSI.h"
#pragma endregion

// Header file initializes methods for the main class.
class RectSI : public ShapeSI
{
	float centreX, centreY, halfLength, halfWidth, angle;
public:
	RectSI(float cX, float cY, float hL, float hW, float angle);
	~RectSI();
	float GetCentreX();
	float GetCentreY();
	float GetHalfLength();
	float GetHalfWidth();
	float GetAngle();
	void SetAttributes(float cX, float cY, float hL, float hW, float angle);
};