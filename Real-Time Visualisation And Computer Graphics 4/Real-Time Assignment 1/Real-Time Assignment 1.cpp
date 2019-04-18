// Michael Mohan 40020843
// Real-Time Assignment
// Press I/O to move forward/backward
// Press W/S to rotate up/down
// Press A/D to rotate left/right
// Press Z/X to rotate side to side

#pragma region PROGRAM DECLARATIONS
#include "stdafx.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//#include <GL\glut.h>
#include "glut.h"
#pragma endregion

#pragma region GLOBAL BOOLEAN AND CAMERA PARAMETERS
bool movingUp = false;
GLfloat x = 0.0f;
GLfloat y = 0.0f;
GLfloat z = 0.0f;
GLfloat initRotX = 0.0f;
GLfloat initRotY = 0.0f;
GLfloat initRotZ = 0.0f;
GLfloat xRotation = 0.0f;
GLfloat yRotation = 0.0f;
GLfloat zRotation = 0.0f;
#pragma endregion

#pragma region LIGHTING VALUES
GLfloat  whiteLight[]  = { 0.2f, 0.2f, 0.2f, 1.0f };
GLfloat  sourceLight[] = { 0.8f, 0.8f, 0.8f, 1.0f };
GLfloat	 lightPos[]    = { 0.0f, 0.0f, 0.0f, 1.0f };
#pragma endregion

// Information for the size of the planets, the rotational speeds, 
// the inclines, the angles of orbit and the minimum distances of 
// the orbits to their centre
// Each planet has a specific index used to access its particular 
// data within each array e.g. the sun = [0], earth = [3]
#pragma region PLANET AND ASTEROID DATA

static GLfloat planetRadii[11]			  = { 100.0f, 3.0f, 10.0f, 10.0f, 3.0f, 5.0f, 40.0f, 35.0f, 20.0f, 20.0f, 3.0f };
static GLfloat planetOrbitalInclines[11]  = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 17.0f };
static GLfloat planetOrbitalDistances[11] = { 0.0f, 105.0f, 123.0f, 168.0f, 20.0f, 220.0f, 500.0f, 655.0f, 830.0f, 970.0f, 1003.0f };
static GLfloat planetOrbits[11]	 		  = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };
static GLfloat planetAxisInclines[11]     = { 0.0f, 0.0352f, 0.0f, 23.44f, 6.688f, 25.19f, 3.13f, 26.73f, 97.77f, 28.32f, 119.61f };
static GLfloat planetRotations[11]        = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };
static GLfloat planetSpeeds[11]			  = { 0.0f, 8.0f, -8.0f, 6.0f, 0.0f, 5.0f, 4.0f, 3.0f, 2.0f, 1.0f, 0.0f };
static GLfloat rotationSpeeds[11]		  = { 1.0f, 36.0f, -32.0f, 28.0f, 0.0f, 24.0f, 20.0f, 16.0f, 12.0f, 8.0f, 4.0f };

static GLfloat asteroidOrbits[]	 		  = { 0.0f, 10.0f, 20.0f, 30.0f, 40.0f, 50.0f, 60.0f, 70.0f, 80.0f, 90.0f, 100.0f, 
											  110.0f, 120.0f, 13.0f, 14.0f, 15.0f, 16.0f, 170.0f, 180.0f, 190.0f, 200.0f,
											  210.0f, 220.0f, 230.0f, 240.0f, 250.0f, 260.0f, 270.0f, 280.0f, 290.0f, 
											  300.0f, 310.0f, 320.0f, 330.0f, 340.0f, 350.0f, 360.0f};
#pragma endregion

// Arrays to hold information needed for texture data
#pragma region TEXTURE INFORMATION
GLuint SunTexture, MercuryTexture, VenusTexture, EarthTexture, MoonTexture, MarsTexture, 
	   JupiterTexture, SaturnTexture, UranusTexture, NeptuneTexture, PlutoTexture, AsteroidTexture,
	   SkyBox1, SkyBox2;
GLuint textures[] = { SunTexture, MercuryTexture, VenusTexture, EarthTexture, MoonTexture, MarsTexture, 
					   JupiterTexture, SaturnTexture, UranusTexture, NeptuneTexture, PlutoTexture,
					   AsteroidTexture, SkyBox1, SkyBox2 };
