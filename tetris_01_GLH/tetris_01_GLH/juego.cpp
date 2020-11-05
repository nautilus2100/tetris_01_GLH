#include "juego.h"


int juego::alto = 600;
float juego::fps = 60.f;
int juego::ancho = 800;
cuadrado* ob1 = new cuadrado(); //extraer variable directamente de clase 
figura* pieza = new figura(rand()%6+1); // extraido directamente de figura.h sin declarar la variable en figura.h sino aqui directamente
list<cuadrado> cuadradosList;
//list<cuadrado> juego::cuadradosList;


juego::juego()
{
	srand(time(NULL)); // numeros aleatorios tomando el tiempo del sistema
	pieza = new figura(rand() % 6 + 1);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); //inicializa con doble bufer
	glutInitWindowPosition(50, 50); // posicion inicial
	glutInitWindowSize(ancho, alto); // tamaño ventana
	glutCreateWindow("Tetris extremo"); // crear ventana con titulo
	glutDisplayFunc(dibujar); // funcion para dibujar
	glutKeyboardFunc(procesar_teclado); 
	glutIdleFunc(actualizar); // funcion actualizar
	iniciar(); // iniciar model matriz y perspectivas

}

void juego::iniciar()
{
	glClearColor(0.1, 0.3, 1, 1);
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
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity(); // carga
	
	
	
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
	
	//dibujando cuadrado
	//cuadrado* ob1 = new cuadrado();
	//ob1->dibujar();
	pieza->dibujar();

	//RECORRER LISTA
	dibujar_cuadrados();
	
	/*objeto1.dibujar();*/
	   

	glPopMatrix();


	glutSwapBuffers(); //muestra
}

void juego::procesar_teclado(unsigned char c, int x, int y) // recibe coordenadas en x e y.
{

	switch (c)
	{
	case 'A': case 'a':
		pieza->set_x(-30);
		break;

	case 'D': case 'd':
		pieza->set_x(30);
		break;

	case 'S': case 's':
		pieza->set_y(-30);
		break;

	case 'W': case 'w':
		pieza->set_y(30);
		break;
	case ' ': 
		pieza->rotar();
		
		for (int i = 0; i < 4; i++)
		{
			pieza->calcular_posicion_x(1);
		}

		break;


	default:
		break;
	}

}

void juego::actualizar()
{
	//tiempos 60 fps por segundo
	static float tiempo_transcurrido = 0;
	static float actulizar_cuadrado = 0;
	//cuadrado* ob2 = new cuadrado();

	//if (glutGet(GLUT_ELAPSED_TIME) - (tiempo_transcurrido + 1.f/fps) > 0)
	if ((glutGet(GLUT_ELAPSED_TIME) > tiempo_transcurrido + 1.f))
	{
		if ( (glutGet(GLUT_ELAPSED_TIME) > actulizar_cuadrado + 1000.f))
		{
			chequear_colision();
			actulizar_cuadrado = glutGet(GLUT_ELAPSED_TIME);
			//ob1->actualizar(); //cuadrado de ejemplo
			
			 // evaluacion de la posicion del cuadrado
			if (pieza->actualizar()) // si colision es verdadera
			{
				//recorre la posicion de cada cuadrado de una figura y guarda su posicion en una lista
				for (int i = 0; i < 4; i++)
				{
					//cuadradosList.push_back(cuadrado(pieza->get_x(i),pieza->get_y(i))); // a la lista cuadradosList se le agrega un cuadrado
					cuadradosList.push_back(cuadrado(pieza->calcular_posicion_x(i), pieza->calcular_posicion_y(i))); // posicion GLOBAL
				}
				//delete pieza;
				pieza = new figura(rand() % 6 + 1); // extraido directamente de figura.h sin declarar la variable en figura.h sino aqui directamente
				cout << "hola que hace" << endl;
			}		
			//objeto1.actualizar();
		}


		tiempo_transcurrido = glutGet(GLUT_ELAPSED_TIME);
		glutPostRedisplay(); // remuestra displya continuamente
		
	}


	
}

void juego::dibujar_tablero() // cuadro central - area de juego
{
	
	//primer imagen a dibujar de ejemplo
	

	//dibujando tablero
	glPushMatrix();
	glTranslatef(-ancho/4, alto/2, 0); // posicionandose en el lado superior izquierdo del nuestro tablero para desde ahi empezar a dibujar
	glColor3f(0, 0, 0);
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

void juego::dibujar_cuadrados()
{
	glColor3f(1, 1, 1);
	list<cuadrado>::iterator p = cuadradosList.begin();
	while (p != cuadradosList.end()) // mientras p no sea el ultimo objeto de la lista
	{
		p->dibujar();
		p++;

	}
}

void juego::chequear_colision()
{

	list<cuadrado>::iterator p = cuadradosList.begin();
	while (p != cuadradosList.end()) // mientras p no sea el ultimo objeto de la lista
	{
		bool hubo_colision = false;
		
		for (int i = 0; i < 4; i++)
		{
			if ((abs(p->get_y() - ((int)pieza->calcular_posicion_y(i) - 30))) < 15)
			{
				if (abs(p->get_x() - (int)pieza->calcular_posicion_x(i)) < 5)
				{
					hubo_colision = true;
				}
			}
		}

		if (hubo_colision)
		{
			for (int i = 0; i < 4; i++)
			{
				//cuadradosList.push_back(cuadrado(pieza->get_x(i),pieza->get_y(i))); // a la lista cuadradosList se le agrega un cuadrado
				cuadradosList.push_back(cuadrado(pieza->calcular_posicion_x(i), pieza->calcular_posicion_y(i))); // posicion GLOBAL
			}

			pieza = new figura(rand() % 6 + 1); // extraido directamente de figura.h sin declarar la variable en figura.h sino aqui directamente

		}


		p++;

	}

}


