#pragma once
#include "cuadrado.h"
#include <cmath>


class figura
{
public:
	figura(unsigned short num); //1 ele, 2 ele invertida, 3 cubo, 4 triangulo, 5 palo
	bool actualizar();
	void dibujar();
	void set_x(double x);
	bool set_y(double y);
	void rotar();
	double get_angulo_cuadradito(unsigned short num);
	float rad2deg(float radianes) { return double(radianes) * 180.0 / 3.14; } // funcion para pasar radianes a grados
	float deg2rad(float grados) { return grados * 3.14 / 180.0; } 

	double get_x(unsigned short num);//obtencion de la posicion del cuadrado que va entrando a la lista
	double get_y(unsigned short num); //obtencion de la posicion del cuadrado que va entrando a la lista

	double calcular_posicion_x(unsigned short num); // posiciones del cuadradito
	double calcular_posicion_y(unsigned short num);

private:
	//cuadrado cuadrados[4];
	unsigned short id;
	unsigned short rotacion;
	double pos_x;
	double pos_y;
	
};

