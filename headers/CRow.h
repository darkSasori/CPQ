#ifndef __CROW_H__
#define __CROW_H__

#include "../headers/Headers.h"
#include "../headers/CValue.h"

class CRow
{
	private:
		int m_iRow;
		vector<CValue> m_vsName;
		vector<CValue> m_vsValue;

	public:
		CRow(int);
		void add(CValue, CValue);
		string operator[](string);
		string operator[](int);
		
};

#endif
