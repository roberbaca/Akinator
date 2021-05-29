#include "ArbolB.h"

ArbolB::ArbolB(string pregunta, string suposicionSi, string suposicionNo)
{
	nodoRaiz = new ABNodo(pregunta);
	nodoRaiz->setNodoSi(new ABNodo(suposicionSi));
	nodoRaiz->setNodoNo(new ABNodo(suposicionNo));

}

void ArbolB::consultar()
{
	nodoRaiz->consultar();
}