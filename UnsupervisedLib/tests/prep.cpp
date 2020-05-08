#include "prep.h"

std::vector<std::vector<float>> prepdata::iris() {
	// File path should be absolute
	std::string filename = "C:/Users/bilgi/Downloads/Iris.csv";

	freader s;
	std::vector<std::pair<std::string, std::vector<float>>> irisData = s.read_csv(filename);
	std::vector<std::vector<float>> cleanedIrisData;
	for (const auto& tm : irisData)
	{
		if (tm.first != "Id" && tm.second.size() > 0)
			cleanedIrisData.push_back(tm.second);

	}

	return dcleaner::reverseData(cleanedIrisData);
}


std::vector<std::vector<float>> prepdata::sample(int rows, int columns) {
	std::vector<std::vector<float>> f;

	return f;
}