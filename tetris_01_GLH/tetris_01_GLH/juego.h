#pragma once
#include "GL\glut.h"
#include <iostream>

using namespace std;

class juego
{
public:
	juego();
	static void dibujar();
	static void procesar_teclado(unsigned char p, int x, int y);
	static void actualizar();
	static void dibujar_tablero();

private:
	static int alto;
	static int ancho;
	static void iniciar();// model matriz y perspectivas
	static float fps;

};
