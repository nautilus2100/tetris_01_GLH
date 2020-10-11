#pragma once
#include "GL\glut.h"
#include "juego.h"

class cuadrado
//class cuadrado : public juego
{
public:
	cuadrado();
	void dibujar();
	void set_x(double x) { pos_x += x; }  // para actualizar posicion sumando a la posicion anterior
	void set_y(double y) { pos_y += y; }
	void actualizar(); // actualiza posicion del cuadrado
	double get_x() { return pos_x; }
	double get_y() { return pos_y; }
	void set_rotacion(unsigned short num);

private:
	double pos_x; // posicion inicial
	double pos_y;	// posicion inicial
	unsigned short rotacionImportada; //rotacion extraida de juego.cpp
};

