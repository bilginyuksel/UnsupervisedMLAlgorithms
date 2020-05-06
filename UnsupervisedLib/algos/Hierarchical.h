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

struct vertex {
	std::vector<float> points;

	vertex(std::vector<float> points) {
		this->points = points;
	}
};

class subTree{
public:
	std::vector<vertex> vertexes;
	std::vector<float> cent_points;

	subTree(vertex n) {
		vertexes.push_back(n);
		this->centroid();
	}

	// copy constuctor
	subTree(const subTree& tree) {
		for (const vertex& n : tree.vertexes) vertexes.push_back(n);
		this->centroid();
	}

	void merge(subTree tree);
	friend class hierarchicalTree;

private:
	void centroid();

};

class hierarchicalTree  {

public:
	hierarchicalTree() {
		/*
		Also we can add a parameter to choose which method to use
		while building the tree. Default we're using euclidian distance method.
		But it is easy to change.
		*/
	}
	std::vector<std::vector<subTree>> tree;
	void build(const std::vector<std::vector<float>>& data);

private:
	int n_cluster;
	std::pair<int, int> findTheClosestIndex(const std::vector<subTree>& trees);
};

