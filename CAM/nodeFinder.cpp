#include "nodeFinder.h"
#include <memory>

NodeFinder::NodeFinder()
	: node{ nullptr }, found{ false } {
	artifact = { "", false };
}

void NodeFinder::addToPath(unsigned int index) {
	path.emplace_front(index);
}

void NodeFinder::setDiscovery(std::string item) {
	if (artifact.discoveryFound) return;
	artifact = { item, true };
}

Discovery NodeFinder::getDiscovery() {
	return artifact;
}