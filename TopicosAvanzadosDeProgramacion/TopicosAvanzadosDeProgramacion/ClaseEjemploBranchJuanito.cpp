

class Alumno
{
public:
	int Progra, Dibujo, Legal;
};

// adrian: funci�n que calcule, asigne e imprima la calificaci�n de progra

void CalcularAsignarEImprimirCaliDeProgra(Alumno& alumno)
{
	// c�lculos y dem�s
	alumno.Progra = 100;

}

// Juanito: funci�n que calcule, asigne e imprima la calificaci�n de Dibujo

void CalcularAsignarEImprimirCaliDeDibujo(Alumno& alumno)
{
	// c�lculos y dem�s
}

int MainEjemplo()
{

	Alumno Pepito;


	CalcularAsignarEImprimirCaliDeProgra(Pepito);


	// Hola, soy adrian


	CalcularAsignarEImprimirCaliDeDibujo(Pepito);

	return 0;

}




