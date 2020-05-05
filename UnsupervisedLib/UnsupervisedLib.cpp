// UnsupervisedLib.cpp : Defines the entry point for the application.
//

#include "UnsupervisedLib.h"
#include "Kmeans.h"


int main()
{
	// Also write example cases and tests for that code.
	// And by the way create file reading util service
	// And also printer service ****** This is important..
	const std::vector<std::vector<float>> d
	{ {1,-1,4},
		{2,3,5},
		{-3,-5,1},
		{12,11,53},
		{1,44,12},
		{3,2,4},
		{7,1,13},
		{-4,10,3},
		{33,-12,-4},
		{-14,1,-3},
		{3,34,-1},
		{-15,13,53},
		{13,4,12} };
	KMeans k(3, 100);
	for (std::vector<float> f : k.centroids) {
		for (int i = 0; i < f.size(); ++i) std::cout << f[i] << " ";
		std::cout << std::endl;
	}
	k.fit(d);
	for (std::vector<float> f : k.centroids) {
		for (int i = 0; i < f.size(); ++i) std::cout << f[i] << " ";
		std::cout << std::endl;
	}
	
	for (float f : k.error_logs)
		std::cout << "Error: " << f << "\n";
	
	std::vector<float> f{ 2,4,1 };
	std::cout << "Prediction : " << k.predict(f)<<"\n";

	for (int kk : k.predict(d)) {
		std::cout << "Prediction : " << kk<<"\n";
	}

	return 0;
}
