#pragma once
#include "GL\glut.h"
#include <iostream>
#include "cuadrado.h"

using namespace std;

class juego
{
public:
	juego();
	static void dibujar();
	static void procesar_teclado(unsigned char p, int x, int y);
	static void actualizar();
	static void iniciar();// model matriz y perspectivas
	static void dibujar_tablero();
	int exportar_alto();
	int exportar_ancho();


private:
	static int alto;
	static int ancho;
	
	static float fps;
	//static cuadrado objeto1;
	
	
};
