#include "../headers/CLogger.h"

CLogger::CLogger(string file){
	m_sFile = file;
	open(m_sFile.c_str());
	if( bad() )
		throw CException("Nao foi possivel abrir o arquivo de log!");
}

CLogger::~CLogger(){
	close();
}

void CLogger::writeMessage(int code, string msg){
	string error = "";
	int w = 16;
	switch( code ){
		case ERROR_LOG: 	error = "[LOG]"; 		break;
		case ERROR_FATAL: 	error = "[FATAL ERROR]"; 	break;
		case ERROR_WARNING:	error = "[WARNING]";		break;
		default:		error = "[NO ERROR CODE]";	break;
	}
	put(error.c_str());
	w -= error.length();
	width(w);
	put(msg.c_str());
}
