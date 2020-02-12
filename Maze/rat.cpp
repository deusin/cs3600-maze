#include "rat.h"
#include <vector>
#include <cstdlib>
#include "glut.h"
#include "graphics.h"

Rat::Rat(double x, double y, double degrees) : x(x), y(y), degrees(degrees)
{
	radius = 0.5;
}

void Rat::Draw()
{
	glPushMatrix();
	glTranslated(x, y, 0);
	glRotated(degrees, 0, 0, 1);
	glScaled(0.5, 0.5, 1.0);
	//DrawTriangle(0.5, 0, -0.3, 0.2, -0.3, -0.2);
	glBegin(GL_TRIANGLES);
	glVertex2d(0.5, 0);
	glVertex2d(-0.3, 0.2);
	glVertex2d(-0.3, -0.2);
	glEnd();
	glPopMatrix();
}

void Rat::SpinLeft()
{
	degrees += 0.5;
}

void Rat::SpinRight()
{
	degrees -= 0.5;
}

void Rat::ScurryForward()
{

}