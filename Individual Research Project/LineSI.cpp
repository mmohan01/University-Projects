// Michael Mohan 40020843
// 2D Physics Engine
#pragma region HEADER DECLARATIONS
#include "StdAfx.h"
#include "LineSI.h"
#pragma endregion

// Constructor to provide access to 
// the components of the object.
LineSI::LineSI(float sX, float sY, float eX, float eY) : ShapeSI(sX, sY)
{
	startX = sX;
	startY = sY;
	endX = eX;
	endY = eY;
}

// Destructor cleans up the data by freeing 
// the memory when the program is finished.
LineSI::~LineSI()
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
float LineSI::GetStartX()
{
	return startX;
}

float LineSI::GetStartY()
{
	return startY;
}

float LineSI::GetEndX()
{
	return endX;
}

float LineSI::GetEndY()
{
	return endY;
}

void LineSI::SetAttributes(float sX, float sY, float eX, float eY)
{
	startX = sX;
	startY = sY;
	endX = eX;
	endY = eY;
}