

class Alumno
{
public:
	int Progra, Dibujo, Legal;
};


void CalcularAsignarEImprimirCaliDeProgra(Alumno& alumno)
{
	// c�lculos y dem�s
	alumno.Progra = 100;

}

int MainEjemplo()
{

	Alumno Pepito;


	CalcularAsignarEImprimirCaliDeProgra(Pepito);


	// Hola, soy adrian


	return 0;

}


