#ifndef _FIGURA_H
#define _FIGURA_H

#define NDEBUG
#include <iostream>
#include <GL/freeglut.h>
#include <math.h>
#include "cFizyka.h"

#define PI 3.1415

class cFigura : public CFizyka {
protected:
	double r_c, g_c, b_c, alfa;
	bool ukryj;
public:
	virtual void Rysuj() = 0;
	virtual void Przesun(double, double);
	virtual void PrzesunDo(double, double);
	virtual void Obroc(double);
	virtual void ObrocDo(double);
	virtual void UstawKolor(double, double, double);
	virtual void Ukryj(bool);
};

#endif