#include "../headers/CConnection.h"

CConnection::CConnection(){
}

CConnection::~CConnection(){
}

ConnStatusType CConnection::Connect(string str){
	m_pgConn = PQconnectdb(str.c_str());
	m_sConn = str;
	ConnStatusType ret = PQstatus(m_pgConn);
	if( ret == CONNECTION_BAD )
		throw CExceptionConnection("Nao foi possivel conectar com o servidor!"); 
	return ret;
}

void CConnection::Finish(){
	PQfinish(m_pgConn);
}

CResult CConnection::Query(string sql){
	PGresult *res;

	m_vQuerys.push_back(sql);
	res = PQexec(m_pgConn, sql.c_str());
	if( PQresultStatus(res) == PGRES_FATAL_ERROR ){
		PQclear(res);
		cout << "[MESSAGE] " << CConnection::getSingleton()->getLastError() << endl;
		throw CExceptionConnection("Houve um erro fatal!");
	}

	return CResult(res);
}

string CConnection::getLastError(){
	return string( PQerrorMessage(m_pgConn) );
}
