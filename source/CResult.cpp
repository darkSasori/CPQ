#include "../headers/CResult.h"

CResult::CResult(PGresult *res)
	: m_cResult(res) {
}

CRow CResult::operator[](int i){
	if( i >= PQntuples(m_cResult) ){
		PQclear(m_cResult);
		throw CExceptionConnection("Nao existe essa linha!");
	}
	else{
		CRow row(i);
		for( int n = 0; n < PQnfields(m_cResult); n++ ){
			row.add( PQfname(m_cResult, n), PQgetvalue(m_cResult, i, n) );
		}
		return row;
	}
	return CRow(0);
}

int CResult::getLength(){
	return PQntuples(m_cResult);
}

int CResult::getStatus(){
	return PQresultStatus(m_cResult);
}
