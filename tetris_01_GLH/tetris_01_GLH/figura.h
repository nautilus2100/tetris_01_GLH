#pragma once
#include "cuadrado.h"


class figura
{
public:
	figura(unsigned short num); //1 ele, 2 ele invertida, 3 cubo, 4 triangulo, 5 palo
	void actualizar();
	void dibujar();


private:
	cuadrado cuadrados[4];
	unsigned short id;
};

