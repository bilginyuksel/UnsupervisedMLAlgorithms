#include "lsr.h"

void LSR::displayEquation() {
	std::cout << "y = " << this->gradient << "x + " << this->intersection << "\n";
}

void LSR::fit(const std::vector<std::pair<float, float>>& data) {
	std::vector<std::vector<float>> d;
	float first = 0, second = 0, third = 0, fourth = 0;

	for (const std::pair<float, float>& p : data) {
		std::vector<float> tmp;
		tmp.push_back(p.first); first += p.first;
		tmp.push_back(p.second); second += p.second;
		tmp.push_back(pow(p.first, 2)); third += pow(p.first, 2);
		tmp.push_back(p.first * p.second); fourth += (p.first * p.second);
		d.push_back(tmp);
	}


	// caluclate gradient
	int n = data.size();
	float m = ((n * fourth) - (first * second)) / ((n*third) - (first*first));
	float b = (second - (m * first)) / n;

	this->gradient = m;
	this->intersection = b;
}


float LSR::predict(const float& data) {
	return (gradient * data) + intersection;
}
