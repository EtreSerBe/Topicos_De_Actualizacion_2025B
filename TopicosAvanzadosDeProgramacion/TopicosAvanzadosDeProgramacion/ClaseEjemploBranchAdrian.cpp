

class Alumno
{
public:
	int Progra, Dibujo, Legal;
};

// adrian: funci�n que calcule, asigne e imprima la calificaci�n de progra


// Juanito: funci�n que calcule, asigne e imprima la calificaci�n de Dibujo

void CalcularAsignarEImprimirCaliDeProgra(Alumno& alumno)
{
	// c�lculos y dem�s
	alumno.Progra = 100;

}

int MainEjemplo()
{
	Alumno Pepito;


	CalcularAsignarEImprimirCaliDeProgra(Pepito);


	return 0;

}


