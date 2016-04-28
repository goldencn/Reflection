#include "stdafx.h"
#include "RClassFactory.h"

void* RClassFactory::getClassByName(std::string name)
{
	std::map<std::string, createClass>::const_iterator ci;
	ci = m_classmap.find(name);
	if(ci == m_classmap.end())
		return NULL;
	else
		return ci->second();
}

void RClassFactory::registClass(std::string name, createClass method)
{
	m_classmap.insert(std::pair<std::string, createClass>(name, method));

}

RClassFactory& RClassFactory::sharedFactory()
{
	static RClassFactory _sharedRCF;
	return _sharedRCF;
}