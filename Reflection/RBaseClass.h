#pragma once
#include "RDynamicClass.h"
class RBaseClass;

typedef void (*setValue)(RBaseClass *t, void *c);

class RBaseClass{
private:
	DECLARE_CLASS(RBaseClass)
public:
	RBaseClass(){}
	virtual ~RBaseClass(){}
	static void* createInstance() {return new RBaseClass();}
	virtual void registProperty(){}
	virtual void display(){}
	
	std::map<std::string, setValue> m_propertyMap;
};

#define SYNTHESIZE(classType, varType, varName)	\
	public:	\
	inline static void set##varName(RBaseClass *cp, void* value){ \
		classType* tp = (classType*)cp;	\
		tp->varName = (varType)value;	\
}	\
	inline varType get##varName(void) const{	\
	return varName;	\
}

IMPLEMENT_CLASS(RBaseClass)