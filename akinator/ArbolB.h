#pragma once
#include <iostream>
#include <string>
#include "ABnodo.h"

using namespace std;

class ArbolB //	�rbol binario que aloja los nodos de tipo ABNodo.
	
{

private:

	ABNodo *nodoRaiz; // debemos crear el nodo raiz

public:

	ArbolB(string pregunta, string suposicionSi, string suposicionNo);
	
	void consultar();

};