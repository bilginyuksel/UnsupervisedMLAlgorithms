#ifndef vector
#include <vector>
#endif

#ifndef iostream
#include <iostream>
#endif

#ifndef utility
#include <utility>
#endif 

#ifndef cmath
#include <cmath>
#endif 

class LSR {
private:
	float gradient, intersection;


public:
	void fit(const std::vector<std::pair<float, float>>& data);
	void displayEquation();
	float predict(const float& x);
};