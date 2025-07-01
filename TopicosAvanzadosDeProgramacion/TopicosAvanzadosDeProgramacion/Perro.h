#pragma once


#include "Animal.h" // necesito incluir el archivo donde est� la clase de la cual se va a heredar.
#include "Fungi.h"

#include <iostream>
using namespace std;


class Perro : public Animal // , public Fungi
{
public:
	Perro() 
	{
		cout << " estoy en el constructor de un perro " << endl;
	}

	// IMPORTANTE, PONER VIRTUAL SI EL DESTRUCTOR DE LA CLASE PADRE VA A SER DISTINTO EN ALGUNA DE LAS HIJAS
	// No estoy 100% seguro de si debe llevar override, pero nos ayuda a asegurarnos de que el destructor de la 
	// clase padre S� est� marcado como virtual. Para prop�sitos de esta clase, S� pondremos este override en los destructores.
	~Perro() override
	{
		cout << " estoy en el destructor de un Perro " << endl;
	}

	// Sobreescritura -> Override
	// Es el mecanismo (la forma pues) en que una clase hija le dice a la clase padre que no va
	// a hacer exactamente lo mismo que ella en una funci�n.

	// Sobre override:
	// 1) Permite que la funci�n llamada a trav�s de un puntero de la clase base sea la funci�n de la clase espec�fica, 
	// y no la de la clase base. (incluso en tiempo de ejecuci�n al parecer)
	// 
	// 2) Si no pones virtual, ni override, la funci�n de la clase hija OCULTA la funci�n de la clase padre, lo que puede
	// causar comportamiento inesperado cuando se usan punteros o referencias de la clase base.
	// 
	// 3) Si la funci�n tiene override, pero la de la clase padre no es virtual, el compilador marca error.
	// Eso es bueno para asegurar que no se haga override de funciones que no se deben modificar en clases hijas.
	// 
	// 4) Sin ese override, un typo o un cambio de par�metros en la funci�n podr�a causar que sean dos funciones distintas:
	// por ejemplo Animal.Sonido() y Perro.Soniido() son dos funciones distintas. Usar override te asegurar�a de que est�s
	// invalidando la Sonido de Animal y no creando otra funci�n llamada Soniido.



	virtual string Sonido() override; //  { ItsAnimal();  return "Guauf"; };

	int NumeroDePatas() override { return 4; };


};
