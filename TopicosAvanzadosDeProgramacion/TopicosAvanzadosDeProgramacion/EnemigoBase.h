#pragma once


#include <iostream>
using namespace std;
#include <time.h>

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