#pragma once
#include "EnemigoBase.h"

#include <math.h>

class EnemigoDeRango :
    public EnemigoBase
{
public:
    EnemigoDeRango(int vidaMaxima,
        string nombre,
        int danoDelAtaque,
        float frecuenciaDeAtaque,
        float distanciaDeAtaque,
        int posicionX,
        int posicionY) : EnemigoBase(vidaMaxima, nombre, danoDelAtaque, 
            frecuenciaDeAtaque, distanciaDeAtaque, posicionX, posicionY)
    {
        cantidadDeBalas = 2;
    }

    ~EnemigoDeRango() override = default;


    void Atacar(int xPos, int yPos, int& vidaDeLaUnidad, int tiempoActual) override
    {
        if (cantidadDeBalas <= 0)
        {
            cout << "enemigo: " << nombre << " se quedó sin balas en el tiempo: " << tiempoActual << endl;
            return; // no puede atacar si no le quedan balas.
        }

        // si sí va a atacar, le quitamos una bala.
        cantidadDeBalas--;
        tiempoDeUltimoAtaque = tiempoActual;
        cout << "enemigo: " << nombre << " atacando en el tiempo: " << tiempoActual << endl;



        // si la distancia entre la posición de este enemigo y la del x,y que llegan como parámetros
        // es menor que la de distanciaDeAtaque, entonces sí atacamos.
        int diffX = posicionX - xPos;
        int diffY = posicionY - yPos;
        float hipotenusa = sqrt((diffX * diffX) + (diffY * diffY)); // raíz cuadrada de la suma de los cuadrados.
        if (hipotenusa > distanciaDeAtaque)
        {
            // entonces no le pegamos, está fuera de nuestra distancia de ataque.
            cout << "enemigo: " << nombre << " atacó pero está fuera de su rango de alcance. Distancia fue: " << hipotenusa << endl;

        }
        else
        {
            // entonces sí le pegamos, y le hacemos daño.
            vidaDeLaUnidad -= danoDelAtaque;
            cout << "enemigo: " << nombre << " le hizo: " << danoDelAtaque << " de daño." << endl;

        }
    }

    int cantidadDeBalas;

};

