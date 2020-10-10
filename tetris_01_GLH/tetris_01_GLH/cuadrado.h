#pragma once
#include "GL\glut.h"
#include "juego.h"

class cuadrado
//class cuadrado : public juego
{
public:
	cuadrado();
	void dibujar();
	void set_x(double x) { pos_x += x; }
	void set_y(double y) { pos_y += y; }
	void actualizar(); // actualiza posicion del cuadrado
	double get_x() { return pos_x; }
	double get_y() { return pos_y; }

private:
	double pos_x;
	double pos_y;
};

