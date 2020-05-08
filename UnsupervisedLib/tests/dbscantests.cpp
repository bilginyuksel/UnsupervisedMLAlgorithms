#include "dbscantests.h"

DBSCAN dbscantest::fit(std::vector<std::vector<float>>& data,
	float eps,
	int min_points) {

	DBSCAN dbscan(eps, min_points);
	dbscan.fit(data);

	return dbscan;
}