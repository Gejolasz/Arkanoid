#ifndef _OKRAG_H
#define _OKRAG_H

#include "figura.h"

class cOkrag : public cFigura 
{
	double r;
public:
	cOkrag(double, double, double);
	void Rysuj();
};

#endif