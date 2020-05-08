#include "agglomerativetests.h"

hierarchicalTree agglomerativetests::buildTree(
	std::vector<std::vector<float>>& data) {

	hierarchicalTree tree;
	tree.build(data);

	return tree;
}