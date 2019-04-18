// Michael Mohan 40020843
// 2D Physics Engine
#pragma region HEADER DECLARATIONS
#include "StdAfx.h"
#include "CircleDI.h"
#pragma endregion

// Constructor to provide access to 
// the components of the object.
CircleDI::CircleDI(float cX, float cY, float r) : ShapeDI(cX, cY, r)
{
	centreX = cX;
	centreY = cY;
	radius = r;
}

// Destructor cleans up the data by freeing 
// the memory when the program is finished.
CircleDI::~CircleDI()
{
	centreX = NULL;
	centreY = NULL;
	radius = NULL;
}

// Sequence of get and set functions
// used to provide access to the private
// members of the class object.
#pragma region GET/SET FUNCTIONS
float CircleDI::GetCentreX()
{
	return centreX;
}

float CircleDI::GetCentreY()
{
	return centreY;
}

float CircleDI::GetRadius()
{
	return radius;
}

// Overrides needed for other shapes.
float CircleDI::GetStartX()
{
	return 0;
}

float CircleDI::GetStartY()
{
	return 0;
}

float CircleDI::GetEndX()
{
	return 0;
}

float CircleDI::GetEndY()
{
	return 0;
}

float CircleDI::GetHalfLength()
{
	return 0;
}

float CircleDI::GetHalfWidth()
{
	return 0;
}

float CircleDI::GetAngle()
{
	return 0;
}

void CircleDI::SetAttributes(float cX, float cY, float r)
{
	centreX = cX;
	centreY = cY;
	radius = r;
}
#pragma endregion