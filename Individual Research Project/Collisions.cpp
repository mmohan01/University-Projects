// Michael Mohan 40020843
// 2D Physics Engine
#pragma region HEADER DECLARATIONS
#include "StdAfx.h"
#include "Collisions.h"
#pragma endregion

// Method to test for Line to Line collision.
// it is also used when checking for
// square/rect to line collision.
bool LineToLineCollision(float sX1, float sY1, float eX1, float eY1, float sX2, float sY2, float eX2, float eY2)
{
	float denominator = ((eY2 - sY2)*(eX1 - sX1)) - ((eX2 - sX2)*(eY1 - sY1));
	float numerator1 = ((eX2 - sX2)*(sY1 - sY2)) - ((eY2 - sY2)*(sX1 - sX2));
	float numerator2 = ((eX1 - sX1)*(sY1 - sY2)) - ((eY1 - sY1)*(sX1 - sX2));

	if (denominator == 0.0f)
		// The lines are parallel.
		return false;

	float Projection1 = numerator1 / denominator;
	float Projection2 = numerator2 / denominator;

	return ((Projection1 >= 0.0f) && (Projection1 <= 1.0f) && (Projection2 >= 0.0f) && (Projection2 <= 1.0f));
}

// Method used to calculate if the circle object has
// collided with a line and returns true if it has.
// It is also used when checking for square/rect to circle collision
bool LineToCircleCollision(float sX, float sY, float eX, float eY, float cX, float cY, float r)
{
	// Find the vector that represents the line.
	float lineX = eX - sX;
	float lineY = eY - sY;

	// Find the vector that represents the distance between
	// the start of the line and the centre of the circle.
	float circleX = cX - sX;
	float circleY = cY - sY;

	// Find the projection of the centre of the circle onto
	// the line by taking the dot product of the circle vector
	// with the line vector (this projects the centre of the
	// circle onto the normal to the line), and divide it by
	// the dot product of the line vector with itself (this
	// can be used to represent finding the normal to the line
	// and calculating the dot product of the circle vector with
	// that).
	float circleDotLine = DotProduct(cX, cY, lineX, lineY);
	float lineDotLine = DotProduct(lineX, lineY, lineX, lineY);
	float circleProjLine = circleDotLine/lineDotLine;		
	
	// This conditional operator constrains the projection.
	// If the value is 0 the circle vector is perpendicular
	// to the line vector and if it is 1 it is parallel so
	// if the the value is less than 0 or more
	// than 1 it is clamped to that range.
	if (circleProjLine < 0)
		circleProjLine = 0;
	else if (circleProjLine > 1)
		circleProjLine = 1;

	// Find the closest point on the line to the centre
	// of the circle by using the projection as a scale
	// along the line (between 0 and 1) and adding it to
	// the initial point on the line.
	float closestPointX = sX + (lineX*circleProjLine);
	float closestPointY = sY + (lineY*circleProjLine);
		
	// Floats used to represent the magnitude
	// of the distance between the centres of
	// the points.
	float xDistance = cX - closestPointX;
	float yDistance = cY - closestPointY;

	// If the distance between the centre of the circle
	// and the closest point on the line is less than the
	// radius of the circle then they intersect.
	return (sqrt(pow(xDistance, 2) + pow(yDistance, 2)) < r);
}

// Method used to calculate if the square object has collided 
// with a line and returns true if it has.
bool LineToSquareCollision(float sX, float sY, float eX, float eY, float cX, float cY, float hL, float a)
{
	int iPlus;
	int counter = 0;
	float coX[4], coY[4];

	// Defines the angular rotation of the square in radians.
	float radians = float(a*(3.141592654 / 180));

	// Constants are used to calculate the 
	// corner points of the square object
	// at any angular rotation.
	float xX = cos(radians)*hL;
	float xY = sin(radians)*hL;
	float yX = -sin(radians)*hL;
	float yY = cos(radians)*hL;

	// The corners of the square object are defined.
	coX[0] = cX - xX + yX;
	coY[0] = cY - xY + yY;
	coX[1] = cX + xX + yX;
	coY[1] = cY + xY + yY;
	coX[2] = cX + xX - yX;
	coY[2] = cY + xY - yY;
	coX[3] = cX - xX - yX;
	coY[3] = cY - xY - yY;

	// For each line of the square object, a line
	// to line collision is checked for and if there
	// is an intersect, true is returned.
	for (int i = 0; i < 4; i++)
	{
		iPlus = i + 1;
		if (i == 3)
			iPlus = 0;

		if (LineToLineCollision(sX, sY, eX, eY, coX[i], coY[i], coX[iPlus], coY[iPlus]))
			counter++;
	}

	// If no intersectsions 
	// occured then false is returned.
	if (counter > 0)
		return true;
	else
		return false;
}

// Method used to calculate if the rect object has collided 
// with a line and returns true if it has.
bool LineToRectCollision(float sX, float sY, float eX, float eY, float cX, float cY, float hL, float hW, float a)
{
	int iPlus;
	int counter = 0;
	float coX[4], coY[4];

	// Defines the angular rotation of the rect in radians.
	float radians = float(a*(3.141592654 / 180));

	// Constants are used to calculate the 
	// corner points of the rect object
	// at any angular rotation.
	float xX = cos(radians)*hL;
	float xY = sin(radians)*hL;
	float yX = -sin(radians)*hL;
	float yY = cos(radians)*hL;

	// The corners of the rect object are defined.
	coX[0] = cX - xX + yX;
	coY[0] = cY - xY + yY;
	coX[1] = cX + xX + yX;
	coY[1] = cY + xY + yY;
	coX[2] = cX + xX - yX;
	coY[2] = cY + xY - yY;
	coX[3] = cX - xX - yX;
	coY[3] = cY - xY - yY;

	// For each line of the rect object, a line
	// to line collision is checked for and if there
	// is an intersect, true is returned.
	for (int i = 0; i < 4; i++)
	{
		iPlus = i + 1;
		if (i == 3)
			iPlus = 0;

		if (LineToLineCollision(sX, sY, eX, eY, coX[i], coY[i], coX[iPlus], coY[iPlus]))
			counter++;
	}

	// If no intersectsions 
	// occured then false is returned.
	if (counter > 0)
		return true;
	else
		return false;
}

// Method used to calculate if the circle object has collided 
// with another circle object and returns true if it has.
bool CircleToCircleCollision(float cX1, float cY1, float r1, float cX2, float cY2, float r2)
{
	// Floats used to represent the magnitude
	// of the distance between the centres of
	// the circles.
	float xDistance = cX1 - cX2;
	float yDistance = cY1 - cY2;

	// If the distance between the centre points of the 2 circles 
	// is less than the sum of their radii then the circles 
	// must be intersecting. 
	return (sqrt(pow(xDistance, 2) + pow(yDistance, 2)) < (r1 + r2));
}

