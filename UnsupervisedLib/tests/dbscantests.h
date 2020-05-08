#include "../algos/dbscan.h"

namespace dbscantest {

	DBSCAN fit(std::vector<std::vector<float>>& data,
		float eps,
		int min_points);
};