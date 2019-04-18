// Michael Mohan 40020843
// 2D Physics Engine
#pragma region HEADER DECLARATIONS
#include "StdAfx.h"
#include "Circle.h"
#pragma endregion

// Constructor to provide access to 
// the components of the object.
Circle::Circle(float cX, float cY, float r)
{
	centreX = cX;
	centreY = cY;
	radius = r;
}

// Destructor cleans up the data by freeing 
// the memory when the program is finished.
Circle::~Circle()
{
	centreX = NULL;
	centreY = NULL;
	radius = NULL;
}

// Sequence of get and set functions
// used to provide access to the private
// members of the class object.
#pragma region GET/SET FUNCTIONS
float Circle::GetCentreX()
{
	return centreX;
}

float Circle::GetCentreY()
{
	return centreY;
}

float Circle::GetRadius()
{
	return radius;
}

void Circle::SetAttributes(float cX, float cY, float r)
{
	centreX = cX;
	centreY = cY;
	radius = r;
}
#pragma endregion
