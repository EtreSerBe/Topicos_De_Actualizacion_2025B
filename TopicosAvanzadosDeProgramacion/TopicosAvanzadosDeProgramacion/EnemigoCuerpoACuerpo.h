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

    void RecibirDano(int dano) override
    {
        int danoReal = dano - reduccionDeDano;
        // evitamos que el da�o real se vaya a negativos, porque si no incrementar�a su vida
        // actual cuando la reducci�n de da�o sea mayor que el da�o recibido
        if (danoReal < 0) 
        {
            danoReal = 0;
        }

        vidaActual -= dano;
        if (vidaActual <= 0)
        {
            cout << "enemigo: " << nombre << " muri�" << endl;
        }
    }

    // A m� se me ocurre que puede tener armadura que reduce el da�o recibido en 1.
    int reduccionDeDano;




};