unsigned char *SunPix, *MercuryPix, *VenusPix, *EarthPix, *MoonPix, *MarsPix, 
			  *JupiterPix, *SaturnPix, *UranusPix, *NeptunePix, *PlutoPix, *AsteroidPix,
			  *SpacePix1, *SpacePix2;
unsigned char *pix[] = { SunPix, MercuryPix, VenusPix, EarthPix, MoonPix, MarsPix, 
						 JupiterPix, SaturnPix, UranusPix, NeptunePix, PlutoPix, AsteroidPix,
						 SpacePix1, SpacePix2 };
#pragma endregion

// Uses event handling to detect user 
// input for camera functionality
void KeyDown(unsigned char key, int mousex, int mousey)
{
	switch (key) 
	{
	// Escape
	case 27:		
		PostQuitMessage(0);
		break;
	
	// Allows for zooming functionality
	case 'i':
		initRotY = (yRotation / 180 * 3.141592654f);
        initRotX = (xRotation / 180 * 3.141592654f);

        x -= 10*float(sin(initRotY));
        z += 10*float(cos(initRotY));
        y += 10*float(sin(initRotX));
		break;
	case 'o':
		initRotY = (yRotation / 180 * 3.141592654f);
        initRotX = (xRotation / 180 * 3.141592654f);

         x += 10*float(sin(initRotY));
         z -= 10*float(cos(initRotY));
         y -= 10*float(sin(initRotX));	
		break;

	// Allows for rotation functionality
	case 'a':	
		 xRotation -= 1.0f;

         if(xRotation > 360.0f)
	        xRotation = 0.0f;
		break;
	case 'd':		
		xRotation += 1.0f;

         if(xRotation < -360.0f) 
		    xRotation = 0.0f;
		break;
	case 'w':		
		yRotation -= 1.0f;

         if(yRotation > 360.0f) 
		    yRotation = 0.0f;
		break;
	case 's':
		yRotation += 1.0f;

         if(yRotation < -360.0f)
		     yRotation = 0.0f;
		break;
	case 'z':		
		zRotation -= 1.0f;

         if(zRotation > 360.0f) 
		    zRotation = 0.0f;
		break;
	case 'x':	
		zRotation += 1.0f;

         if(zRotation < -360.0f) 
		    zRotation = 0.0f;
		break;
	}

	if (z > 1510)
		z = 1510;
	if (z < 0)
		z = 0;
}

// Method is used to draw the rings of Saturn and Uranus
void DrawRings(GLUquadricObj* pObj, GLdouble innerRadius, GLdouble outerRadius) 
{ 
	glEnable(GL_TEXTURE_2D); 
	glDisable(GL_CULL_FACE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);  
	gluDisk(pObj, innerRadius, outerRadius, 50, 1);
	glEnable(GL_CULL_FACE);
	glDisable(GL_TEXTURE_2D); 
}

// Method to used  to cause Plutos orbit
// to incline from 17 degrees to -17 degrees
void PlutoIncline(int i)
{
	// Changes Plutos orbital incline
	GLfloat plutoIncline = 68.0f/360.0f;
	if (movingUp == true)
		planetOrbitalInclines[i] += plutoIncline;
	else if (movingUp == false)
		planetOrbitalInclines[i] -= plutoIncline;
	
	if (planetOrbitalInclines[i] < -17.0f)
	{
		planetOrbitalInclines[i] += plutoIncline;
		movingUp = true;
	}
	else if (planetOrbitalInclines[i] > 17.0f)
	{
		planetOrbitalInclines[i] -= plutoIncline;
		movingUp = false;
	}
}

