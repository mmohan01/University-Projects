// Michael Mohan 40020843
// 2D Physics Engine
#pragma region HEADER DECLARATIONS
#include "StdAfx.h"
#include "Line.h"
#pragma endregion

// Constructor to provide access to 
// the components of the object.
Line::Line(float sX, float sY, float eX, float eY)
{
	startX = sX;
	startY = sY;
	endX = eX;
	endY = eY;
}

// Destructor cleans up the data by freeing 
// the memory when the program is finished.
Line::~Line()
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
float Line::GetStartX()
{
	return startX;
}

float Line::GetStartY()
{
	return startY;
}

float Line::GetEndX()
{
	return endX;
}

float Line::GetEndY()
{
	return endY;
}

void Line::SetAttributes(float sX, float sY, float eX, float eY)
{
	startX = sX;
	startY = sY; 
	endX = eX;
	endY = eY;
}