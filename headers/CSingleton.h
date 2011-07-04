#ifndef __CSINGLETON_H__
#define __CSINGLETON_H__

#include "../headers/Headers.h"

template<typename T>
class CSingleton
{
	private:
		static T *m_Instance;


	public:
		static T* getSingleton(){
			if( !m_Instance ){
				m_Instance = new T;
			}
			return m_Instance;
		}
};

template<typename T>
T* CSingleton<T>::m_Instance 	= 0;

#endif