// Method is used to load in the texture files 
// to be used to map onto the planets
unsigned char *LoadBmp(char *fn, int *wi, int *hi)
{
	 BITMAPFILEHEADER bmfh;
	 BITMAPINFOHEADER bmih;
	 WORD bits;
	 FILE *t24;
	 unsigned char *lpBitmapBits;
	 long imagesize, nc;
 
	 // Read the bitmap
	 t24 = fopen((char *)fn, "rb");

	 if (t24 == NULL)
	 {
		 printf("Could not open input file\n"); 
		 exit(0);
	 }

	 fread((char *)&bmfh, sizeof(BITMAPFILEHEADER), 1, t24);
	 fread((char *)&bmih, sizeof(BITMAPINFOHEADER), 1, t24);

	 if (bmih.biClrUsed != 0)
		 nc = bmih.biClrUsed;
	 else
	 {
		 bits = bmih.biBitCount;
		 switch (bits)
		 {
			 case 1:    nc = 2;   break;
			 case 4:    nc = 16;  break;
			 case 8:    nc = 256; break;
			 default:   nc = 0;   break;
		 }
	 }

	 if (nc > 0)
	 {
		 printf("Cannot handle paletted image\n"); 
		 exit(0);
	 }

	 imagesize = bmfh.bfSize-bmfh.bfOffBits;
	 if ((lpBitmapBits = (unsigned char *)malloc(imagesize)) == NULL)
	 { 
		 fclose(t24); 
		 exit(0); 
	 }

	 fread((char *)lpBitmapBits, imagesize, 1, t24);
	 fclose(t24);
	 *wi = bmih.biWidth; 
	 *hi = bmih.biHeight;
	 return lpBitmapBits;
}

// Initialises texture information and loads and 
// generates the textures to be mapped onto the planets
void CreateTexture(char *filename, int i)
 {
	int w, h;
	glEnable(GL_TEXTURE_2D);
	pix[i] = LoadBmp(filename, &w, &h);

	glGenTextures(1, &textures[i]);
	// Bind the texture onto the object
	glBindTexture(GL_TEXTURE_2D, textures[i]);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pix[i]);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	free(pix[i]);
	// Deactivate textures
	glDisable(GL_TEXTURE_2D);
 }

// Creates a skybox to draw the textures
// onto the edges of the scene and give
// the illusion of being in space
void DrawSpace(GLfloat length)
{
	// Store the current matrix
    glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	
	// Render the front quad
    glBindTexture(GL_TEXTURE_2D, textures[12]);
	
    glBegin(GL_QUADS);
		glTexCoord2f(1.0, 0.0); glVertex3f(-length, -length, -length);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(length, -length, -length);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(length, length, -length);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-length, length, -length);
    glEnd();

    // Render the back quad
    glBindTexture(GL_TEXTURE_2D, textures[12]);
	glDisable(GL_CULL_FACE);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-length, -length, length);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(length, -length, length);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(length, length, length);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-length, length, length);
    glEnd();
	glEnable(GL_CULL_FACE);

    // Render the left quad
    glBindTexture(GL_TEXTURE_2D, textures[12]);
	glDisable(GL_CULL_FACE);
    glBegin(GL_QUADS);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-length, -length, -length);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-length, -length, length);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-length, length, length);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-length, length, -length);
    glEnd();
	glEnable(GL_CULL_FACE);

	// Render the right quad
    glBindTexture(GL_TEXTURE_2D, textures[12]);

    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(length, -length, -length);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(length, -length, length);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(length, length, length);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(length, length, -length);
    glEnd();

    // Render the top quad
    glBindTexture(GL_TEXTURE_2D, textures[12]);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(length, length, -length);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(length, length, length);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-length, length, length);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-length, length, -length);
    glEnd();

    // Render the bottom quad
    glBindTexture(GL_TEXTURE_2D, textures[13]);
	glDisable(GL_CULL_FACE);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(length, -length, -length);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(length, -length, length);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-length, -length, length);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-length, -length, -length);
    glEnd();
	glEnable(GL_CULL_FACE);

    // Restore enable bits and matrix
	glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

