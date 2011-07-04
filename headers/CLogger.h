#ifndef __CLOGGER_H__
#define __CLOGGER_H__

#include "../headers/Headers.h"
#include "../headers/CSingleton.h"
#include "../headers/CException.h"

class CLogger : public CSingleton<CLogger>, ofstream
{
	private:
		string m_sFile;

	public:
		CLogger(string);
		~CLogger();

		void writeMessage(int, string);
};

#endif
