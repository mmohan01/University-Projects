// Michael Mohan 40020843
// 2D Physics Engine
#pragma region HEADER DECLARATIONS
#pragma once
#include "ShapeDI.h"
#pragma endregion

// Header file initializes methods for the main class.
class SquareDI : public ShapeDI
{
	float centreX, centreY, halfLength, angle;
public:
	SquareDI(float cX, float cY, float hL, float a);
	~SquareDI();

	virtual float GetCentreX();
	virtual float GetCentreY();
	float GetHalfLength();
	float GetAngle();

	// Overrides needed for other shapes.
	float GetStartX();
	float GetStartY();
	float GetEndX();
	float GetEndY();
	float GetRadius();
	float GetHalfWidth();

	void SetAttributes(float cX, float cY, float hL, float a);

};