#pragma once
#include "RClassFactory.h"
class RDynamicClass
{
public:
	RDynamicClass(std::string name, createClass method)
	{
		RClassFactory::sharedFactory().registClass(name, method);
	}
};

#define DECLARE_CLASS(className) static RDynamicClass* m_className##dc;

#define IMPLEMENT_CLASS(className)	\
	RDynamicClass* className::m_className##dc =	\
	new RDynamicClass(#className, className::createInstance);

