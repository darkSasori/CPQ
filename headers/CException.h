#ifndef __CEXCEPTION_H__
#define __CEXCEPTION_H__

#include "../headers/Headers.h"

class CException
{
	private:
		string m_sError, m_sFile;
		int m_iLine;

	public:
		CException(string error, string file = "", int line = 0);
		~CException();

		void Print();
};

#endif
