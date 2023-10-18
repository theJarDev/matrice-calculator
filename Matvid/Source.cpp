#include<iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

using namespace std;

//matrices compuestas
float transformacion[4][4];
float punto[4][1];
float ultima[4][4];
float ultimaUltima[4][4];
int matrices = 0;

float matriz1[10][10];
float matriz2[10][10];
float matrizFinal[10][10];
int m1, n1, m2, n2;

void rellenarMatriz(float** M, int fil, int col);
void sumarMatrices();
void restarMatrices();
void multiplicarMatrices();
void imprimirMatriz(float** M, int fil, int col);
void imprimirMatriz(int** M, int fil, int col);
void matrizxVector();
float condicionFracciones(string valor);
bool ValidarNumeroOFraccion(string valor);
bool verificarNumero(string valor);

void matricesCompuestas();

void multiplicarCompuestas();

void cuaterniones();

void trazadoDeCurvas();

void main() {
	int x;
	Console::CursorVisible = false;
	do
	{
		system("CLS");
		cout << "Seleccione la accion que desea realizar:" << endl;
		cout << "1) Suma de matrices" << endl;
		cout << "2) Resta de matrices" << endl;
		cout << "3) Multiplicacion de matrices" << endl;
		cout << "4) Matriz x vector" << endl;
		cout << "5) Matriz compuesta" << endl;
		cout << "6) Cuaterniones " << endl;
		cout << "7) Trazado de curvas" << endl;
		cout << "8) Salir del programa" << endl;

		cin >> x;

		system("CLS");
		switch (x)
		{

		case 1: //suma de matrices
			cout << "Suma de matrices.\n" << endl;

			sumarMatrices();
			system("Pause>null");

			break;

		case 2: //resta de matrices
			cout << "Resta de matrices.\n" << endl;

			restarMatrices();
			system("Pause>null");

			break;

		case 3: //multiplicacion de matrices
			cout << "Multiplicacion de matrices.\n" << endl;

			multiplicarMatrices();
			system("Pause>null");

			break;

		case 4: //matrizxvector
			cout << "Multiplicacion de matriz por vector.\n" << endl;

			matrizxVector();
			system("Pause>null");

			break;

		case 5: //matrices compuestas

			matricesCompuestas();

			break;

		case 6://cuaternios
			cout << "Cuaterniones.\n" << endl;
			cuaterniones();
			break;

		case 7://trazado de curvas

			trazadoDeCurvas();
			break;

		case 8: //salir del programa
			break;

		default:
			cout << "Error. Operacion invalida. Seleccione una opcion del menu" << endl;
			system("pause");
			break;
		}

	} while (x != 8);

}

