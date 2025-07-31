#pragma once
#include "Composite.h"

#include <iostream>
using namespace std;

class FiguraComposite :
    public Composite
{
public:
    FiguraComposite(string name) : Composite(name)
    {
    }

    void Render() override
    {
        cout << "hola, estoy en Render de una FiguraComposite con nombre: " << name << endl;
    }


};

