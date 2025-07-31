#pragma once
#include "Composite.h"
class TextoComposite :
    public Composite
{
public:
    TextoComposite(string name) : Composite(name)
    {
    }

    void Render() override
    {
        cout << "hola, estoy en Render de un textoComposite con nombre: " << name << endl;
    }

};

