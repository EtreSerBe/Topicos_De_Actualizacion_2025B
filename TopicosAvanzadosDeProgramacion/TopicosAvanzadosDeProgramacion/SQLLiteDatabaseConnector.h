#pragma once
#include "DatabaseInterface.h"
class SQLLiteDatabaseConnector :
    public DatabaseInterface
{
public:
	bool ConectarConBaseDeDatos(string nombreDeBaseDeDatos) override
	{
		// hacer la conexi�n a la base de datos de SQLite con el nombre recibido como par�metro.
		return true;
	}

	bool DesconectarConBaseDeDatos(string nombreDeBaseDeDatos) override
	{
		// hacer la desconexi�n a la base de datos de SQLite con el nombre recibido como par�metro.
		return true;
	}

	string* RealizarQuery(string query) override
	{
		string myString;
		// hacer la query a la base de datos de SQLite con el query recibido como par�metro.
		return &myString;
	}
};

