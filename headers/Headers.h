#ifndef __HEADERS_H__
#define __HEADERS_H__

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

// Postgres
#include "../lib/postgres/include/libpq-fe.h"

// namespaces
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ofstream;

enum LOGGER_TYPE {
	ERROR_LOG = 1,	// [LOG]
	ERROR_FATAL,	// [FATAL ERROR]
	ERROR_WARNING,	// [WARNING]
};
#endif
