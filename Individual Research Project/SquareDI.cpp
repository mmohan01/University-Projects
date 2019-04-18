// Michael Mohan 40020843
// 2D Physics Engine
#pragma region HEADER DECLARATIONS
#include "StdAfx.h"
#include "SquareDI.h"
#pragma endregion

// Constructor to provide access to 
// the components of the object.
SquareDI::SquareDI(float cX, float cY, float hL, float a) : ShapeDI(cX, cY, hL, a)
{
	centreX = cX;
	centreY = cY;
	halfLength = hL;
	angle = a;
}

// Destructor cleans up the data by freeing 
// the memory when the program is finished.
SquareDI::~SquareDI()
{
	centreX = NULL;
	centreY = NULL;
	halfLength = NULL;
	angle = NULL;
}

// Sequence of get and set functions
// used to provide access to the private
// members of the class object.
#pragma region GET/SET FUNCTIONS
float SquareDI::GetCentreX()
{
	return centreX;
}

float SquareDI::GetCentreY()
{
	return centreY;
}

float SquareDI::GetHalfLength()
{
	return halfLength;
}

float SquareDI::GetAngle()
{
	return angle;
}

//Overrides needed for other shapes.
float SquareDI::GetStartX()
{
	return 0;
}

float SquareDI::GetStartY()
{
	return 0;
}

float SquareDI::GetEndX()
{
	return 0;
}

float SquareDI::GetEndY()
{
	return 0;
}

float SquareDI::GetRadius()
{
	return 0;
}

float SquareDI::GetHalfWidth()
{
	return 0;
}

void SquareDI::SetAttributes(float cX, float cY, float hL, float a)
{
	centreX = cX;
	centreY = cY;
	halfLength = hL;
	angle = a;
}
#pragma endregion