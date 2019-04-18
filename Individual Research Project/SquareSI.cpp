// Michael Mohan 40020843
// 2D Physics Engine
#pragma region HEADER DECLARATIONS
#include "StdAfx.h"
#include "SquareSI.h"
#pragma endregion

// Constructor to provide access to 
// the components of the object.
SquareSI::SquareSI(float cX, float cY, float hL, float a) : ShapeSI(cX, cY)
{
	centreX = cX;
	centreY = cY;
	halfLength = hL;
	angle = a;
}

// Destructor cleans up the data by freeing 
// the memory when the program is finished.
SquareSI::~SquareSI()
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
float SquareSI::GetCentreX()
{
	return centreX;
}

float SquareSI::GetCentreY()
{
	return centreY;
}

float SquareSI::GetHalfLength()
{
	return halfLength;
}

float SquareSI::GetAngle()
{
	return angle;
}

void SquareSI::SetAttributes(float cX, float cY, float hL, float a)
{
	centreX = cX;
	centreY = cY;
	halfLength = hL;
	angle = a;
}
#pragma endregion