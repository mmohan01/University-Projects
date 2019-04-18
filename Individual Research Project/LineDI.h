// Michael Mohan 40020843
// 2D Physics Engine
#pragma region HEADER DECLARATIONS
#pragma once
#include "ShapeDI.h"
#pragma endregion

// Header file initializes methods for the main class.
class LineDI : public ShapeDI
{
	float startX, startY, endX, endY;
public:
	LineDI(float sX, float sY, float eX, float eY);
	~LineDI();

	virtual float GetStartX();
	virtual float GetStartY();
	virtual float GetEndX();
	virtual float GetEndY();
	
	// Overrides needed for other shapes.
	float GetCentreX();
	float GetCentreY();
	float GetRadius();
	float GetHalfLength();
	float GetHalfWidth();
	float GetAngle();

	void SetAttributes(float sX, float sY, float eX, float eY);
};