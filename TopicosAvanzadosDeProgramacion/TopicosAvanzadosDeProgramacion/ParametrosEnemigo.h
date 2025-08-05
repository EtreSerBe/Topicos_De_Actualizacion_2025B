#pragma once



struct ParametrosEnemigo
{
    ParametrosEnemigo(int vidaMaxima,
        int vidaMinima,
        int danoMaximo,
        int danoMinimo,
        float frecuenciaMaximaAtaque,
        float frecuenciaMinimaAtaque, 
        float distanciaMaximaAtaque,
        float distanciaMinimaAtaque)
    {
        this->vidaMaxima = vidaMaxima;
        this->vidaMinima = vidaMinima;
        this->danoMaximo = danoMaximo;
        this->danoMinimo = danoMinimo;
        this->frecuenciaMaximaAtaque = frecuenciaMaximaAtaque;
        this->frecuenciaMinimaAtaque = frecuenciaMinimaAtaque;
        this->distanciaMaximaAtaque = distanciaMaximaAtaque;
        this->distanciaMinimaAtaque = distanciaMinimaAtaque;
    }

    int vidaMaxima;
    int vidaMinima;
    int danoMaximo;
    int danoMinimo;
    float frecuenciaMaximaAtaque;
    float frecuenciaMinimaAtaque;
    float distanciaMaximaAtaque;
    float distanciaMinimaAtaque;
};

