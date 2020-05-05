#include "Hierarchical.h"

void HierarchicalClu::fit(
	const std::vector<std::vector<float>>& data) {
	/*
	1- Make each data point a single-point cluster -> N clusters
	2- Take the two closest data points and make them one cluster -> N-1 clusters
	3- Take the two closest clusters and make them one cluster -> Forms N-2 clusters.
	4- Repeat step-3 until you are left with only one cluster.
	*/
	
	for (const std::vector<float>& d : data) {
		std::vector<Cluster> clusters;
		std::vector<std::vector<float>> f;
		f.push_back(d);
		clusters.push_back(Cluster(f));
	}
}