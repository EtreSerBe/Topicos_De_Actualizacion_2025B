#pragma once


#include <iostream>
using namespace std;

// Clase padre (clase base llamada a veces)
class Animal
{
public:
	Animal()
	{ 
		cout << " estoy en el constructor de un Animal " << endl;
		name = "Cuca";
	}

	virtual ~Animal()
	{
		cout << " estoy en el destructor de un Animal " << endl;
	}

	string name;

	string ObtenerNombre() { return name; };

	virtual string Sonido() { return "sin definir"; };

	// Funci�n virtual PURA, es decir, que no tiene una definici�n en la clase padre, 
	// y es FORZOSO que las clases hijas le hagan un override y la implementen, si no no 
	// se podr�n instanciar.
	virtual int NumeroDePatas() = 0;
};

