#pragma once
#include "cuadrado.h"


class figura
{
public:
	figura(unsigned short num); //1 ele, 2 ele invertida, 3 cubo, 4 triangulo, 5 palo
	bool actualizar();
	void dibujar();
	void set_x(double x);
	bool set_y(double y);
	void rotar();

	double get_x(unsigned short num);//obtencion de la posicion del cuadrado que va entrando a la lista
	double get_y(unsigned short num); //obtencion de la posicion del cuadrado que va entrando a la lista


private:
	//cuadrado cuadrados[4];
	unsigned short id;
	unsigned short rotacion;
	double pos_x;
	double pos_y;
};

