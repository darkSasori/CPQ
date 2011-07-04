#include "../headers/CRow.h"

CRow::CRow(int r){
	m_iRow = r;
}

void CRow::add(CValue n, CValue v){
	m_vsName.push_back(n);
	m_vsValue.push_back(v);
}

string CRow::operator[](string n){
	int v = 0;
	for( vector<CValue>::iterator i = m_vsName.begin(); i != m_vsName.end(); i++ ){
		if( *i == n ){
			return m_vsValue[v];
		}
		v++;
	}
	return string("NULL");
}

string CRow::operator[](int i){
	return m_vsValue[i];
}
