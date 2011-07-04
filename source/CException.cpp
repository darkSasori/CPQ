#include "../headers/CException.h"

CException::CException(string error, string file, int line){
	m_sError 	= error;
	m_sFile	 	= file;
	m_iLine 	= line;
}

CException::~CException(){
	delete this;
}

void CException::Print(){
	if( m_sFile != "" ){
		cout << "[ " << m_sFile.c_str();
		if( m_iLine != 0 ){
			cout << m_iLine;
		}
		cout << " ] ";
	}
	cout << m_sError.c_str() << endl;
}
