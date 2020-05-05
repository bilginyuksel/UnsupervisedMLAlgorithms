#include "bagglomerative.h"

void SubTree::centroid() {
	float x = 0, y = 0;
	for (Node n : nodes) {
		x += n.x;
		y += n.y;
	}
	this->x = x / nodes.size();
	this->y = y / nodes.size();
}

void SubTree::merge(SubTree tree) {
	for (Node n : tree.nodes) {
		nodes.push_back(n);
	}

	this->centroid();
}

std::pair<int, int> HierarchicalTree::findTheClosestIndex(const std::vector<SubTree>& trees) {
	int consumer = 0, consumed = 0;
	float min_distance = 100000;
	for (int i = 0; i < trees.size(); ++i) {
		float euclid = 0;
		for (int j = i + 1; j < trees.size(); ++j) {
			// Calculate the euclid distance
			std::cout << "ix: " << trees[i].x << ", iy: " << trees[i].y << ", jx: " << trees[j].x << ", jy: " << trees[j].y << " -> ";
			euclid = sqrt(pow((trees[i].x - trees[j].x), 2) + pow((trees[i].y - trees[j].y), 2));
			std::cout << "euclid: " << euclid << "\n";
			if (min_distance > euclid) {
				min_distance = euclid;
				consumer = i;
				consumed = j;
			}
		}
	}

	return std::make_pair(consumer, consumed);
}

void HierarchicalTree::build(const std::vector<std::vector<float>>& data) {
	/*
	first thing to do is make all data node.
	*/
	std::vector<Node> nodes;
	for (const std::vector<float>& d : data) {
		nodes.push_back(Node(d[0], d[1]));
	}

	// Make all nodes a subTree
	std::vector<SubTree> trees;
	for (Node n : nodes) trees.push_back(SubTree(n));

	// In here algorithm starts.
	// Execute the algorithm n-1 times
	int limit = data.size() - 1;
	tree.push_back(trees);
	int tree_iterator = 0;

	while (limit-- > 0) {
		std::pair<int, int> cos_cod = findTheClosestIndex(tree[tree_iterator]);
		std::cout << "First: " << cos_cod.first << ", Second: " << cos_cod.second << "\n";

		SubTree t = trees[cos_cod.first];
		t.merge(trees[cos_cod.second]);
		trees.erase(trees.begin() + cos_cod.first);
		trees.erase(trees.begin() + cos_cod.second-1);
		trees.push_back(t);
		tree.push_back(trees);
		tree_iterator++;
	}

	// Print the bigtree
	for (const std::vector<SubTree>& t : tree) {
		std::cout << "-------------\n";
		for (const SubTree& sT : t) {
			// Print Node's in subtree
			std::cout << "{";
			for (const Node& n : sT.nodes) std::cout << " (" << n.x << ", " << n.y << ") ";
			std::cout << "}\n";
		}
		std::cout << "-------------\n";
	}
}

