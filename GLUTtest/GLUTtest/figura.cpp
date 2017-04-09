#include "figura.h"

void cFigura::Przesun(double _x, double _y)
{
	x += _x;
	y += _y;
}
void cFigura::Obroc(double _alfa)
{
	alfa += _alfa;
}
void cFigura::PrzesunDo(double _x, double _y)
{
	x = _x;
	y = _y;
}
void cFigura::ObrocDo(double _alfa)
{
	alfa = _alfa;
}
void cFigura::UstawKolor(double _r, double _g, double _b)
{
	r_c = _r;
	g_c = _g;
	b_c = _b;
}
void cFigura::Ukryj(bool u)
{
	ukryj = u;
}