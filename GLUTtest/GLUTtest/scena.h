#ifndef _SCENA_H
#define _SCENA_H

#include <iostream>

#define NDEBUG
#include <GL/freeglut.h>

#include "prostokat.h"
#include "figura.h"
#include "okrag.h"
#include <vector>
using namespace std;

class cScena
{
	vector<cFigura*> figury;

public:
	void resize(int width, int height);
	void idle();
	void display();
	void InitGLUTScene(const char * window_name);
	void SetCallbackFunctions();
	cScena();
	void DodajFigure(cFigura*);
	void Aktualizuj();
	void Rysuj();
	void Inicjuj(int argc, char** argv);


};
extern cScena scena;
#endif