// Method used to calculate if the circle object has collided 
// with a square and returns true if it has.
bool CircleToSquareCollision(float cX1, float cY1, float r, float cX2, float cY2, float hL, float a)
{
	int iPlus;
	int counter = 0;
	float coX[4], coY[4];

	// Defines the angular rotation of the square in radians.
	float radians = float(a*(3.141592654 / 180));

	// Constants are used to calculate the 
	// corner points of the square object
	// at any angular rotation.
	float xX = cos(radians)*hL;
	float xY = sin(radians)*hL;
	float yX = -sin(radians)*hL;
	float yY = cos(radians)*hL;

	// The corners of the square object are defined.
	coX[0] = cX2 - xX + yX;
	coY[0] = cY2 - xY + yY;
	coX[1] = cX2 + xX + yX;
	coY[1] = cY2 + xY + yY;
	coX[2] = cX2 + xX - yX;
	coY[2] = cY2 + xY - yY;
	coX[3] = cX2 - xX - yX;
	coY[3] = cY2 - xY - yY;

	// Check for collison with the circle 
	// and the faces of the square.
	for (int i = 0; i < 4; i++)
	{
		iPlus = i + 1;
		if (i == 3)
			iPlus = 0;

		if (LineToCircleCollision(coX[i], coY[i], coX[iPlus], coY[iPlus], cX1, cY1, r))
			counter++;
	}

	// Check for collision with the circle 
	// and the vertices of the square.
	for (int j = 0; j < 4; j++)
	{
		// Find the distance between each corner
		// of the square and the centre of the circle.
		float xDistance = cX1 - coX[j];
		float yDistance = cY1 - coY[j];

		// If the distance between the corner of the square and the
		// centre of the circle is less than the radius of the circle,
		// then the circle is intersecting with the square.
		if (sqrt(pow(xDistance, 2) + pow(yDistance, 2)) < r)
			counter++;
	}

	// If no collision has occured by now, return false.
	if (counter > 0)
		return true;
	else
		return false;
}

// Method used to calculate if the circle object has collided 
// with a rectangle and returns true if it has.
bool CircleToRectCollision(float cX1, float cY1, float r, float cX2, float cY2, float hL, float hW, float a)
{
	int iPlus;
	int counter = 0;
	float coX[4], coY[4];

	// Defines the angular rotation of the rect in radians.
	float radians = float(a*(3.141592654 / 180));

	// Constants are used to calculate the 
	// corner points of the rect object
	// at any angular rotation.
	float xX = cos(radians)*hL;
	float xY = sin(radians)*hL;
	float yX = -sin(radians)*hL;
	float yY = cos(radians)*hL;

	// The corners of the rect object are defined.
	coX[0] = cX2 - xX + yX;
	coY[0] = cY2 - xY + yY;
	coX[1] = cX2 + xX + yX;
	coY[1] = cY2 + xY + yY;
	coX[2] = cX2 + xX - yX;
	coY[2] = cY2 + xY - yY;
	coX[3] = cX2 - xX - yX;
	coY[3] = cY2 - xY - yY;

	// Check for collison with the circle 
	// and the faces of the rect.
	for (int i = 0; i < 4; i++)
	{
		iPlus = i + 1;
		if (i == 3)
			iPlus = 0;

		if (LineToCircleCollision(coX[i], coY[i], coX[iPlus], coY[iPlus], cX1, cY1, r))
			counter++;
	}

	// Check for collision with the circle 
	// and the vertices of the rect.
	for (int j = 0; j < 4; j++)
	{
		// Find the distance between each corner
		// of the rect and the centre of the circle.
		float xDistance = cX1 - coX[j];
		float yDistance = cY1 - coY[j];

		// If the distance between the corner of the rect and the
		// centre of the circle is less than the radius of the circle,
		// then the circle is intersecting with the rect.
		if (sqrt(pow(xDistance, 2) + pow(yDistance, 2)) < r)
			counter++;
	}

	// If no collision has occured by now, return false.
	if (counter > 0)
		return true;
	else
		return false;
}

// Method used to calculate if the square object has collided 
// with another square and returns true if it has.
bool SquareToSquareCollision(float cX1, float cY1, float hL1, float a1, float cX2, float cY2, float hL2, float a2)
{
	int iPlus, jPlus;
	int counter = 0;
	float coX1[4], coY1[4], coX2[4], coY2[4];

	// Defines the angular rotation of square 1 in radians.
	float radians1 = float(a1*(3.141592654 / 180));

	// Constants are used to calculate 
	// the corner points of square 1
	// at any angular rotation.
	float xX1 = cos(radians1)*hL1;
	float xY1 = sin(radians1)*hL1;
	float yX1 = -sin(radians1)*hL1;
	float yY1 = cos(radians1)*hL1;

	// The corners of square 1 are defined.
	coX1[0] = cX1 - xX1 + yX1;
	coY1[0] = cY1 - xY1 + yY1;
	coX1[1] = cX1 + xX1 + yX1;
	coY1[1] = cY1 + xY1 + yY1;
	coX1[2] = cX1 + xX1 - yX1;
	coY1[2] = cY1 + xY1 - yY1;
	coX1[3] = cX1 - xX1 - yX1;
	coY1[3] = cY1 - xY1 - yY1;

	// Defines the angular rotation of square 2 in radians.
	float radians2 = float(a2*(3.141592654 / 180));

	// Constants are used to calculate 
	// the corner points of square 2
	// at any angular rotation.
	float xX2 = cos(radians2)*hL2;
	float xY2 = sin(radians2)*hL2;
	float yX2 = -sin(radians2)*hL2;
	float yY2 = cos(radians2)*hL2;

	// The corners of square 2 are defined.
	coX2[0] = cX2 - xX2 + yX2;
	coY2[0] = cY2 - xY2 + yY2;
	coX2[1] = cX2 + xX2 + yX2;
	coY2[1] = cY2 + xY2 + yY2;
	coX2[2] = cX2 + xX2 - yX2;
	coY2[2] = cY2 + xY2 - yY2;
	coX2[3] = cX2 - xX2 - yX2;
	coY2[3] = cY2 - xY2 - yY2;

	for (int i = 0; i < 4; i++)
	{
		iPlus = i + 1;
		if (i == 3)
			iPlus = 0;

		for (int j = 0; j < 4; j++)
		{
			jPlus = j + 1;
			if (j == 3)
				jPlus = 0;

			// For each side of each Square, a line to line collision
			// is checked for and if there is an intersection, true is returned.
			if (LineToLineCollision(coX1[i], coY1[i], coX1[iPlus], coY1[iPlus], coX2[i], coY2[i], coX2[iPlus], coY2[iPlus]))
				counter++;
		}
	}

	// If no intersectsions 
	// occured then false is returned.
	if (counter > 0)
		return true;
	else
		return false;
}

