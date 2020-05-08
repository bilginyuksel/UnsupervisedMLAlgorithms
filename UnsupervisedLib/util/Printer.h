#ifndef vector
#include <vector>
#endif

#ifndef iostream
#include <iostream>
#endif

#include <iomanip>

#ifndef PRINTER



#define PRINTER

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
	// void kMeans(const KMeans& k);ü
	const void print1D(const std::string continious_content,
		const std::vector<float>& data);

	const void print1D(const std::string continious_content,
		const std::vector<int>& data);
};

#endif // !PRINTER