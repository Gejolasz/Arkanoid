#include "okrag.h"
cOkrag::cOkrag(double _x, double _y, double _r)
{
	x = _x;
	y = _y;
	r = _r;
	r_c = 1;
	g_c = 0.5;
	b_c = 0.25;
	alfa = 0;
	ukryj = 0;
	setGeometria(_x, _y, -_r, -_r, _r, _r);
}
void cOkrag::Rysuj()
{

	double angle, vectorX, vectorY, vectorX1, vectorY1;

	glPushMatrix();

	glTranslated(x, y, 0.0);
	glRotated(0, 1.0, 0.0, 0.0);
	glRotated(0, 0.0, 1.0, 0.0);
	glRotated(alfa, 0.0, 0.0, 1.0);

	if (!ukryj) {	glColor3d(1,0,0);
		glBegin(GL_LINES);//hitbox
		{
			glVertex3d(-r, r, 0);
			glVertex3d(r, r, 0);
			glVertex3d(r, -r, 0);
			glVertex3d(-r, -r, 0);
			glVertex3d(r, r, 0);
			glVertex3d(r, -r, 0);
			glVertex3d(-r, -r, 0);
			glVertex3d(-r, r, 0);
		}
		glEnd();
		glColor3d(r_c, g_c, b_c);


		//Draw Circle
			glBegin(GL_POLYGON);
			for (double i = 0; i < 2 * PI; i += PI / 180) //<-- Change this Value
				glVertex3f(cos(i) * r, sin(i) * r, 0.0);
			glEnd();
			//Draw Circle
	
	}

	glPopMatrix();
}