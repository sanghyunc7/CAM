#include "headphones.h"

Headphones::Headphones(std::string name, int price, std::string company)
	: Product{ name }, price{ price }, company{ company }
{}

Headphones::Headphones(std::string name, int price)
	: Product{ name }, price{ price }
{}

Headphones::Headphones(std::string name)
	: Product{ name }
{}



ProductType Headphones::getType() {
	return ProductType::HEADPHONES;
}