void matricesCompuestas() {

	float s1, s2, s3, angulo, rad;
	float t1, t2, t3;

	int n;

	do {

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				transformacion[i][j] = 0;

			}
		}

		system("cls");
		cout << "No. de transformaciones hechas:" << matrices << ".\n" << endl;
		cout << "Su matriz compuesta final es: " << endl;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				cout << ultima[i][j] << "  ";
			}
			cout << "\n";
		}
		cout << "Seleccione la accion a realizar: " << endl;
		cout << "1)Ingresar matriz de escalacion" << endl;
		cout << "2)Ingresar matriz de traslacion" << endl;
		cout << "3)Ingresar matriz de rotacion" << endl;
		cout << "4)Hacer una operacion con las matrices ingresadas anteriormente" << endl;
		cout << "5)Salir" << endl;
		cin >> n;

		switch (n) {
		case 1: {
			system("cls");

			cout << "Ingrese sus parametros de escalacion" << endl;
			cout << "-En x:" << endl; cin >> s1;
			cout << "-En y:" << endl; cin >> s2;
			cout << "-En z:" << endl; cin >> s3;
			cout << "\n";

			transformacion[0][0] = s1;
			transformacion[1][1] = s2;
			transformacion[2][2] = s3;
			transformacion[3][3] = 1;

			cout << "Su matriz se genero con exito: " << endl;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					cout << transformacion[i][j] << "  ";
				}
				cout << "\n";
			}

			multiplicarCompuestas();

			system("pause");

		}
			  break;//Escalacion
		case 2: {
			system("cls");


			cout << "Ingrese sus parametros de traslacion" << endl;
			cout << "-En x:" << endl; cin >> t1;
			cout << "-En y:" << endl; cin >> t2;
			cout << "-En z:" << endl; cin >> t3;
			cout << "\n";
			transformacion[0][0] = 1;
			transformacion[1][1] = 1;
			transformacion[2][2] = 1;
			transformacion[3][3] = 1;
			transformacion[0][3] = t1;
			transformacion[1][3] = t2;
			transformacion[2][3] = t3;

			cout << "Su matriz se genero con exito: " << endl;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					cout << transformacion[i][j] << "  ";
				}
				cout << "\n";
			}

			multiplicarCompuestas();
			system("pause");

		}
			  break;//Traslacion
		case 3: {
			system("cls");

			cout << "Seleccione el eje de rotacion" << endl;
			cout << "1)En x" << endl;
			cout << "2)En y" << endl;
			cout << "3)En z" << endl;
			cin >> n;

			switch (n) {
			case 1: {
				system("cls");

				cout << "Rotacion en X\n" << endl;
				cout << "Ingrese su angulo de rotacion: ";
				cin >> angulo;
				cout << "\n";

				rad = angulo * (M_PI / 180);

				transformacion[0][0] = 1;
				transformacion[1][1] = cos(rad);
				transformacion[1][2] = -sin(rad);
				transformacion[2][1] = sin(rad);
				transformacion[2][2] = cos(rad);
				transformacion[3][3] = 1;

				cout << "Su matriz se genero con exito: " << endl;
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						cout << transformacion[i][j] << "  ";
					}
					cout << "\n";
				}

				multiplicarCompuestas();
				system("pause");
			}
				  break;

			case 2: {
				system("cls");

				cout << "Rotacion en Y\n" << endl;
				cout << "Ingrese su angulo de rotacion: ";
				cin >> angulo;
				cout << "\n";

				rad = angulo * (M_PI / 180);
				transformacion[0][0] = cos(rad);
				transformacion[0][2] = sin(rad);
				transformacion[1][1] = 1;
				transformacion[2][0] = -sin(rad);
				transformacion[2][2] = cos(rad);
				transformacion[3][3] = 1;

				cout << "Su matriz se genero con exito: " << endl;
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						cout << transformacion[i][j] << "  ";
					}
					cout << "\n";
				}

				multiplicarCompuestas();
				system("pause");
			}
				  break;

			case 3: {
				system("cls");

				cout << "Rotacion en Z\n" << endl;
				cout << "Ingrese su angulo de rotacion: ";
				cin >> angulo;
				cout << "\n";
				rad = angulo * (M_PI / 180);
				transformacion[0][0] = cos(rad);
				transformacion[0][1] = -sin(rad);
				transformacion[1][1] = cos(rad);
				transformacion[1][0] = sin(rad);
				transformacion[2][2] = 1;
				transformacion[3][3] = 1;

				cout << "Su matriz se genero con exito: " << endl;
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						cout << transformacion[i][j] << "  ";
					}
					cout << "\n";
				}

				multiplicarCompuestas();
				system("pause");
			}
				  break;

			default:
				cout << "Error. Operacion invalida. Seleccione una opcion del menu" << endl;
				system("pause");
				break;
			}

		}
			  break;//Rotaciones
		case 4: {
			system("cls");

			cout << "Su matriz compuesta final es: " << endl;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					cout << ultima[i][j] << "  ";
				}
				cout << "\n";
			}
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					ultimaUltima[i][j] = ultima[i][j];
				}
			}

			system("pause");
			do {
				system("cls");
				cout << "Ingrese los datos de su punto" << endl;
				cout << "-En x:" << endl; cin >> punto[0][0];
				cout << "-En y:" << endl; cin >> punto[1][0];
				cout << "-En z:" << endl; cin >> punto[2][0];
				punto[3][0] = 1;

				int cont = 0;
				float acum = 0;
				cout << "Resultado: " << endl;
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 1; j++)
					{
						for (cont = 0, acum = 0; cont < 4; cont++)
						{
							acum = acum + ultimaUltima[i][cont] * punto[cont][j];
						}

						matrizFinal[i][j] = acum;
						cout << matrizFinal[i][j] << "  ";
					}
					cout << "\n";
				}


				cout << "¿Desea ingresar otro punto?" << endl;
				cout << "1)Si     2)No" << endl;
				cin >> n;
			} while (n == 1);

			//se reinician los valores a 0

			matrices = 0;


			system("pause"); }
			  break;//Operacion con puntos
		case 5: {
			system("cls");
			cout << "Adios..." << endl;
			//se reinician los valores a 0
			matrices = 0;

			system("PAUSE");
		}
			  break;//Salir
		default:
			cout << "Error. Operacion invalida. Seleccione una opcion del menu" << endl;
			system("pause");
			break;
		}
	} while (n != 5);
}

