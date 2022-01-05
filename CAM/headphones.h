#pragma once
#include <string>

#include "product.h"
#include "listing.h"




class Headphones: public Product {
	std::string company;
public:
	int price = 0;

	ProductType getType() override;

	//might convert this to a builder
	Headphones(std::string name, int price, std::string company);
	Headphones(std::string name, int price);
	Headphones(std::string name);
};