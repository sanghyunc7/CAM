#pragma once

#include "product.h"
#include <chrono>
#include <memory>

typedef enum {
	SALE, 
	WANTED,
	TRADE,
	SERVICE
} ListingType;

class Listing {
	std::shared_ptr<Product> product;
	ListingType listingType;
	std::string link;

	
public:
	Listing(ListingType listingType, std::string name, std::string link, std::chrono::year_month_day);

};