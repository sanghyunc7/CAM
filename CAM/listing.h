#pragma once

#include "product.h"
#include <chrono>

typedef enum {
	SALE, 
	WANTED,
	TRADE
} ListingType;

class Listing {
	Product product;
public:
	Listing(ListingType listingType, std::string name, std::string link, 
		int price, std::chrono::year_month)
};