#include "scena.h"

cScena scena;
void display()
{
	scena.display();
}
void idle()
{
	scena.idle();
}
void resize(int w, int h)
{
	scena.resize(w,h);
}




void cScena::resize(int width, int height)
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

void cScena::idle()
{

	//aktualizacja, kolizja wszystkich ze wszystkimi...



	glutPostRedisplay();

}


void cScena::display()
{
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glPushMatrix();


//rysowanie elementow sceny

		for (int i = 0; i < figury.size(); i++)
		{
			figury[i]->Rysuj();
		}

		glPopMatrix();
		glutSwapBuffers();
	}


}

void cScena::InitGLUTScene(const char* window_name)
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

void cScena::SetCallbackFunctions()
{
	glutReshapeFunc(::resize);
	glutDisplayFunc(::display);
	glutIdleFunc(::idle);
}

cScena::cScena()
{//konstruktor sceny...
	cOkrag * pPilka = new cOkrag(0, -1, 0.1);
	cProstokat * pGora = new cProstokat(0, 2.5, 5, 0.25);
	cProstokat * pPrawy = new cProstokat(2.5, 0, 0.25, 5);
	cProstokat * pLewy = new cProstokat(-2.5, 0, 0.25, 5);
	cProstokat * pPaletka = new cProstokat(0, -2, 2, 0.1); pPaletka->UstawKolor(1, 1, 1);
	cProstokat * pDol = new cProstokat(0, -2.5, 5, 0.25);

	figury.push_back(pPilka);
	figury.push_back(pPaletka);
	figury.push_back(pPrawy);
	figury.push_back(pGora);
	figury.push_back(pLewy);
	figury.push_back(pDol);


}

void cScena::DodajFigure(cFigura* figura)
{
	figury.push_back(figura);
}

void cScena::Aktualizuj()
{

	glutPostRedisplay();
}

void cScena::Inicjuj(int argc, char ** argv)
{
	/*pPilka->setFizyka(9.81 / 10000000.0, -90);
	pPilka->setPredkosc(0.001, 80);
	pPaletka->UstawKolor(1, 1, 1);*/

	glutInit(&argc, argv);
	InitGLUTScene("Arkanoid");
	SetCallbackFunctions();

	// start GLUT event loop. It ends when user close the window.
	glutMainLoop();
}
