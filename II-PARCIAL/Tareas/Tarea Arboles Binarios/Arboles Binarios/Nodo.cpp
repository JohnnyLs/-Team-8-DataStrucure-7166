#include "Nodo.h"

void Nodo::setDato(int _dato) {
	dato = _dato;
}

void Nodo::setIzquierda(Nodo* _izquierda) {
	izquierda = _izquierda;

}
void Nodo::setDerecha(Nodo* _derecha) {
	derecha = _derecha;
}
int Nodo::getDato() {
	return dato;
}

Nodo*& Nodo::getIzquierda() {
	return izquierda;
}

Nodo*& Nodo::getDerecha() {
	return derecha;
}
