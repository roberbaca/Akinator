#pragma once
#include <iostream>
#include <string>
#include "ArbolB.h"

using namespace std;

class Juego
{
public:

	Juego();

	bool jugarOtraVez();
	void nuevaPartida();


private:

	ArbolB* tree;
	string respuesta;
};