// Method used to calculate if the rect object has collided 
// with a square and returns true if it has.
bool SquareToRectCollision(float cX1, float cY1, float hL1, float a1, float cX2, float cY2, float hL2, float hW, float a2)
{
	int iPlus, jPlus;
	int counter = 0;
	float coX1[4], coY1[4], coX2[4], coY2[4];

	// Defines the angular rotation of the square object in radians.
	float radians1 = float(a1*(3.141592654 / 180));

	// Constants are used to calculate the 
	// corner points of the square object
	// at any angular rotation.
	float xX1 = cos(radians1)*hL1;
	float xY1 = sin(radians1)*hL1;
	float yX1 = -sin(radians1)*hL1;
	float yY1 = cos(radians1)*hL1;

	// The corners of the square object are defined.
	coX1[0] = cX1 - xX1 + yX1;
	coY1[0] = cY1 - xY1 + yY1;
	coX1[1] = cX1 + xX1 + yX1;
	coY1[1] = cY1 + xY1 + yY1;
	coX1[2] = cX1 + xX1 - yX1;
	coY1[2] = cY1 + xY1 - yY1;
	coX1[3] = cX1 - xX1 - yX1;
	coY1[3] = cY1 - xY1 - yY1;

	// Defines the angular rotation of the rect object in radians.
	float radians2 = float(a2*(3.141592654 / 180));

	// Constants are used to calculate the
	// corner points of the rect object
	// at any angular rotation.
	float xX2 = cos(radians2)*hL2;
	float xY2 = sin(radians2)*hL2;
	float yX2 = -sin(radians2)*hL2;
	float yY2 = cos(radians2)*hL2;

	// The corners of the rect object are defined.
	coX2[0] = cX2 - xX2 + yX2;
	coY2[0] = cY2 - xY2 + yY2;
	coX2[1] = cX2 + xX2 + yX2;
	coY2[1] = cY2 + xY2 + yY2;
	coX2[2] = cX2 + xX2 - yX2;
	coY2[2] = cY2 + xY2 - yY2;
	coX2[3] = cX2 - xX2 - yX2;
	coY2[3] = cY2 - xY2 - yY2;

	for (int i = 0; i < 4; i++)
	{
		iPlus = i + 1;
		if (i == 3)
			iPlus = 0;

		for (int j = 0; j < 4; j++)
		{
			jPlus = j + 1;
			if (j == 3)
				jPlus = 0;

			// For each side of the rectangle, a line to line collision
			// is checked for with each side of the square and if there 
			// is an intersection, true is returned.
			if (LineToLineCollision(coX1[i], coY1[i], coX1[iPlus], coY1[iPlus], coX2[i], coY2[i], coX2[iPlus], coY2[iPlus]))
				counter++;
		}
	}

	// If no intersectsions 
	// occured then false is returned.
	if (counter > 0)
		return true;
	else
		return false;
}

// Method used to calculate if the rect object has collided 
// with another rectangle and returns true if it has.
bool RectToRectCollision(float cX1, float cY1, float hL1, float hW1, float a1, float cX2, float cY2, float hL2, float hW2, float a2)
{
	int iPlus, jPlus;
	int counter = 0;
	float coX1[4], coY1[4], coX2[4], coY2[4];

	// Defines the angular rotation of rect 1 in radians.
	float radians1 = float(a1*(3.141592654 / 180));

	// Constants are used to calculate 
	// the corner points of rect 1
	// at any angular rotation.
	float xX1 = cos(radians1)*hL1;
	float xY1 = sin(radians1)*hL1;
	float yX1 = -sin(radians1)*hL1;
	float yY1 = cos(radians1)*hL1;

	// The corners of rect 1 are defined.
	coX1[0] = cX1 - xX1 + yX1;
	coY1[0] = cY1 - xY1 + yY1;
	coX1[1] = cX1 + xX1 + yX1;
	coY1[1] = cY1 + xY1 + yY1;
	coX1[2] = cX1 + xX1 - yX1;
	coY1[2] = cY1 + xY1 - yY1;
	coX1[3] = cX1 - xX1 - yX1;
	coY1[3] = cY1 - xY1 - yY1;

	// Defines the angular rotation of rect 2 in radians.
	float radians2 = float(a2*(3.141592654 / 180));

	// Constants are used to calculate 
	// the corner points of rect 2
	// at any angular rotation.
	float xX2 = cos(radians2)*hL2;
	float xY2 = sin(radians2)*hL2;
	float yX2 = -sin(radians2)*hL2;
	float yY2 = cos(radians2)*hL2;

	// The corners of rect 2 are defined.
	coX2[0] = cX2 - xX2 + yX2;
	coY2[0] = cY2 - xY2 + yY2;
	coX2[1] = cX2 + xX2 + yX2;
	coY2[1] = cY2 + xY2 + yY2;
	coX2[2] = cX2 + xX2 - yX2;
	coY2[2] = cY2 + xY2 - yY2;
	coX2[3] = cX2 - xX2 - yX2;
	coY2[3] = cY2 - xY2 - yY2;

	for (int i = 0; i < 4; i++)
	{
		iPlus = i + 1;
		if (i == 3)
			iPlus = 0;

		for (int j = 0; j < 4; j++)
		{
			jPlus = j + 1;
			if (j == 3)
				jPlus = 0;

			// For each side of each rectangle, a line to line collision
			// is checked for and if there is an intersection, true is returned.
			if (LineToLineCollision(coX1[i], coY1[i], coX1[iPlus], coY1[iPlus], coX2[i], coY2[i], coX2[iPlus], coY2[iPlus]))
				counter++;
		}
	}

	// If no intersectsions 
	// occured then false is returned.
	if (counter > 0)
		return true;
	else
		return false;
}


// First optimised version of the method.
// Introduces early breaks.
bool LineToLineCollisionOptimised1(float sX1, float sY1, float eX1, float eY1, float sX2, float sY2, float eX2, float eY2)
{
	float denominator = ((eY2 - sY2)*(eX1 - sX1)) - ((eX2 - sX2)*(eY1 - sY1));
	float numerator1 = ((eX2 - sX2)*(sY1 - sY2)) - ((eY2 - sY2)*(sX1 - sX2));
	float numerator2 = ((eX1 - sX1)*(sY1 - sY2)) - ((eY1 - sY1)*(sX1 - sX2));

	if (denominator == 0.0f)
		// The lines are parallel.
		return false;

	float Projection1 = numerator1 / denominator;
	float Projection2 = numerator2 / denominator;

	return ((Projection1 >= 0.0f) && (Projection1 <= 1.0f) && (Projection2 >= 0.0f) && (Projection2 <= 1.0f));
}

// First optimised version of the method.
// Introduces early breaks.
bool LineToCircleCollisionOptimised1(float sX, float sY, float eX, float eY, float cX, float cY, float r)
{
	// Find the vector that represents the line.
	float lineX = eX - sX;
	float lineY = eY - sY;

	// Find the vector that represents the distance between
	// the start of the line and the centre of the circle.
	float circleX = cX - sX;
	float circleY = cY - sY;

	// Find the projection of the centre of the circle onto
	// the line by taking the dot product of the circle vector
	// with the line vector (this projects the centre of the
	// circle onto the normal to the line), and divide it by
	// the dot product of the line vector with itself (this
	// can be used to represent finding the normal to the line
	// and calculating the dot product of the circle vector with
	// that).
	float circleDotLine = DotProduct(cX, cY, lineX, lineY);
	float lineDotLine = DotProduct(lineX, lineY, lineX, lineY);
	float circleProjLine = circleDotLine / lineDotLine;

	// This conditional operator constrains the projection.
	// If the value is 0 the circle vector is perpendicular
	// to the line vector and if it is 1 it is parallel so
	// if the the value is less than 0 or more
	// than 1 it is clamped to that range.
	if (circleProjLine < 0)
		circleProjLine = 0;
	else if (circleProjLine > 1)
		circleProjLine = 1;

	// Find the closest point on the line to the centre
	// of the circle by using the projection as a scale
	// along the line (between 0 and 1) and adding it to
	// the initial point on the line.
	float closestPointX = sX + (lineX*circleProjLine);
	float closestPointY = sY + (lineY*circleProjLine);

	// Floats used to represent the magnitude
	// of the distance between the centres of
	// the points.
	float xDistance = cX - closestPointX;
	float yDistance = cY - closestPointY;

	// If the distance between the centre of the circle
	// and the closest point on the line is less than the
	// radius of the circle then they intersect.
	return (sqrt(pow(xDistance, 2) + pow(yDistance, 2)) < r);
}

