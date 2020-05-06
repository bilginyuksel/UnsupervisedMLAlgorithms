#ifndef vector
#include <vector>
#endif

#ifndef iostream
#include <iostream>
#endif

#ifndef time
#include <time.h>
#endif

#ifndef stdlib
#include <stdlib.h>
#endif

class kbase {
public:
	int n_clusters;
	int max_iter;
private:

	virtual std::vector<std::vector<float>> randomize_centroids(
		int n_features,
		const std::vector<std::vector<float>>& data) = 0;

	float calculateError(
		const std::vector<std::vector<float>>& old_centroids,
		const std::vector<std::vector<float>>& n_centroids);

	virtual std::vector<std::vector<float>> update_centroids(
		const std::vector<std::vector<float>>& data) = 0;

public:
	std::vector<std::vector<float>> centroids;
	std::vector<float> error_logs;

	kbase(int n_clusters, int max_iter) {
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

class k_median : public kbase{
public:
	k_median(int n_clusters, int max_iter) : kbase(n_clusters, max_iter){}
private:
	std::vector<std::vector<float>> randomize_centroids(
		int n_features,
		const std::vector<std::vector<float>>& data);

	std::vector<std::vector<float>> update_centroids(
		const std::vector<std::vector<float>>& data);

};


class k_means_plus : public kbase {
public:
	k_means_plus(int n_clusters, int max_iter) : kbase(n_clusters, max_iter) {}
private:
	std::vector<std::vector<float>> randomize_centroids(
		int n_features,
		const std::vector<std::vector<float>>& data);

	std::vector<std::vector<float>> update_centroids(
		const std::vector<std::vector<float>>& data);
};