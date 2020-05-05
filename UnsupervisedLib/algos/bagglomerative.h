#ifndef vector
#include <vector>
#endif

#ifndef iostream
#include <iostream>
#endif

#ifndef cmath
#include <cmath>
#endif

#ifndef utility
#include <utility>
#endif

struct Node {
	float x, y;

	Node(float x, float y) {
		this->x = x;
		this->y = y;
	}
};

class SubTree {
public:
	std::vector<Node> nodes;
	float x, y;

	SubTree(Node n) {
		nodes.push_back(n);
		this->centroid();
	}

	// copy constuctor
	SubTree(const SubTree& tree) {
		for (const Node& n : tree.nodes) nodes.push_back(n);
		this->centroid();
	}

	void merge(SubTree tree);

private:
	void centroid();

};

class HierarchicalTree {
public:
	std::vector<std::vector<SubTree>> tree;

	void build(const std::vector<std::vector<float>>& data);

private:
	std::pair<int, int> findTheClosestIndex(const std::vector<SubTree>& trees);
};
