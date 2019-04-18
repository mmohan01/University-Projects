// Michael Mohan 40020843
// 2D Physics Engine
#pragma region HEADER DECLARATIONS
#include "StdAfx.h"
#include "Square.h"
#pragma endregion

// Constructor to provide access to 
// the components of the object.
Square::Square(float cX, float cY, float hL, float a)
{
	centreX = cX;
	centreY = cY;
	halfLength = hL;
	angle = a;
}

// Destructor cleans up the data by freeing 
// the memory when the program is finished.
Square::~Square()
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
float Square::GetCentreX()
{
	return centreX;
}

float Square::GetCentreY()
{
	return centreY;
}

float Square::GetHalfLength()
{
	return halfLength;
}

float Square::GetAngle()
{
	return angle;
}

void Square::SetAttributes(float cX, float cY, float hL, float a)
{
	centreX = cX;
	centreY = cY;
	halfLength = hL;
	angle = a;
}
#pragma endregion