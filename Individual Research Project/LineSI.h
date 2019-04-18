// Michael Mohan 40020843
// 2D Physics Engine
#pragma region HEADER DECLARATIONS
#pragma once
#include "ShapeSI.h"
#pragma endregion

// Header file initializes methods for the main class.
class LineSI : public ShapeSI
{
	float startX, startY, endX, endY;
public:
	LineSI(float sX, float sY, float eX, float eY);
	~LineSI();
	float GetStartX();
	float GetStartY();
	float GetEndX();
	float GetEndY();
	void SetAttributes(float sX, float sY, float eX, float eY);
};