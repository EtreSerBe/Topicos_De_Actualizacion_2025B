#pragma once
#include "FactoryEnemigos.h"
#include "EnemigoDeRango.h"

#include <cstdlib>
#include <ctime>

class FactoryEnemigosRango :
    public FactoryEnemigos
{
public:
    FactoryEnemigosRango(int vidaMaxima,
        int vidaMinima,
        int danoMaximo,
        int danoMinimo,
        float frecuenciaMaximaAtaque,
        float frecuenciaMinimaAtaque)
    {
        srand(time(0)); // inicializar la semilla del random para que sí sea random.

        this->vidaMaxima = vidaMaxima;
        this->vidaMinima = vidaMinima;
        this->danoMaximo = danoMaximo;
        this->danoMinimo = danoMinimo;
        this->frecuenciaMaximaAtaque = frecuenciaMaximaAtaque;
        this->frecuenciaMinimaAtaque = frecuenciaMinimaAtaque;
    }

    EnemigoBase* MetodoFabrica() override // importantísimo ponerle el override
    {
        int randomVida = vidaMinima + (rand() % (vidaMaxima - vidaMinima + 1));
        int randomDano = danoMinimo + (rand() % (danoMaximo - danoMinimo + 1));
        float randomFrecuenciaAtaque = frecuenciaMinimaAtaque + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (frecuenciaMaximaAtaque - frecuenciaMinimaAtaque)));

        return new EnemigoDeRango(randomVida, "sniper", randomDano, randomFrecuenciaAtaque, 20, 10, 5);
    }

private:
    int vidaMaxima;
    int vidaMinima;
    int danoMaximo;
    int danoMinimo;
    float frecuenciaMaximaAtaque;
    float frecuenciaMinimaAtaque;


};

