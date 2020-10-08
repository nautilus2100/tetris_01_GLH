// tetris_01_GLH.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "GL\glut.h"
#include <iostream>
#include "juego.h"




int main(int argc, char* args[])
{

	glutInit(&argc, args);

	//objeto juego
	juego partida01;

	glutMainLoop();



	return 0;


}