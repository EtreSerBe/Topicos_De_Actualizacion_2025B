#pragma once
#include "Perro.h"


class Chihuahua :
    public Perro
{
public:

    string Sonido() override { return "Guauf Guauf GuaufGuaufGuaufGuaufGuaufGuauf"; };

};

