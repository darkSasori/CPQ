#ifndef __CEXCEPTIONCONNECTION_H__
#define __CEXCEPTIONCONNECTION_H__

#include "../headers/Headers.h"
#include "../headers/CException.h"
#include "../headers/CConnection.h"

class CExceptionConnection : public CException
{
	public:
		CExceptionConnection(string error, string file = "", int line = 0);
		void Print();
};

#endif
