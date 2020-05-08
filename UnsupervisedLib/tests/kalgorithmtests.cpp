#include "kalgorithmtests.h"


k_means_plus kalgorithmtests::kmplus(
	std::vector<std::vector<float>>& data,
	int cluster,
	int max_iteration) {

	k_means_plus k(cluster, max_iteration);
	print disp;

	k.fit(data);

	// Log errors
	// disp.print1D("K-means++ errors", k.error_logs);
	disp.dataFrame("K-means++ centroids", k.centroids);

	return k;
}

k_median kalgorithmtests::kmedian(
	std::vector<std::vector<float>>& data,
	int cluster,
	int max_iteration) {

	k_median k(cluster, max_iteration);
	print disp;

	k.fit(data);

	// Log errors
	// disp.print1D("K-median errors", k.error_logs);
	disp.dataFrame("K-median centroids", k.centroids);

	return k;
}

KMeans kalgorithmtests::kmeans(
	std::vector<std::vector<float>>& data,
	int cluster,
	int max_iteration) {

	KMeans k(cluster, max_iteration);
	print disp;

	k.fit(data);

	// Log errors
	// disp.print1D("K-means errors", k.error_logs);
	disp.dataFrame("K-means centroids", k.centroids);

	return k;
}
