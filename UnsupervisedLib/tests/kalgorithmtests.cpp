#include "kalgorithmtests.h"


k_means_plus kalgorithmtests::kmplus(
	std::vector<std::vector<float>>& data,
	int cluster,
	int max_iteration) {

	k_means_plus k(cluster, max_iteration);
	print disp;

	k.fit(data);

	// Log errors
	disp.print1D("K-means++ errors", k.error_logs);
	disp.dataFrame("K-means++ centroids", k.centroids);
	
	std::vector<std::vector<float>> test{
		{5.1, 2.4,3.2,1.8},{2.3,3.1,5,1.1},{1.1,3.4,5.5,3.2},{4.3,5.5,3.3,1.1}};
	disp.dataFrame("Test Data", test);
	disp.print1D("Predictions",k.predict(test));

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
	disp.print1D("K-median errors", k.error_logs);
	disp.dataFrame("K-median centroids", k.centroids);
	std::vector<std::vector<float>> test{
		{5.1, 2.4,3.2,1.8},{2.3,3.1,5,1.1},{1.1,3.4,5.5,3.2},{4.3,5.5,3.3,1.1} };
	disp.dataFrame("Test Data", test);
	disp.print1D("Predictions", k.predict(test));
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
	disp.print1D("K-means errors", k.error_logs);
	disp.dataFrame("K-means centroids", k.centroids);
	std::vector<std::vector<float>> test{
		{5.1, 2.4,3.2,1.8},{2.3,3.1,5,1.1},{1.1,3.4,5.5,3.2},{4.3,5.5,3.3,1.1} };
	disp.dataFrame("Test Data", test);
	disp.print1D("Predictions", k.predict(test));
	return k;
}
