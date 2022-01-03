#pragma once
#include <string>

//pure virtual

class Product {
public:
	//revise?: change the type later to an enum
	virtual std::string getType() = 0;
};
