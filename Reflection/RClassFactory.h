#pragma once

using namespace std;

#include <map>
#include <string>

typedef void* (*createClass)();

class RClassFactory{
public:
	RClassFactory(){}
	virtual ~RClassFactory(){}

	void* getClassByName(std::string name);

	void registClass(std::string name, createClass method);

	static RClassFactory& sharedFactory();
private:
	std::map<std::string, createClass> m_classmap;
};
