// Michael Mohan 40020843
// 2D Physics Engine
#pragma region HEADER DECLARATIONS
#pragma once
#include "Headers.h"
#pragma endregion

// Abstract class "Shape" created for other shapes to derive from. 
// Header file initializes methods for the main class.
class ShapeSI
{
protected:
	float centreX, centreY;
public:
	ShapeSI(float cX, float cY);
	~ShapeSI();
	float GetCentreX();
	float GetCentreY();
	void SetAttributes(float cX, float cY);
};