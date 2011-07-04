#ifndef __CVALUE_H__
#define __CVALUE_H__

#include "../headers/Headers.h"

class CValue : public string
{
	public:
		CValue(char *);
		const char* toDate(string format);
		int toInt();
		double toDouble();
};

#endif