// This method is used to draw the planets 
// onto the screen, using arrays to specify
// the details of each planets orbit
void DrawPlanet(GLUquadricObj* pObj, int i)
{
	glPushMatrix();

	// Activate textures
	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[i]);

	// Rotate coordinate system
	glRotatef(planetOrbits[i], 0.0f, 1.0f, 0.0f);
	// The orbit incline
	glRotatef(planetOrbitalInclines[i], 0.0f, 0.0f, 1.0f);
	// The planet's initial distance from the Sun
	glTranslatef(planetOrbitalDistances[i], 0.0f, 0.0f);
	// Rotates planets so that textures 
	// are facing the right way
	glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
	// The axis incline
	glRotatef(planetAxisInclines[i], 1.0f, 0.0f, 0.0f);
	// The axis rotation
	glRotatef(planetRotations[i], 0.0f, 0.0f, 1.0f);
	// Draw the planet
	gluSphere(pObj, planetRadii[i], 30, 30);

	// Draw rings on Saturn
	if (i == 7)
	{
		DrawRings(pObj, 40, 55);
		DrawRings(pObj, 58, 68);
	}

	// Draw rings on Uranus
	if (i == 8)
	{
		DrawRings(pObj, 28, 29);
		DrawRings(pObj, 30, 32);
		DrawRings(pObj, 33, 34);
	}

	// Restore the matrix state
	// to the Modelview matrix
	glPopMatrix();

	glDisable(GL_LIGHTING);
	// Deactivate textures
	glDisable(GL_TEXTURE_2D);
	// Move the light after we draw the planet
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

	// Step the planet rotation forward by its speed
	planetRotations[i] += rotationSpeeds[i];

	if ((planetRotations[i] > 360.0f)||(planetRotations[i] < -360.0f))
		planetRotations[i] = 0.0f;

	// Step the planet orbit forward by its speed
	planetOrbits[i] += planetSpeeds[i];

	// If the planet is Pluto it 
	// will have an angled orbit
	if (i == 10)
		PlutoIncline(i);
}

// Method that is used to draw the asteroids
// is similar to DrawPlanet, but maps the same
// texture onto each asteroid and allows the 
// programmer to manipulate attributes in
// the method call instead of using arrays
void DrawAsteroid(int i, static GLfloat orbitSpeed, static GLfloat orbitIncline, 
				  static GLfloat orbitDistance, static GLfloat asteroidRadius)
{
	glPushMatrix();
	
	// Activate textures
	GLUquadricObj* pObjAsteroid;
	pObjAsteroid = gluNewQuadric();
	gluQuadricTexture(pObjAsteroid, GL_TRUE);

	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[11]);

	// Rotate coordinate system
	glRotatef(asteroidOrbits[i], 0.0f, 1.0f, 0.0f);
	// The orbit incline
	glRotatef(orbitIncline, 0.0f, 0.0f, 1.0f);
	// The asteroid's initial distance from the Sun
	glTranslatef(orbitDistance, 0.0f, 0.0f);
	// Rotates asteroids so that textures 
	// are facing the right way
	glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
	// Draw the asteroid
	gluSphere(pObjAsteroid, asteroidRadius, 30, 30);

	// Restore the matrix state
	// to the Modelview matrix
	glPopMatrix();

	gluDeleteQuadric(pObjAsteroid);
	glDisable(GL_LIGHTING);
	// Deactivate textures
	glDisable(GL_TEXTURE_2D);
	// Move the light after we draw the asteroid
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

	// Step the asteroid forward by its speed
	asteroidOrbits[i] += orbitSpeed;
}

