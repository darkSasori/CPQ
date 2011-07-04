compiler 	= g++
output 		= caixa
libsDIR		= lib/postgres/lib
includeDIR	= lib/postgres/include
libs		= pq
flags		= -Wall

all: Caixa

Caixa: Main.o CException.o CExceptionConnection.o CResult.o CRow.o CSingleton.o CConnection.o \
	CValue.o CLogger.o
	$(compiler) $(flags) -o $(output) -L$(libsDIR) -l$(libs) \
		Main.o CConnection.o CException.o CExceptionConnection.o CResult.o CRow.o CSingleton.o \
		CValue.o CLogger.o

Main.o: source/Main.cpp
	$(compiler) $(flags) -c source/Main.cpp

CConnection.o: source/CConnection.cpp
	$(compiler) $(flags) -c source/CConnection.cpp

CException.o: source/CException.cpp
	$(compiler) $(flags) -c source/CException.cpp

CExceptionConnection.o: source/CExceptionConnection.cpp
	$(compiler) $(flags) -c source/CExceptionConnection.cpp

CResult.o: source/CResult.cpp
	$(compiler) $(flags) -c source/CResult.cpp

CRow.o: source/CRow.cpp
	$(compiler) $(flags) -c source/CRow.cpp

CSingleton.o: source/CSingleton.cpp
	$(compiler) $(flags) -c source/CSingleton.cpp

CValue.o: source/CValue.cpp
	$(compiler) $(flags) -c source/CValue.cpp

CLogger.o: source/CLogger.cpp
	$(compiler) $(flags) -c source/CLogger.cpp

rm:
	rm -f *.o

