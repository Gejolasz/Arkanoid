#include <Windows.h>
#include <iostream>

#define NDEBUG
#include <GL/freeglut.h>

#include "prostokat.h"
#include "figura.h"
#include "okrag.h"
#include "cFizyka.h"
#include <vector>

int dt = GetTickCount();

std::vector<cFigura> scena;
cOkrag * pPilka = new cOkrag(0, -1, 0.1);
cProstokat * pGora = new cProstokat(0, 2.5, 5, 0.25);
cProstokat * pPrawy = new cProstokat(2.5, 0, 0.25, 5);
cProstokat * pLewy = new cProstokat(-2.5, 0, 0.25, 5);
cProstokat * pPaletka = new cProstokat(0, -2, 5, 0.1);
/* GLUT callback Handlers */
void resize(int width, int height)
{
	const float ar = (float)width / (float)height;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void idle()
{

		pPilka->UstawKolor(abs(sin(GetTickCount() / 1000.0)), abs(sin(120 + GetTickCount() / 1000.0)), abs(sin(240 + GetTickCount() / 1000.0)));
		pPilka->Kolizja(*pGora);
		pPilka->Kolizja(*pPrawy);
		pPilka->Kolizja(*pLewy);
		if (pPaletka->Kolizja(*pPilka))
			pPaletka->UstawKolor(1, 0, 0);
		else
			pPaletka->UstawKolor(1, 1, 1);

		pPilka->Aktualizuj(GetTickCount());
		pPilka->Reset();



		glutPostRedisplay();
	
}


void display()
{
	//if (GetTickCount() - dt > 40)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glPushMatrix();


		pPilka->Rysuj();

		pPrawy->Rysuj();
		pLewy->Rysuj();
		pGora->Rysuj();

		pPaletka->Rysuj();

		glPopMatrix();
		glutSwapBuffers();
		dt = GetTickCount();
	}

	
}

void InitGLUTScene(const char* window_name)
{
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(40, 40);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

	glutCreateWindow(window_name);

	// set white as the clear colour
	glClearColor(0.25, 0.25, 0.25, 1);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
}

void SetCallbackFunctions()
{
	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutIdleFunc(idle);
}

int main(int argc, char *argv[])
{
	// it's still possible to use console to print messages
	std::cout << "Hello openGL world!" << std::endl;

	pPilka->setFizyka(9.81/10000000.0, -90);
	pPilka->setPredkosc(0.001, 80);
	pPaletka->UstawKolor(1, 1, 1);

	glutInit(&argc, argv);
	InitGLUTScene("Arkanoid");
	SetCallbackFunctions();

	// start GLUT event loop. It ends when user close the window.
	glutMainLoop();

	return 0;
}