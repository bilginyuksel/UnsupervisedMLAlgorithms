#ifndef vector
#include <vector>
#endif
#ifndef map
#include <map>
#endif

class Cluster {
private:
	std::vector<std::vector<float>> nodes;
	std::vector<float> centroid;
	
	std::vector<float> computeCentroids() {
		int n_features = nodes[0].size();
		for (int i = 0; i < n_features; ++i) centroid.push_back(0);
		
		for (int i = 0; i < nodes.size(); ++i) {
			for (int j = 0; j < n_features; ++j)
				centroid[j] += nodes[i][j];
		}

		for (int i = 0; i < n_features; ++i)
			centroid[i] /= nodes.size();

		return centroid;
	}


public:
	Cluster(
		const std::vector<std::vector<float>> n) {
		// Calculate the centroid according to data points.
		this->nodes = n;
		this->centroid = computeCentroids();
	}

	friend class HierarchicalClu;
};

class HierarchicalClu {
private:
	std::vector<std::vector<Cluster>> clusters;
public:
	void fit(const std::vector<std::vector<float>>& data);
};