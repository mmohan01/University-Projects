// Michael Mohan 40020843
// 2D Physics Engine
#pragma region HEADER DECLARATIONS
#include "StdAfx.h"
#include "ShapeDI.h"
#pragma endregion

// Constructor to provide access to 
// the components of the object.
ShapeDI::ShapeDI(float sX, float sY, float eX, float eY, float cX, float cY, float r, float hL, float hW, float a)
{
	startX = sX;
	startY = sY;
	endX = eX;
	endY = eY;
	centreX = cX;
	centreY = cY;
	radius = r;
	halfLength = hL;
	halfWidth = hW;
	angle = a;
}

// Abstract constructor overload for CircleDI objects to inherit from.
ShapeDI::ShapeDI(float f1, float f2, float f3)
{
}

// Abstract constructor overload for LineDI and SquareDI objects to inherit from.
ShapeDI::ShapeDI(float f1, float f2, float f3, float f4)
{
}

// Abstract constructor overload for RectDI objects to inherit from.
ShapeDI::ShapeDI(float f1, float f2, float f3, float f4, float f5)
{
}

// Destructor cleans up the data by freeing 
// the memory when the program is finished.
ShapeDI::~ShapeDI()
{
	startX = NULL;
	startY = NULL;
	endX = NULL;
	endY = NULL;
	centreX = NULL;
	centreY = NULL;
	radius = NULL;
	halfLength = NULL;
	halfWidth = NULL;
	angle = NULL;
}

// Sequence of get and set functions
// used to provide access to the private
// members of the class object.
#pragma region GET/SET FUNCTIONS
float ShapeDI::GetStartX()
{
	return 0;
}

float ShapeDI::GetStartY()
{
	return 0;
}

float ShapeDI::GetEndX()
{
	return 0;
}

float ShapeDI::GetEndY()
{
	return 0;
}

float ShapeDI::GetCentreX()
{
	return 0;
}

float ShapeDI::GetCentreY()
{
	return 0;
}

float ShapeDI::GetRadius()
{
	return 0;
}

float ShapeDI::GetHalfLength()
{
	return 0;
}

float ShapeDI::GetHalfWidth()
{
	return 0;
}

float ShapeDI::GetAngle()
{
	return 0;
}

void ShapeDI::SetAttributes(float sX, float sY, float eX, float eY, float cX, float cY, float r, float hL, float hW, float a)
{
	startX = sX;
	startY = sY;
	endX = eX;
	endY = eY;
	centreX = cX;
	centreY = cY;
	radius = r;
	halfLength = hL;
	halfWidth = hW;
	angle = a;
}
#pragma endregion