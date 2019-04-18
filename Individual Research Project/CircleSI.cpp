// Michael Mohan 40020843
// 2D Physics Engine
#pragma region HEADER DECLARATIONS
#include "StdAfx.h"
#include "CircleSI.h"
#pragma endregion

// Constructor to provide access to 
// the components of the object.
CircleSI::CircleSI(float cX, float cY, float r) : ShapeSI(cX, cY)
{
	centreX = cX;
	centreY = cY;
	radius = r;
}

// Destructor cleans up the data by freeing 
// the memory when the program is finished.
CircleSI::~CircleSI()
{
	centreX = NULL;
	centreY = NULL;
	radius = NULL;
}

// Sequence of get and set functions
// used to provide access to the private
// members of the class object.
#pragma region GET/SET FUNCTIONS
float CircleSI::GetCentreX()
{
	return centreX;
}

float CircleSI::GetCentreY()
{
	return centreY;
}

float CircleSI::GetRadius()
{
	return radius;
}

void CircleSI::SetAttributes(float cX, float cY, float r)
{
	centreX = cX;
	centreY = cY;
	radius = r;
}
#pragma endregion