// First optimised version of the method.
// Introduces early breaks.
bool LineToSquareCollisionOptimised1(float sX, float sY, float eX, float eY, float cX, float cY, float hL, float a)
{

	int iPlus;
	float coX[4], coY[4];

	// Defines the angular rotation of the square in radians.
	float radians = float(a*(3.141592654 / 180));

	// Constants are used to calculate the
	// corner points of the square object
	// at any angular rotation.
	float xX = cos(radians)*hL;
	float xY = sin(radians)*hL;
	float yX = -sin(radians)*hL;
	float yY = cos(radians)*hL;

	// The corners of the square object are defined.
	coX[0] = cX - xX + yX;
	coY[0] = cY - xY + yY;
	coX[1] = cX + xX + yX;
	coY[1] = cY + xY + yY;
	coX[2] = cX + xX - yX;
	coY[2] = cY + xY - yY;
	coX[3] = cX - xX - yX;
	coY[3] = cY - xY - yY;


	// For each line of the square object, a line
	// to line collision is checked for and if there
	// is an intersect, true is returned.
	for (int i = 0; i < 4; i++)
	{
		iPlus = i + 1;
		if (i == 3)
			iPlus = 0;

		if (LineToLineCollisionOptimised1(sX, sY, eX, eY, coX[i], coY[i], coX[iPlus], coY[iPlus]))
			return true;
	}

	// If no intersectsions 
	// occured then false is returned.
	return false;
}

// First optimised version of the method.
// Introduces early breaks.
bool LineToRectCollisionOptimised1(float sX, float sY, float eX, float eY, float cX, float cY, float hL, float hW, float a)
{
	int iPlus;
	float coX[4], coY[4];

	// Defines the angular rotation of the rect in radians.
	float radians = float(a*(3.141592654 / 180));

	// Constants are used to calculate the 
	// corner points of the rect object
	// at any angular rotation.
	float xX = cos(radians)*hL;
	float xY = sin(radians)*hL;
	float yX = -sin(radians)*hL;
	float yY = cos(radians)*hL;

	// The corners of the rect object are defined.
	coX[0] = cX - xX + yX;
	coY[0] = cY - xY + yY;
	coX[1] = cX + xX + yX;
	coY[1] = cY + xY + yY;
	coX[2] = cX + xX - yX;
	coY[2] = cY + xY - yY;
	coX[3] = cX - xX - yX;
	coY[3] = cY - xY - yY;

	// For each line of the rect object, a line
	// to line collision is checked for and if there
	// is an intersect, true is returned.
	for (int i = 0; i < 4; i++)
	{
		iPlus = i + 1;
		if (i == 3)
			iPlus = 0;

		if (LineToLineCollisionOptimised1(sX, sY, eX, eY, coX[i], coY[i], coX[iPlus], coY[iPlus]))
			return true;
	}

	// If no intersectsions 
	// occured then false is returned.
	return false;
}

// First optimised version of the method.
// Introduces early breaks.
bool CircleToCircleCollisionOptimised1(float cX1, float cY1, float r1, float cX2, float cY2, float r2)
{
	// Floats used to represent the magnitude
	// of the distance between the centres of
	// the circles.
	float xDistance = cX1 - cX2;
	float yDistance = cY1 - cY2;

	// If the distance between the centre points of the 2 circles 
	// is less than the sum of their radii then the circles 
	// must be intersecting. 
	return (sqrt(pow(xDistance, 2) + pow(yDistance, 2)) < (r1 + r2));
}

// First optimised version of the method.
// Introduces early breaks.
bool CircleToSquareCollisionOptimised1(float cX1, float cY1, float r, float cX2, float cY2, float hL, float a)
{
	int iPlus;
	float coX[4], coY[4];

	// Defines the angular rotation of the square in radians.
	float radians = float(a*(3.141592654 / 180));

	// Constants are used to calculate the 
	// corner points of the square object
	// at any angular rotation.
	float xX = cos(radians)*hL;
	float xY = sin(radians)*hL;
	float yX = -sin(radians)*hL;
	float yY = cos(radians)*hL;

	// The corners of the square object are defined.
	coX[0] = cX2 - xX + yX;
	coY[0] = cY2 - xY + yY;
	coX[1] = cX2 + xX + yX;
	coY[1] = cY2 + xY + yY;
	coX[2] = cX2 + xX - yX;
	coY[2] = cY2 + xY - yY;
	coX[3] = cX2 - xX - yX;
	coY[3] = cY2 - xY - yY;

	// Check for collison with the circle 
	// and the faces of the square.
	for (int i = 0; i < 4; i++)
	{
		iPlus = i + 1;
		if (i == 3)
			iPlus = 0;

		if (LineToCircleCollisionOptimised1(coX[i], coY[i], coX[iPlus], coY[iPlus], cX1, cY1, r))
			return true;
	}

	// Check for collision with the circle 
	// and the vertices of the square.
	for (int j = 0; j < 4; j++)
	{
		// Find the distance between each corner
		// of the square and the centre of the circle.
		float xDistance = cX1 - coX[j];
		float yDistance = cY1 - coY[j];

		// If the distance between the corner of the square and the
		// centre of the circle is less than the radius of the circle,
		// then the circle is intersecting with the square.
		if (sqrt(pow(xDistance, 2) + pow(yDistance, 2)) < r)
			return true;
	}

	// If no collision has occured by now, return false.
	return false;
}

// First optimised version of the method.
// Introduces early breaks.
bool CircleToRectCollisionOptimised1(float cX1, float cY1, float r, float cX2, float cY2, float hL, float hW, float a)
{
	int iPlus;
	float coX[4], coY[4];

	// Defines the angular rotation of the rect in radians.
	float radians = float(a*(3.141592654 / 180));

	// Constants are used to calculate the 
	// corner points of the rect object
	// at any angular rotation.
	float xX = cos(radians)*hL;
	float xY = sin(radians)*hL;
	float yX = -sin(radians)*hL;
	float yY = cos(radians)*hL;

	// The corners of the rect object are defined.
	coX[0] = cX2 - xX + yX;
	coY[0] = cY2 - xY + yY;
	coX[1] = cX2 + xX + yX;
	coY[1] = cY2 + xY + yY;
	coX[2] = cX2 + xX - yX;
	coY[2] = cY2 + xY - yY;
	coX[3] = cX2 - xX - yX;
	coY[3] = cY2 - xY - yY;

	// Check for collison with the circle 
	// and the faces of the rect.
	for (int i = 0; i < 4; i++)
	{
		iPlus = i + 1;
		if (i == 3)
			iPlus = 0;

		if (LineToCircleCollisionOptimised1(coX[i], coY[i], coX[iPlus], coY[iPlus], cX1, cY1, r))
			return true;
	}

	// Check for collision with the circle 
	// and the vertices of the rect.
	for (int j = 0; j < 4; j++)
	{
		// Find the distance between each corner
		// of the rect and the centre of the circle.
		float xDistance = cX1 - coX[j];
		float yDistance = cY1 - coY[j];

		// If the distance between the corner of the rect and the
		// centre of the circle is less than the radius of the circle,
		// then the circle is intersecting with the rect.
		if (sqrt(pow(xDistance, 2) + pow(yDistance, 2)) < r)
			return true;
	}

	// If no collision has occured by now, return false.
	return false;
}

