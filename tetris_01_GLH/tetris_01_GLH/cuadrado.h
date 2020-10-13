#pragma once
#include "GL\glut.h"
#include "juego.h"

#include <iostream>

class cuadrado
//class cuadrado : public juego
{
public:
	cuadrado(); // constructor para figura
	cuadrado(double x, double y);  // constructor para los cuadrados que se van almacenando en la lista de cuadradosList
	void dibujar();
	
	void set_x(double x) { pos_x = 0; pos_x = x; std::cout << x << std::endl; }  // para actualizar posicion sumando a la posicion anterior
	void set_y(double y) { pos_x = 0; pos_y = y; std::cout << y << std::endl; }

	void actualizar(); // actualiza posicion del cuadrado
	double get_x() { return pos_x; }
	double get_y() { return pos_y; }
	void set_rotacion(unsigned short num);

private:
	double pos_x; // posicion inicial
	double pos_y;	// posicion inicial
	unsigned short rotacionImportada = 0 ; //rotacion extraida de juego.cpp
};

