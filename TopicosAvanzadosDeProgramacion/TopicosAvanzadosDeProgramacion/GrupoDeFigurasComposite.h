#pragma once
#include "Composite.h"

#include <iostream>
#include <vector>
using namespace std;

class GrupoDeFigurasComposite :
    public Composite
{
public:
    GrupoDeFigurasComposite(string name) : Composite(name)
    { }

    vector<Composite*> elementos;

    string otrasCosas;

    void Render() override
    {
        cout << "hola, estoy en Render de del grupo de figuras con nombre: " << name << endl;

        for (int i = 0; i < elementos.size(); i++)
        {
            elementos[i]->Render();
        }

        // hacer otros procedimientos con objetos que no heredan de composite, pero que son importantes
        // de hacer aquí u algo así.
        cout << otrasCosas << endl;
    }

    void AddElement(Composite* element) override
    {
        elementos.push_back(element);
    }

};

