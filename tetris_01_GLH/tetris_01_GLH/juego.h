#pragma once
#include "GL\glut.h"
#include <iostream>
#include "cuadrado.h"
#include "figura.h"
#include <list>
#include <ctime> // libreria tiempo de sistema

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
	static void dibujar_cuadrados(); //
	static void chequear_colision();


private:
	static int alto;
	static int ancho;
	
	static float fps;

	//static list<cuadrado> cuadradosList; // lista para almacenar piezas posicionadas

	//static cuadrado objeto1;
	//static figura ele;
	
	
};
