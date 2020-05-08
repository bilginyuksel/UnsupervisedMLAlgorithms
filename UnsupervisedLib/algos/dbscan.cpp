#include "dbscan.h"

void DBSCAN::fit(const std::vector<std::vector<float>>& data) {
	for (const std::vector<float>& d : data) points.push_back(db_point(d));

	std::cout << "----------- POINTS BEFORE CLUSTERING -------------------\n";
	for (const db_point& s : points) {
		for (int z = 0; z < s.data.size(); ++z) std::cout << s.data[z] << ", ";
		std::cout << "status:" << s.status << "\n";
	}

	int clusterID = 1;
	for (int i = 0; i < points.size(); ++i)
		if (points[i].status == UNCLASSIFIED) if (expandCluster(points[i], clusterID)) clusterID++;

	std::cout << "----------- POINTS AFTER CLUSTERING -------------------\n";
	for (const db_point& s : points) {
		for (int z = 0; z < s.data.size(); ++z) std::cout << s.data[z] << ", ";
		std::cout << "status:" << s.status << "\n";
	}
}


bool DBSCAN::expandCluster(db_point& d, int clusterID) {
	std::vector<int> neighbors = findNeighbors(d);

	if (neighbors.size() < min_points) {
		d.status = NOISE;
		return false;
	}

	int index_core_point = 0;
	for (int i = 0; i < neighbors.size(); ++i) {
		points[neighbors[i]].status = clusterID;
		if (points[neighbors[i]].data == d.data) index_core_point = i;
	}

	neighbors.erase(neighbors.begin() + index_core_point);

	for (int i = 0; i < neighbors.size(); ++i) {
		std::vector<int> subNeighbors = findNeighbors(points[neighbors[i]]);
		if (subNeighbors.size() >= min_points) {
			for (int j = 0; j < subNeighbors.size(); ++j) {
				// Traverse sub neighbors
				if (points[subNeighbors[j]].status == UNCLASSIFIED || points[subNeighbors[j]].status == NOISE) {
					if (points[subNeighbors[j]].status == UNCLASSIFIED)
						neighbors.push_back(subNeighbors[j]);
					points[subNeighbors[j]].status = clusterID;
				}
			}
		}
	}

	return true;
}


std::vector<int> DBSCAN::findNeighbors(db_point& d) {
	std::vector<int> neighbors;
	for (int i = 0; i < points.size(); ++i)
		if (dist::euclid(points[i].data, d.data) <= eps) neighbors.push_back(i);

	return neighbors;
}