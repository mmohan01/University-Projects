// Michael Mohan 40020843
// 2D Physics Engine
#pragma region HEADER DECLARATIONS
#include "StdAfx.h"
#include "RectSI.h"
#pragma endregion

// Constructor to provide access to 
// the components of the object.
RectSI::RectSI(float cX, float cY, float hL, float hW, float a) : ShapeSI(cX, cY)
{
	centreX = cX;
	centreY = cY;
	halfLength = hL;
	halfWidth = hW;
	angle = a;
}

// Destructor cleans up the data by freeing 
// the memory when the program is finished.
RectSI::~RectSI()
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
float RectSI::GetCentreX()
{
	return centreX;
}

float RectSI::GetCentreY()
{
	return centreY;
}

float RectSI::GetHalfLength()
{
	return halfLength;
}

float RectSI::GetHalfWidth()
{
	return halfWidth;
}

float RectSI::GetAngle()
{
	return angle;
}

void RectSI::SetAttributes(float cX, float cY, float hL, float hW, float a)
{
	centreX = cX;
	centreY = cY;
	halfLength = hL;
	halfWidth = hW;
	angle = a;
}
#pragma endregion