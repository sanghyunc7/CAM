#include "listing.h"
#include "headphones.h"
#include "product.h"
#include "exceptionHandler/error.h"
Listing::Listing(ListingType listingType, ProductType productType, std::string name, 
	std::string link, std::chrono::year_month_day ymd)
	: listingType{ listingType }, link{ link }, ymd{ ymd }
{
	switch (productType) {
	case ProductType::HEADPHONES:
		product = std::make_shared<Headphones>(name);
		return;
	default:
		throw Error("This type of Product is not handled by the Listing constructor");
	}
}