#pragma once

#include <iostream>
using namespace std;

// Clase virtual pura (interface) que nos permite interactuar con el sistema de base de datos que se necesite.
// No tiene mucho sentido.
// Este es un patr�n de dise�o en fachada. Oculta al usuario qu� est� pasando detr�s de escenas, pero 
// permite cambiar c�mo se est�n realizando ciertos procesos pero llam�ndolos de la misma manera sin importar qu�.
class DatabaseInterface 
{
public:
	virtual bool ConectarConBaseDeDatos(string nombreDeBaseDeDatos) = 0;

	virtual bool DesconectarConBaseDeDatos(string nombreDeBaseDeDatos) = 0;

	virtual string* RealizarQuery(string query) = 0;

};

