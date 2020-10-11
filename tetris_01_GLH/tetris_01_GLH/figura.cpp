#include "figura.h"

cuadrado cuadrados[4];

figura::figura(unsigned short num)
{
	id = num; // numero para seleccionar figura a construir
	rotacion = 1; // valor de rotacion
	pos_x2 = 0; // posicion matriz local para rotar
	pos_y2 = 330; // posicion matriz local para rotar

	// Se utiliza el switch aqui para construir la figura al principio en el constructor y despues mandarla a dibujar una sola vez
	switch (id)
	{
	case 1: // ele normal
		cuadrados[1].set_x(30) ;
		cuadrados[2].set_x(-30);
		cuadrados[3].set_x(-30);
		cuadrados[3].set_y(30);
		break;

	case 2: // ele invertida
		cuadrados[1].set_x(30);
		cuadrados[2].set_x(-30);
		cuadrados[3].set_x(30);
		cuadrados[3].set_y(30);
		break;

	case 3: // te invertida
		cuadrados[1].set_x(30);
		cuadrados[2].set_x(-30);
		cuadrados[3].set_x(0);
		cuadrados[3].set_y(30);
		break;

	case 4: //cubo
		cuadrados[1].set_x(30);
		cuadrados[2].set_x(30);
		cuadrados[2].set_y(30);
		cuadrados[3].set_x(0);
		cuadrados[3].set_y(30);
		break;

	case 5:
		cuadrados[1].set_x(30);
		cuadrados[2].set_x(-30);
		cuadrados[3].set_x(-60);
		//cuadrados[3].set_y(30);
		break;

	default:
		break;
	}
}

void figura::actualizar()
{
	pos_y2 -= 30;
	
	/*for (int i = 0; i < 4; i++)
	{
		cuadrados[i].actualizar();
	}*/
}

void figura::dibujar()
{
	switch (id)
	{
	case 1:
		glColor3f(1, 1, 0);
		break;

	case 2:
		glColor3f(1, 1, 0);
		break;

	case 3:
		glColor3f(1, 0, 1);
		break;

	case 4:
		glColor3f(0,0, 0);
		break;

	case 5:
		glColor3f(1, 0, 0);
		break;

	default:
		break;
	}
	// Actualiza la rotacion segun el valor que introduce usuario

	//dibuja el conjunto de 4 cuadrados dentro de una matriz local a 330 hacia arriba del centro de la pantalla
	glPushMatrix();
	glTranslatef(pos_x2, pos_y2, 0);
	for (int i = 0; i < 4; i++)
	{
		cuadrados[i].dibujar();
	}
	glPopMatrix();
}

void figura::set_x(double x)
{
	pos_x2 += x; // ahora se mueve la posicion de la matriz

	//antes se movian los cuadros directamente
	/*for (int i = 0; i < 4; i++)
	{
		cuadrados[i].set_x(x);
	}*/

}

void figura::set_y(double y)
{
	pos_y2 += y;

	/*for (int i = 0; i < 4; i++)
	{
		cuadrados[i].set_y(y);
	}*/

}

//funcion para rotar la matriz local de las figuras
void figura::rotar()
{
	rotacion++;
	if (rotacion > 4) rotacion = 1; // llevar este dato a cuadrado.cpp para rotar la matriz local
	
	for (int i = 0; i < 4; i++)
	{
		cuadrados[i].set_rotacion(rotacion); // rota cada uno de los cuadros gracias a esta funcion heredada de cuadrado.h
	}

}
