// Michael Mohan 002083
// 2D Physics Engine
#pragma region HEADER DECLARATIONS
#include "Methods.h"
#pragma endregion

// Unoptimised Algorithm.
bool LineToLineCollision(float sX1, float sY1, float eX1, float eY1, float sX2, float sY2, float eX2, float eY2);
bool LineToCircleCollision(float sX, float sY, float eX, float eY, float cX, float cY, float r);
bool LineToSquareCollision(float sX, float sY, float eX, float eY, float cX, float cY, float hL, float a);
bool LineToRectCollision(float sX, float sY, float eX, float eY, float cX, float cY, float hL, float hW, float a);

bool CircleToCircleCollision(float cX1, float cY1, float r1, float cX2, float cY2, float r2);
bool CircleToSquareCollision(float cX1, float cY1, float r, float cX2, float cY2, float hL, float a);
bool CircleToRectCollision(float cX1, float cY1, float r, float cX2, float cY2, float hL, float hW, float a);

bool SquareToSquareCollision(float cX1, float cY1, float hL1, float a1, float cX2, float cY2, float hL2, float a2);
bool SquareToRectCollision(float cX1, float cY1, float hL1, float a1, float cX2, float cY2, float hL2, float hW, float a2);

bool RectToRectCollision(float cX1, float cY1, float hL1, float hW1, float a1, float cX2, float cY2, float hL2, float hW2, float a2);

// First Optimised algorithm.
bool LineToLineCollisionOptimised1(float sX1, float sY1, float eX1, float eY1, float sX2, float sY2, float eX2, float eY2);
bool LineToCircleCollisionOptimised1(float sX, float sY, float eX, float eY, float cX, float cY, float r);
bool LineToSquareCollisionOptimised1(float sX, float sY, float eX, float eY, float cX, float cY, float hL, float a);
bool LineToRectCollisionOptimised1(float sX, float sY, float eX, float eY, float cX, float cY, float hL, float hW, float a);

bool CircleToCircleCollisionOptimised1(float cX1, float cY1, float r1, float cX2, float cY2, float r2);
bool CircleToSquareCollisionOptimised1(float cX1, float cY1, float r, float cX2, float cY2, float hL, float a);
bool CircleToRectCollisionOptimised1(float cX1, float cY1, float r, float cX2, float cY2, float hL, float hW, float a);

bool SquareToSquareCollisionOptimised1(float cX1, float cY1, float hL1, float a1, float cX2, float cY2, float hL2, float a2);
bool SquareToRectCollisionOptimised1(float cX1, float cY1, float hL1, float a1, float cX2, float cY2, float hL2, float hW, float a2);

bool RectToRectCollisionOptimised1(float cX1, float cY1, float hL1, float hW1, float a1, float cX2, float cY2, float hL2, float hW2, float a2);

// Second Optimised algorithm.
bool LineToLineCollisionOptimised2(float sX1, float sY1, float eX1, float eY1, float sX2, float sY2, float eX2, float eY2);
bool LineToCircleCollisionOptimised2(float sX, float sY, float eX, float eY, float cX, float cY, float r);
bool LineToSquareCollisionOptimised2(float sX, float sY, float eX, float eY, float cX, float cY, float hL, float a);
bool LineToRectCollisionOptimised2(float sX, float sY, float eX, float eY, float cX, float cY, float hL, float hW, float a);

bool CircleToCircleCollisionOptimised2(float cX1, float cY1, float r1, float cX2, float cY2, float r2);
bool CircleToSquareCollisionOptimised2(float cX1, float cY1, float r, float cX2, float cY2, float hL, float a);
bool CircleToRectCollisionOptimised2(float cX1, float cY1, float r, float cX2, float cY2, float hL, float hW, float a);

bool SquareToSquareCollisionOptimised2(float cX1, float cY1, float hL1, float a1, float cX2, float cY2, float hL2, float a2);
bool SquareToRectCollisionOptimised2(float cX1, float cY1, float hL1, float a1, float cX2, float cY2, float hL2, float hW, float a2);

bool RectToRectCollisionOptimised2(float cX1, float cY1, float hL1, float hW1, float a1, float cX2, float cY2, float hL2, float hW2, float a2);