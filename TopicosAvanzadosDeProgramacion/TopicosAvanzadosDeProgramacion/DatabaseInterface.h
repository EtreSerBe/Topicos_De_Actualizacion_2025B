#pragma once

#include <iostream>
using namespace std;

// Clase virtual pura (interface) que nos permite interactuar con el sistema de base de datos que se necesite.
// No tiene mucho sentido.
// Este es un patrón de diseño en fachada. Oculta al usuario qué está pasando detrás de escenas, pero 
// permite cambiar cómo se están realizando ciertos procesos pero llamándolos de la misma manera sin importar qué.
class DatabaseInterface 
{
public:
	virtual bool ConectarConBaseDeDatos(string nombreDeBaseDeDatos) = 0;

	virtual bool DesconectarConBaseDeDatos(string nombreDeBaseDeDatos) = 0;

	virtual string* RealizarQuery(string query) = 0;

};