// First optimised version of the method.
// Introduces early breaks.
bool SquareToSquareCollisionOptimised1(float cX1, float cY1, float hL1, float a1, float cX2, float cY2, float hL2, float a2)
{
	int iPlus, jPlus;
	float coX1[4], coY1[4], coX2[4], coY2[4];

	// Defines the angular rotation of square 1 in radians.
	float radians1 = float(a1*(3.141592654 / 180));

	// Constants are used to calculate 
	// the corner points of square 1
	// at any angular rotation.
	float xX1 = cos(radians1)*hL1;
	float xY1 = sin(radians1)*hL1;
	float yX1 = -sin(radians1)*hL1;
	float yY1 = cos(radians1)*hL1;

	// The corners of square 1 are defined.
	coX1[0] = cX1 - xX1 + yX1;
	coY1[0] = cY1 - xY1 + yY1;
	coX1[1] = cX1 + xX1 + yX1;
	coY1[1] = cY1 + xY1 + yY1;
	coX1[2] = cX1 + xX1 - yX1;
	coY1[2] = cY1 + xY1 - yY1;
	coX1[3] = cX1 - xX1 - yX1;
	coY1[3] = cY1 - xY1 - yY1;

	// Defines the angular rotation of square 2 in radians.
	float radians2 = float(a2*(3.141592654 / 180));

	// Constants are used to calculate 
	// the corner points of square 2
	// at any angular rotation.
	float xX2 = cos(radians2)*hL2;
	float xY2 = sin(radians2)*hL2;
	float yX2 = -sin(radians2)*hL2;
	float yY2 = cos(radians2)*hL2;

	// The corners of square 2 are defined.
	coX2[0] = cX2 - xX2 + yX2;
	coY2[0] = cY2 - xY2 + yY2;
	coX2[1] = cX2 + xX2 + yX2;
	coY2[1] = cY2 + xY2 + yY2;
	coX2[2] = cX2 + xX2 - yX2;
	coY2[2] = cY2 + xY2 - yY2;
	coX2[3] = cX2 - xX2 - yX2;
	coY2[3] = cY2 - xY2 - yY2;

	for (int i = 0; i < 4; i++)
	{
		iPlus = i + 1;
		if (i == 3)
			iPlus = 0;

		for (int j = 0; j < 4; j++)
		{
			jPlus = j + 1;
			if (j == 3)
				jPlus = 0;

			// For each side of each Square, a line to line collision
			// is checked for and if there is an intersection, true is returned.
			if (LineToLineCollisionOptimised1(coX1[i], coY1[i], coX1[iPlus], coY1[iPlus], coX2[i], coY2[i], coX2[iPlus], coY2[iPlus]))
				return true;
		}
	}

	// If no intersectsions 
	// occured then false is returned.
	return false;
}

// First optimised version of the method.
// Introduces early breaks.
bool SquareToRectCollisionOptimised1(float cX1, float cY1, float hL1, float a1, float cX2, float cY2, float hL2, float hW, float a2)
{
	int iPlus, jPlus;
	float coX1[4], coY1[4], coX2[4], coY2[4];

	// Defines the angular rotation of the square object in radians.
	float radians1 = float(a1*(3.141592654 / 180));

	// Constants are used to calculate the 
	// corner points of the square object
	// at any angular rotation.
	float xX1 = cos(radians1)*hL1;
	float xY1 = sin(radians1)*hL1;
	float yX1 = -sin(radians1)*hL1;
	float yY1 = cos(radians1)*hL1;

	// The corners of the square object are defined.
	coX1[0] = cX1 - xX1 + yX1;
	coY1[0] = cY1 - xY1 + yY1;
	coX1[1] = cX1 + xX1 + yX1;
	coY1[1] = cY1 + xY1 + yY1;
	coX1[2] = cX1 + xX1 - yX1;
	coY1[2] = cY1 + xY1 - yY1;
	coX1[3] = cX1 - xX1 - yX1;
	coY1[3] = cY1 - xY1 - yY1;

	// Defines the angular rotation of the rect object in radians.
	float radians2 = float(a2*(3.141592654 / 180));

	// Constants are used to calculate the 
	// corner points of the rect object
	// at any angular rotation.
	float xX2 = cos(radians2)*hL2;
	float xY2 = sin(radians2)*hL2;
	float yX2 = -sin(radians2)*hL2;
	float yY2 = cos(radians2)*hL2;

	// The corners of the rect object are defined.
	coX2[0] = cX2 - xX2 + yX2;
	coY2[0] = cY2 - xY2 + yY2;
	coX2[1] = cX2 + xX2 + yX2;
	coY2[1] = cY2 + xY2 + yY2;
	coX2[2] = cX2 + xX2 - yX2;
	coY2[2] = cY2 + xY2 - yY2;
	coX2[3] = cX2 - xX2 - yX2;
	coY2[3] = cY2 - xY2 - yY2;

	for (int i = 0; i < 4; i++)
	{
		iPlus = i + 1;
		if (i == 3)
			iPlus = 0;

		for (int j = 0; j < 4; j++)
		{
			jPlus = j + 1;
			if (j == 3)
				jPlus = 0;

			// For each side of the rectangle, a line to line collision
			// is checked for with each side of the square and if there 
			// is an intersection, true is returned.
			if (LineToLineCollisionOptimised1(coX1[i], coY1[i], coX1[iPlus], coY1[iPlus], coX2[i], coY2[i], coX2[iPlus], coY2[iPlus]))
				return true;
		}
	}

	// If no intersectsions 
	// occured then false is returned.
	return false;
}