void multiplicarCompuestas() { //agregar un switch
	switch (matrices) {
	case 0: {

		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				ultima[i][j] = transformacion[i][j];
			}
		}

		matrices = 1;
	} break;
	case 1: {

		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				ultimaUltima[i][j] = ultima[i][j];
			}
		}
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				ultima[i][j] = 0;
			}
		}

		int cont = 0;
		float acum = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (cont = 0, acum = 0; cont < 4; cont++)
				{
					acum = acum + transformacion[i][cont] * ultimaUltima[cont][j];
				}

				ultima[i][j] = acum;

			}
		}
		matrices = 2;
	}break;
	case 2: {

		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				ultimaUltima[i][j] = ultima[i][j];
			}
		}
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				ultima[i][j] = 0;
			}
		}

		int cont = 0;
		float acum = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (cont = 0, acum = 0; cont < 4; cont++)
				{
					acum = acum + transformacion[i][cont] * ultimaUltima[cont][j];
				}

				ultima[i][j] = acum;

			}
		}

		matrices = 3;
	}break;
	case 3: {

		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				ultimaUltima[i][j] = ultima[i][j];
			}
		}
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				ultima[i][j] = 0;
			}
		}

		int cont = 0;
		float acum = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (cont = 0, acum = 0; cont < 4; cont++)
				{
					acum = acum + transformacion[i][cont] * ultimaUltima[cont][j];
				}

				ultima[i][j] = acum;

			}
		}

		matrices = 4;
	}break;
	case 4: {

		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				ultimaUltima[i][j] = ultima[i][j];
			}
		}
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				ultima[i][j] = 0;
			}
		}

		int cont = 0;
		float acum = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (cont = 0, acum = 0; cont < 4; cont++)
				{
					acum = acum + transformacion[i][cont] * ultimaUltima[cont][j];
				}

				ultima[i][j] = acum;

			}
		}
		matrices = 5;
	}break;
	case 5: {

		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				ultimaUltima[i][j] = ultima[i][j];
			}
		}
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				ultima[i][j] = 0;
			}
		}

		int cont = 0;
		float acum = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (cont = 0, acum = 0; cont < 4; cont++)
				{
					acum = acum + transformacion[i][cont] * ultimaUltima[cont][j];
				}

				ultima[i][j] = acum;

			}
		}
		matrices = 6;
	}break;
	case 6: {

		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				ultimaUltima[i][j] = ultima[i][j];
			}
		}
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				ultima[i][j] = 0;
			}
		}

		int cont = 0;
		float acum = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (cont = 0, acum = 0; cont < 4; cont++)
				{
					acum = acum + transformacion[i][cont] * ultimaUltima[cont][j];
				}

				ultima[i][j] = acum;

			}
		}
		matrices = 7;
	}break;
	case 7: {

		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				ultimaUltima[i][j] = ultima[i][j];
			}
		}
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				ultima[i][j] = 0;
			}
		}

		int cont = 0;
		float acum = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (cont = 0, acum = 0; cont < 4; cont++)
				{
					acum = acum + transformacion[i][cont] * ultimaUltima[cont][j];
				}

				ultima[i][j] = acum;

			}
		}
		matrices = 8;
	}break;
	default: break;
	}
}

