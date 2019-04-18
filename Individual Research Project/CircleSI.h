// Michael Mohan 40020843
// 2D Physics Engine
#pragma region HEADER DECLARATIONS
#pragma once
#include "ShapeSI.h"
#pragma endregion

// Header file initializes methods for the main class.
class CircleSI : public ShapeSI
{
	float centreX, centreY, radius;
public:
	CircleSI(float cX, float cY, float r);
	~CircleSI();
	float GetCentreX();
	float GetCentreY();
	float GetRadius();
	void SetAttributes(float cX, float cY, float r);
};