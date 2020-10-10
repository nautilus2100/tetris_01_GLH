#include "juego.h"


int juego::alto = 600;
float juego::fps = 60.f;
int juego::ancho = 800;
//cuadrado* juego::objeto1;
cuadrado* ob1 = new cuadrado(); //extraer variable directamente de clase 








juego::juego()
{
	

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(ancho, alto);
	glutCreateWindow("Tetris extremo");
	glutDisplayFunc(dibujar);
	glutKeyboardFunc(procesar_teclado);
	glutIdleFunc(actualizar);
	iniciar();

}

void juego::iniciar()
{
	glClearColor(0, 0, 1, 1);
	glMatrixMode(GL_PROJECTION); glLoadIdentity();//carga el modo de matriz
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//// primer valor inicio del ancho valor 0
	//// segundo valor final del ancho valor ancho
	//// tercer valor inicio de lo alto valor 0
	//// cuarto valor final de lo alto valor ancho
	//// quinto y sexto valor lejania y cercania del eje z
	glOrtho(0, ancho, 0, alto, -1, 1); // CAMARA
	//glOrtho(0, ancho, 0, alto, -1, 1);
	glMatrixMode(GL_MODELVIEW); glLoadIdentity();
	
	
	
	//glColor3f(1.f, 0, 0); // color general de las lineas

	//glLineWidth(3.f);//ancho de linea

	

	// el 0 esta en el centro de la pantalla con eje X, Y  en donde si hay positivos y negativos.
	

	

}





void juego::dibujar()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	glTranslatef(ancho/2, alto/2, 0); // reposicionando en el centro
	
	dibujar_tablero();
	
	//cuadrado* ob1 = new cuadrado();
	ob1->dibujar();
	
	/*objeto1.dibujar();*/
	   

	glPopMatrix();


	glutSwapBuffers();
}

void juego::procesar_teclado(unsigned char p, int x, int y)
{

}

void juego::actualizar()
{
	//tiempos 60 fps por segundo
	static float tiempo_transcurrido = 0;
	static float actulizar_cuadrado = 0;
	//cuadrado* ob2 = new cuadrado();

	if (glutGet(GLUT_ELAPSED_TIME) - (tiempo_transcurrido + 1.f/fps) > 0)
	{
		if ( (glutGet(GLUT_ELAPSED_TIME) > actulizar_cuadrado + 1.f))
		{
			actulizar_cuadrado = glutGet(GLUT_ELAPSED_TIME);
			ob1->actualizar();
			//objeto1.actualizar();
		}


		tiempo_transcurrido = glutGet(GLUT_ELAPSED_TIME);
		glutPostRedisplay();
		
	}


	
}

void juego::dibujar_tablero() // cuadro central - area de juego
{
	
	//primer imagen a dibujar de ejemplo
	

	//dibujando tablero
	glPushMatrix();
	glTranslatef(-ancho/4, alto/2, 0); // posicionandose en el lado superior izquierdo del nuestro tablero para desde ahi empezar a dibujar
	glColor3f(1, 1, 1);
	glBegin(GL_QUAD_STRIP);
	glVertex2f(0, 0);
	glVertex2f(ancho/2, 0);
	glVertex2f(0, -alto);
	glVertex2f(ancho/2, -alto);
	glEnd();

	glPointSize(22);
	glBegin(GL_POINTS);
	glColor3f(1.f, 0.f, 0);
	glVertex2f(0, 0);
	glEnd();
	
	glPopMatrix();


	
	



}

int juego::exportar_alto()
{
	return alto;
}

int juego::exportar_ancho()
{
	return ancho;
}


