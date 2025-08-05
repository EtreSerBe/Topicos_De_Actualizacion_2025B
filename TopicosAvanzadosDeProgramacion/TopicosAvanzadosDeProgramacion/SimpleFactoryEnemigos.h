#pragma once

#include "EnemigoBase.h"
#include "EnemigoDeRango.h"
#include "EnemigoCuerpoACuerpo.h"
#include "ParametrosEnemigo.h"


// Enum o enumeraci�n es algo peculiar.
enum class ETiposDeEnemigos : char
{
	None,  // se le asigna 0 autom�ticamente
	Sniper, // se le asigna 1 autom�ticamente
	Melee, // se le asigna 2, etc.
	// Volador
};
// por defecto, un enum ocupa 4 bytes

// enums de 1 byte, cuando lo que vayan a enumerar tenga 255 posibilidades o menos.


enum class EPokemon : short // necesitar�amos un short (que tiene ~65355 posibles valores) y ocupa 2 bytes.
{
	Bulbasaur,  // se le asigna 0 autom�ticamente
	Ivysaur, // se le asigna 1 autom�ticamente
	Ho_oh = 249, // se le asigna 249 porque se lo asign� manualmente, etc.
	Venasaur // se le asigna el 250 porque est� despu�s del 249
};

// otras cosas muy �tiles con enums son banderas y m�scaras


// una m�scara de bits es un conjunto de bytes (generalmente en grupos de 8 bits) 
// y lo que se hace es tomar los bits de una variable y compararlos con los bits de la m�scara.
// cuando ambos bits son 1 se mantienen, y cuando no, se hacen 0 en el resultado.

// [0, 0, 0, 0, 1, 1, 1, 1] // variable
// [0, 1, 0, 1, 0, 1, 0, 1] // m�scara
// [0, 0, 0, 0, 0, 1, 0, 1] // m�scara de bits de AND. Se le conoce como M�scara de AND.

// Si cualquiera de los 2 es 1, resulta en 1.
// [0, 0, 0, 0, 1, 1, 1, 1] // variable
// [0, 1, 0, 1, 0, 1, 0, 1] // m�scara
// [0, 1, 0, 1, 1, 1, 1, 1] // m�scara de bits de OR. Se le conoce como M�scara de OR.


// Si los valores son distintos, resulta en 1.
// [0, 0, 0, 0, 1, 1, 1, 1] // variable
// [0, 1, 0, 1, 0, 1, 0, 1] // m�scara
// [0, 1, 0, 1, 1, 0, 1, 0] // m�scara de bits de XOR. Se le conoce como M�scara de XOR.


// Si los valores son 0, resulta en 1.
// [0, 0, 0, 0, 1, 1, 1, 1] // variable
// [0, 1, 0, 1, 0, 1, 0, 1] // m�scara
// [1, 0, 1, 0, 0, 0, 0, 0] // m�scara de bits de NAND. Se le conoce como M�scara de NAND.


enum class ECapasDeColision : char
{
	Piso = 0,
	Balas = 2,
	Vision = 4,
	Jugadores = 8,
	Vidrio = 16,
	otro = 32,
	magia = 64,
	camara = 128
};

//class Bala
//{
//	// colisionas con el piso, los jugadores y el vidrio nada m�s.
//	ECapasDeColision objetosConLosQueColisiona = [1, 0, 0, 1, 1, 0, 0, 0];
//};


class SimpleFactoryEnemigos
{
public:
	ETiposDeEnemigos myTipoDeEnemigos; // esto ocupa 4 bytes de espacio en memoria, porque eso ocupa el enum por defecto.

	EnemigoBase* CrearProducto(ETiposDeEnemigos tipoDeEnemigo, ParametrosEnemigo* parametros)
	{
		if (tipoDeEnemigo == ETiposDeEnemigos::Sniper)
			return new EnemigoDeRango(parametros);
		if(tipoDeEnemigo == ETiposDeEnemigos::Melee)
			return new EnemigoCuerpoACuerpo(parametros);
		//if(nombreDeTipoDeEnemigo == �Volador�)
		//	return new EnemigoVolador(parametros);
		return nullptr;
	}


};

