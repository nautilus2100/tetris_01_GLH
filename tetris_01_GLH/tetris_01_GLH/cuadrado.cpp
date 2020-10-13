#include "cuadrado.h"

cuadrado::cuadrado()
{
	//pos_x = 0; // antigua posicion, cuando no se necesitaba matriz local para rotas
	//pos_y = (exportar_alto() / 2)+30;
	//pos_y = 330; // antigua posicion, cuando no se necesitaba matriz local para rotas
	pos_x = 0;
	pos_y = 0;
}

cuadrado::cuadrado(double x, double y)
{
	pos_x = x, 
	pos_y = y; 
}
  
void cuadrado::dibujar()
{
	glPushMatrix();

	// Actualiza la rotacion segun el valor que introduce usuario
	switch (rotacionImportada)
	{
	case 0:
		glRotatef(0, 0, 0, 1);
		break;

	case 2:
		glRotatef(90, 0, 0, 1);
		break;
	case 3:
		glRotatef(180, 0, 0, 1);
		break;
	case 4:
		glRotatef(270, 0, 0, 1);
		break;

	default:
		break;
	}




	glTranslated(pos_x, pos_y, 0);
	//Color3f(1,1,0); // el color se asigna segun el id en la funcion dibujar dentro de figura.cpp
	glBegin(GL_QUAD_STRIP);
	glVertex2f(-15, -15);
	glVertex2f(15, -15);
	glVertex2f(-15, 15);
	glVertex2f(15, 15);


	glEnd();
	glPopMatrix();

}

void cuadrado::actualizar()
{
	//pos_y -= 30;
	//cout << "actualizando" << endl; // comprobacion de que funcion esta siendo llamada
}

void cuadrado::set_rotacion(unsigned short num)
{
	rotacionImportada = num;
}

