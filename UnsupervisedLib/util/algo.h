#ifndef vector
#include <vector>
#endif
#ifndef cmath
#include <cmath>
#endif

#define SIZES_ARE_NOT_EQUAL -1

namespace dist {
	float euclid(
		const std::vector<float>& d,
		const std::vector<float>& d1);
};