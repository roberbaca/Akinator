#include "juego.h"


Juego::Juego()
{
    nuevaPartida();
    cout << "\nComenzando nueva partida." << endl;
    tree->consultar();

    while (jugarOtraVez())
    {
        cout << "\nPiensa en un animal..." << endl;
        cout << "\nVoy a intentar adivinarlo!" << endl;
        tree->consultar();
    }

    if (!jugarOtraVez())
    {
        cout << "Gracias por jugar!" << endl;
        exit(1);
    }


}

void Juego::nuevaPartida()
{
    /* 
        En la primer partida, debemos "crear" el arbol, ingresando preguntas
        y respuestas asociadas para aumentar el conocimiento de la computadora. 
        La pimera pregunta que ingresemos será el nodo raiz.
    */

    cout << "No encuentro conocimiento previo!" << endl;
    cout << "Inciando un nuevo juego" << endl;

    cout << "\nIngresa una pregunta sobre un animal" << endl;
    string pregunta;
    getline(cin, pregunta);

    cout << "\nIngresa una suposicion si la respuesta es SI" << endl;;
    string suposicionSi;
    getline(cin, suposicionSi);

    cout << "\nIngresa una suposicion si la respuesta es NO" << endl;;
    string suposicionNo;
    getline(cin, suposicionNo);

    tree = new ArbolB(pregunta, suposicionSi, suposicionNo);
 }

bool Juego::jugarOtraVez()
{

    /* 
        Consulta al usuario si quiere volver a jugar. 
        Si la respuesta es SI, la computadora va a utilizar el conomiento nuevo 
        para mejorar.
    */


   cout<<"\n Volver a jugar? (s/n) "<<endl;
   //string respuesta;
   getline(cin, respuesta);
  
   while (respuesta != "s" && respuesta != "n")
   {
       cout << "Por favor responda con ´s´ por SI o ´n´ por NO: " << endl;
       cin >> respuesta;
   }

   if (respuesta == "s")
   {
        return true;
   }

   else if (respuesta == "n")
   {
       return false;
   }
 
}