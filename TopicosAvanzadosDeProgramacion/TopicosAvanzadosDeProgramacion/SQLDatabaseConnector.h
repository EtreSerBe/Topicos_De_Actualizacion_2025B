#pragma once
#include "DatabaseInterface.h"
class SQLDatabaseConnector :
	public DatabaseInterface
{
public:
	bool ConectarConBaseDeDatos(string nombreDeBaseDeDatos) override
	{
		// hacer la conexi�n a la base de datos de SQL con el nombre recibido como par�metro.
		return true;
	}

	bool DesconectarConBaseDeDatos(string nombreDeBaseDeDatos) override
	{
		// hacer la desconexi�n a la base de datos de SQL con el nombre recibido como par�metro.
		return true;
	}

	string* RealizarQuery(string query) override 
	{
		string myString;
		// hacer la query a la base de datos de SQL con el query recibido como par�metro.
		return &myString;
	}

};