void cuaterniones() {
# define M_PIl   3.141592653589793238462643383279502884L

	float angulo;
	float vector[3];
	float punto[3];
	//rellenar valores
	cout << "Rellene los valores del vector." << endl;
	cout << "Recuerde que:" << endl;
	cout << "1) es la posición en x." << endl;
	cout << "2) es la posición en y." << endl;
	cout << "3) es la posición en z." << endl;
	for (int i = 0; i < 3; i++) {
		cout << "Valor del vector en la posición " << i + 1 << ")" << endl; cin >> vector[i];
	}


	cout << endl << "valor del angulo" << endl;
	cin >> angulo;


	cout << "Rellene los valores del punto." << endl;
	cout << "Recuerde que:" << endl;
	cout << "1) es la posicion en x." << endl;
	cout << "2) es la posicion en y." << endl;
	cout << "3) es la posicion en z." << endl;
	for (int i = 0; i < 3; i++) {
		cout << "Valor del punto en la posición " << i + 1 << ")" << endl; cin >> punto[i];
	}

	//realizar operación
	float v;
	float A;
	float B;
	float C;
	float mg[3][3];
	float s;
	float resultado[3];


	angulo = angulo / 2;


	s = cos(angulo * M_PIl / 180);
	v = sqrt(pow(vector[0], 2) + pow(vector[1], 2) + pow(vector[2], 2));


	A = vector[0] / v;
	B = vector[1] / v;
	C = vector[2] / v;


	A = A * sin(angulo * M_PIl / 180);
	B = B * sin(angulo * M_PIl / 180);
	C = C * sin(angulo * M_PIl / 180);


	mg[0][0] = 1 - 2 * pow(B, 2) - 2 * pow(C, 2);
	mg[0][1] = 2 * A * B - 2 * s * C;
	mg[0][2] = 2 * A * C + 2 * s * B;
	mg[1][0] = 2 * A * B + 2 * s * C;
	mg[1][1] = 1 - 2 * pow(A, 2) - 2 * pow(C, 2);
	mg[1][2] = 2 * B * C - 2 * s * A;
	mg[2][0] = 2 * A * C - 2 * s * B;
	mg[2][1] = 2 * B * C + 2 * s * A;
	mg[2][2] = 1 - 2 * pow(A, 2) - 2 * pow(B, 2);


	for (int m = 0; m < 3; m++) {
		resultado[m] = 0;
		for (int n = 0; n < 3; n++) {
			resultado[m] = mg[m][n] * punto[n] + resultado[m];
		}
	}


	for (int i = 0; i < 3; i++) {
		cout << resultado[i] << ",\t";
	}
	cout << endl;

	system("PAUSE");

}