// First optimised version of the method.
// Introduces early breaks.
bool RectToRectCollisionOptimised1(float cX1, float cY1, float hL1, float hW1, float a1, float cX2, float cY2, float hL2, float hW2, float a2)
{
	int iPlus, jPlus;
	float coX1[4], coY1[4], coX2[4], coY2[4];

	// Defines the angular rotation of rect 1 in radians.
	float radians1 = float(a1*(3.141592654 / 180));

	// Constants are used to calculate 
	// the corner points of rect 1
	// at any angular rotation.
	float xX1 = cos(radians1)*hL1;
	float xY1 = sin(radians1)*hL1;
	float yX1 = -sin(radians1)*hL1;
	float yY1 = cos(radians1)*hL1;

	// The corners of rect 1 are defined.
	coX1[0] = cX1 - xX1 + yX1;
	coY1[0] = cY1 - xY1 + yY1;
	coX1[1] = cX1 + xX1 + yX1;
	coY1[1] = cY1 + xY1 + yY1;
	coX1[2] = cX1 + xX1 - yX1;
	coY1[2] = cY1 + xY1 - yY1;
	coX1[3] = cX1 - xX1 - yX1;
	coY1[3] = cY1 - xY1 - yY1;

	// Defines the angular rotation of rect 2 in radians.
	float radians2 = float(a2*(3.141592654 / 180));

	// Constants are used to calculate 
	// the corner points of rect 2
	// at any angular rotation.
	float xX2 = cos(radians2)*hL2;
	float xY2 = sin(radians2)*hL2;
	float yX2 = -sin(radians2)*hL2;
	float yY2 = cos(radians2)*hL2;

	// The corners of rect 2 are defined.
	coX2[0] = cX2 - xX2 + yX2;
	coY2[0] = cY2 - xY2 + yY2;
	coX2[1] = cX2 + xX2 + yX2;
	coY2[1] = cY2 + xY2 + yY2;
	coX2[2] = cX2 + xX2 - yX2;
	coY2[2] = cY2 + xY2 - yY2;
	coX2[3] = cX2 - xX2 - yX2;
	coY2[3] = cY2 - xY2 - yY2;

	for (int i = 0; i < 4; i++)
	{
		iPlus = i + 1;
		if (i == 3)
			iPlus = 0;

		for (int j = 0; j < 4; j++)
		{
			jPlus = j + 1;
			if (j == 3)
				jPlus = 0;

			// For each side of each rectangle, a line to line collision
			// is checked for and if there is an intersection, true is returned.
			if (LineToLineCollisionOptimised1(coX1[i], coY1[i], coX1[iPlus], coY1[iPlus], coX2[i], coY2[i], coX2[iPlus], coY2[iPlus]))
				return true;
		}
	}

	// If no intersectsions 
	// occured then false is returned.
	return false;
}


// Second optimised version of the method.
// Removes square roots.
bool LineToLineCollisionOptimised2(float sX1, float sY1, float eX1, float eY1, float sX2, float sY2, float eX2, float eY2)
{
	float denominator = ((eY2 - sY2)*(eX1 - sX1)) - ((eX2 - sX2)*(eY1 - sY1));
	float numerator1 = ((eX2 - sX2)*(sY1 - sY2)) - ((eY2 - sY2)*(sX1 - sX2));
	float numerator2 = ((eX1 - sX1)*(sY1 - sY2)) - ((eY1 - sY1)*(sX1 - sX2));

	if (denominator == 0.0f)
		// The lines are parallel.
		return false;

	float Projection1 = numerator1 / denominator;
	float Projection2 = numerator2 / denominator;

	return ((Projection1 >= 0.0f) && (Projection1 <= 1.0f) && (Projection2 >= 0.0f) && (Projection2 <= 1.0f));
}

// Second optimised version of the method.
// Removes square roots.
bool LineToCircleCollisionOptimised2(float sX, float sY, float eX, float eY, float cX, float cY, float r)
{
	// Find the vector that represents the line.
	float lineX = eX - sX;
	float lineY = eY - sY;

	// Find the vector that represents the distance between
	// the start of the line and the centre of the circle.
	float circleX = cX - sX;
	float circleY = cY - sY;

	// Find the projection of the centre of the circle onto
	// the line by taking the dot product of the circle vector
	// with the line vector (this projects the centre of the
	// circle onto the normal to the line), and divide it by
	// the dot product of the line vector with itself (this
	// can be used to represent finding the normal to the line
	// and calculating the dot product of the circle vector with
	// that).
	float circleDotLine = DotProduct(cX, cY, lineX, lineY);
	float lineDotLine = DotProduct(lineX, lineY, lineX, lineY);
	float circleProjLine = circleDotLine / lineDotLine;

	// This conditional operator constrains the projection.
	// If the value is 0 the circle vector is perpendicular
	// to the line vector and if it is 1 it is parallel so
	// if the the value is less than 0 or more
	// than 1 it is clamped to that range.
	if (circleProjLine < 0)
		circleProjLine = 0;
	else if (circleProjLine > 1)
		circleProjLine = 1;

	// Find the closest point on the line to the centre
	// of the circle by using the projection as a scale
	// along the line (between 0 and 1) and adding it to
	// the initial point on the line.
	float closestPointX = sX + (lineX*circleProjLine);
	float closestPointY = sY + (lineY*circleProjLine);

	// Floats used to represent the magnitude
	// of the distance between the centres of
	// the points.
	float xDistance = cX - closestPointX;
	float yDistance = cY - closestPointY;

	// If the distance between the centre of the circle
	// and the closest point on the line is less than the
	// radius of the circle then they intersect.
	// I am adding the squared magnitude of the 2 values to 
	// prevent using the expensive square root operator:
	// sqrt(x2 + y2) < r ==> x2 + y2 < r2.
	return (SquaredMagnitude(xDistance, yDistance) < (pow(r, 2)));
}

// Second optimised version of the method.
// Removes square roots.
bool LineToSquareCollisionOptimised2(float sX, float sY, float eX, float eY, float cX, float cY, float hL, float a)
{

	int iPlus;
	int counter = 0;
	float coX[4], coY[4];

	// Defines the angular rotation of the square in radians.
	float radians = float(a*(3.141592654 / 180));

	// Constants are used to calculate the
	// corner points of the square object
	// at any angular rotation.
	float xX = cos(radians)*hL;
	float xY = sin(radians)*hL;
	float yX = -sin(radians)*hL;
	float yY = cos(radians)*hL;

	// The corners of the square object are defined.
	coX[0] = cX - xX + yX;
	coY[0] = cY - xY + yY;
	coX[1] = cX + xX + yX;
	coY[1] = cY + xY + yY;
	coX[2] = cX + xX - yX;
	coY[2] = cY + xY - yY;
	coX[3] = cX - xX - yX;
	coY[3] = cY - xY - yY;


	// For each line of the square object, a line
	// to line collision is checked for and if there
	// is an intersect, true is returned.
	for (int i = 0; i < 4; i++)
	{
		iPlus = i + 1;
		if (i == 3)
			iPlus = 0;

		if (LineToLineCollisionOptimised2(sX, sY, eX, eY, coX[i], coY[i], coX[iPlus], coY[iPlus]))
			counter++;
	}

	// If no intersectsions 
	// occured then false is returned.
	if (counter > 0)
		return true;
	else
		return false;
}

// Second optimised version of the method.
// Removes square roots.
bool LineToRectCollisionOptimised2(float sX, float sY, float eX, float eY, float cX, float cY, float hL, float hW, float a)
{
	int iPlus;
	int counter = 0;
	float coX[4], coY[4];

	// Defines the angular rotation of the rect in radians.
	float radians = float(a*(3.141592654 / 180));

	// Constants are used to calculate the 
	// corner points of the rect object
	// at any angular rotation.
	float xX = cos(radians)*hL;
	float xY = sin(radians)*hL;
	float yX = -sin(radians)*hL;
	float yY = cos(radians)*hL;

	// The corners of the rect object are defined.
	coX[0] = cX - xX + yX;
	coY[0] = cY - xY + yY;
	coX[1] = cX + xX + yX;
	coY[1] = cY + xY + yY;
	coX[2] = cX + xX - yX;
	coY[2] = cY + xY - yY;
	coX[3] = cX - xX - yX;
	coY[3] = cY - xY - yY;

	// For each line of the rect object, a line
	// to line collision is checked for and if there
	// is an intersect, true is returned.
	for (int i = 0; i < 4; i++)
	{
		iPlus = i + 1;
		if (i == 3)
			iPlus = 0;

		if (LineToLineCollisionOptimised2(sX, sY, eX, eY, coX[i], coY[i], coX[iPlus], coY[iPlus]))
			counter++;
	}

	// If no intersectsions 
	// occured then false is returned.
	if (counter > 0)
		return true;
	else
		return false;
}

