#include "Perro.h"


// Como esta es la definici�n de una funci�n que est� DENTRO del scope de la clase Perro, 
// entonces tambi�n cuenta como que est� dentro del scope de la clase Perro.
string Perro::Sonido()
{
	// S� se puede mandar a llamar porque Perro es una clase que hereda de Animal, y la funci�n 
	// es protected.
	ItsAnimalProtected();

	// Esta de aqu�, es privada de Animal, por lo tanto no la puedo usar mas que dentro del scope de Animal.
	// ItsAnimalPrivate(); 

	return "Guauf";
}

