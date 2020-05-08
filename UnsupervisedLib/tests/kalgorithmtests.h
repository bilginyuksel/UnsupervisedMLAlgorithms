#include "../algos/kbase.h"
#include "../algos/KMeans.h"
#include "../util/Printer.h"

namespace kalgorithmtests {

	k_means_plus kmplus(std::vector<std::vector<float>>& data,
		int cluster,
		int max_iteration);

	k_median kmedian(std::vector<std::vector<float>>& data,
		int cluster,
		int max_iteration);

	KMeans kmeans(std::vector<std::vector<float>>& data,
		int cluster,
		int max_iteration);
};