// Second optimised version of the method.
// Removes square roots.
bool CircleToCircleCollisionOptimised2(float cX1, float cY1, float r1, float cX2, float cY2, float r2)
{
	// Floats used to represent the magnitude
	// of the distance between the centres of
	// the circles.
	float xDistance = cX1 - cX2;
	float yDistance = cY1 - cY2;

	// If the distance between the centre points of the 2 circles 
	// is less than the sum of their radii then the circles 
	// must be intersecting. 
	// I am adding the squared magnitude of the 2 values to 
	// prevent using the expensive square root operator:
	// sqrt(x2 + y2) < r1 + r2 ==> x2 + y2 < (r1 + r2)2.
	return (SquaredMagnitude(xDistance, yDistance) < (pow(r1 + r2, 2)));
}

// Second optimised version of the method.
// Removes square roots.
bool CircleToSquareCollisionOptimised2(float cX1, float cY1, float r, float cX2, float cY2, float hL, float a)
{
	int iPlus;
	int counter = 0;
	float coX[4], coY[4];

	// Defines the angular rotation of the square in radians.
	float radians = float(a*(3.141592654 / 180));

	// Constants are used to calculate the 
	// corner points of the square object
	// at any angular rotation.
	float xX = cos(radians)*hL;
	float xY = sin(radians)*hL;
	float yX = -sin(radians)*hL;
	float yY = cos(radians)*hL;

	// The corners of the square object are defined.
	coX[0] = cX2 - xX + yX;
	coY[0] = cY2 - xY + yY;
	coX[1] = cX2 + xX + yX;
	coY[1] = cY2 + xY + yY;
	coX[2] = cX2 + xX - yX;
	coY[2] = cY2 + xY - yY;
	coX[3] = cX2 - xX - yX;
	coY[3] = cY2 - xY - yY;

	// Check for collison with the circle 
	// and the faces of the square.
	for (int i = 0; i < 4; i++)
	{
		iPlus = i + 1;
		if (i == 3)
			iPlus = 0;

		if (LineToCircleCollisionOptimised2(coX[i], coY[i], coX[iPlus], coY[iPlus], cX1, cY1, r))
			counter++;
	}

	// Check for collision with the circle 
	// and the vertices of the square.
	for (int j = 0; j < 4; j++)
	{
		// Find the distance between each corner
		// of the square and the centre of the circle.
		float xDistance = cX1 - coX[j];
		float yDistance = cY1 - coY[j];

		// If the distance between the corner of the square and the
		// centre of the circle is less than the radius of the circle,
		// then the circle is intersecting with the square. 
		// To avoid the use of the expensive square root operator 
		// the squared distance is used instead:
		// sqrt(distanceX2 + distanceY2) < radius --> distanceX2 + distanceY2 < radius2.
		if (SquaredMagnitude(xDistance, yDistance)  < pow(r, 2))
			counter++;
	}

	// If no collision has occured by now, return false.
	if (counter > 0)
		return true;
	else
		return false;
}

// Second optimised version of the method.
// Removes square roots.
bool CircleToRectCollisionOptimised2(float cX1, float cY1, float r, float cX2, float cY2, float hL, float hW, float a)
{
	int iPlus;
	int counter = 0;
	float coX[4], coY[4];

	// Defines the angular rotation of the rect in radians.
	float radians = float(a*(3.141592654 / 180));

	// Constants are used to calculate the 
	// corner points of the rect object
	// at any angular rotation.
	float xX = cos(radians)*hL;
	float xY = sin(radians)*hL;
	float yX = -sin(radians)*hL;
	float yY = cos(radians)*hL;

	// The corners of the rect object are defined.
	coX[0] = cX2 - xX + yX;
	coY[0] = cY2 - xY + yY;
	coX[1] = cX2 + xX + yX;
	coY[1] = cY2 + xY + yY;
	coX[2] = cX2 + xX - yX;
	coY[2] = cY2 + xY - yY;
	coX[3] = cX2 - xX - yX;
	coY[3] = cY2 - xY - yY;

	// Check for collison with the circle 
	// and the faces of the rect.
	for (int i = 0; i < 4; i++)
	{
		iPlus = i + 1;
		if (i == 3)
			iPlus = 0;

		if (LineToCircleCollisionOptimised2(coX[i], coY[i], coX[iPlus], coY[iPlus], cX1, cY1, r))
			counter++;
	}

	// Check for collision with the circle 
	// and the vertices of the rect.
	for (int j = 0; j < 4; j++)
	{
		// Find the distance between each corner
		// of the rect and the centre of the circle.
		float xDistance = cX1 - coX[j];
		float yDistance = cY1 - coY[j];

		// If the distance between the corner of the rect and the
		// centre of the circle is less than the radius of the circle,
		// then the circle is intersecting with the rect. 
		// To avoid the use of the expensive square root operator 
		// the squared distance is used instead:
		// sqrt(distanceX2 + distanceY2) < radius --> distanceX2 + distanceY2 < radius2.
		if (SquaredMagnitude(xDistance, yDistance)  < pow(r, 2))
			counter++;
	}

	// If no collision has occured by now, return false.
	if (counter > 0)
		return true;
	else
		return false;
}

