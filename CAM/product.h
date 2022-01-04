#pragma once
#include <string>

typedef enum {
	HEADPHONES,
	HEADPHONE_AMPLIFIER,
	DACS,
	CABLES,
	SPEAKERS
} ProductType;

class Product {
public:
	std::string name;
	Product(std::string name);
	virtual ProductType getType() = 0;
	virtual ~Product() = 0;
};
