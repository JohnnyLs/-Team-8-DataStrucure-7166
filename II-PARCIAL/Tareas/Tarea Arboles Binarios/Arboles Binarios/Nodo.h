#pragma once
#include <iostream>
#include <stdio.h>
using namespace std;
class Nodo
{
	private:
		int dato;
		Nodo* izquierda;
		Nodo* derecha;
	public:
		void setDato(int);
		void setIzquierda(Nodo*);
		void setDerecha(Nodo*);
		int getDato();
		Nodo*& getIzquierda();
		Nodo*& getDerecha();
		/*devuelve la informacion del nodo*/
};

