// Michael Mohan 40020843
// 2D Physics Engine
#pragma region HEADER DECLARATIONS
#pragma once
#include "Headers.h"
#pragma endregion

// Abstract class "Shape" created for other shapes to derive from. 
// Header file initializes methods for the main class.
class ShapeDI
{
protected:
	float startX, startY, endX, endY, centreX, centreY, radius, halfLength, halfWidth, angle;
public:
	ShapeDI(float sX, float sY, float eX, float eY, float cX, float cY, float r, float hL, float hW, float a);
	ShapeDI(float f1, float f2, float f3);
	ShapeDI(float f1, float f2, float f3, float f4);
	ShapeDI(float f1, float f2, float f3, float f4, float f5);
	~ShapeDI();

	virtual float GetStartX();
	virtual float GetStartY();
	virtual float GetEndX();
	virtual float GetEndY();

	virtual float GetCentreX();
	virtual float GetCentreY();
	virtual float GetRadius();

	virtual float GetHalfLength();
	virtual float GetHalfWidth();
	virtual float GetAngle();
	
	void SetAttributes(float sX, float sY, float eX, float eY, float cX, float cY, float r, float hL, float hW, float a);
};