#ifndef vector
#include <vector>
#endif

#ifndef iostream
#include <iostream>
#endif

#include <iomanip>

class print {
/*Maybe use template classes maybe not it doesn't matter*/
public:
	void dataFrame(
		std::string title,
		const std::vector<std::vector<float>>& data);

	/*
	write functions for already known classes.
	Like K-Means we already built kMeans and this class
	is builtin for this library.
	*/
	void kMeans(const KMeans& k);
};