void trazadoDeCurvas() {
	int num;
	float x1, y1, x2, y2, x, y, dx, dy, p0, r, ry, rx;

	do {
		cout << "Seleccione la accion a realizar: " << endl;
		cout << "1)Trazado de lineas" << endl;
		cout << "2)Trazado de circulos" << endl;
		cout << "3)Trazado de elipses" << endl;
		cout << "4)Salir" << endl;
		cin >> num;

		switch (num)
		{
		case 1: {
			system("cls");
			cout << "Trazado de lineas" << endl;
			cout << "Ingrese sus extremos de la linea:" << endl;
			cout << "Punto 1" << endl;
			cout << "-En x:"; cin >> x1;
			cout << "-En y:"; cin >> y1;
			cout << "Punto 2" << endl;
			cout << "-En x:"; cin >> x2;
			cout << "-En y:"; cin >> y2;

			dx = x2 - x1;
			dy = y2 - y1;

			p0 = (2 * dy) - dx;

			/*cout <<"0 - "<< "( " << x1 << ", " << y1 << " ) parametro :" << p0 << endl;*/

			for (int i = 0; i < dx + 1; i++) {
				cout << i << " - ";
				if (p0 < 0) {

					cout << "( " << x1 << ", " << y1 << " ) parametro :" << p0 << endl;
					x1 = x1 + 1;
					p0 = p0 + (2 * dy);

				}
				else {

					cout << "( " << x1 << ", " << y1 << " ) parametro :" << p0 << endl;
					x1 = x1 + 1;
					y1 = y1 + 1;

					p0 = p0 + (2 * dy) - (2 * dx);

				}

			}
			system("pause");
		}break;
		case 2: {
			system("cls");
			cout << "Trazado de circulo" << endl;
			cout << "Ingrese su radio: "; cin >> r;
			cout << "Ingrese el centro del circulo: " << endl;
			cout << "-En x:"; cin >> x1;
			cout << "-En y:"; cin >> y1;

			x = 0;
			y = r;
			p0 = 1 - r;

			int h = 0;

			do {

				cout << h << " - ";
				if (p0 < 0) {

					cout << "( " << x + x1 << ", " << y + y1 << " ) parametro :" << p0 << endl;
					x = x + 1;
					p0 = p0 + (2 * x) + 1;

				}
				else {

					cout << "( " << x + x1 << ", " << y + y1 << " ) parametro :" << p0 << endl;
					x = x + 1;
					y = y - 1;

					p0 = p0 + (2 * x) + 1 - (2 * y);

				}
				h++;
			} while (x <= y);

			system("pause");

		}break;
		case 3: {
			system("cls");
			cout << "Trazado de Elipse" << endl;
			cout << "Ingrese sus radios" << endl;
			cout << "-En x:"; cin >> rx;
			cout << "-En y:"; cin >> ry;
			cout << "Ingrese el centro de la elipse: " << endl;
			cout << "-En x:"; cin >> x1;
			cout << "-En y:"; cin >> y1;

			x = 0;
			y = ry;

			p0 = pow(ry, 2) - (pow(rx, 2) * ry) + (.25 * pow(rx, 2));

			y2 = 2 * pow(ry, 2) * x;
			x2 = 2 * pow(rx, 2) * y;


			cout << "\nRegion 1: \n";
			int i = 0;

			do {
				cout << i << " - ";
				if (p0 < 0) {

					cout << "( " << x + x1 << ", " << y + y1 << " ) parametro :" << p0 << "   2ry^2x: " << y2 << "  2rx^2y: " << x2 << endl;

					p0 = p0 + (2 * pow(ry, 2) * x + 2 * pow(ry, 2)) + pow(ry, 2);
					x = x + 1;
					y2 = 2 * pow(ry, 2) * x;
					x2 = 2 * pow(rx, 2) * y;
				}
				else {

					cout << "( " << x + x1 << ", " << y + y1 << " ) parametro :" << p0 << "   2ry^2x: " << y2 << "  2rx^2y: " << x2 << endl;

					p0 = p0 + (2 * pow(ry, 2) * x + 2 * pow(ry, 2)) - (2 * pow(rx, 2) * y - 2 * pow(rx, 2)) + pow(ry, 2);
					x = x + 1;
					y = y - 1;
					y2 = 2 * pow(ry, 2) * x;
					x2 = 2 * pow(rx, 2) * y;
				}
				i++;
			} while (y2 < x2);
			cout << i << " - " << "( " << x + x1 << ", " << y + y1 << " ) parametro :" << p0 << "   2ry^2x: " << y2 << "  2rx^2y: " << x2 << endl;


			p0 = pow(ry, 2) * pow((x + .5), 2) + pow(rx, 2) * pow((y - 1), 2) - pow(rx, 2) * pow(ry, 2);

			cout << "\nRegion 2: \n";
			int j = 0;

			do {
				cout << j << " - ";
				if (p0 < 0) {

					cout << "( " << x + x1 << ", " << y + y1 << " ) parametro :" << p0 << "   2ry^2x: " << y2 << "  2rx^2y: " << x2 << endl;

					p0 = p0 + (2 * pow(ry, 2) * x + 2 * pow(ry, 2)) - (2 * pow(rx, 2) * y - 2 * pow(rx, 2)) + pow(rx, 2);
					y = y - 1;
					x = x + 1;
					y2 = 2 * pow(ry, 2) * x;
					x2 = 2 * pow(rx, 2) * y;
				}
				else {

					cout << "( " << x + x1 << ", " << y + y1 << " ) parametro :" << p0 << "   2ry^2x: " << y2 << "  2rx^2y: " << x2 << endl;

					p0 = p0 - (2 * pow(rx, 2) * y - 2 * pow(rx, 2)) + pow(rx, 2);
					y = y - 1;
					y2 = 2 * pow(ry, 2) * x;
					x2 = 2 * pow(rx, 2) * y;
				}
				j++;
			} while (y != 0);
			cout << j << " - " << "( " << x + x1 << ", " << y + y1 << " ) parametro :" << p0 << "   2ry^2x: " << y2 << "  2rx^2y: " << x2 << endl;





			system("pause");
		}break;

		default:cout << "Error. Operacion invalida. Seleccione una opcion del menu" << endl;
			system("pause");
			break;
		}
	} while (num != 4);
}

void rellenarMatriz(float** M, int fil, int col)
{
	string valor;
	cout << "Rellene su matriz:\n";
	for (int i = 0; i < fil; i++) {
		for (int j = 0; j < col; j++) {

			bool esValido = false;
			do {
				cout << "[" << i << "][" << j << "]: ";
				cin >> valor;

				esValido = ValidarNumeroOFraccion(valor);
				if (!esValido) {
					cout << "El numero o fraccion es invalido" << endl;
				}

			} while (!esValido);


			M[i][j] = condicionFracciones(valor);

		}
	}
}

