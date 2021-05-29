#pragma once
#include <iostream>
#include <string>

using namespace std;


class ABNodo
{

private:

	string mensaje; //Almacena la pregunta, o si es nodo hoja, un animal
	ABNodo* nodoNo; //Enlace a nodo por respuesta "no"
	ABNodo* nodoSi; //Enlace a nodo por respuesta "si"

	string preguntaUsuario;
	string input, input2, input3;

public:

	ABNodo(string mensajeNodo); // constructor
	bool esPregunta(); // Devuelve si el nodo es hoja, por lo tanto no es pregunta
	void consultar();
	void actualizarArbol();
	
    string getMensaje();

    void setMensaje(string mensajeNodo);
    void setNodoNo(ABNodo *nodo);
    void setNodoSi(ABNodo* nodo);
 
};