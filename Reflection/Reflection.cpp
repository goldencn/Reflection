// Reflection.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "RDerivedClass.h"

int _tmain(int argc, _TCHAR* argv[])
{
	RBaseClass* pVar = (RBaseClass*)RClassFactory::sharedFactory().getClassByName("RDerivedClass");
	pVar->registProperty();
	int pValue = 1;
	pVar->m_propertyMap["setm_pValue"](pVar, &pValue);
	pVar->display();
	return 0;
}

