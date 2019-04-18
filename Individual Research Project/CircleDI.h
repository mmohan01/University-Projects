// Michael Mohan 40020843
// 2D Physics Engine
#pragma region HEADER DECLARATIONS
#pragma once
#include "ShapeDI.h"
#pragma endregion

// Header file initializes methods for the main class.
class CircleDI : public ShapeDI
{
	float centreX, centreY, radius;
public:
	CircleDI(float cX, float cY, float r);
	~CircleDI();

	virtual float GetCentreX();
	virtual float GetCentreY();
	virtual float GetRadius();

	// Overrides needed for other shapes.
	float GetStartX();
	float GetStartY();
	float GetEndX();
	float GetEndY();
	float GetHalfLength();
	float GetHalfWidth();
	float GetAngle();

	void SetAttributes(float cX, float cY, float r);
};