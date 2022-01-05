#pragma once

#include "product.h"
#include <chrono>
#include <memory>

typedef enum class ListingType{
	SALE, 
	WANTED,
	TRADE,
	SERVICE
} ListingType;

class Listing {
	std::shared_ptr<Product> product;
	ListingType listingType;
	std::string link;
	std::chrono::year_month_day ymd;
	
public:
	Listing(ListingType listingType, ProductType productType, std::string name, 
		std::string link, std::chrono::year_month_day ymd);

};