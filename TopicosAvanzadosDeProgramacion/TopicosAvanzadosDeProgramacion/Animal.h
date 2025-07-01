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
		ItsAnimalPrivate();
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



public:
	// Como es p�blica, se puede mandar a llamar dentro de cualquier scope.
	bool ItsAnimalPublic() { return true; };

	// Una funci�n const quiere decir que el objeto/instancia que la mande a llamar
	// NO va a modificar ninguno de sus valores durante el c�digo de esa funci�n.
	void Renombrar(string newName) const { /*name = newName; // no te deja porque cambiar�a el name*/ };

	// qu� s� te deja hacer una funci�n const?
	// cualquier cosa que NO modifique al objeto/instancia que la manda a llamar.
	int Multiplicar(int a, int b) const { return a * b; };

	const string NombreMasApellido(string apellido) const
	{
		return name + " " + apellido;
	}

protected:
	// Similitudes entre private y protected:
	// los miembros y funciones private o protected NO se pueden usar fuera del scope de la clase.
	// Ejemplo de esto: S� puedes llamar a esos miembros y funciones DENTRO de funciones de la misma clase
	// pero en ning�n otro lugar.

	// Diferencias entre private y protected.
	// Private solo se pueden usar en el scope de la clase donde se declaran, 
	// mientras que protected se puede adem�s usar en el scope de todas las clases donde se herede

	bool ItsAnimalProtected() { return true; };


private:
	bool ItsAnimalPrivate() { return true; };
};

