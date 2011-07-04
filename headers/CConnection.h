#ifndef __CCONNECTION_H__
#define __CCONNECTION_H__

#include "../headers/Headers.h"
#include "../headers/CExceptionConnection.h"
#include "../headers/CResult.h"
#include "../headers/CSingleton.h"
#include "../headers/CLogger.h"

class CResult;
class CConnection : public CSingleton<CConnection>
{	
	private:
		PGconn *m_pgConn;
		string m_sConn;
		vector<string> m_vQuerys;

	public:	
		CConnection();
		virtual ~CConnection();
		ConnStatusType Connect(string str);
		void Finish();
		CResult Query(string sql);
		string getLastError();
		void StartTransiction();
		void Rollback();
		void Commit();
};

#endif
