#pragma once

#include <gumbo.h>
#include <string>
#include <deque>



//maybe make this a base class
//have child classes like linkFinder, AdTypeFinder (WANTED, SALE, e.g.), priceFinder
//maybe move the path_to_link algorithm to linkFinder 
//call the function generic like find_path

typedef struct {
	std::string discovery;
	bool discoveryFound;
} Discovery;

class NodeFinder {
	Discovery artifact;
public:
	GumboNode* node;
	std::deque<unsigned int> path;
	bool found;

	NodeFinder();

	void addToPath(unsigned int index);
	void setDiscovery(std::string item);				//will not do anything if discovery is already set
	Discovery getDiscovery();
};