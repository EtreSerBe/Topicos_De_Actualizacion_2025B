#pragma once
#include "VirtualPura.h"
class OpenGLWrapper :
    public VirtualPura
{
	bool InicializarAPIGrafica() override
	{
		// inicializas el sistema con las reglas de OpenGL
		return true; // si todo sali� bien, return true.
	}

	virtual bool ApagarAPIGrafica() override
	{
		// apagas el sistema con las reglas de OpenGL
		return true; // si todo sali� bien, return true.
	}

	virtual void RenderizarGeometria(/*aqu� ir�an los par�metros de la geometr�a*/) override
	{
	}

};

