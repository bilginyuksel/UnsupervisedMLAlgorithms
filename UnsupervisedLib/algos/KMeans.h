#include <vector>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#ifndef iostream
#include <iostream>
#endif

class KMeans {
private:
	int n_clusters;
	int max_iter;


	std::vector<std::vector<float>> randomize_centroids(
		int n_features);

	float calculateError(
		const std::vector<std::vector<float>>& old_centroids,
		const std::vector<std::vector<float>>& n_centroids);

	std::vector<std::vector<float>> update_centroids(
		const std::vector<std::vector<float>>& data);
public:
	std::vector<std::vector<float>> centroids;
	std::vector<float> error_logs;

	KMeans(int n_clusters, int max_iter) {
		this->n_clusters = n_clusters;
		this->max_iter = max_iter;
	}

	/*
	Fit kmeans unsupervised learning machine learning model.
	It is a train operation for kmeans.
	*/
	void fit(
		const std::vector<std::vector<float>>& data);

	/*
	To predict new data point is belong to which centroid
	Give one data point to the predict function. And it will
	return the predicted centroids ID.
	*/
	int predict(
		const std::vector<float>& t);

	/*
	To predict new set of data points are belong to which centroids
	Give data points to the predict function. And it will
	return the predicted centroid Id list.
	*/
	std::vector<int> predict(
		const std::vector<std::vector<float>>& t);
};

