#include "prostokat.h"

cProstokat::cProstokat(double _x, double _y,double _a,double _b)
{
	x = _x;
	y = _y;
	a = _a;
	b = _b;
	r_c = 0.5;
	g_c = 0.5;
	b_c = 0.5;
	alfa = 0;
	ukryj = 0;
	setGeometria(_x, _y, -a / 2.0, -b / 2.0, a / 2.0, b / 2.0);
}
void cProstokat::Rysuj()
{
	glPushMatrix();

	glTranslated(x, y, 0.0);
	glRotated(0, 1.0, 0.0, 0.0);
	glRotated(0, 0.0, 1.0, 0.0);
	glRotated(alfa, 0.0, 0.0, 1.0);

	
	if (!ukryj)
	{	
		glColor3d(1, 0, 0);
		glBegin(GL_LINES);//hitbox
		{
			glVertex3d(-a/2, -b/2, 0);
			glVertex3d(a/2, -b/2, 0);
			glVertex3d(-a/2, b/2, 0);
			glVertex3d(a/2, b/2, 0);
			glVertex3d(a/2, b/2, 0);
			glVertex3d(a/2, -b/2, 0);
			glVertex3d(-a/2, -b/2, 0);
			glVertex3d(-a/2, b/2, 0);
		}
		glEnd();
	glColor3d(r_c, g_c, b_c);
		glBegin(GL_POLYGON);
		{
			glVertex3d(-a / 2, b / 2, 0);
			glVertex3d(a / 2, b / 2, 0);
			glVertex3d(a / 2, -b / 2, 0);
			glVertex3d(-a / 2, -b / 2, 0);
		}
		glEnd();
	}
	glPopMatrix();
}