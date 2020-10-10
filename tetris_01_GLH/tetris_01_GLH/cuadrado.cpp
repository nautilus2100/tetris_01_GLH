#include "cuadrado.h"

cuadrado::cuadrado()
{
	pos_x = 0;
	//pos_y = (exportar_alto() / 2)+30;
	pos_y = 0; //*-------------------------------CORREGIR
}

void cuadrado::dibujar()
{
	glPushMatrix();
	glTranslated(pos_x, pos_y, 0);
	glColor3f(1,1,0);
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
	pos_y -= 0.03;
	cout << "actualizando" << endl;
}

