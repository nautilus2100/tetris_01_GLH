#include "figura.h"
#include <cmath>

cuadrado cuadrados[4];

figura::figura(unsigned short num)
{
	id = num; // numero para seleccionar figura a construir
	rotacion = 1; // valor de rotacion
	pos_x = 15; // posicion matriz local para rotar
	pos_y = 345; // posicion matriz local para rotar

	// Se utiliza el switch aqui para construir la figura al principio en el constructor y despues mandarla a dibujar una sola vez
	switch (id)
	{
	case 1: // ele normal
		cout << "figura 1" << endl;
		cuadrados[1].set_x(30) ;
		cuadrados[2].set_x(-30);
		cuadrados[3].set_x(-30);
		cuadrados[3].set_y(30);

		break;

	case 2: // ele invertida
		cout << "figura 2" << endl;
		cuadrados[1].set_x(30);
		cuadrados[2].set_x(-30);
		cuadrados[3].set_x(30);
		cuadrados[3].set_y(30);
		break;

	case 3: // te invertida
		cout << "figura 3" << endl;
		cuadrados[1].set_x(30);
		cuadrados[2].set_x(-30);
		cuadrados[2].set_y(-30);
		cuadrados[3].set_x(0);
		cuadrados[3].set_y(30);
		break;

	case 4: //cubo
		cout << "figura 4" << endl;
		cuadrados[1].set_x(30);
		cuadrados[2].set_x(30);
		cuadrados[2].set_y(30);
		cuadrados[3].set_x(0);
		cuadrados[3].set_y(30);
		break;

	case 5: // ELE minuscula
		cout << "figura 5" << endl;
		cuadrados[0].set_x(30);
		cuadrados[0].set_y(-30);
		cuadrados[1].set_x(30);
		cuadrados[1].set_y(-30);
		cuadrados[2].set_x(-30);
		cuadrados[3].set_x(-60);
		//cuadrados[3].set_y(30);
		break;

	case 6:
		cout << "figura 6" << endl;
		cuadrados[1].set_x(-30);
		cuadrados[2].set_y(30);
		cuadrados[3].set_x(30);
		cuadrados[3].set_y(30);
		break;

	default:
		break;
	}
}

bool figura::actualizar() // actualiza posicion automaticamente solo si la posicion es mayor a 15
{
	bool colisiono = false;

	for (int i = 0; i < 4; i++)
	{
		if ((int)calcular_posicion_y(i) > -280) // colision vs pared inferior del tablero
		{
			pos_y -= 30;
		}
		else
		{
			colisiono = true;
		}

	}

	if (!colisiono) // si NO colisiono
	{
		pos_y -= 30;
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

	case 6:
		glColor3f(0, 1, 0);
		break;

	default:
		break;
	}
	// Actualiza la rotacion segun el valor que introduce usuario

	//dibuja el conjunto de 4 cuadrados dentro de una matriz local a 330 hacia arriba del centro de la pantalla
	glPushMatrix();
	glTranslatef(pos_x, pos_y, 0);
	for (int i = 0; i < 4; i++)
	{
		cuadrados[i].dibujar();
	}
	glPopMatrix();
}

void figura::set_x(double x) // 
{
	cout << x << endl;
	if (x > 0)
	{
		if (pos_x < 135)
		{
			pos_x += x;
		}
		
	}
	else
	{
		if (pos_x > -135)
		{
			pos_x += x;
			
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
	cout << y << endl;

	if (pos_y > -285)
	{
		pos_y += y;
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

//Funcion para rotacion obtener rotacion global  
double figura::get_angulo_cuadradito(unsigned short num)
{
	double angulo_cuadrado = atan2f(cuadrados[num].get_y(),cuadrados[num].get_x()); // angulo local cuadradito
	
	//cout << rad2deg(angulo_cuadrado) << endl; // pasar de grados a radianes viene de nuestra funcion creada
	
	double rotacion_local = (rotacion - 1) * 90.0; // angulo local de conjunto de cuadraditos (figura)

	//cout << rad2deg(angulo_cuadrado) + rotacion_local << endl; // pasar de grados a radianes viene de nuestra funcion creada

	return angulo_cuadrado + deg2rad(rotacion_local);

}

double figura::get_x(unsigned short num)
{
	return cuadrados[num].get_x()+ pos_x; 
}

double figura::get_y(unsigned short num)
{
	return cuadrados[num].get_y()+pos_y;
}

double figura::calcular_posicion_x(unsigned short num)
{
	double hipotenusa;

	hipotenusa = sqrt((pow((cuadrados[num].get_x() ), 2))+(pow((cuadrados[num].get_y() ),2)));
	
	
	return cos(get_angulo_cuadradito(num))*hipotenusa+pos_x;


}

double figura::calcular_posicion_y(unsigned short num)
{
	double hipotenusa;

	hipotenusa = sqrt((pow((cuadrados[num].get_x()), 2)) + (pow((cuadrados[num].get_y()), 2)));


	return sin(get_angulo_cuadradito(num)) * hipotenusa + pos_y;
}


	

