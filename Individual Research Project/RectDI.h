// Michael Mohan 40020843
// 2D Physics Engine
#pragma region HEADER DECLARATIONS
#pragma once
#include "ShapeDI.h"
#pragma endregion

// Header file initializes methods for the main class.
class RectDI : public ShapeDI
{
	float centreX, centreY, halfLength, halfWidth, angle;
public:
	RectDI(float cX, float cY, float hL, float hW, float angle);
	~RectDI();

	virtual float GetCentreX();
	virtual float GetCentreY();
	float GetHalfLength();
	float GetHalfWidth();
	float GetAngle();

	// Overrides needed for other shapes.
	float GetStartX();
	float GetStartY();
	float GetEndX();
	float GetEndY();
	float GetRadius();
	void SetAttributes(float cX, float cY, float hL, float hW, float angle);
};