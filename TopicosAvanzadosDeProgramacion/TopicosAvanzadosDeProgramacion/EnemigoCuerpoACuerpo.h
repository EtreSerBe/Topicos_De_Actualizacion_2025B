#pragma once
#include "EnemigoBase.h"


#include <math.h>

class EnemigoCuerpoACuerpo :
    public EnemigoBase
{
public:
    EnemigoCuerpoACuerpo(int vidaMaxima,
        string nombre,
        int danoDelAtaque,
        float frecuenciaDeAtaque,
        float distanciaDeAtaque,
        int posicionX,
        int posicionY) : EnemigoBase(vidaMaxima, nombre, danoDelAtaque, 
            frecuenciaDeAtaque, distanciaDeAtaque, posicionX, posicionY)
    {
        reduccionDeDano = 2;
    }

    ~EnemigoCuerpoACuerpo() override = default;


    void Atacar(int xPos, int yPos, int &vidaDeLaUnidad, int tiempoActual) override
    {
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

    void RecibirDano(int dano) override
    {
        int danoReal = dano - reduccionDeDano;
        // evitamos que el daño real se vaya a negativos, porque si no incrementaría su vida
        // actual cuando la reducción de daño sea mayor que el daño recibido
        if (danoReal < 0) 
        {
            danoReal = 0;
        }

        vidaActual -= dano;
        if (vidaActual <= 0)
        {
            cout << "enemigo: " << nombre << " murió" << endl;
        }
    }

    // A mí se me ocurre que puede tener armadura que reduce el daño recibido en 1.
    int reduccionDeDano;




};

