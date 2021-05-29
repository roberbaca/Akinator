#include "ABnodo.h"

ABNodo::ABNodo(string mensajeNodo)//Constructor
{
	/*	Declaracion de Nodo, si los punteros a otros nodos son nulos, se trata de una
		respuesta, en caso contrario se trata de una pregunta. */

	mensaje = mensajeNodo;
	nodoNo = NULL;
	nodoSi = NULL;
}


bool ABNodo::esPregunta()
{
	/*
		cuando un nodo tiene sus dos enlaces en NULL, la computadora no tiene más preguntas 
		por hacer y está lista para suponer qué objeto es.
	*/

	if (nodoNo == NULL && nodoSi == NULL)
	{
		return false; // es una hoja
	}

	else
	{
		return true; // no es una hoja
	}

}


void ABNodo::consultar()
{
	// El juego requiere que el jugador responda una pregunta


	if (esPregunta()) // hace la pregunta correspondiente
	{
		cout << mensaje << endl;
		getline(cin, input);

		while (input != "s" && input != "n")
		{
			cout << "Por favor responda con ´s´ por SI o ´n´ por NO: " << endl;
			getline(cin, input);
		}

			
		/*si el jugador responde que sí, la computadora hará la siguiente pregunta con nodoSi‐>consultar(), 
		mostrando en pantalla mensaje, y nodoNo‐>consultar() si el jugador responde que no.*/

		if (input == "s")
		{
			nodoSi->consultar();
		}
		else if(input == "n")
		{
			nodoNo->consultar();
		}
	}

	else // Cuando es un nodo hoja, dispara la suposición mostrando en pantalla mensaje
	{
		cout << "Estabas pensando en un " + mensaje + "? (s/n)" << endl;
		getline(cin, input2);

		while (input2 != "s" && input2 != "n")
		{
			cout << "Por favor responda con ´s´ por SI o ´n´ por NO: " << endl;
			getline(cin, input2);
		}


		if (input2 == "s")
		{
			cout << "ADIVINE !!! \n" << endl; // Si adivina el animal, termina el juego.

		}

		else if (input2 == "n")
				
		/*  si no adivina, se llama al método actualizarArbol(), donde el usuario escribe cuál fue el animal que pensó y una
			característica que distinga al animal pensado del supuesto por la computadora.
		*/

		{
			actualizarArbol();
		}
	}
}

void ABNodo::actualizarArbol()
{

	string objetoUsuario;

	cout << " GANASTE ! no pude adivinar..." << endl;
	cout << "En que animal estabas pensando?:" << endl;
	getline(cin, objetoUsuario); //El usuario ingresa su animal

	cout << "Por favor, ingresa una pregunta que distinga un " << mensaje << " de un " << objetoUsuario << ": " << endl;
	getline(cin, preguntaUsuario); //El usuario ingresa la pregunta asociada

	cout << "Si pensaras en un " << objetoUsuario << " , cual seria la respuesta a esa pregunta?: (s/n)" << endl;
	getline(cin, input3); //El usuario ingresa la respuesta asociada

	while (input3 != "s" && input3 != "n")
	{
		cout << "Por favor responda con 's' por SI o 'n' por NO: " << endl;
		getline(cin, input3);
	}


	//Distingue si es s o n para realizar los enlaces correctos a los nuevos nodos
	if (input3 == "s")
	{
		nodoNo = new ABNodo(mensaje);
		nodoSi = new ABNodo(objetoUsuario);
	}
	else if (input3 == "n")
	{
		nodoSi = new ABNodo(mensaje);
		nodoNo = new ABNodo(objetoUsuario);
	}

	cout << "Gracias! Has expandido mi conocimiento!" << endl;

	mensaje = preguntaUsuario; //La pregunta del usuario es ahora el mensaje del nodo padre actual
}


string ABNodo::getMensaje()
{
	return mensaje;
}

void ABNodo::setMensaje(string mensajeNodo)
{
	mensaje = mensajeNodo;
}

void ABNodo::setNodoNo(ABNodo *nodo)
{
	nodoNo = nodo;
}

void ABNodo::setNodoSi(ABNodo* nodo)
{
	nodoSi = nodo;
}