// Called to draw scene
void RenderScene(void)
{
	#pragma region INITIALISATION
	// Clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	// Initialise the lighting settings
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT_MODEL_TWO_SIDE);
	// Save the matrix state and load the identity matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Rotate the camera on the x-axis (left and right)
	glRotatef(xRotation, 0.0f, 1.0f, 0.0f);  
	// Rotate the camera on the y-axis (up and down)
	glRotatef(yRotation, 1.0f, 0.0f, 0.0f); 
	// Rotate the camera on the z-axis (side to side)
	glRotatef(zRotation, 0.0f, 0.0f, 1.0f);
	// Translate the whole scene out and into view
	// by 1650.0f to see the whole solar system
	glTranslatef(x, y, z - 1650.0f);
	
	// Commands used for defunct camera method
	//gluLookAt(x, y, z - 1650.0f, x + xRotation, y + yRotation, z + zRotation, 0.0f, 1.0f, 0.0f); 	
	#pragma endregion

	// Increment to reference the details of each planets 
	// orbits through predefined arrays of floats
	int i = 0;

	#pragma region DRAW SUN
	glPushMatrix();

	// For mapping the texture onto the planet
	GLUquadricObj* pObjSun;
	pObjSun = gluNewQuadric();
	gluQuadricTexture(pObjSun, GL_TRUE);

    glDisable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[i]);

	// The axis rotation
	glRotatef(planetRotations[i], 0.0f, 1.0f, 0.0f);
	gluSphere(pObjSun, planetRadii[i], 30, 17);

    glEnable(GL_LIGHTING);
	// Deactivate textures
	glDisable(GL_TEXTURE_2D);
	gluDeleteQuadric(pObjSun);
	// Move the light after we draw the Sun
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

	// Step the suns rotation forward by its speed
	planetRotations[i] += rotationSpeeds[i];

	if (planetRotations[i] > 360.0f)
		planetRotations[i] = 0.0f;
	#pragma endregion

	i++;
	// For mapping the texture onto Mercury
	GLUquadricObj* pObjMercury;
	pObjMercury = gluNewQuadric();
	gluQuadricTexture(pObjMercury, GL_TRUE);
	// Draw Mercury
	DrawPlanet(pObjMercury, i);
	gluDeleteQuadric(pObjMercury);

	i++;
	// For mapping the texture onto Venus
	GLUquadricObj* pObjVenus;
	pObjVenus = gluNewQuadric();
	gluQuadricTexture(pObjVenus, GL_TRUE);
	// Draw the planet
	DrawPlanet(pObjVenus, i);
	gluDeleteQuadric(pObjVenus);

	#pragma region DRAW EARTH AND MOON
	glPushMatrix();

	i++;
	// For mapping the texture onto the planet
	GLUquadricObj* pObjEarth;
	pObjEarth = gluNewQuadric();
	gluQuadricTexture(pObjEarth, GL_TRUE);

	// Activate textures
	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[i]);
	
	
	// Rotate coordinate system
	glRotatef(planetOrbits[i], 0.0f, 1.0f, 0.0f);
	// The Earths initial distance from the Sun
	glTranslatef(planetOrbitalDistances[i], 0.0f, 0.0f);
	//The axis incline
	glRotatef(planetAxisInclines[i], 0.0f, 0.0f, 1.0f);
	// Rotates the Earth so that the 
	// texture faces the right way
	glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
	// The axis rotation
	glRotatef(planetRotations[i], 0.0f, 0.0f, 1.0f);
	// Draw the Earth
	gluSphere(pObjEarth, planetRadii[i], 30, 17);

	i++;
	glPushMatrix();
	// For mapping the texture onto the moon
	GLUquadricObj* pObjMoon;
	pObjMoon = gluNewQuadric();
	gluQuadricTexture(pObjMoon, GL_TRUE);
	glBindTexture(GL_TEXTURE_2D, textures[i]);

	//The axis incline
	glRotatef(planetAxisInclines[i], 0.0f, 0.0f, 1.0f);
	// The axis rotation
	glRotatef(planetRotations[i], 0.0f, 1.0f, 0.0f);
	// The Moon's distance from the Earth
	glTranslatef(planetOrbitalDistances[i], 0.0f, 0.0f);
	
	// Draw the Moon
	gluSphere(pObjMoon, planetRadii[i], 30, 17);

	// Restore the matrix state
	// to the Modelview matrix
	glPopMatrix();
	glPopMatrix();

	glDisable(GL_LIGHTING);
	// Deactivate textures
	glDisable(GL_TEXTURE_2D);
	gluDeleteQuadric(pObjEarth);
	gluDeleteQuadric(pObjMoon);
	// Move the light after we draw the Earth and Moon
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

	// Step the Earths rotation forward by its speed
	planetRotations[3] += rotationSpeeds[3];

	if (planetRotations[3] > 360.0f)
		planetRotations[3] = 0.0f;
	
	// Step the Earths orbit forward by its speed
	planetOrbits[3] += planetSpeeds[3];
	#pragma endregion

	i++;
	// For mapping the texture onto Mars
	GLUquadricObj* pObjMars;
	pObjMars = gluNewQuadric();
	gluQuadricTexture(pObjMars, GL_TRUE);
	// Draw Mars
	DrawPlanet(pObjMars, i);
	gluDeleteQuadric(pObjMars);

	#pragma region DRAW ASTEROIDS
	// int, orbitSpeed, orbitIncline, orbitDistance, asteroidRadius
	DrawAsteroid(0, 4.5f, 0.0f, 290.0f, 2.0f);
	DrawAsteroid(1, 4.5f, -7.0f, 320.0f, 2.0f);
	DrawAsteroid(2, 4.3f, 0.0f, 350.0f, 2.0f);
	DrawAsteroid(3, 4.5f, 0.0f, 380.0f, 2.0f);
	DrawAsteroid(4, 4.8f, 0.0f, 410.0f, 2.0f);
	DrawAsteroid(5, 4.6f, 5.0f, 290.0f, 2.0f);
	DrawAsteroid(6, 4.0f, 5.0f, 320.0f, 3.0f);
	DrawAsteroid(7, 4.0f, 5.0f, 350.0f, 2.0f);
	DrawAsteroid(8, 4.2f, 5.0f, 380.0f, 2.0f);
	DrawAsteroid(9, 4.5f, 5.0f, 410.0f, 2.0f);
	DrawAsteroid(10, 4.5f, -5.0f, 290.0f, 2.0f);
	DrawAsteroid(11, 4.5f, -5.0f, 320.0f, 2.0f);
	DrawAsteroid(12, 4.5f, -5.0f, 350.0f, 2.0f);
	DrawAsteroid(13, 5.2f, -5.0f, 380.0f, 2.0f);
	DrawAsteroid(14, 4.5f, -5.0f, 410.0f, 2.0f);
	DrawAsteroid(15, 4.5f, 0.0f, 290.0f, 2.0f);
	DrawAsteroid(16, 4.8f, 0.0f, 320.0f, 2.0f);
	DrawAsteroid(17, 4.3f, 0.0f, 350.0f, 2.0f);
	DrawAsteroid(18, 4.5f, 0.0f, 380.0f, 2.0f);
	DrawAsteroid(19, 4.8f, 0.0f, 410.0f, 2.0f);
	DrawAsteroid(20, 4.6f, 5.0f, 290.0f, 3.0f);
	DrawAsteroid(21, 4.0f, 5.0f, 320.0f, 2.0f);
	DrawAsteroid(22, 4.0f, 5.0f, 350.0f, 2.0f);
	DrawAsteroid(23, 4.2f, 5.0f, 380.0f, 2.0f);
	DrawAsteroid(24, 4.5f, 5.0f, 410.0f, 2.0f);
	DrawAsteroid(25, 4.5f, -5.0f, 290.0f, 2.0f);
	DrawAsteroid(26, 4.5f, -5.0f, 320.0f, 2.0f);
	DrawAsteroid(27, 4.5f, -5.0f, 350.0f, 2.0f);
	DrawAsteroid(28, 3.8f, -5.0f, 380.0f, 2.0f);
	DrawAsteroid(29, 4.5f, -5.0f, 450.0f, 2.0f);
	DrawAsteroid(30, 4.5f, 0.0f, 290.0f, 2.0f);
	DrawAsteroid(31, 4.3f, 0.0f, 320.0f, 2.0f);
	DrawAsteroid(32, 4.5f, 0.0f, 350.0f, 2.0f);
	DrawAsteroid(33, 4.8f, 5.0f, 380.0f, 2.0f);
	DrawAsteroid(34, 4.6f, 5.0f, 410.0f, 2.0f);
	DrawAsteroid(35, 4.0f, 5.0f, 320.0f, 2.0f);
	DrawAsteroid(36, 4.0f, 5.0f, 380.0f, 1.0f);
	#pragma endregion

	i++;
	// For mapping the texture onto Jupiter
	GLUquadricObj* pObjJupiter;
	pObjJupiter = gluNewQuadric();
	gluQuadricTexture(pObjJupiter, GL_TRUE);
	// Draw Jupiter
	DrawPlanet(pObjJupiter, i);
	gluDeleteQuadric(pObjJupiter);

	i++;
	// For mapping the texture onto Saturn
	GLUquadricObj* pObjSaturn;
	pObjSaturn = gluNewQuadric();
	gluQuadricTexture(pObjSaturn, GL_TRUE);
	// Draw Saturn
	DrawPlanet(pObjSaturn, i);
	gluDeleteQuadric(pObjSaturn);

	i++;
	// For mapping the texture onto Uranus
	GLUquadricObj* pObjUranus;
	pObjUranus = gluNewQuadric();
	gluQuadricTexture(pObjUranus, GL_TRUE);
	// Draw Uranus
	DrawPlanet(pObjUranus, i);
	gluDeleteQuadric(pObjUranus);

	i++;
	// For mapping the texture onto Neptune
	GLUquadricObj* pObjNeptune;
	pObjNeptune = gluNewQuadric();
	gluQuadricTexture(pObjNeptune, GL_TRUE);
	// Draw Neptune
	DrawPlanet(pObjNeptune, i);
	gluDeleteQuadric(pObjNeptune);

	i++;
	// For mapping the texture onto Pluto
	GLUquadricObj* pObjPluto;
	pObjPluto = gluNewQuadric();
	gluQuadricTexture(pObjPluto, GL_TRUE);
	// Draw Pluto
	DrawPlanet(pObjPluto, i);
	gluDeleteQuadric(pObjPluto);

	glPopMatrix();
	// Draw skybox
	DrawSpace(3000.0f);

	// Show the image
	glutSwapBuffers();
}

