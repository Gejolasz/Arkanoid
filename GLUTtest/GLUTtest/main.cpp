#include <Windows.h>
#include <iostream>

#define NDEBUG
#include <GL/freeglut.h>

#include "prostokat.h"
#include "figura.h"
#include "okrag.h"
#include "cFizyka.h"
#include "scena.h"
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{	std::cout << "Hello openGL world!" << std::endl;

	scena.Inicjuj(argc, argv);

	return 0;
}