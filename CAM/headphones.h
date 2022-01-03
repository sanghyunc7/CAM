#pragma once

#include "product.h"
#include <string>


class Headphones: public Product {
public:
	std::string getType() override;
};