void sumarMatrices()
{
	int fil, col;

	cout << "Las matrices deben tener las mismas dimensiones para ser sumadas" << endl;
	cout << "Introduzca las dimensiones para sus dos matrices:" << endl;
	cout << "Filas" << endl;; cin >> fil;
	cout << "Columnas" << endl; cin >> col;

	float** A = new float* [fil];
	for (int i = 0; i < fil; i++)
		A[i] = new float[col];

	float** B = new float* [fil];
	for (int i = 0; i < fil; i++)
		B[i] = new float[col];

	float** C = new float* [fil];
	for (int i = 0; i < fil; i++)
		C[i] = new float[col];

	cout << "Matriz A: " << endl;;
	rellenarMatriz(A, fil, col);

	cout << "Matriz B: " << endl;;
	rellenarMatriz(B, fil, col);

	for (int i = 0; i < fil; i++)
		for (int j = 0; j < col; j++)
			C[i][j] = A[i][j] + B[i][j];

	cout << "Matriz A:";
	imprimirMatriz(A, fil, col);
	cout << "\nMatriz B:";
	imprimirMatriz(B, fil, col);
	cout << "\nLa suma es: ";
	imprimirMatriz(C, fil, col);

}

void restarMatrices()
{
	int fil, col;

	cout << "Las matrices deben tener las mismas dimensiones para ser sumadas" << endl;
	cout << "Introduzca las dimensiones para sus dos matrices:" << endl;
	cout << "Filas" << endl;; cin >> fil;
	cout << "Columnas" << endl; cin >> col;

	float** A = new float* [fil];
	for (int i = 0; i < fil; i++)
		A[i] = new float[col];

	float** B = new float* [fil];
	for (int i = 0; i < fil; i++)
		B[i] = new float[col];

	float** C = new float* [fil];
	for (int i = 0; i < fil; i++)
		C[i] = new float[col];

	cout << "Matriz A: " << endl;
	rellenarMatriz(A, fil, col);

	cout << "Matriz B: " << endl;
	rellenarMatriz(B, fil, col);

	for (int i = 0; i < fil; i++)
		for (int j = 0; j < col; j++)
			C[i][j] = A[i][j] - B[i][j];

	cout << "Matriz A:";
	imprimirMatriz(A, fil, col);
	cout << "\nMatriz B:";
	imprimirMatriz(B, fil, col);
	cout << "\nLa resta es: ";
	imprimirMatriz(C, fil, col);
}

void multiplicarMatrices()
{
	int filA, colA, filB, colB;

	cout << "El numero de columnas de la matriz A debe ser igual al numero de filas de la matriz B" << endl;

	cout << "Dimensiones de la matriz A:";
	cout << "\nFilas: "; cin >> filA;
	cout << "Columnas: "; cin >> colA;

	float** A = new float* [filA];
	for (int i = 0; i < filA; i++)
		A[i] = new float[colA];

	rellenarMatriz(A, filA, colA);

	cout << "Dimensiones de la matriz B:";
	cout << "\nFilas: "; cin >> filB;
	cout << "\nColumnas: "; cin >> colB;

	float** B = new float* [filB];
	for (int i = 0; i < filB; i++)
		B[i] = new float[colB];

	rellenarMatriz(B, filB, colB);

	float** C = new float* [filA];
	for (int i = 0; i < filA; i++)
		C[i] = new float[colA];

	if (colA == filB) {
		for (int i = 0; i < filA; ++i) {
			for (int j = 0; j < colB; ++j) {
				C[i][j] = 0;
				for (int z = 0; z < colA; ++z)
					C[i][j] += A[i][z] * B[z][j];
			}
		}

		cout << "\nMatriz A:";
		imprimirMatriz(A, filA, colA);
		cout << "\nMatriz B:";
		imprimirMatriz(B, filB, colB);
		cout << "\nLa multiplicación es: " << endl;
		imprimirMatriz(C, filA, colB);

	}
	else
		cout << "\nNo pueden multiplicarse debido a que el numero de columnas de la matriz A con coincide con el de filas de la matriz B" << endl;

}

