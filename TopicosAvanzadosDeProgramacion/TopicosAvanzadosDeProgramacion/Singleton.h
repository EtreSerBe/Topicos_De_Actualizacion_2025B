#ifndef SINGLETON_H
#define SINGLETON_H 1

#pragma once

#include <iostream>
using namespace std;

extern int globalVar; // la declaramos en el h, pero la definimos en el cpp.

static int statiGlobalVar = 200; // la declaramos en el h, pero la definimos en el cpp.


// Solo puede existir una instancia de esta clase, y debe ser accesible desde cualquier lado.
class Singleton
{
	Singleton()
	{
		cout << "singleton creado." << endl;
		name = "singleton :D";
	}

	~Singleton()
	{
		cout << "singleton destruido." << endl;
	}

public:



	// Una manera de acceder a esa instancia única (instance).
	static Singleton& GetInstance();

	void PrintHello();

	int FuncionConVariableStatic(int valorASumar)
	{
		// Una variable static dentro una función únicamente se le puede asignar valores 
		// todas las veces necesarias PERO solo durante la primera vez que se llama a la función.
		static int staticVar = valorASumar;

		staticVar = 6;

		cout << staticVar + valorASumar;
		return staticVar + valorASumar;
	}

	// Solo debe ser usada cuando estás 100% seguro de que ningún sistema lo está usando.
	static void ShutDown(); 
private:
	static Singleton* instance;

	string name;

};

#endif