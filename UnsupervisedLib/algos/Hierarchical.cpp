#include "Hierarchical.h"
#include "../util/algo.h"


void subTree::centroid() {
	std::vector<float> n_points;
	for (int i = 0; i < vertexes[0].points.size();++i) n_points.push_back(0);

	for (vertex n : vertexes) {
		for (int i = 0; i < n.points.size(); ++i) n_points[i] += n.points[i];
	}
	for (int i = 0; i < n_points.size(); ++i)
		n_points[i] /= vertexes.size();
	
	this->cent_points = n_points;
}

void subTree::merge(subTree tree) {
	for (vertex n : tree.vertexes) {
		vertexes.push_back(n);
	}

	this->centroid();
}

std::pair<int, int> hierarchicalTree::findTheClosestIndex(const std::vector<subTree>& trees) {
	int consumer = 0, consumed = 0;
	float min_distance = 100000;
	for (int i = 0; i < trees.size(); ++i) {
		float euclid = 0;
		for (int j = i + 1; j < trees.size(); ++j) {
			// Calculate the euclid distance
			euclid = dist::euclid(trees[i].cent_points, trees[j].cent_points);
			// std::cout << "ix: " << trees[i].x << ", iy: " << trees[i].y << ", jx: " << trees[j].x << ", jy: " << trees[j].y << " -> ";
			// euclid = sqrt(pow((trees[i].x - trees[j].x), 2) + pow((trees[i].y - trees[j].y), 2));
			// std::cout << "euclid: " << euclid << "\n";
			if (min_distance > euclid) {
				min_distance = euclid;
				consumer = i;
				consumed = j;
			}
		}
	}

	return std::make_pair(consumer, consumed);
}

void hierarchicalTree::build(const std::vector<std::vector<float>>& data) {
	/*
	first thing to do is make all data node.
	*/
	std::vector<vertex> nodes;
	int it = 0;
	for (const std::vector<float>& d : data) {
		nodes.push_back(vertex(d,it++));
	}

	// Make all nodes a subTree
	std::vector<subTree> trees;
	for (vertex n : nodes) trees.push_back(subTree(n));

	// In here algorithm starts.
	// Execute the algorithm n-1 times
	int limit = data.size() - 1;
	tree.push_back(trees);
	int tree_iterator = 0;

	while (limit-- > 0 ) {
		std::pair<int, int> cos_cod = findTheClosestIndex(tree[tree_iterator]);
		// std::cout << "First: " << cos_cod.first << ", Second: " << cos_cod.second << "\n";

		subTree t = trees[cos_cod.first];
		t.merge(trees[cos_cod.second]);
		trees.erase(trees.begin() + cos_cod.first);
		trees.erase(trees.begin() + cos_cod.second - 1);
		trees.push_back(t);
		tree.push_back(trees);
		tree_iterator++;
	}

	// Print the bigtree
	int generation = 0;
	for (const std::vector<subTree>& t : tree) {
		std::cout << "-------------\n";
		std::cout << "********************** " << generation++ << ". GENERATION *************************\n";
		for (const subTree& sT : t) {
			// Print Node's in subTree
			std::cout << "{";
			for (int i = 0; i < sT.vertexes.size(); ++i) std::cout << sT.vertexes[i].id << ", ";
			/*
			for (const vertex& n : sT.vertexes) {
				std::cout << " (";
				for (int i = 0; i < n.points.size(); ++i) std::cout << n.points[i] << ", ";
				std::cout <<  ") ";
			}
			*/
			std::cout << "}\n";
		}
	}
}

