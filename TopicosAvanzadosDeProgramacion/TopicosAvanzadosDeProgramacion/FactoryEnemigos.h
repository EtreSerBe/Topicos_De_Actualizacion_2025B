#pragma once


#include "EnemigoBase.h"

class FactoryEnemigos
{
	// otras mejoras incluirían el reciclaje de Objetos (Object pooling), 
	// manejar todos los objetos de la clase concreta desde la fábrica concreta.
	// Hacer la fábrica singleton, y así asegurar que solo existe una fábrica de cada clase concreta,
	// y que dicha instancia de la fábrica concreta se puede mandar a llamar desde cualquier parte del código.


public:
	virtual EnemigoBase* MetodoFabrica() = 0; // virtual pura. Podría no serlo, ahorita vemos cuando no lo es.
};