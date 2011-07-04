#include "../headers/Headers.h"
#include "../headers/CConnection.h"
#include "../headers/CException.h"
#include "../headers/CExceptionConnection.h"
#include "../headers/CResult.h"
#include "../headers/CRow.h"
#include "../headers/CValue.h"
#include "../headers/CLogger.h"

int main(int narg, char **carg){
	try{
		CLogger log("teste.txt");
		log.writeMessage(ERROR_LOG, "teste log");
		CConnection *conn = CConnection::getSingleton();
		conn->Connect("host=localhost dbname=academico user=felipe password=felipe");

		conn->Finish();
	}
	catch(CExceptionConnection e){
		e.Print();
	}
	catch(CException e){
		e.Print();
	}
	return 0;
}
