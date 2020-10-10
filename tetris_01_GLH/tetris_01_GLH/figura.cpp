#include "figura.h"

cuadrado cuadrados[4];

figura::figura(unsigned short num)
{
	id = num; // numero para seleccionar figura a construir

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
	for (int i = 0; i < 4; i++)
	{
		cuadrados[i].actualizar();
	}
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

	//dibuja el conjunto de 4 cuadrados 
	for (int i = 0; i < 4; i++)
	{
		cuadrados[i].dibujar();
	}
}