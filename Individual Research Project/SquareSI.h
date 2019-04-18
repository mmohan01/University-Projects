// Michael Mohan 40020843
// 2D Physics Engine
#pragma region HEADER DECLARATIONS
#pragma once
#include "ShapeSI.h"
#pragma endregion

// Header file initializes methods for the main class.
class SquareSI : public ShapeSI
{
	float centreX, centreY, halfLength, angle;
public:
	SquareSI(float cX, float cY, float hL, float a);
	~SquareSI();
	float GetCentreX();
	float GetCentreY();
	float GetHalfLength();
	float GetAngle();
	void SetAttributes(float cX, float cY, float hL, float a);

};