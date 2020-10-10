#include "cuadrado.h"

cuadrado::cuadrado()
{
	pos_x = 0;
	//pos_y = (exportar_alto() / 2)+30;
	pos_y = 330; //*-------------------------------CORREGIR
}
  
void cuadrado::dibujar()
{
	glPushMatrix();
	glTranslated(pos_x, pos_y, 0);
	//Color3f(1,1,0); // el color se asigna segun el id en la funcion dibujar dentro de figura.cpp
	glBegin(GL_QUAD_STRIP);
	glVertex2f(0, 0);
	glVertex2f(30, 0);
	glVertex2f(0, 30);
	glVertex2f(30, 30);


	glEnd();
	glPopMatrix();

}

void cuadrado::actualizar()
{
	pos_y -= 30;
	//cout << "actualizando" << endl; // comprobacion de que funcion esta siendo llamada
}

