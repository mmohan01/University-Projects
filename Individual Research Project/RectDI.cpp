// Michael Mohan 40020843
// 2D Physics Engine
#pragma region HEADER DECLARATIONS
#include "StdAfx.h"
#include "RectDI.h"
#pragma endregion

// Constructor to provide access to 
// the components of the object.
RectDI::RectDI(float cX, float cY, float hL, float hW, float a) : ShapeDI(cX, cY, hL, hW, a)
{
	centreX = cX;
	centreY = cY;
	halfLength = hL;
	halfWidth = hW;
	angle = a;
}

// Destructor cleans up the data by freeing 
// the memory when the program is finished.
RectDI::~RectDI()
{
	centreX = NULL;
	centreY = NULL;
	halfLength = NULL;
	halfWidth = NULL;
	angle = NULL;
}

// Sequence of get and set functions
// used to provide access to the private
// members of the class object.
#pragma region GET/SET FUNCTIONS
float RectDI::GetCentreX()
{
	return centreX;
}

float RectDI::GetCentreY()
{
	return centreY;
}

float RectDI::GetHalfLength()
{
	return halfLength;
}

float RectDI::GetHalfWidth()
{
	return halfWidth;
}

float RectDI::GetAngle()
{
	return angle;
}

// Overrides needed for other shapes.
float RectDI::GetStartX()
{
	return 0;
}

float RectDI::GetStartY()
{
	return 0;
}

float RectDI::GetEndX()
{
	return 0;
}

float RectDI::GetEndY()
{
	return 0;
}

float RectDI::GetRadius()
{
	return 0;
}

void RectDI::SetAttributes(float cX, float cY, float hL, float hW, float a)
{
	centreX = cX;
	centreY = cY;
	halfLength = hL;
	halfWidth = hW;
	angle = a;
}
#pragma endregion