void matrizxVector()
{
	int fil = 0, colm = 0, valor2 = 0;
	float valorFinal = 0;
	string valor = "a";
	char separador = '/';
	string sentencia = "3/4";
	float fraccion[2];
	int aux = 0;

	cout << "\nDimension de la matriz:";
	cout << "\nFilas: "; cin >> fil;
	cout << "Columnas: "; cin >> colm;

	float** arreglo = new float* [fil];
	float** resultado = new float* [fil];
	for (int i = 0; i < fil; i++)
	{
		arreglo[i] = new float[colm];
		resultado[i] = new float[colm];
	}
	cout << "Rellene su matriz" << endl;
	for (int i = 0; i < fil; i++) {
		for (int j = 0; j < colm; j++) {
			cout << "Matriz[" << i + 1 << "][" << j + 1 << "]: ";
			cin >> valor;

			valorFinal = condicionFracciones(valor);

			arreglo[i][j] = valorFinal;
			resultado[i][j] = 0;
		}
	}
	cout << "\nDimension del vector:";
	int* vector = new int[fil];
	for (int i = 0; i < fil; i++)
	{
		cout << "Vector[" << i + 1 << "]: ";
		cin >> valor2;
		vector[i] = valor2;
	}
	for (int i = 0; i < fil; i++) {
		for (int j = 0; j < colm; j++) {
			resultado[j][i] = vector[i] * arreglo[j][i];
		}
	}
	imprimirMatriz(resultado, fil, colm);
}

void imprimirMatriz(float** M, int fil, int col)
{
	for (int i = 0; i < fil; i++) {

		for (int j = 0; j < col; j++)
			cout << M[i][j] << " ";

		cout << "\n";
	}
	cout << endl;
}

void imprimirMatriz(int** M, int fil, int col)
{
	for (int i = 0; i < fil; i++) {

		for (int j = 0; j < col; j++)
			cout << M[i][j] << " ";

		cout << "\n";
	}
	cout << endl;
}

bool ValidarNumeroOFraccion(string valor)
{

	bool resultado = false;

	int neg = valor.find('-');
	if (neg != std::string::npos)
	{
		if (neg == 0)
		{
			valor = valor.substr(1, valor.length());
		}
	}


	int pos = valor.find('/');
	if (pos == std::string::npos) {

		resultado = verificarNumero(valor);
	}
	else
	{

		string a = valor.substr(0, pos);
		string b = valor.substr(pos + 1, valor.length());

		if (a.length() > 0 && b.length() > 0)
		{
			bool operandoIzqValido = verificarNumero(a);
			bool operandoDerValido = verificarNumero(b);

			if (operandoIzqValido && operandoDerValido)
			{
				float operandoDer = stof(b);

				if (operandoDer != 0.0)
				{
					resultado = true;
				}
			}
		}
	}

	return resultado;
}

bool verificarNumero(string valor) {
	bool resultado = true;

	bool esDigito;
	char element;

	int neg = valor.find('-');
	if (neg != std::string::npos)
	{
		if (neg == 0)
		{
			valor = valor.substr(1, valor.length());
		}
	}


	int pos = valor.find('.');
	if (pos == std::string::npos)
	{
		for (int i = 0; i < valor.length(); i++)
		{
			element = valor[i];
			esDigito = isdigit(element);
			if (!esDigito)
			{
				resultado = resultado && false;
			}
		}
	}
	else
	{


		string enteros = valor.substr(0, pos);
		string decimales = valor.substr(pos + 1, valor.length());

		if (enteros.length() <= 0 || decimales.length() <= 0) {
			resultado = resultado && false;
		}

		for (int i = 0; i < enteros.length(); i++)
		{
			element = enteros[i];
			esDigito = isdigit(element);
			if (!esDigito)
			{
				resultado = resultado && false;
			}
		}


		for (int i = 0; i < decimales.length(); i++)
		{
			element = decimales[i];
			esDigito = isdigit(element);
			if (!esDigito)
			{
				resultado = resultado && false;
			}
		}
	}

	return resultado;
}

float condicionFracciones(string valor)
{
	float valorFinal = 0;




	int pos = valor.find('/');
	if (pos == std::string::npos)
	{

		valorFinal = stof(valor);
	}
	else
	{

		string a = valor.substr(0, pos);
		string b = valor.substr(pos + 1, valor.length());
		float operandoizq = stof(a);
		float operandoder = stof(b);
		valorFinal = operandoizq / operandoder;
	}



	return valorFinal;
}

bool fraccion(char* M[]) {
	for (int i = 0; i < sizeof(M); i++)
	{
		if (strcmp(M[i], "/") == 0)
		{
			return true;
		}
	}
}