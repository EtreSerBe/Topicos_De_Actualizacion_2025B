#include "Singleton.h"


int globalVar = 100;



// le decimos al compilador que esta variable est�tica de la clase Singleton existe, 
// y est� inicializada como nullptr.
// TIENE que ser definida fuera de la declaraci�n/definici�n de la clase.
Singleton* Singleton::instance = nullptr;


// Una manera de acceder a esa instancia �nica (instance).
Singleton& Singleton:: GetInstance()
{
	// el instance se crea tal cual la variable en la primera vez que se le requiera.
	// la primera vez entre a esta funci�n, instance debe ser nullptr, entonces 
	// ah� sabemos que debemos darle new.
	if (instance == nullptr)
	{
		instance = new Singleton();
	}

	return *instance;
}

void Singleton::PrintHello()
{
	cout << "hola, soy el singleton de nombre: " << name << endl;
}

void Singleton::ShutDown()
{
	delete instance;
}