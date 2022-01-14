/**************++++++++++++++++++++++++++++++++++********************
			  UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
		Pograma: Recursividad de la torre de hanoi
		Autores:
		  -CAIZA Alisson
		  -LOACHAMIN Johnny
		  -SALAZAR Matthew
		  -SALAZAR Dominique
		 Fecha de creación: 2022-01-13
		Fecha de modificación: 2022-01-14
		Versión: V1.0
				  ESTRUCTURA DE DATOS 7166
********************************************************************/

#include <iostream> 
#include "btree.h" 
#define TAMANO 10
using namespace std;
int main()
{
	std::cout << ">>>>ARBOL B<<<<\n";
	int matriz[TAMANO];
	btree arbol(2);
	stclave clave;
	int i;
	int j;
	
	for (i = 0; i < TAMANO; i++) {
		do {
			matriz[i] = rand() % 10000;
			clave.valor = matriz[i];
			clave.registro = i;
		} while (!arbol.Insertar(clave));
	}
	cout << "Mostrar: " << endl;
	arbol.Mostrar();
	cout << "Buscar elemento 23: " << matriz[0] << " posicion: " <<
		arbol.Buscar(matriz[0]) << endl;
	system("PAUSE");


	for (i = 0; i < TAMANO; i++) {
		std::cout << "Borrar: [" << i << "]: " << matriz[i] << endl;
		arbol.Borrar(matriz[i]);
	}
	arbol.Mostrar();
	return 0;
}