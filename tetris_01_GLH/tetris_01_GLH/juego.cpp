#include "juego.h"

int juego::alto = 800;
int juego::ancho = 600;
float juego::fps = 60.f;


juego::juego()
{
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(alto, ancho);
	glutCreateWindow("Tetris extremo");
	glutDisplayFunc(dibujar);
	glutKeyboardFunc(procesar_teclado);
	glutIdleFunc(actualizar);
	iniciar();

}

void juego::iniciar()
{
	glClearColor(0, 0, 0,1);
	glOrtho(ancho, 0, alto, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}



void juego::dibujar()
{
	glClear(GL_COLOR_BUFFER_BIT);

	dibujar_tablero();


	glutSwapBuffers();
}

void juego::procesar_teclado(unsigned char p, int x, int y)
{

}

void juego::actualizar()
{
	//tiempos 60 fps por segundo
	static float tiempo_transcurrido = 0;
	if (glutGet(GLUT_ELAPSED_TIME) - (tiempo_transcurrido + 1.f/fps) > 0)
	{
		tiempo_transcurrido = glutGet(GLUT_ELAPSED_TIME);
		glutPostRedisplay();
	}


	
}

void juego::dibujar_tablero() // cuadro central - area de juego
{
	
	glBegin(GL_QUADS);


	glEnd();
}




