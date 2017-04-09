#ifndef _PROSTOKAT_H
#define _PROSTOKAT_H

#include "figura.h"

#define NDEBUG
#include <iostream>
#include <GL/freeglut.h>

class cProstokat : public cFigura
{
	double a, b;
public:
	cProstokat(double, double, double, double);
	void Rysuj();
};


#endif