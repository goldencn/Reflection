#pragma once
#include "RBaseClass.h"
#include <iostream>

class RDerivedClass: RBaseClass{
private:
	DECLARE_CLASS(RDerivedClass)
public:
	SYNTHESIZE(RDerivedClass, int*, m_pValue)
	RDerivedClass(){}
	virtual ~RDerivedClass(){}
	static void* createInstance() {return new RDerivedClass();}
	virtual void registProperty()
	{
		m_propertyMap.insert(std::pair<std::string, setValue>("setm_pValue", setm_pValue));
	}
	virtual void display(){
		std::cout<< *getm_pValue() << std::endl;
	}
protected:
	int * m_pValue;
};

IMPLEMENT_CLASS(RDerivedClass)