// Michael Mohan 40020843
// 2D Physics Engine
#pragma region HEADER DECLARATIONS
#include "StdAfx.h"
#include "ShapeSI.h"
#pragma endregion

// Constructor to provide access to 
// the components of the object.
ShapeSI::ShapeSI(float cX, float cY)
{
	centreX = cX;
	centreY = cY;
}

// Destructor cleans up the data by freeing 
// the memory when the program is finished.
ShapeSI::~ShapeSI()
{
	centreX = NULL;
	centreY = NULL;
}

// Sequence of get and set functions
// used to provide access to the private
// members of the class object.
#pragma region GET/SET FUNCTIONS
float ShapeSI::GetCentreX()
{
	return centreX;
}

float ShapeSI::GetCentreY()
{
	return centreY;
}

void ShapeSI::SetAttributes(float cX, float cY)
{
	centreX = cX;
	centreY = cY;
}
#pragma endregion