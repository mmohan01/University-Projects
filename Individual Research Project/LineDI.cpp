// Michael Mohan 40020843
// 2D Physics Engine
#pragma region HEADER DECLARATIONS
#include "StdAfx.h"
#include "LineDI.h"
#pragma endregion

// Constructor to provide access to 
// the components of the object.
LineDI::LineDI(float sX, float sY, float eX, float eY) : ShapeDI(sX, sY, eX, eY)
{
	startX = sX;
	startY = sY;
	endX = eX;
	endY = eY;
}

// Destructor cleans up the data by freeing 
// the memory when the program is finished.
LineDI::~LineDI()
{
	startX = NULL;
	startY = NULL;
	endX = NULL;
	endY = NULL;
}

// Sequence of get and set functions
// used to provide access to the private
// members of the class object.
#pragma region GET/SET FUNCTIONS
float LineDI::GetStartX()
{
	return startX;
}

float LineDI::GetStartY()
{
	return startY;
}

float LineDI::GetEndX()
{
	return endX;
}

float LineDI::GetEndY()
{
	return endY;
}

// Overrides needed for other shapes.
float LineDI::GetCentreX()
{
	return 0;
}

float LineDI::GetCentreY()
{
	return 0;
}

float LineDI::GetRadius()
{
	return 0;
}

float LineDI::GetHalfLength()
{
	return 0;
}

float LineDI::GetHalfWidth()
{
	return 0;
}

float LineDI::GetAngle()
{
	return 0;
}

void LineDI::SetAttributes(float sX, float sY, float eX, float eY)
{
	startX = sX;
	startY = sY;
	endX = eX;
	endY = eY;
}