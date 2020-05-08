#include "algo.h"

float dist::euclid(
	const std::vector<float>& d,
	const std::vector<float>& d1) {

	// throw an error if they have not equal element size.
	if (d.size() != d1.size()) throw SIZES_ARE_NOT_EQUAL;

	int len = d.size();
	float euclid = 0;
	for (int i = 0; i < len; ++i)
		euclid += pow(d[0] - d1[0], 2);

	return sqrt(euclid);
}

std::vector<std::vector<float>> dcleaner::reverseData(
	const std::vector<std::vector<float>>& data) {

	std::vector < std::vector<float>> clean;

	for (int i = 0; i < data[0].size(); ++i) {
		std::vector<float> tmp;
		for (int j = 0; j < data.size(); ++j) {
			tmp.push_back(data[j][i]);
		}
		clean.push_back(tmp);
	}
	return clean;
}