// This function does any needed initialization on 
// the rendering context. 
void SetupRC()
{
	// Light values and coordinates:
	// Hidden surface removal
	glEnable(GL_DEPTH_TEST);
	// Counter clock-wise polygons face out
	glFrontFace(GL_CCW);
	// Do not calculate inside of the planets
	glEnable(GL_CULL_FACE);

	// Enable lighting
	glEnable(GL_LIGHTING);

	// Setup and enable light 0
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, whiteLight);
	glLightfv(GL_LIGHT0,GL_DIFFUSE, sourceLight);
	glLightfv(GL_LIGHT0,GL_POSITION, lightPos);
	glEnable(GL_LIGHT0);

	// Enable color tracking
	glEnable(GL_COLOR_MATERIAL);

	// Set Material properties to follow glColor values
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	// Black blue background
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
}

// Makes sure the program redraws the scene 
// after every 100 milliseconds
void TimerFunc(int value)
{
    glutPostRedisplay();
    glutTimerFunc(100, TimerFunc, 1);
}

// Gives the user the ability to change
// the size of the program window
void ChangeSize(int w, int h)
{
    GLfloat fAspect;

    // Prevent a divide by zero
    if (h == 0)
        h = 1;

    // Set Viewport to window dimensions
    glViewport(0, 0, w, h);

    // Calculate aspect ratio of the window
    fAspect = (GLfloat)w/(GLfloat)h;

    // Set the perspective coordinate system
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // field of view of 45 degrees, near and far planes 1.0 and 7,000
    gluPerspective(45.0f, fAspect, 1.0, 7000.0);

    // Modelview matrix reset
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// The main program
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1350, 690);
	glutCreateWindow("Solar System");

	// Activate textures
	CreateTexture("sunmap.bmp", 0);
	CreateTexture("mercurymap.bmp", 1);
	CreateTexture("venusmap.bmp", 2);
	CreateTexture("earthmap1k.bmp", 3);
	CreateTexture("moonmap.bmp", 4);
	CreateTexture("marsmap1k.bmp", 5);
	CreateTexture("jupitermap.bmp", 6);
	CreateTexture("saturnmap.bmp", 7);
	CreateTexture("uranusmap.bmp", 8);
	CreateTexture("neptunemap.bmp", 9);
	CreateTexture("plutomap2k.bmp", 10);
	CreateTexture("asteroidmap.bmp", 11);
	CreateTexture("spacemap1.bmp", 12);
	CreateTexture("spacemap2.bmp", 13);
	SetupRC(); 
	glutTimerFunc(250, TimerFunc, 1);
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	glutKeyboardFunc(KeyDown);
	glutMainLoop();

	// Keeps the window open
	system ("PAUSE");
	return 0;
}