// Second optimised version of the method.
// Removes square roots.
bool SquareToSquareCollisionOptimised2(float cX1, float cY1, float hL1, float a1, float cX2, float cY2, float hL2, float a2)
{
	int iPlus, jPlus;
	int counter = 0;
	float coX1[4], coY1[4], coX2[4], coY2[4];

	// Defines the angular rotation of square 1 in radians.
	float radians1 = float(a1*(3.141592654 / 180));

	// Constants are used to calculate 
	// the corner points of square 1
	// at any angular rotation.
	float xX1 = cos(radians1)*hL1;
	float xY1 = sin(radians1)*hL1;
	float yX1 = -sin(radians1)*hL1;
	float yY1 = cos(radians1)*hL1;

	// The corners of square 1 are defined.
	coX1[0] = cX1 - xX1 + yX1;
	coY1[0] = cY1 - xY1 + yY1;
	coX1[1] = cX1 + xX1 + yX1;
	coY1[1] = cY1 + xY1 + yY1;
	coX1[2] = cX1 + xX1 - yX1;
	coY1[2] = cY1 + xY1 - yY1;
	coX1[3] = cX1 - xX1 - yX1;
	coY1[3] = cY1 - xY1 - yY1;

	// Defines the angular rotation of square 2 in radians.
	float radians2 = float(a2*(3.141592654 / 180));

	// Constants are used to calculate 
	// the corner points of square 2
	// at any angular rotation.
	float xX2 = cos(radians2)*hL2;
	float xY2 = sin(radians2)*hL2;
	float yX2 = -sin(radians2)*hL2;
	float yY2 = cos(radians2)*hL2;

	// The corners of square 2 are defined.
	coX2[0] = cX2 - xX2 + yX2;
	coY2[0] = cY2 - xY2 + yY2;
	coX2[1] = cX2 + xX2 + yX2;
	coY2[1] = cY2 + xY2 + yY2;
	coX2[2] = cX2 + xX2 - yX2;
	coY2[2] = cY2 + xY2 - yY2;
	coX2[3] = cX2 - xX2 - yX2;
	coY2[3] = cY2 - xY2 - yY2;

	for (int i = 0; i < 4; i++)
	{
		iPlus = i + 1;
		if (i == 3)
			iPlus = 0;

		for (int j = 0; j < 4; j++)
		{
			jPlus = j + 1;
			if (j == 3)
				jPlus = 0;

			// For each side of each Square, a line to line collision
			// is checked for and if there is an intersection, true is returned.
			if (LineToLineCollisionOptimised2(coX1[i], coY1[i], coX1[iPlus], coY1[iPlus], coX2[i], coY2[i], coX2[iPlus], coY2[iPlus]))
				counter++;
		}
	}

	// If no intersectsions 
	// occured then false is returned.
	if (counter > 0)
		return true;
	else
		return false;
}

// Second optimised version of the method.
// Removes square roots.
bool SquareToRectCollisionOptimised2(float cX1, float cY1, float hL1, float a1, float cX2, float cY2, float hL2, float hW, float a2)
{
	int iPlus, jPlus;
	int counter = 0;
	float coX1[4], coY1[4], coX2[4], coY2[4];

	// Defines the angular rotation of the square object in radians.
	float radians1 = float(a1*(3.141592654 / 180));

	// Constants are used to calculate the 
	// corner points of the square object
	// at any angular rotation.
	float xX1 = cos(radians1)*hL1;
	float xY1 = sin(radians1)*hL1;
	float yX1 = -sin(radians1)*hL1;
	float yY1 = cos(radians1)*hL1;

	// The corners of the square object are defined.
	coX1[0] = cX1 - xX1 + yX1;
	coY1[0] = cY1 - xY1 + yY1;
	coX1[1] = cX1 + xX1 + yX1;
	coY1[1] = cY1 + xY1 + yY1;
	coX1[2] = cX1 + xX1 - yX1;
	coY1[2] = cY1 + xY1 - yY1;
	coX1[3] = cX1 - xX1 - yX1;
	coY1[3] = cY1 - xY1 - yY1;

	// Defines the angular rotation of the rect object in radians.
	float radians2 = float(a2*(3.141592654 / 180));

	// Constants are used to calculate the 
	// corner points of the rect object
	// at any angular rotation.
	float xX2 = cos(radians2)*hL2;
	float xY2 = sin(radians2)*hL2;
	float yX2 = -sin(radians2)*hL2;
	float yY2 = cos(radians2)*hL2;

	// The corners of the rect object are defined.
	coX2[0] = cX2 - xX2 + yX2;
	coY2[0] = cY2 - xY2 + yY2;
	coX2[1] = cX2 + xX2 + yX2;
	coY2[1] = cY2 + xY2 + yY2;
	coX2[2] = cX2 + xX2 - yX2;
	coY2[2] = cY2 + xY2 - yY2;
	coX2[3] = cX2 - xX2 - yX2;
	coY2[3] = cY2 - xY2 - yY2;

	for (int i = 0; i < 4; i++)
	{
		iPlus = i + 1;
		if (i == 3)
			iPlus = 0;

		for (int j = 0; j < 4; j++)
		{
			jPlus = j + 1;
			if (j == 3)
				jPlus = 0;

			// For each side of the rectangle, a line to line collision
			// is checked for with each side of the square and if there 
			// is an intersection, true is returned.
			if (LineToLineCollisionOptimised2(coX1[i], coY1[i], coX1[iPlus], coY1[iPlus], coX2[i], coY2[i], coX2[iPlus], coY2[iPlus]))
				counter++;
		}
	}

	// If no intersectsions 
	// occured then false is returned.
	if (counter > 0)
		return true;
	else
		return false;
}

// Second optimised version of the method.
// Removes square roots.
bool RectToRectCollisionOptimised2(float cX1, float cY1, float hL1, float hW1, float a1, float cX2, float cY2, float hL2, float hW2, float a2)
{
	int iPlus, jPlus;
	int counter = 0;
	float coX1[4], coY1[4], coX2[4], coY2[4];

	// Defines the angular rotation of rect 1 in radians.
	float radians1 = float(a1*(3.141592654 / 180));

	// Constants are used to calculate 
	// the corner points of rect 1
	// at any angular rotation.
	float xX1 = cos(radians1)*hL1;
	float xY1 = sin(radians1)*hL1;
	float yX1 = -sin(radians1)*hL1;
	float yY1 = cos(radians1)*hL1;

	// The corners of rect 1 are defined.
	coX1[0] = cX1 - xX1 + yX1;
	coY1[0] = cY1 - xY1 + yY1;
	coX1[1] = cX1 + xX1 + yX1;
	coY1[1] = cY1 + xY1 + yY1;
	coX1[2] = cX1 + xX1 - yX1;
	coY1[2] = cY1 + xY1 - yY1;
	coX1[3] = cX1 - xX1 - yX1;
	coY1[3] = cY1 - xY1 - yY1;

	// Defines the angular rotation of rect 2 in radians.
	float radians2 = float(a2*(3.141592654 / 180));

	// Constants are used to calculate 
	// the corner points of rect 2
	// at any angular rotation.
	float xX2 = cos(radians2)*hL2;
	float xY2 = sin(radians2)*hL2;
	float yX2 = -sin(radians2)*hL2;
	float yY2 = cos(radians2)*hL2;

	// The corners of rect 2 are defined.
	coX2[0] = cX2 - xX2 + yX2;
	coY2[0] = cY2 - xY2 + yY2;
	coX2[1] = cX2 + xX2 + yX2;
	coY2[1] = cY2 + xY2 + yY2;
	coX2[2] = cX2 + xX2 - yX2;
	coY2[2] = cY2 + xY2 - yY2;
	coX2[3] = cX2 - xX2 - yX2;
	coY2[3] = cY2 - xY2 - yY2;

	for (int i = 0; i < 4; i++)
	{
		iPlus = i + 1;
		if (i == 3)
			iPlus = 0;

		for (int j = 0; j < 4; j++)
		{
			jPlus = j + 1;
			if (j == 3)
				jPlus = 0;

			// For each side of each rectangle, a line to line collision
			// is checked for and if there is an intersection, true is returned.
			if (LineToLineCollisionOptimised2(coX1[i], coY1[i], coX1[iPlus], coY1[iPlus], coX2[i], coY2[i], coX2[iPlus], coY2[iPlus]))
				counter++;
		}
	}

	// If no intersectsions 
	// occured then false is returned.
	if (counter > 0)
		return true;
	else
		return false;
}

