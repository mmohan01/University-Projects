// Michael Mohan 40020843
// 2D Physics Engine
#pragma region HEADER DECLARATIONS
#include "StdAfx.h"
#include "Rect.h"
#pragma endregion

// Constructor to provide access to 
// the components of the object.
Rect::Rect(float cX, float cY, float hL, float hW, float a)
{
	centreX = cX;
	centreY = cY;
	halfLength = hL;
	halfWidth = hW;
	angle = a;
}

// Destructor cleans up the data by freeing 
// the memory when the program is finished.
Rect::~Rect()
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
float Rect::GetCentreX()
{
	return centreX;
}

float Rect::GetCentreY()
{
	return centreY;
}

float Rect::GetHalfLength()
{
	return halfLength;
}

float Rect::GetHalfWidth()
{
	return halfWidth;
}

float Rect::GetAngle()
{
	return angle;
}

void Rect::SetAttributes(float cX, float cY, float hL, float hW, float a)
{
	centreX = cX;
	centreY = cY;
	halfLength = hL;
	halfWidth = hW;
	angle = a;
}
#pragma endregion