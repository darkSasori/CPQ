#include "../headers/CExceptionConnection.h"

CExceptionConnection::CExceptionConnection(string error, string file, int line)
	:CException(error, file, line)
{
}

void CExceptionConnection::Print(){
	CException::Print();
	CConnection::getSingleton()->Finish();
}
