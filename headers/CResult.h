#ifndef __CRESULT_H__
#define __CRESULT_H__

#include "../headers/Headers.h"
#include "../headers/CRow.h"
#include "../headers/CExceptionConnection.h"

class CResult
{
	private:
		PGresult *m_cResult;
		vector<CRow> m_vcRow;

	public:
		CResult(PGresult*);
		bool Load();
		CRow operator[](int i);
		int getLength();
		int getStatus();
};

#endif
