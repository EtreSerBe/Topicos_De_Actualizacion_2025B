#pragma once


#include "EnemigoBase.h"

class FactoryEnemigos
{
	// otras mejoras incluir�an el reciclaje de Objetos (Object pooling), 
	// manejar todos los objetos de la clase concreta desde la f�brica concreta.
	// Hacer la f�brica singleton, y as� asegurar que solo existe una f�brica de cada clase concreta,
	// y que dicha instancia de la f�brica concreta se puede mandar a llamar desde cualquier parte del c�digo.


public:
	virtual EnemigoBase* MetodoFabrica() = 0; // virtual pura. Podr�a no serlo, ahorita vemos cuando no lo es.
};