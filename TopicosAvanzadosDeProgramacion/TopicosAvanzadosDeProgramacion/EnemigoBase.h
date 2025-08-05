#pragma once


#include <iostream>
using namespace std;
#include <time.h>
#include "ParametrosEnemigo.h"
#include <cstdlib>
#include <ctime>

class EnemigoBase
{
public:
	EnemigoBase(int vidaMaxima, 
	string nombre, 
	int danoDelAtaque,
	float frecuenciaDeAtaque,
	float distanciaDeAtaque,
	int posicionX,
	int posicionY)
	{
		this->vidaMaxima = vidaMaxima;
		this->nombre = nombre;
		this->danoDelAtaque = danoDelAtaque;
		this->frecuenciaDeAtaque = frecuenciaDeAtaque;
		this->distanciaDeAtaque = distanciaDeAtaque;
		this->posicionX = posicionX;
		this->posicionY = posicionY;
		tiempoDeUltimoAtaque = 0;
		vidaActual = vidaMaxima;
	}

	EnemigoBase()
	{ }


	// NO OLVIDEN QUE SEA VIRTUAL
	virtual ~EnemigoBase()
	{

	}

	virtual void Atacar(int xPos, int yPos, int& vidaDeLaUnidad, int tiempoActual) = 0;

	virtual void RecibirDano(int dano)
	{
		vidaActual -= dano;
		if (vidaActual <= 0)
		{
			cout << "enemigo: " << nombre << " murió" << endl;
		}
	}

	// regresa verdadero si ya pasó más de "frecuenciaDeAtaque" tiempo desde "tiempoDeUltimoAtaque"
	bool YaPuedeAtacar(float tiempoActual)
	{
		// time_t timestamp;
		// time(&timestamp);
		// timestamp
		// datos de ejemplo: tiempo actual=9; frecuenciaDeAtaque=3; tiempoDeUltimoAtaque=5;
		if (tiempoActual - frecuenciaDeAtaque >= tiempoDeUltimoAtaque)
		{
			return true; // ya puede atacar porque 
		}
		return false;
	}



protected:
	void InicializarConParametros(ParametrosEnemigo* parametros, int posicionX = 0, int posicionY = 0)
	{
		srand(time(0)); // inicializar la semilla del random para que sí sea random.

		this->posicionX = posicionX;
		this->posicionY = posicionY;

		vidaMaxima = parametros->vidaMinima + (rand() % (parametros->vidaMaxima - parametros->vidaMinima + 1));
		danoDelAtaque = parametros->danoMinimo + (rand() % (parametros->danoMaximo - parametros->danoMinimo + 1));
		frecuenciaDeAtaque = parametros->frecuenciaMinimaAtaque + static_cast<float>(rand()) /
			(static_cast<float>(RAND_MAX / (parametros->frecuenciaMaximaAtaque - parametros->frecuenciaMinimaAtaque)));

		distanciaDeAtaque = parametros->distanciaMinimaAtaque + static_cast<float>(rand()) /
			(static_cast<float>(RAND_MAX / (parametros->distanciaMaximaAtaque - parametros->distanciaMinimaAtaque)));
	}

	// si yo heredo esta clase base que tiene un "número de balas", pero la clase que lo hereda no
	// tiene una pistola, ¿enhtonces para qué quiere un número de balas?
	// int numeroDeBalas;

	int vidaMaxima;
	int vidaActual;
	string nombre;

	int danoDelAtaque;
	float frecuenciaDeAtaque;
	float distanciaDeAtaque;
	float tiempoDeUltimoAtaque;
	int posicionX;
	int posicionY;



};