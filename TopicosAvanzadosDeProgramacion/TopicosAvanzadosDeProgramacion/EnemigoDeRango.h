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
            cout << "enemigo: " << nombre << " se qued� sin balas en el tiempo: " << tiempoActual << endl;
            return; // no puede atacar si no le quedan balas.
        }

        // si s� va a atacar, le quitamos una bala.
        cantidadDeBalas--;
        tiempoDeUltimoAtaque = tiempoActual;
        cout << "enemigo: " << nombre << " atacando en el tiempo: " << tiempoActual << endl;



        // si la distancia entre la posici�n de este enemigo y la del x,y que llegan como par�metros
        // es menor que la de distanciaDeAtaque, entonces s� atacamos.
        int diffX = posicionX - xPos;
        int diffY = posicionY - yPos;
        float hipotenusa = sqrt((diffX * diffX) + (diffY * diffY)); // ra�z cuadrada de la suma de los cuadrados.
        if (hipotenusa > distanciaDeAtaque)
        {
            // entonces no le pegamos, est� fuera de nuestra distancia de ataque.
            cout << "enemigo: " << nombre << " atac� pero est� fuera de su rango de alcance. Distancia fue: " << hipotenusa << endl;

        }
        else
        {
            // entonces s� le pegamos, y le hacemos da�o.
            vidaDeLaUnidad -= danoDelAtaque;
            cout << "enemigo: " << nombre << " le hizo: " << danoDelAtaque << " de da�o." << endl;

        }
    }

    int cantidadDeBalas;

};

