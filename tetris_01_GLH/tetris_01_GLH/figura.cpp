#include "figura.h"

cuadrado cuadrados[4];

figura::figura(unsigned short num)
{
	id = num; // numero para seleccionar figura a construir
	rotacion = 1; // valor de rotacion
	pos_x2 = 15; // posicion matriz local para rotar
	pos_y2 = 345; // posicion matriz local para rotar

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

bool figura::actualizar() // actualiza posicion automaticamente solo si la posicion es mayor a 15
{
	bool colisiono = false;
	if (pos_y2 > -285) // colision vs pared inferior del tablero
	{
		pos_y2 -= 30;
	}
	else
	{
		colisiono = true;
	}
	return colisiono;
	
	
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

void figura::set_x(double x) // 
{
	if (x > 0)
	{
		if (pos_x2 < 135)
		{
			pos_x2 += x;
		}
		
	}
	else
	{
		if (pos_x2 > -135)
		{
			pos_x2 += x;
			
		}
	}
	

	//antes se movian los cuadros directamente
	/*for (int i = 0; i < 4; i++)
	{
		cuadrados[i].set_x(x);
	}*/

}

bool figura::set_y(double y) // funcion que solo baja si es mayor a 15
{
	bool colisiono = false;

	if (pos_y2 > -285)
	{
		pos_y2 += y;
	}
	else
	{
		colisiono = true; //si hay colicion con el piso devuelve true para preparar lista de cuadrados
	}

	return colisiono;
	

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
