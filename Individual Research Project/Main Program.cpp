// Michael Mohan 40020843
// 2D Collision Detection
#pragma region HEADER DECLARATIONS
#include "StdAfx.h"
#include "Main Program.h"
#pragma endregion

// The main program.
int main(int argc, char* argv[])
{
	#pragma region INPUT
	// Input variables to determine which 
	// variations of the code to test.
	int algorithm = 1;
	int dataAlignment = 1;
	int padding = 0;
	int inheritance = 1;

	// Input variables to capture shape properties
	// from the console if the user chooses to specify them.
	int lineAmount = 1000;
	int circleAmount = 1000;
	int squareAmount = 1000;
	int rectAmount = 1000;
	float lineSize = 1;
	float circleSize = 1;
	float squareSize = 1;
	float rectSize = 1;
	float range = 50;

	// Other input variables.
	int choice, test;
	int average = 20;

	// If chosen, this option will cause the program to run 
	// three times for each option and take the average. 
	cout << "Would you like to collect test results?";
	cout << "\nPlease enter 1 for yes or 2 for no: ";
	cin >> test;
	Validate(test, 2);

	if (test != 1)
	{
		// Get input from the user to find out 
		// which variations of the code to run.
		cout << "For the following, please enter between 1 and 3";
		cout << "\nWhat type of algorithm do you want to run? ";
		cin >> algorithm;
		Validate(algorithm, 3);

		cout << "What type of inheritance do you want to use? ";
		cin >> inheritance;
		Validate(inheritance, 3);

		cout << "What variation of data alignment do you want to use? Enter 1 or 2: ";
		cin >> dataAlignment;
		Validate(dataAlignment, 2);
		//if (dataAlignment != 2)
		//{
		//	cout << "How much padding would you like to use? ";
		//	cin >> padding;
		//	Validate(padding, 64);
		//}		
	}

	cout << "Would you like to declare shape properties?";
	cout << "\nPlease enter 1 for yes or 2 for no: ";
	cin >> choice;
	Validate(choice, 2);
	if (choice != 2)
	{
		#undef max
		cout << "Please specify the amount of the following shapes respectively:";
		cout << "\nline, circle, square, rectangle: ";
		cin >> lineAmount;
		Validate(lineAmount, 2147483647);
		cin >> circleAmount;
		Validate(circleAmount, 2147483647);
		cin >> squareAmount;
		Validate(squareAmount, 2147483647);
		cin >> rectAmount;
		Validate(rectAmount, 2147483647);
		cout << "Please specify sizes for each shape: ";
		cin >> lineSize;
		Validate((int)lineSize, 2147483647);
		cin >> circleSize;
		Validate((int)circleSize, 2147483647);
		cin >> squareSize;
		Validate((int)squareSize, 2147483647);
		cin >> rectSize;
		Validate((int)rectSize, 2147483647);
		cout << "Finally, please specify the area width/height to draw the shapes: ";
		cin >> range;
		Validate((int)range, 2147483647);
	}
	#pragma endregion

	#pragma region INITIALISE VARIABLES
	// Defines the amount of shapes.
	#define LINEAMOUNT lineAmount
	#define CIRCLEAMOUNT circleAmount
	#define SQUAREAMOUNT squareAmount
	#define RECTAMOUNT rectAmount

	// Defines the radius of each shape.
	#define LINESIZE lineSize
	#define CIRCLESIZE circleSize
	#define SQUARESIZE squareSize
	#define RECTSIZE rectSize

	// Defines the range for the minimum and maximum bounds
	// of the area in which the shapes can be drawn. This
	// value will be used for both the x and y planes.
	#define RANGE range

	// Value used to apply data alignment to variables.
	// If data alignment is not activated then this will
	// not be set, resulting in no padding. If it is, 
	// then the padding will be set to the value that has
	// been specified on input.
	//#define ALIGN __declspec(align(1))

	// Counters declared for 
	// each type of collision.
	//ALIGN 
	int L2L, L2C, L2S, L2R, C2C, C2S, C2R, S2S, S2R, R2R;

	// Used to output average times to a text file.
	double averageTime = 0;

	// Declares a list to hold all
	// the objects of each shape.
	// "inheritance" input determines which 
	// type of shape objects are to be created
	// and which type of vector arrays are used
	// to hold all the objects of each shape.
	//ALIGN
	vector<Line> LineList;
	vector<Circle> CircleList;
	vector<Square> SquareList;
	vector<Rect> RectList;

	vector<LineSI> LineListSI;
	vector<CircleSI> CircleListSI;
	vector<SquareSI> SquareListSI;
	vector<RectSI> RectListSI;

	vector<LineDI> LineListDI;
	vector<CircleDI> CircleListDI;
	vector<SquareDI> SquareListDI;
	vector<RectDI> RectListDI;

	// Lists created to implement an
	// alternate form of data alignment.
	vector<float> LineStartX;
	vector<float> LineStartY;
	vector<float> LineEndX;
	vector<float> LineEndY;

	vector<float> CircleCentreX;
	vector<float> CircleCentreY;
	vector<float> CircleRadius;

	vector<float> SquareCentreX;
	vector<float> SquareCentreY;
	vector<float> SquareHalfLength;
	vector<float> SquareAngle;

	vector<float> RectCentreX;
	vector<float> RectCentreY;
	vector<float> RectHalfLength;
	vector<float> RectHalfWidth;
	vector<float> RectAngle;
	#pragma endregion

	// Create results files to write to if needed.
	//FILE *f = CreateTextFile("Results.txt");
	FILE *f = CreateTextFile("Results.csv");
	if (test == 1)
		fprintf(f, "Method, Test 1, Test 2, Test 3, Test 4, Test 5, Test 6, Test 7, Test 8, Test 9, Test 10, Test 11, Test 12, Test 13, Test 14, Test 15, Test 16, Test 17, Test 18, Test 19, Test 20, Average\n");


	// If testing is activated, the program will run for each setting.
	// If not, the loops will only run once for the selected settings.
	// Inner loop is set to 6 instead of 2 to run each method 3 times for an average.
	int a, b, c;
	if (test == 1)
	{
		a = 3;
		b = 3;
		c = 2*average;
	}
	else
	{
		a = 1;
		b = 1;
		c = 1;
	}

	// Loops to handle running each test case one after the other.
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			for (int k = 1; k <= c; k++)
			{
				// Seed used to allow random values to 
				// change each time the program is run.
				//srand(int(time(NULL)));	

				// Counters initialised.
				L2L = 0;
				L2C = 0;
				L2S = 0;
				L2R = 0;
				C2C = 0;
				C2S = 0;
				C2R = 0;
				S2S = 0;
				S2R = 0;
				R2R = 0;

				// Logging output for testing.
				if ((test == 1) && ((k == 1) || (k == (average + 1))))
					//fprintf(f, "Settings %d, %d, %d: ", algorithm, inheritance, dataAlignment);
					fprintf(f, "%d.%d.%d,", algorithm, inheritance, dataAlignment);

				#pragma region DATA ALIGNMENT
				// If "dataAlignment" is set to optimised, each shape properties 
				// is added into a list before being added to the shapes, in
				// order to align the data and make it easier to access.
				if (dataAlignment == 1)
				{
					for (int i = 0; i < LINEAMOUNT; i++)
					{
						// Used to normalise the size of the lines drawn.
						float lineStartX = Random(-RANGE, RANGE);
						float lineStartY = Random(-RANGE, RANGE);
						LineStartX.push_back(lineStartX);
						LineStartY.push_back(lineStartY);
						LineEndX.push_back(Random(lineStartX - LINESIZE, lineStartX + LINESIZE));
						LineEndY.push_back(Random(lineStartY - LINESIZE, lineStartY + LINESIZE));
					}

					for (int i = 0; i < CIRCLEAMOUNT; i++)
					{
						CircleCentreX.push_back(Random(-RANGE, RANGE));
						CircleCentreY.push_back(Random(-RANGE, RANGE));
						CircleRadius.push_back(Random(0, float(CIRCLESIZE)));
					}

					for (int i = 0; i < SQUAREAMOUNT; i++)
					{
						SquareCentreX.push_back(Random(-RANGE, RANGE));
						SquareCentreY.push_back(Random(-RANGE, RANGE));
						SquareHalfLength.push_back(Random(0, float(SQUARESIZE)));
						SquareAngle.push_back(float(rand() % 360));
					}

					for (int i = 0; i < RECTAMOUNT; i++)
					{
						RectCentreX.push_back(Random(-RANGE, RANGE));
						RectCentreY.push_back(Random(-RANGE, RANGE));
						RectHalfLength.push_back(Random(0, float(RECTSIZE)));
						RectHalfWidth.push_back(Random(0, float(RECTSIZE)));
						RectAngle.push_back(float(rand() % 360));
					}
				}
				#pragma endregion

				#pragma region CREATE SHAPES
				if (dataAlignment == 1)
				{
					if (inheritance == 1)
					{
						for (int i = 0; i < LINEAMOUNT; i++)
						{
							Line Linei(LineStartX[i], LineStartY[i], LineEndX[i], LineEndY[i]);
							LineList.push_back(Linei);
						}

						for (int i = 0; i < CIRCLEAMOUNT; i++)
						{
							Circle Circlei(CircleCentreX[i], CircleCentreY[i], CircleRadius[i]);
							CircleList.push_back(Circlei);
						}

						for (int i = 0; i < SQUAREAMOUNT; i++)
						{
							Square Squarei(SquareCentreX[i], SquareCentreY[i], SquareHalfLength[i], SquareAngle[i]);
							SquareList.push_back(Squarei);
						}

						for (int i = 0; i < RECTAMOUNT; i++)
						{
							Rect Recti(RectCentreX[i], RectCentreY[i], RectHalfLength[i], RectHalfWidth[i], RectAngle[i]);
							RectList.push_back(Recti);
						}
					}
					else if (inheritance == 2)
					{
						for (int i = 0; i < LINEAMOUNT; i++)
						{
							LineSI Linei(LineStartX[i], LineStartY[i], LineEndX[i], LineEndY[i]);
							LineListSI.push_back(Linei);
						}

						for (int i = 0; i < CIRCLEAMOUNT; i++)
						{
							CircleSI Circlei(CircleCentreX[i], CircleCentreY[i], CircleRadius[i]);
							CircleListSI.push_back(Circlei);
						}

						for (int i = 0; i < SQUAREAMOUNT; i++)
						{
							SquareSI Squarei(SquareCentreX[i], SquareCentreY[i], SquareHalfLength[i], SquareAngle[i]);
							SquareListSI.push_back(Squarei);
						}

						for (int i = 0; i < RECTAMOUNT; i++)
						{
							RectSI Recti(RectCentreX[i], RectCentreY[i], RectHalfLength[i], RectHalfWidth[i], RectAngle[i]);
							RectListSI.push_back(Recti);
						}
					}
					else if (inheritance == 3)
					{
						for (int i = 0; i < LINEAMOUNT; i++)
						{
							LineDI Linei(LineStartX[i], LineStartY[i], LineEndX[i], LineEndY[i]);
							LineListDI.push_back(Linei);
						}

						for (int i = 0; i < CIRCLEAMOUNT; i++)
						{
							CircleDI Circlei(CircleCentreX[i], CircleCentreY[i], CircleRadius[i]);
							CircleListDI.push_back(Circlei);
						}

						for (int i = 0; i < SQUAREAMOUNT; i++)
						{
							SquareDI Squarei(SquareCentreX[i], SquareCentreY[i], SquareHalfLength[i], SquareAngle[i]);
							SquareListDI.push_back(Squarei);
						}

						for (int i = 0; i < RECTAMOUNT; i++)
						{
							RectDI Recti(RectCentreX[i], RectCentreY[i], RectHalfLength[i], RectHalfWidth[i], RectAngle[i]);
							RectListDI.push_back(Recti);
						}
					}
				}
				else
				{
					if (inheritance == 1)
					{
						for (int i = 0; i < Max(LINEAMOUNT, CIRCLEAMOUNT, SQUAREAMOUNT, RECTAMOUNT); i++)
						{
							if (i < LINEAMOUNT)
							{
								// Used to normalise the size of the lines drawn.
								float lineStartX = Random(-RANGE, RANGE);
								float lineStartY = Random(-RANGE, RANGE);
								Line Linei(lineStartX, lineStartY, Random(lineStartX - LINESIZE, lineStartX + LINESIZE),
									Random(lineStartY - LINESIZE, lineStartY + LINESIZE));
								LineList.push_back(Linei);
							}

							if (i < CIRCLEAMOUNT)
							{
								Circle Circlei(Random(-RANGE, RANGE), Random(-RANGE, RANGE), Random(0, float(CIRCLESIZE)));
								CircleList.push_back(Circlei);
							}

							if (i < SQUAREAMOUNT)
							{
								Square Squarei(Random(-RANGE, RANGE), Random(-RANGE, RANGE), Random(0, float(SQUARESIZE)), float(rand() % 360));
								SquareList.push_back(Squarei);
							}

							if (i < RECTAMOUNT)
							{
								Rect Recti(Random(-RANGE, RANGE), Random(-RANGE, RANGE), Random(0, float(RECTSIZE)),
									Random(0, float(RECTSIZE)), float(rand() % 360));
								RectList.push_back(Recti);
							}
						}
					}
					else if (inheritance == 2)
					{
						for (int i = 0; i < Max(LINEAMOUNT, CIRCLEAMOUNT, SQUAREAMOUNT, RECTAMOUNT); i++)
						{
							if (i < LINEAMOUNT)
							{
								// Used to normalise the size of the lines drawn.
								float lineStartX = Random(-RANGE, RANGE);
								float lineStartY = Random(-RANGE, RANGE);
								LineSI Linei(lineStartX, lineStartY, Random(lineStartX - LINESIZE, lineStartX + LINESIZE),
									Random(lineStartY - LINESIZE, lineStartY + LINESIZE));
								LineListSI.push_back(Linei);
							}

							if (i < CIRCLEAMOUNT)
							{
								CircleSI Circlei(Random(-RANGE, RANGE), Random(-RANGE, RANGE), Random(0, float(CIRCLESIZE)));
								CircleListSI.push_back(Circlei);
							}

							if (i < SQUAREAMOUNT)
							{
								SquareSI Squarei(Random(-RANGE, RANGE), Random(-RANGE, RANGE), Random(0, float(SQUARESIZE)), float(rand() % 360));
								SquareListSI.push_back(Squarei);
							}

							if (i < RECTAMOUNT)
							{
								RectSI Recti(Random(-RANGE, RANGE), Random(-RANGE, RANGE), Random(0, float(RECTSIZE)),
									Random(0, float(RECTSIZE)), float(rand() % 360));
								RectListSI.push_back(Recti);
							}
						}
					}
					else if (inheritance == 3)
					{
						for (int i = 0; i < Max(LINEAMOUNT, CIRCLEAMOUNT, SQUAREAMOUNT, RECTAMOUNT); i++)
						{
							if (i < LINEAMOUNT)
							{
								// Used to normalise the size of the lines drawn.
								float lineStartX = Random(-RANGE, RANGE);
								float lineStartY = Random(-RANGE, RANGE);
								LineDI Linei(lineStartX, lineStartY, Random(lineStartX - LINESIZE, lineStartX + LINESIZE),
									Random(lineStartY - LINESIZE, lineStartY + LINESIZE));
								LineListDI.push_back(Linei);
							}

							if (i < CIRCLEAMOUNT)
							{
								CircleDI Circlei(Random(-RANGE, RANGE), Random(-RANGE, RANGE), Random(0, float(CIRCLESIZE)));
								CircleListDI.push_back(Circlei);
							}

							if (i < SQUAREAMOUNT)
							{
								SquareDI Squarei(Random(-RANGE, RANGE), Random(-RANGE, RANGE), Random(0, float(SQUARESIZE)), float(rand() % 360));
								SquareListDI.push_back(Squarei);
							}

							if (i < RECTAMOUNT)
							{
								RectDI Recti(Random(-RANGE, RANGE), Random(-RANGE, RANGE), Random(0, float(RECTSIZE)),
									Random(0, float(RECTSIZE)), float(rand() % 360));
								RectListDI.push_back(Recti);
							}
						}
					}
				}
				#pragma endregion

				if (test == 2)
					cout << "\nShapes initialised. Processing...\n\n";

				// Timer
				clock_t start, end;
				start = clock();
				StartCounter();

				#pragma region COLLISION DETECTION
				if (algorithm == 1)
				{
					if (inheritance == 1)
					{
						// Draws the lines onto the screen and works out
						// whether they collide with each other.
						for (int i = 0; i < LINEAMOUNT; i++)
						{
							for (int j = 0; j < LINEAMOUNT; j++)
							{
								// If the shape is not checking for collision with itself
								// or against a shape that has previously checked against it.
								if (i < j)
								{
									if (LineToLineCollisionOptimised1(LineList[i].GetStartX(), LineList[i].GetStartY(), LineList[i].GetEndX(), LineList[i].GetEndY(),
										LineList[j].GetStartX(), LineList[j].GetStartY(), LineList[j].GetEndX(), LineList[j].GetEndY()))
										L2L++;
								}
							}

							for (int j = 0; j < CIRCLEAMOUNT; j++)
							{
								if (LineToCircleCollisionOptimised1(LineList[i].GetStartX(), LineList[i].GetStartY(), LineList[i].GetEndX(), LineList[i].GetEndY(),
									CircleList[j].GetCentreX(), CircleList[j].GetCentreY(), CircleList[j].GetRadius()))
									L2C++;
							}

							for (int j = 0; j < SQUAREAMOUNT; j++)
							{
								if (LineToSquareCollisionOptimised1(LineList[i].GetStartX(), LineList[i].GetStartY(), LineList[i].GetEndX(), LineList[i].GetEndY(),
									SquareList[j].GetCentreX(), SquareList[j].GetCentreY(), SquareList[j].GetHalfLength(), SquareList[j].GetAngle()))
									L2S++;
							}

							for (int j = 0; j < RECTAMOUNT; j++)
							{
								if (LineToRectCollisionOptimised1(LineList[i].GetStartX(), LineList[i].GetStartY(), LineList[i].GetEndX(), LineList[i].GetEndY(),
									RectList[j].GetCentreX(), RectList[j].GetCentreY(), RectList[j].GetHalfLength(), RectList[j].GetHalfWidth(), RectList[j].GetAngle()))
									L2R++;
							}
						}

						// Draws the circles onto the screen and works out
						// whether they collide with any other shape,
						// including each other.
						for (int i = 0; i < CIRCLEAMOUNT; i++)
						{
							for (int j = 0; j < CIRCLEAMOUNT; j++)
							{
								// If the shape is not checking for collision with itself
								// or against a shape that has previously checked against it.
								if (i < j)
								{
									if (CircleToCircleCollisionOptimised1(CircleList[i].GetCentreX(), CircleList[i].GetCentreY(), CircleList[i].GetRadius(),
										CircleList[j].GetCentreX(), CircleList[j].GetCentreY(), CircleList[j].GetRadius()))
										C2C++;
								}
							}

							for (int j = 0; j < SQUAREAMOUNT; j++)
							{
								if (CircleToSquareCollisionOptimised1(CircleList[i].GetCentreX(), CircleList[i].GetCentreY(), CircleList[i].GetRadius(),
									SquareList[j].GetCentreX(), SquareList[j].GetCentreY(), SquareList[j].GetHalfLength(), SquareList[j].GetAngle()))
									C2S++;
							}

							for (int j = 0; j < RECTAMOUNT; j++)
							{
								if (CircleToRectCollisionOptimised1(CircleList[i].GetCentreX(), CircleList[i].GetCentreY(), CircleList[i].GetRadius(),
									RectList[j].GetCentreX(), RectList[j].GetCentreY(), RectList[j].GetHalfLength(), RectList[j].GetHalfWidth(), RectList[j].GetAngle()))
									C2R++;
							}
						}

						// Draws the squares onto the screen and works out
						// whether they collide with any other shape,
						// including each other.
						for (int i = 0; i < SQUAREAMOUNT; i++)
						{
							for (int j = 0; j < SQUAREAMOUNT; j++)
							{
								// If the shape is not checking for collision with itself
								// or against a shape that has previously checked against it.
								if (i < j)
								{
									if (SquareToSquareCollisionOptimised1(SquareList[i].GetCentreX(), SquareList[i].GetCentreY(), SquareList[i].GetHalfLength(), SquareList[i].GetAngle(),
										SquareList[j].GetCentreX(), SquareList[j].GetCentreY(), SquareList[j].GetHalfLength(), SquareList[j].GetAngle()))
										S2S++;
								}
							}

							for (int j = 0; j < RECTAMOUNT; j++)
							{
								if (SquareToRectCollisionOptimised1(SquareList[i].GetCentreX(), SquareList[i].GetCentreY(), SquareList[i].GetHalfLength(), SquareList[i].GetAngle(),
									RectList[j].GetCentreX(), RectList[j].GetCentreY(), RectList[j].GetHalfLength(), RectList[j].GetHalfWidth(), RectList[j].GetAngle()))
									S2R++;
							}
						}

						// Draws the rects onto the screen and works out
						// whether they collide with any other shape,
						// including each other.
						for (int i = 0; i < RECTAMOUNT; i++)
						{
							for (int j = 0; j < RECTAMOUNT; j++)
							{
								// If the shape is not checking for collision with itself
								// or against a shape that has previously checked against it.
								if (i < j)
								{
									if (RectToRectCollisionOptimised1(RectList[i].GetCentreX(), RectList[i].GetCentreY(), RectList[i].GetHalfLength(), RectList[i].GetHalfWidth(), RectList[i].GetAngle(),
										RectList[j].GetCentreX(), RectList[j].GetCentreY(), RectList[j].GetHalfLength(), RectList[j].GetHalfWidth(), RectList[j].GetAngle()))
										R2R++;
								}
							}
						}
					}
					else if (inheritance == 2)
					{
						// Draws the lines onto the screen and works out
						// whether they collide with each other.
						for (int i = 0; i < LINEAMOUNT; i++)
						{
							for (int j = 0; j < LINEAMOUNT; j++)
							{
								// If the shape is not checking for collision with itself
								// or against a shape that has previously checked against it.
								if (i < j)
								{
									if (LineToLineCollisionOptimised1(LineListSI[i].GetStartX(), LineListSI[i].GetStartY(), LineListSI[i].GetEndX(), LineListSI[i].GetEndY(),
										LineListSI[j].GetStartX(), LineListSI[j].GetStartY(), LineListSI[j].GetEndX(), LineListSI[j].GetEndY()))
										L2L++;
								}
							}

							for (int j = 0; j < CIRCLEAMOUNT; j++)
							{
								if (LineToCircleCollisionOptimised1(LineListSI[i].GetStartX(), LineListSI[i].GetStartY(), LineListSI[i].GetEndX(), LineListSI[i].GetEndY(),
									CircleListSI[j].GetCentreX(), CircleListSI[j].GetCentreY(), CircleListSI[j].GetRadius()))
									L2C++;
							}

							for (int j = 0; j < SQUAREAMOUNT; j++)
							{
								if (LineToSquareCollisionOptimised1(LineListSI[i].GetStartX(), LineListSI[i].GetStartY(), LineListSI[i].GetEndX(), LineListSI[i].GetEndY(),
									SquareListSI[j].GetCentreX(), SquareListSI[j].GetCentreY(), SquareListSI[j].GetHalfLength(), SquareListSI[j].GetAngle()))
									L2S++;
							}

							for (int j = 0; j < RECTAMOUNT; j++)
							{
								if (LineToRectCollisionOptimised1(LineListSI[i].GetStartX(), LineListSI[i].GetStartY(), LineListSI[i].GetEndX(), LineListSI[i].GetEndY(),
									RectListSI[j].GetCentreX(), RectListSI[j].GetCentreY(), RectListSI[j].GetHalfLength(), RectListSI[j].GetHalfWidth(), RectListSI[j].GetAngle()))
									L2R++;
							}
						}

						// Draws the circles onto the screen and works out
						// whether they collide with any other shape,
						// including each other.
						for (int i = 0; i < CIRCLEAMOUNT; i++)
						{
							for (int j = 0; j < CIRCLEAMOUNT; j++)
							{
								// If the shape is not checking for collision with itself
								// or against a shape that has previously checked against it.
								if (i < j)
								{
									if (CircleToCircleCollisionOptimised1(CircleListSI[i].GetCentreX(), CircleListSI[i].GetCentreY(), CircleListSI[i].GetRadius(),
										CircleListSI[j].GetCentreX(), CircleListSI[j].GetCentreY(), CircleListSI[j].GetRadius()))
										C2C++;
								}
							}

							for (int j = 0; j < SQUAREAMOUNT; j++)
							{
								if (CircleToSquareCollisionOptimised1(CircleListSI[i].GetCentreX(), CircleListSI[i].GetCentreY(), CircleListSI[i].GetRadius(),
									SquareListSI[j].GetCentreX(), SquareListSI[j].GetCentreY(), SquareListSI[j].GetHalfLength(), SquareListSI[j].GetAngle()))
									C2S++;
							}

							for (int j = 0; j < RECTAMOUNT; j++)
							{
								if (CircleToRectCollisionOptimised1(CircleListSI[i].GetCentreX(), CircleListSI[i].GetCentreY(), CircleListSI[i].GetRadius(),
									RectListSI[j].GetCentreX(), RectListSI[j].GetCentreY(), RectListSI[j].GetHalfLength(), RectListSI[j].GetHalfWidth(), RectListSI[j].GetAngle()))
									C2R++;
							}
						}

						// Draws the squares onto the screen and works out
						// whether they collide with any other shape,
						// including each other.
						for (int i = 0; i < SQUAREAMOUNT; i++)
						{
							for (int j = 0; j < SQUAREAMOUNT; j++)
							{
								// If the shape is not checking for collision with itself
								// or against a shape that has previously checked against it.
								if (i < j)
								{
									if (SquareToSquareCollisionOptimised1(SquareListSI[i].GetCentreX(), SquareListSI[i].GetCentreY(), SquareListSI[i].GetHalfLength(), SquareListSI[i].GetAngle(),
										SquareListSI[j].GetCentreX(), SquareListSI[j].GetCentreY(), SquareListSI[j].GetHalfLength(), SquareListSI[j].GetAngle()))
										S2S++;
								}
							}

							for (int j = 0; j < RECTAMOUNT; j++)
							{
								if (SquareToRectCollisionOptimised1(SquareListSI[i].GetCentreX(), SquareListSI[i].GetCentreY(), SquareListSI[i].GetHalfLength(), SquareListSI[i].GetAngle(),
									RectListSI[j].GetCentreX(), RectListSI[j].GetCentreY(), RectListSI[j].GetHalfLength(), RectListSI[j].GetHalfWidth(), RectListSI[j].GetAngle()))
									S2R++;
							}
						}

						// Draws the rects onto the screen and works out
						// whether they collide with any other shape,
						// including each other.
						for (int i = 0; i < RECTAMOUNT; i++)
						{
							for (int j = 0; j < RECTAMOUNT; j++)
							{
								// If the shape is not checking for collision with itself
								// or against a shape that has previously checked against it.
								if (i < j)
								{
									if (RectToRectCollisionOptimised1(RectListSI[i].GetCentreX(), RectListSI[i].GetCentreY(), RectListSI[i].GetHalfLength(), RectListSI[i].GetHalfWidth(), RectListSI[i].GetAngle(),
										RectListSI[j].GetCentreX(), RectListSI[j].GetCentreY(), RectListSI[j].GetHalfLength(), RectListSI[j].GetHalfWidth(), RectListSI[j].GetAngle()))
										R2R++;
								}
							}
						}
					}
					else if (inheritance == 3)
					{
						// Draws the lines onto the screen and works out
						// whether they collide with each other.
						for (int i = 0; i < LINEAMOUNT; i++)
						{
							for (int j = 0; j < LINEAMOUNT; j++)
							{
								// If the shape is not checking for collision with itself
								// or against a shape that has previously checked against it.
								if (i < j)
								{
									ShapeDI &Linedi = LineListDI[i];
									ShapeDI &Linedj = LineListDI[j];
									if (LineToLineCollisionOptimised1(Linedi.GetStartX(), Linedi.GetStartY(), Linedi.GetEndX(), Linedi.GetEndY(),
										Linedj.GetStartX(), Linedj.GetStartY(), Linedj.GetEndX(), Linedj.GetEndY()))
										L2L++;
								}
							}

							for (int j = 0; j < CIRCLEAMOUNT; j++)
							{
								ShapeDI &Linedi = LineListDI[i];
								ShapeDI &Circledj = CircleListDI[j];
								if (LineToCircleCollisionOptimised1(Linedi.GetStartX(), Linedi.GetStartY(), Linedi.GetEndX(), Linedi.GetEndY(),
									Circledj.GetCentreX(), Circledj.GetCentreY(), Circledj.GetRadius()))
									L2C++;
							}

							for (int j = 0; j < SQUAREAMOUNT; j++)
							{
								ShapeDI &Linedi = LineListDI[i];
								ShapeDI &Squaredj = SquareListDI[j];
								if (LineToSquareCollisionOptimised1(Linedi.GetStartX(), Linedi.GetStartY(), Linedi.GetEndX(), Linedi.GetEndY(),
									Squaredj.GetCentreX(), Squaredj.GetCentreY(), Squaredj.GetHalfLength(), Squaredj.GetAngle()))
									L2S++;
							}

							for (int j = 0; j < RECTAMOUNT; j++)
							{
								ShapeDI &Linedi = LineListDI[i];
								ShapeDI &Rectdj = RectListDI[j];
								if (LineToRectCollisionOptimised1(Linedi.GetStartX(), Linedi.GetStartY(), Linedi.GetEndX(), Linedi.GetEndY(),
									Rectdj.GetCentreX(), Rectdj.GetCentreY(), Rectdj.GetHalfLength(), Rectdj.GetHalfWidth(), Rectdj.GetAngle()))
									L2R++;
							}
						}

						// Draws the circles onto the screen and works out
						// whether they collide with any other shape,
						// including each other.
						for (int i = 0; i < CIRCLEAMOUNT; i++)
						{
							for (int j = 0; j < CIRCLEAMOUNT; j++)
							{
								// If the shape is not checking for collision with itself
								// or against a shape that has previously checked against it.
								if (i < j)
								{
									ShapeDI &Circledi = CircleListDI[i];
									ShapeDI &Circledj = CircleListDI[j];
									if (CircleToCircleCollisionOptimised1(Circledi.GetCentreX(), Circledi.GetCentreY(), Circledi.GetRadius(),
										Circledj.GetCentreX(), Circledj.GetCentreY(), Circledj.GetRadius()))
										C2C++;
								}
							}

							for (int j = 0; j < SQUAREAMOUNT; j++)
							{
								ShapeDI &Circledi = CircleListDI[i];
								ShapeDI &Squaredj = SquareListDI[j];
								if (CircleToSquareCollisionOptimised1(Circledi.GetCentreX(), Circledi.GetCentreY(), Circledi.GetRadius(),
									Squaredj.GetCentreX(), Squaredj.GetCentreY(), Squaredj.GetHalfLength(), Squaredj.GetAngle()))
									C2S++;
							}

							for (int j = 0; j < RECTAMOUNT; j++)
							{
								ShapeDI &Circledi = CircleListDI[i];
								ShapeDI &Rectdj = RectListDI[j];
								if (CircleToRectCollisionOptimised1(Circledi.GetCentreX(), Circledi.GetCentreY(), Circledi.GetRadius(),
									Rectdj.GetCentreX(), Rectdj.GetCentreY(), Rectdj.GetHalfLength(), Rectdj.GetHalfWidth(), Rectdj.GetAngle()))
									C2R++;
							}
						}

						// Draws the squares onto the screen and works out
						// whether they collide with any other shape,
						// including each other.
						for (int i = 0; i < SQUAREAMOUNT; i++)
						{
							for (int j = 0; j < SQUAREAMOUNT; j++)
							{
								// If the shape is not checking for collision with itself
								// or against a shape that has previously checked against it.
								if (i < j)
								{
									ShapeDI &Squaredi = SquareListDI[i];
									ShapeDI &Squaredj = SquareListDI[j];
									if (SquareToSquareCollisionOptimised1(Squaredi.GetCentreX(), Squaredi.GetCentreY(), Squaredi.GetHalfLength(), Squaredi.GetAngle(),
										Squaredj.GetCentreX(), Squaredj.GetCentreY(), Squaredj.GetHalfLength(), Squaredj.GetAngle()))
										S2S++;
								}
							}

							for (int j = 0; j < RECTAMOUNT; j++)
							{
								ShapeDI &Squaredi = SquareListDI[i];
								ShapeDI &Rectdj = RectListDI[j];
								if (SquareToRectCollisionOptimised1(Squaredi.GetCentreX(), Squaredi.GetCentreY(), Squaredi.GetHalfLength(), Squaredi.GetAngle(),
									Rectdj.GetCentreX(), Rectdj.GetCentreY(), Rectdj.GetHalfLength(), Rectdj.GetHalfWidth(), Rectdj.GetAngle()))
									S2R++;
							}
						}

						// Draws the rects onto the screen and works out
						// whether they collide with any other shape,
						// including each other.
						for (int i = 0; i < RECTAMOUNT; i++)
						{
							for (int j = 0; j < RECTAMOUNT; j++)
							{
								// If the shape is not checking for collision with itself
								// or against a shape that has previously checked against it.
								if (i < j)
								{
									ShapeDI &Rectdi = RectListDI[i];
									ShapeDI &Rectdj = RectListDI[j];
									if (RectToRectCollisionOptimised1(Rectdi.GetCentreX(), Rectdi.GetCentreY(), Rectdi.GetHalfLength(), Rectdi.GetHalfWidth(), Rectdi.GetAngle(),
										Rectdj.GetCentreX(), Rectdj.GetCentreY(), Rectdj.GetHalfLength(), Rectdj.GetHalfWidth(), Rectdj.GetAngle()))
										R2R++;
								}
							}
						}
					}
				}
				else if (algorithm == 2)
				{
					if (inheritance == 1)
					{
						// Draws the lines onto the screen and works out
						// whether they collide with each other.
						for (int i = 0; i < LINEAMOUNT; i++)
						{
							for (int j = 0; j < LINEAMOUNT; j++)
							{
								// If the shape is not checking for collision with itself
								// or against a shape that has previously checked against it.
								if (i < j)
								{
									if (LineToLineCollisionOptimised2(LineList[i].GetStartX(), LineList[i].GetStartY(), LineList[i].GetEndX(), LineList[i].GetEndY(),
										LineList[j].GetStartX(), LineList[j].GetStartY(), LineList[j].GetEndX(), LineList[j].GetEndY()))
										L2L++;
								}
							}

							for (int j = 0; j < CIRCLEAMOUNT; j++)
							{
								if (LineToCircleCollisionOptimised2(LineList[i].GetStartX(), LineList[i].GetStartY(), LineList[i].GetEndX(), LineList[i].GetEndY(),
									CircleList[j].GetCentreX(), CircleList[j].GetCentreY(), CircleList[j].GetRadius()))
									L2C++;
							}

							for (int j = 0; j < SQUAREAMOUNT; j++)
							{
								if (LineToSquareCollisionOptimised2(LineList[i].GetStartX(), LineList[i].GetStartY(), LineList[i].GetEndX(), LineList[i].GetEndY(),
									SquareList[j].GetCentreX(), SquareList[j].GetCentreY(), SquareList[j].GetHalfLength(), SquareList[j].GetAngle()))
									L2S++;
							}

							for (int j = 0; j < RECTAMOUNT; j++)
							{
								if (LineToRectCollisionOptimised2(LineList[i].GetStartX(), LineList[i].GetStartY(), LineList[i].GetEndX(), LineList[i].GetEndY(),
									RectList[j].GetCentreX(), RectList[j].GetCentreY(), RectList[j].GetHalfLength(), RectList[j].GetHalfWidth(), RectList[j].GetAngle()))
									L2R++;
							}
						}

						// Draws the circles onto the screen and works out
						// whether they collide with any other shape,
						// including each other.
						for (int i = 0; i < CIRCLEAMOUNT; i++)
						{
							for (int j = 0; j < CIRCLEAMOUNT; j++)
							{
								// If the shape is not checking for collision with itself
								// or against a shape that has previously checked against it.
								if (i < j)
								{
									if (CircleToCircleCollisionOptimised2(CircleList[i].GetCentreX(), CircleList[i].GetCentreY(), CircleList[i].GetRadius(),
										CircleList[j].GetCentreX(), CircleList[j].GetCentreY(), CircleList[j].GetRadius()))
										C2C++;
								}
							}

							for (int j = 0; j < SQUAREAMOUNT; j++)
							{
								if (CircleToSquareCollisionOptimised2(CircleList[i].GetCentreX(), CircleList[i].GetCentreY(), CircleList[i].GetRadius(),
									SquareList[j].GetCentreX(), SquareList[j].GetCentreY(), SquareList[j].GetHalfLength(), SquareList[j].GetAngle()))
									C2S++;
							}

							for (int j = 0; j < RECTAMOUNT; j++)
							{
								if (CircleToRectCollisionOptimised2(CircleList[i].GetCentreX(), CircleList[i].GetCentreY(), CircleList[i].GetRadius(),
									RectList[j].GetCentreX(), RectList[j].GetCentreY(), RectList[j].GetHalfLength(), RectList[j].GetHalfWidth(), RectList[j].GetAngle()))
									C2R++;
							}
						}

						// Draws the squares onto the screen and works out
						// whether they collide with any other shape,
						// including each other.
						for (int i = 0; i < SQUAREAMOUNT; i++)
						{
							for (int j = 0; j < SQUAREAMOUNT; j++)
							{
								// If the shape is not checking for collision with itself
								// or against a shape that has previously checked against it.
								if (i < j)
								{
									if (SquareToSquareCollisionOptimised2(SquareList[i].GetCentreX(), SquareList[i].GetCentreY(), SquareList[i].GetHalfLength(), SquareList[i].GetAngle(),
										SquareList[j].GetCentreX(), SquareList[j].GetCentreY(), SquareList[j].GetHalfLength(), SquareList[j].GetAngle()))
										S2S++;
								}
							}

							for (int j = 0; j < RECTAMOUNT; j++)
							{
								if (SquareToRectCollisionOptimised2(SquareList[i].GetCentreX(), SquareList[i].GetCentreY(), SquareList[i].GetHalfLength(), SquareList[i].GetAngle(),
									RectList[j].GetCentreX(), RectList[j].GetCentreY(), RectList[j].GetHalfLength(), RectList[j].GetHalfWidth(), RectList[j].GetAngle()))
									S2R++;
							}
						}

						// Draws the rects onto the screen and works out
						// whether they collide with any other shape,
						// including each other.
						for (int i = 0; i < RECTAMOUNT; i++)
						{
							for (int j = 0; j < RECTAMOUNT; j++)
							{
								// If the shape is not checking for collision with itself
								// or against a shape that has previously checked against it.
								if (i < j)
								{
									if (RectToRectCollisionOptimised2(RectList[i].GetCentreX(), RectList[i].GetCentreY(), RectList[i].GetHalfLength(), RectList[i].GetHalfWidth(), RectList[i].GetAngle(),
										RectList[j].GetCentreX(), RectList[j].GetCentreY(), RectList[j].GetHalfLength(), RectList[j].GetHalfWidth(), RectList[j].GetAngle()))
										R2R++;
								}
							}
						}
					}
					else if (inheritance == 2)
					{
						// Draws the lines onto the screen and works out
						// whether they collide with each other.
						for (int i = 0; i < LINEAMOUNT; i++)
						{
							for (int j = 0; j < LINEAMOUNT; j++)
							{
								// If the shape is not checking for collision with itself
								// or against a shape that has previously checked against it.
								if (i < j)
								{
									if (LineToLineCollisionOptimised2(LineListSI[i].GetStartX(), LineListSI[i].GetStartY(), LineListSI[i].GetEndX(), LineListSI[i].GetEndY(),
										LineListSI[j].GetStartX(), LineListSI[j].GetStartY(), LineListSI[j].GetEndX(), LineListSI[j].GetEndY()))
										L2L++;
								}
							}

							for (int j = 0; j < CIRCLEAMOUNT; j++)
							{
								if (LineToCircleCollisionOptimised2(LineListSI[i].GetStartX(), LineListSI[i].GetStartY(), LineListSI[i].GetEndX(), LineListSI[i].GetEndY(),
									CircleListSI[j].GetCentreX(), CircleListSI[j].GetCentreY(), CircleListSI[j].GetRadius()))
									L2C++;
							}

							for (int j = 0; j < SQUAREAMOUNT; j++)
							{
								if (LineToSquareCollisionOptimised2(LineListSI[i].GetStartX(), LineListSI[i].GetStartY(), LineListSI[i].GetEndX(), LineListSI[i].GetEndY(),
									SquareListSI[j].GetCentreX(), SquareListSI[j].GetCentreY(), SquareListSI[j].GetHalfLength(), SquareListSI[j].GetAngle()))
									L2S++;
							}

							for (int j = 0; j < RECTAMOUNT; j++)
							{
								if (LineToRectCollisionOptimised2(LineListSI[i].GetStartX(), LineListSI[i].GetStartY(), LineListSI[i].GetEndX(), LineListSI[i].GetEndY(),
									RectListSI[j].GetCentreX(), RectListSI[j].GetCentreY(), RectListSI[j].GetHalfLength(), RectListSI[j].GetHalfWidth(), RectListSI[j].GetAngle()))
									L2R++;
							}
						}

						// Draws the circles onto the screen and works out
						// whether they collide with any other shape,
						// including each other.
						for (int i = 0; i < CIRCLEAMOUNT; i++)
						{
							for (int j = 0; j < CIRCLEAMOUNT; j++)
							{
								// If the shape is not checking for collision with itself
								// or against a shape that has previously checked against it.
								if (i < j)
								{
									if (CircleToCircleCollisionOptimised2(CircleListSI[i].GetCentreX(), CircleListSI[i].GetCentreY(), CircleListSI[i].GetRadius(),
										CircleListSI[j].GetCentreX(), CircleListSI[j].GetCentreY(), CircleListSI[j].GetRadius()))
										C2C++;
								}
							}

							for (int j = 0; j < SQUAREAMOUNT; j++)
							{
								if (CircleToSquareCollisionOptimised2(CircleListSI[i].GetCentreX(), CircleListSI[i].GetCentreY(), CircleListSI[i].GetRadius(),
									SquareListSI[j].GetCentreX(), SquareListSI[j].GetCentreY(), SquareListSI[j].GetHalfLength(), SquareListSI[j].GetAngle()))
									C2S++;
							}

							for (int j = 0; j < RECTAMOUNT; j++)
							{
								if (CircleToRectCollisionOptimised2(CircleListSI[i].GetCentreX(), CircleListSI[i].GetCentreY(), CircleListSI[i].GetRadius(),
									RectListSI[j].GetCentreX(), RectListSI[j].GetCentreY(), RectListSI[j].GetHalfLength(), RectListSI[j].GetHalfWidth(), RectListSI[j].GetAngle()))
									C2R++;
							}
						}

						// Draws the squares onto the screen and works out
						// whether they collide with any other shape,
						// including each other.
						for (int i = 0; i < SQUAREAMOUNT; i++)
						{
							for (int j = 0; j < SQUAREAMOUNT; j++)
							{
								// If the shape is not checking for collision with itself
								// or against a shape that has previously checked against it.
								if (i < j)
								{
									if (SquareToSquareCollisionOptimised2(SquareListSI[i].GetCentreX(), SquareListSI[i].GetCentreY(), SquareListSI[i].GetHalfLength(), SquareListSI[i].GetAngle(),
										SquareListSI[j].GetCentreX(), SquareListSI[j].GetCentreY(), SquareListSI[j].GetHalfLength(), SquareListSI[j].GetAngle()))
										S2S++;
								}
							}

							for (int j = 0; j < RECTAMOUNT; j++)
							{
								if (SquareToRectCollisionOptimised2(SquareListSI[i].GetCentreX(), SquareListSI[i].GetCentreY(), SquareListSI[i].GetHalfLength(), SquareListSI[i].GetAngle(),
									RectListSI[j].GetCentreX(), RectListSI[j].GetCentreY(), RectListSI[j].GetHalfLength(), RectListSI[j].GetHalfWidth(), RectListSI[j].GetAngle()))
									S2R++;
							}
						}

						// Draws the rects onto the screen and works out
						// whether they collide with any other shape,
						// including each other.
						for (int i = 0; i < RECTAMOUNT; i++)
						{
							for (int j = 0; j < RECTAMOUNT; j++)
							{
								// If the shape is not checking for collision with itself
								// or against a shape that has previously checked against it.
								if (i < j)
								{
									if (RectToRectCollisionOptimised2(RectListSI[i].GetCentreX(), RectListSI[i].GetCentreY(), RectListSI[i].GetHalfLength(), RectListSI[i].GetHalfWidth(), RectListSI[i].GetAngle(),
										RectListSI[j].GetCentreX(), RectListSI[j].GetCentreY(), RectListSI[j].GetHalfLength(), RectListSI[j].GetHalfWidth(), RectListSI[j].GetAngle()))
										R2R++;
								}
							}
						}
					}
					else if (inheritance == 3)
					{
						// Draws the lines onto the screen and works out
						// whether they collide with each other.
						for (int i = 0; i < LINEAMOUNT; i++)
						{
							for (int j = 0; j < LINEAMOUNT; j++)
							{
								// If the shape is not checking for collision with itself
								// or against a shape that has previously checked against it.
								if (i < j)
								{
									ShapeDI &Linedi = LineListDI[i];
									ShapeDI &Linedj = LineListDI[j];
									if (LineToLineCollisionOptimised2(Linedi.GetStartX(), Linedi.GetStartY(), Linedi.GetEndX(), Linedi.GetEndY(),
										Linedj.GetStartX(), Linedj.GetStartY(), Linedj.GetEndX(), Linedj.GetEndY()))
										L2L++;
								}
							}

							for (int j = 0; j < CIRCLEAMOUNT; j++)
							{
								ShapeDI &Linedi = LineListDI[i];
								ShapeDI &Circledj = CircleListDI[j];
								if (LineToCircleCollisionOptimised2(Linedi.GetStartX(), Linedi.GetStartY(), Linedi.GetEndX(), Linedi.GetEndY(),
									Circledj.GetCentreX(), Circledj.GetCentreY(), Circledj.GetRadius()))
									L2C++;
							}

							for (int j = 0; j < SQUAREAMOUNT; j++)
							{
								ShapeDI &Linedi = LineListDI[i];
								ShapeDI &Squaredj = SquareListDI[j];
								if (LineToSquareCollisionOptimised2(Linedi.GetStartX(), Linedi.GetStartY(), Linedi.GetEndX(), Linedi.GetEndY(),
									Squaredj.GetCentreX(), Squaredj.GetCentreY(), Squaredj.GetHalfLength(), Squaredj.GetAngle()))
									L2S++;
							}

							for (int j = 0; j < RECTAMOUNT; j++)
							{
								ShapeDI &Linedi = LineListDI[i];
								ShapeDI &Rectdj = RectListDI[j];
								if (LineToRectCollisionOptimised2(Linedi.GetStartX(), Linedi.GetStartY(), Linedi.GetEndX(), Linedi.GetEndY(),
									Rectdj.GetCentreX(), Rectdj.GetCentreY(), Rectdj.GetHalfLength(), Rectdj.GetHalfWidth(), Rectdj.GetAngle()))
									L2R++;
							}
						}

						// Draws the circles onto the screen and works out
						// whether they collide with any other shape,
						// including each other.
						for (int i = 0; i < CIRCLEAMOUNT; i++)
						{
							for (int j = 0; j < CIRCLEAMOUNT; j++)
							{
								// If the shape is not checking for collision with itself
								// or against a shape that has previously checked against it.
								if (i < j)
								{
									ShapeDI &Circledi = CircleListDI[i];
									ShapeDI &Circledj = CircleListDI[j];
									if (CircleToCircleCollisionOptimised2(Circledi.GetCentreX(), Circledi.GetCentreY(), Circledi.GetRadius(),
										Circledj.GetCentreX(), Circledj.GetCentreY(), Circledj.GetRadius()))
										C2C++;
								}
							}

							for (int j = 0; j < SQUAREAMOUNT; j++)
							{
								ShapeDI &Circledi = CircleListDI[i];
								ShapeDI &Squaredj = SquareListDI[j];
								if (CircleToSquareCollisionOptimised2(Circledi.GetCentreX(), Circledi.GetCentreY(), Circledi.GetRadius(),
									Squaredj.GetCentreX(), Squaredj.GetCentreY(), Squaredj.GetHalfLength(), Squaredj.GetAngle()))
									C2S++;
							}

							for (int j = 0; j < RECTAMOUNT; j++)
							{
								ShapeDI &Circledi = CircleListDI[i];
								ShapeDI &Rectdj = RectListDI[j];
								if (CircleToRectCollisionOptimised2(Circledi.GetCentreX(), Circledi.GetCentreY(), Circledi.GetRadius(),
									Rectdj.GetCentreX(), Rectdj.GetCentreY(), Rectdj.GetHalfLength(), Rectdj.GetHalfWidth(), Rectdj.GetAngle()))
									C2R++;
							}
						}

						// Draws the squares onto the screen and works out
						// whether they collide with any other shape,
						// including each other.
						for (int i = 0; i < SQUAREAMOUNT; i++)
						{
							for (int j = 0; j < SQUAREAMOUNT; j++)
							{
								// If the shape is not checking for collision with itself
								// or against a shape that has previously checked against it.
								if (i < j)
								{
									ShapeDI &Squaredi = SquareListDI[i];
									ShapeDI &Squaredj = SquareListDI[j];
									if (SquareToSquareCollisionOptimised2(Squaredi.GetCentreX(), Squaredi.GetCentreY(), Squaredi.GetHalfLength(), Squaredi.GetAngle(),
										Squaredj.GetCentreX(), Squaredj.GetCentreY(), Squaredj.GetHalfLength(), Squaredj.GetAngle()))
										S2S++;
								}
							}

							for (int j = 0; j < RECTAMOUNT; j++)
							{
								ShapeDI &Squaredi = SquareListDI[i];
								ShapeDI &Rectdj = RectListDI[j];
								if (SquareToRectCollisionOptimised2(Squaredi.GetCentreX(), Squaredi.GetCentreY(), Squaredi.GetHalfLength(), Squaredi.GetAngle(),
									Rectdj.GetCentreX(), Rectdj.GetCentreY(), Rectdj.GetHalfLength(), Rectdj.GetHalfWidth(), Rectdj.GetAngle()))
									S2R++;
							}
						}

						// Draws the rects onto the screen and works out
						// whether they collide with any other shape,
						// including each other.
						for (int i = 0; i < RECTAMOUNT; i++)
						{
							for (int j = 0; j < RECTAMOUNT; j++)
							{
								// If the shape is not checking for collision with itself
								// or against a shape that has previously checked against it.
								if (i < j)
								{
									ShapeDI &Rectdi = RectListDI[i];
									ShapeDI &Rectdj = RectListDI[j];
									if (RectToRectCollisionOptimised2(Rectdi.GetCentreX(), Rectdi.GetCentreY(), Rectdi.GetHalfLength(), Rectdi.GetHalfWidth(), Rectdi.GetAngle(),
										Rectdj.GetCentreX(), Rectdj.GetCentreY(), Rectdj.GetHalfLength(), Rectdj.GetHalfWidth(), Rectdj.GetAngle()))
										R2R++;
								}
							}
						}
					}
				}
				else
				{
					if (inheritance == 1)
					{
						// Draws the lines onto the screen and works out
						// whether they collide with each other.
						for (int i = 0; i < LINEAMOUNT; i++)
						{
							for (int j = 0; j < LINEAMOUNT; j++)
							{
								// If the shape is not checking for collision with itself
								// or against a shape that has previously checked against it.
								if (i < j)
								{
									if (LineToLineCollision(LineList[i].GetStartX(), LineList[i].GetStartY(), LineList[i].GetEndX(), LineList[i].GetEndY(),
										LineList[j].GetStartX(), LineList[j].GetStartY(), LineList[j].GetEndX(), LineList[j].GetEndY()))
										L2L++;
								}
							}

							for (int j = 0; j < CIRCLEAMOUNT; j++)
							{
								if (LineToCircleCollision(LineList[i].GetStartX(), LineList[i].GetStartY(), LineList[i].GetEndX(), LineList[i].GetEndY(),
									CircleList[j].GetCentreX(), CircleList[j].GetCentreY(), CircleList[j].GetRadius()))
									L2C++;
							}

							for (int j = 0; j < SQUAREAMOUNT; j++)
							{
								if (LineToSquareCollision(LineList[i].GetStartX(), LineList[i].GetStartY(), LineList[i].GetEndX(), LineList[i].GetEndY(),
									SquareList[j].GetCentreX(), SquareList[j].GetCentreY(), SquareList[j].GetHalfLength(), SquareList[j].GetAngle()))
									L2S++;
							}

							for (int j = 0; j < RECTAMOUNT; j++)
							{
								if (LineToRectCollision(LineList[i].GetStartX(), LineList[i].GetStartY(), LineList[i].GetEndX(), LineList[i].GetEndY(),
									RectList[j].GetCentreX(), RectList[j].GetCentreY(), RectList[j].GetHalfLength(), RectList[j].GetHalfWidth(), RectList[j].GetAngle()))
									L2R++;
							}
						}

						// Draws the circles onto the screen and works out
						// whether they collide with any other shape,
						// including each other.
						for (int i = 0; i < CIRCLEAMOUNT; i++)
						{
							for (int j = 0; j < CIRCLEAMOUNT; j++)
							{
								// If the shape is not checking for collision with itself
								// or against a shape that has previously checked against it.
								if (i < j)
								{
									if (CircleToCircleCollision(CircleList[i].GetCentreX(), CircleList[i].GetCentreY(), CircleList[i].GetRadius(),
										CircleList[j].GetCentreX(), CircleList[j].GetCentreY(), CircleList[j].GetRadius()))
										C2C++;
								}
							}

							for (int j = 0; j < SQUAREAMOUNT; j++)
							{
								if (CircleToSquareCollision(CircleList[i].GetCentreX(), CircleList[i].GetCentreY(), CircleList[i].GetRadius(),
									SquareList[j].GetCentreX(), SquareList[j].GetCentreY(), SquareList[j].GetHalfLength(), SquareList[j].GetAngle()))
									C2S++;
							}

							for (int j = 0; j < RECTAMOUNT; j++)
							{
								if (CircleToRectCollision(CircleList[i].GetCentreX(), CircleList[i].GetCentreY(), CircleList[i].GetRadius(),
									RectList[j].GetCentreX(), RectList[j].GetCentreY(), RectList[j].GetHalfLength(), RectList[j].GetHalfWidth(), RectList[j].GetAngle()))
									C2R++;
							}
						}

						// Draws the squares onto the screen and works out
						// whether they collide with any other shape,
						// including each other.
						for (int i = 0; i < SQUAREAMOUNT; i++)
						{
							for (int j = 0; j < SQUAREAMOUNT; j++)
							{
								// If the shape is not checking for collision with itself
								// or against a shape that has previously checked against it.
								if (i < j)
								{
									if (SquareToSquareCollision(SquareList[i].GetCentreX(), SquareList[i].GetCentreY(), SquareList[i].GetHalfLength(), SquareList[i].GetAngle(),
										SquareList[j].GetCentreX(), SquareList[j].GetCentreY(), SquareList[j].GetHalfLength(), SquareList[j].GetAngle()))
										S2S++;
								}
							}

							for (int j = 0; j < RECTAMOUNT; j++)
							{
								if (SquareToRectCollision(SquareList[i].GetCentreX(), SquareList[i].GetCentreY(), SquareList[i].GetHalfLength(), SquareList[i].GetAngle(),
									RectList[j].GetCentreX(), RectList[j].GetCentreY(), RectList[j].GetHalfLength(), RectList[j].GetHalfWidth(), RectList[j].GetAngle()))
									S2R++;
							}
						}

						// Draws the rects onto the screen and works out
						// whether they collide with any other shape,
						// including each other.
						for (int i = 0; i < RECTAMOUNT; i++)
						{
							for (int j = 0; j < RECTAMOUNT; j++)
							{
								// If the shape is not checking for collision with itself
								// or against a shape that has previously checked against it.
								if (i < j)
								{
									if (RectToRectCollision(RectList[i].GetCentreX(), RectList[i].GetCentreY(), RectList[i].GetHalfLength(), RectList[i].GetHalfWidth(), RectList[i].GetAngle(),
										RectList[j].GetCentreX(), RectList[j].GetCentreY(), RectList[j].GetHalfLength(), RectList[j].GetHalfWidth(), RectList[j].GetAngle()))
										R2R++;
								}
							}
						}
					}
					else if (inheritance == 2)
					{
						// Draws the lines onto the screen and works out
						// whether they collide with each other.
						for (int i = 0; i < LINEAMOUNT; i++)
						{
							for (int j = 0; j < LINEAMOUNT; j++)
							{
								// If the shape is not checking for collision with itself
								// or against a shape that has previously checked against it.
								if (i < j)
								{
									if (LineToLineCollision(LineListSI[i].GetStartX(), LineListSI[i].GetStartY(), LineListSI[i].GetEndX(), LineListSI[i].GetEndY(),
										LineListSI[j].GetStartX(), LineListSI[j].GetStartY(), LineListSI[j].GetEndX(), LineListSI[j].GetEndY()))
										L2L++;
								}
							}

							for (int j = 0; j < CIRCLEAMOUNT; j++)
							{
								if (LineToCircleCollision(LineListSI[i].GetStartX(), LineListSI[i].GetStartY(), LineListSI[i].GetEndX(), LineListSI[i].GetEndY(),
									CircleListSI[j].GetCentreX(), CircleListSI[j].GetCentreY(), CircleListSI[j].GetRadius()))
									L2C++;
							}

							for (int j = 0; j < SQUAREAMOUNT; j++)
							{
								if (LineToSquareCollision(LineListSI[i].GetStartX(), LineListSI[i].GetStartY(), LineListSI[i].GetEndX(), LineListSI[i].GetEndY(),
									SquareListSI[j].GetCentreX(), SquareListSI[j].GetCentreY(), SquareListSI[j].GetHalfLength(), SquareListSI[j].GetAngle()))
									L2S++;
							}

							for (int j = 0; j < RECTAMOUNT; j++)
							{
								if (LineToRectCollision(LineListSI[i].GetStartX(), LineListSI[i].GetStartY(), LineListSI[i].GetEndX(), LineListSI[i].GetEndY(),
									RectListSI[j].GetCentreX(), RectListSI[j].GetCentreY(), RectListSI[j].GetHalfLength(), RectListSI[j].GetHalfWidth(), RectListSI[j].GetAngle()))
									L2R++;
							}
						}

						// Draws the circles onto the screen and works out
						// whether they collide with any other shape,
						// including each other.
						for (int i = 0; i < CIRCLEAMOUNT; i++)
						{
							for (int j = 0; j < CIRCLEAMOUNT; j++)
							{
								// If the shape is not checking for collision with itself
								// or against a shape that has previously checked against it.
								if (i < j)
								{
									if (CircleToCircleCollision(CircleListSI[i].GetCentreX(), CircleListSI[i].GetCentreY(), CircleListSI[i].GetRadius(),
										CircleListSI[j].GetCentreX(), CircleListSI[j].GetCentreY(), CircleListSI[j].GetRadius()))
										C2C++;
								}
							}

							for (int j = 0; j < SQUAREAMOUNT; j++)
							{
								if (CircleToSquareCollision(CircleListSI[i].GetCentreX(), CircleListSI[i].GetCentreY(), CircleListSI[i].GetRadius(),
									SquareListSI[j].GetCentreX(), SquareListSI[j].GetCentreY(), SquareListSI[j].GetHalfLength(), SquareListSI[j].GetAngle()))
									C2S++;
							}

							for (int j = 0; j < RECTAMOUNT; j++)
							{
								if (CircleToRectCollision(CircleListSI[i].GetCentreX(), CircleListSI[i].GetCentreY(), CircleListSI[i].GetRadius(),
									RectListSI[j].GetCentreX(), RectListSI[j].GetCentreY(), RectListSI[j].GetHalfLength(), RectListSI[j].GetHalfWidth(), RectListSI[j].GetAngle()))
									C2R++;
							}
						}

						// Draws the squares onto the screen and works out
						// whether they collide with any other shape,
						// including each other.
						for (int i = 0; i < SQUAREAMOUNT; i++)
						{
							for (int j = 0; j < SQUAREAMOUNT; j++)
							{
								// If the shape is not checking for collision with itself
								// or against a shape that has previously checked against it.
								if (i < j)
								{
									if (SquareToSquareCollision(SquareListSI[i].GetCentreX(), SquareListSI[i].GetCentreY(), SquareListSI[i].GetHalfLength(), SquareListSI[i].GetAngle(),
										SquareListSI[j].GetCentreX(), SquareListSI[j].GetCentreY(), SquareListSI[j].GetHalfLength(), SquareListSI[j].GetAngle()))
										S2S++;
								}
							}

							for (int j = 0; j < RECTAMOUNT; j++)
							{
								if (SquareToRectCollision(SquareListSI[i].GetCentreX(), SquareListSI[i].GetCentreY(), SquareListSI[i].GetHalfLength(), SquareListSI[i].GetAngle(),
									RectListSI[j].GetCentreX(), RectListSI[j].GetCentreY(), RectListSI[j].GetHalfLength(), RectListSI[j].GetHalfWidth(), RectListSI[j].GetAngle()))
									S2R++;
							}
						}

						// Draws the rects onto the screen and works out
						// whether they collide with any other shape,
						// including each other.
						for (int i = 0; i < RECTAMOUNT; i++)
						{
							for (int j = 0; j < RECTAMOUNT; j++)
							{
								// If the shape is not checking for collision with itself
								// or against a shape that has previously checked against it.
								if (i < j)
								{
									if (RectToRectCollision(RectListSI[i].GetCentreX(), RectListSI[i].GetCentreY(), RectListSI[i].GetHalfLength(), RectListSI[i].GetHalfWidth(), RectListSI[i].GetAngle(),
										RectListSI[j].GetCentreX(), RectListSI[j].GetCentreY(), RectListSI[j].GetHalfLength(), RectListSI[j].GetHalfWidth(), RectListSI[j].GetAngle()))
										R2R++;
								}
							}
						}
					}
					else if (inheritance == 3)
					{
						// Draws the lines onto the screen and works out
						// whether they collide with each other.
						for (int i = 0; i < LINEAMOUNT; i++)
						{
							for (int j = 0; j < LINEAMOUNT; j++)
							{
								// If the shape is not checking for collision with itself
								// or against a shape that has previously checked against it.
								if (i < j)
								{
									ShapeDI &Linedi = LineListDI[i];
									ShapeDI &Linedj = LineListDI[j];
									if (LineToLineCollision(Linedi.GetStartX(), Linedi.GetStartY(), Linedi.GetEndX(), Linedi.GetEndY(),
										Linedj.GetStartX(), Linedj.GetStartY(), Linedj.GetEndX(), Linedj.GetEndY()))
										L2L++;
								}
							}

							for (int j = 0; j < CIRCLEAMOUNT; j++)
							{
								ShapeDI &Linedi = LineListDI[i];
								ShapeDI &Circledj = CircleListDI[j];
								if (LineToCircleCollision(Linedi.GetStartX(), Linedi.GetStartY(), Linedi.GetEndX(), Linedi.GetEndY(),
									Circledj.GetCentreX(), Circledj.GetCentreY(), Circledj.GetRadius()))
									L2C++;
							}

							for (int j = 0; j < SQUAREAMOUNT; j++)
							{
								ShapeDI &Linedi = LineListDI[i];
								ShapeDI &Squaredj = SquareListDI[j];
								if (LineToSquareCollision(Linedi.GetStartX(), Linedi.GetStartY(), Linedi.GetEndX(), Linedi.GetEndY(),
									Squaredj.GetCentreX(), Squaredj.GetCentreY(), Squaredj.GetHalfLength(), Squaredj.GetAngle()))
									L2S++;
							}

							for (int j = 0; j < RECTAMOUNT; j++)
							{
								ShapeDI &Linedi = LineListDI[i];
								ShapeDI &Rectdj = RectListDI[j];
								if (LineToRectCollision(Linedi.GetStartX(), Linedi.GetStartY(), Linedi.GetEndX(), Linedi.GetEndY(),
									Rectdj.GetCentreX(), Rectdj.GetCentreY(), Rectdj.GetHalfLength(), Rectdj.GetHalfWidth(), Rectdj.GetAngle()))
									L2R++;
							}
						}

						// Draws the circles onto the screen and works out
						// whether they collide with any other shape,
						// including each other.
						for (int i = 0; i < CIRCLEAMOUNT; i++)
						{
							for (int j = 0; j < CIRCLEAMOUNT; j++)
							{
								// If the shape is not checking for collision with itself
								// or against a shape that has previously checked against it.
								if (i < j)
								{
									ShapeDI &Circledi = CircleListDI[i];
									ShapeDI &Circledj = CircleListDI[j];
									if (CircleToCircleCollision(Circledi.GetCentreX(), Circledi.GetCentreY(), Circledi.GetRadius(),
										Circledj.GetCentreX(), Circledj.GetCentreY(), Circledj.GetRadius()))
										C2C++;
								}
							}

							for (int j = 0; j < SQUAREAMOUNT; j++)
							{
								ShapeDI &Circledi = CircleListDI[i];
								ShapeDI &Squaredj = SquareListDI[j];
								if (CircleToSquareCollision(Circledi.GetCentreX(), Circledi.GetCentreY(), Circledi.GetRadius(),
									Squaredj.GetCentreX(), Squaredj.GetCentreY(), Squaredj.GetHalfLength(), Squaredj.GetAngle()))
									C2S++;
							}

							for (int j = 0; j < RECTAMOUNT; j++)
							{
								ShapeDI &Circledi = CircleListDI[i];
								ShapeDI &Rectdj = RectListDI[j];
								if (CircleToRectCollision(Circledi.GetCentreX(), Circledi.GetCentreY(), Circledi.GetRadius(),
									Rectdj.GetCentreX(), Rectdj.GetCentreY(), Rectdj.GetHalfLength(), Rectdj.GetHalfWidth(), Rectdj.GetAngle()))
									C2R++;
							}
						}

						// Draws the squares onto the screen and works out
						// whether they collide with any other shape,
						// including each other.
						for (int i = 0; i < SQUAREAMOUNT; i++)
						{
							for (int j = 0; j < SQUAREAMOUNT; j++)
							{
								// If the shape is not checking for collision with itself
								// or against a shape that has previously checked against it.
								if (i < j)
								{
									ShapeDI &Squaredi = SquareListDI[i];
									ShapeDI &Squaredj = SquareListDI[j];
									if (SquareToSquareCollision(Squaredi.GetCentreX(), Squaredi.GetCentreY(), Squaredi.GetHalfLength(), Squaredi.GetAngle(),
										Squaredj.GetCentreX(), Squaredj.GetCentreY(), Squaredj.GetHalfLength(), Squaredj.GetAngle()))
										S2S++;
								}
							}

							for (int j = 0; j < RECTAMOUNT; j++)
							{
								ShapeDI &Squaredi = SquareListDI[i];
								ShapeDI &Rectdj = RectListDI[j];
								if (SquareToRectCollision(Squaredi.GetCentreX(), Squaredi.GetCentreY(), Squaredi.GetHalfLength(), Squaredi.GetAngle(),
									Rectdj.GetCentreX(), Rectdj.GetCentreY(), Rectdj.GetHalfLength(), Rectdj.GetHalfWidth(), Rectdj.GetAngle()))
									S2R++;
							}
						}

						// Draws the rects onto the screen and works out
						// whether they collide with any other shape,
						// including each other.
						for (int i = 0; i < RECTAMOUNT; i++)
						{
							for (int j = 0; j < RECTAMOUNT; j++)
							{
								// If the shape is not checking for collision with itself
								// or against a shape that has previously checked against it.
								if (i < j)
								{
									ShapeDI &Rectdi = RectListDI[i];
									ShapeDI &Rectdj = RectListDI[j];
									if (RectToRectCollision(Rectdi.GetCentreX(), Rectdi.GetCentreY(), Rectdi.GetHalfLength(), Rectdi.GetHalfWidth(), Rectdi.GetAngle(),
										Rectdj.GetCentreX(), Rectdj.GetCentreY(), Rectdj.GetHalfLength(), Rectdj.GetHalfWidth(), Rectdj.GetAngle()))
										R2R++;
								}
							}
						}
					}
				}
				#pragma endregion

				// Timer
				end = clock();
				double timeTaken = double(end - start) / 1000;
				double timeTakenMilli = GetCounter();

				#pragma region OUTPUT
				if (test == 1)
					cout << "\nAlgorithm: " << algorithm << ", Inheritance: " << inheritance << ", Data: " << dataAlignment << "\n\n";

				cout << "Line To Line Collisions: " << L2L << "\n";
				cout << "Line To Circle Collisions: " << L2C << "\n";
				cout << "Line To Square Collisions: " << L2S << "\n";
				cout << "Line To Rectangle Collisions: " << L2R << "\n";
				cout << "Circle To Circle Collisions: " << C2C << "\n";
				cout << "Circle To Square Collisions: " << C2S << "\n";
				cout << "Circle To Rectangle Collisions: " << C2R << "\n";
				cout << "Square To Square Collisions: " << S2S << "\n";
				cout << "Square To Rectangle Collisions: " << S2R << "\n";
				cout << "Rectangle To Rectangle Collisions: " << R2R << "\n";

				int Sum = L2L + L2C + L2S + L2R + C2C + C2S + C2R + S2S + S2R + R2R;
				cout << "\nOverall Amount Of Collisions: " << Sum << "\n";
				cout << "Time Taken To Compute: " << timeTaken << " seconds/" << timeTakenMilli << " milliseconds\n";
				#pragma endregion

				// Handles logging output for testing,
				if (test == 1)
				{
					//fprintf(f, "%f ", timeTaken);
					fprintf(f, "%f,", timeTaken);
					averageTime += timeTaken;

					// Each optimisation method will 
					// run three times in succession.
					if (k%average == 0)
					{
						dataAlignment++;
						averageTime /= average;
						//fprintf(f, "- %f\n", averageTime);
						fprintf(f, "%f\n", averageTime);
						averageTime = 0;
					}

					if (dataAlignment > 2)
						dataAlignment = 1;
				}
			}
			inheritance++;
			if (inheritance > 3)
				inheritance = 1;
		}
		algorithm++;
	}

	#pragma region CLEANUP MEMORY
	LineList.clear();
	CircleList.clear();
	SquareList.clear();
	RectList.clear();

	LineListSI.clear();
	CircleListSI.clear();
	SquareListSI.clear();
	RectListSI.clear();

	LineListDI.clear();
	CircleListDI.clear();
	SquareListDI.clear();
	RectListDI.clear();

	LineStartX.clear();
	LineStartY.clear();
	LineEndX.clear();
	LineEndY.clear();

	CircleCentreX.clear();
	CircleCentreY.clear();
	CircleRadius.clear();

	SquareCentreX.clear();
	SquareCentreY.clear();
	SquareHalfLength.clear();
	SquareAngle.clear();

	RectCentreX.clear();
	RectCentreY.clear();
	RectHalfLength.clear();
	RectHalfWidth.clear();
	RectAngle.clear();

	fclose(f);
	#pragma endregion

	// Keeps command window open
	// until any button is pressed.
	if (test == 2)
	{
		cin.sync();
		cin.get();
	}
	return 0;
}


