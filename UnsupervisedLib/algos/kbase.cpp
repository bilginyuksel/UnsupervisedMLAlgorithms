#include "kbase.h"
#include "../util/algo.h"

float kbase::calculateError(
	const std::vector<std::vector<float>>& old_centroids,
	const std::vector<std::vector<float>>& n_centroids) {
	// Error situation
	if (old_centroids.size() != n_centroids.size()) throw - 1;
	// Calculate the error between them.
	int len = old_centroids.size();
	float error = 0;
	for (int i = 0; i < len; ++i) error += dist::euclid(old_centroids[i], n_centroids[i]);

	return error;
}

void kbase::fit(const std::vector<std::vector<float>>& data) {

	this->centroids = randomize_centroids(data[0].size(), data);
	float error = 100;
	int iteration = -1;

	while (error != 0 && max_iter >= ++iteration) {
		std::vector<std::vector<float>> old_centroids = centroids;
		this->centroids = this->update_centroids(data);

		error = this->calculateError(
			old_centroids,
			centroids);

		// Store error logs
		error_logs.push_back(error);
	}
}

int kbase::predict(const std::vector<float>& t) {
	// We can control if this vector array has the same length or not
	// Because if the data feature size is not the same with the centroid
	// size it will give an error
	if (centroids.empty() || centroids[0].size() != t.size()) return -1;

	int min_index = 0;
	float min_dist = dist::euclid(t, centroids[0]); // It is like max integer point
	for (int i = 1; i < centroids.size(); i++) {
		float euclid = dist::euclid(t, centroids[i]);
		// std::cout << "Dist: " << dist << "\n";
		if (euclid < min_dist) {
			min_dist = euclid;
			min_index = i;
		}
	}

	return min_index;
}

std::vector<int> kbase::predict(const std::vector<std::vector<float>>& t) {

	std::vector<int> cl;

	for (const std::vector<float>& tmp : t) {
		int min_index = 0;
		float min_dist = dist::euclid(tmp, centroids[0]); // It is like max integer
		for (int i = 1; i < centroids.size(); ++i){
			float euclid = dist::euclid(tmp, centroids[i]);
			if (euclid < min_dist) {
				min_dist = euclid;
				min_index = i;
			}
		}
		cl.push_back(min_index);
	}
	return cl;
}


//******************************************************************
// K-Median implementation

std::vector<std::vector<float>> k_median::randomize_centroids(
	int n_features,
	const std::vector<std::vector<float>>& data) {
	/*
	Randomize centroid points according to
	cluster_size and feature_size.
	To evaluate this method find the min, max data points
	from the actual data.
	*/
	// ------------------------------------------------------
	/*
	Randomize numbers between the largest point of data and the minimum point of data
	----------------------------------------------------------*/
	std::vector<float> min_elements;
	std::vector<float> max_elements;
	for (int i = 0; i < n_features; ++i) {
		min_elements.push_back(data[0][i]);
		max_elements.push_back(data[0][i]);
	}
	for (int i = 1; i < data.size(); ++i) {
		for (int j = 0; j < data[0].size(); ++j) {
			if (data[i][j] < min_elements[j]) min_elements[j] = data[i][j];
			if (data[i][j] > max_elements[j]) max_elements[j] = data[i][j];
		}
	}

	srand(time(NULL));


	std::vector<std::vector<float>> tmp_centroids;
	for (int i = 0; i < n_clusters; ++i) {
		std::vector<float> tmp;
		for (int j = 0; j < n_features; ++j) {
			tmp.push_back(rand() % (int)(max_elements[j] + min_elements[j]) + ((int)min_elements[j]));
		}
		tmp_centroids.push_back(tmp);
	}

	/*
	std::cout << "Temp Centroids\n";
	for (std::vector<float>& t : tmp_centroids) {
		for (int i = 0; i < t.size(); ++i) std::cout << t[i] << " ";
		std::cout << "\n";
	}
	*/

	return tmp_centroids;

}

std::vector<std::vector<float>> k_median::update_centroids(
	const std::vector<std::vector<float>>& data) {
	
	std::vector<std::vector<float>> tmp_cent;
	std::vector<std::vector<int>> cent_data;
	for (int i = 0; i < n_clusters; ++i) cent_data.push_back(std::vector<int>());

	for (int i = 0; i < data.size(); ++i) {
		int min_index = 0;
		float min_dist = dist::euclid(data[i], centroids[0]);
		for (int j = 1; j < centroids.size(); ++j) {
			float euclid = dist::euclid(data[i], centroids[j]);
			if (min_dist > euclid) {
				min_dist = euclid;
				min_index = j;
			}
		}
		cent_data[min_index].push_back(i);
	}
	
	
	// Update centroids
	for (int i = 0; i < cent_data.size(); ++i) {
		int median_index = int(cent_data[i].size() / 2) + 1;
		tmp_cent.push_back( data[median_index]);
	}

	return tmp_cent;
}

// *************************************************************
// K-Means implementation

std::vector<std::vector<float>> k_means_plus::randomize_centroids(
	int n_features,
	const std::vector<std::vector<float>>& data) {
	
	std::vector<std::vector<float>> cent;
	// initialize first centroid
	int random = rand() % data.size();
	cent.push_back(data[random]);

	for (int cluster = 1; cluster < n_clusters; ++cluster) {
		
		// For every center point after the first one
		// generate the farthest center point.
		// To find the farthest point first traverse the data and calculate the
		// distances between the data and the centroids and get the minimum data.
		// So this means find the closest center to that data and store the distance of it.
		// After finish traversing the data list find the maximum distance from distance list.
		// And generate new centroid to there.
		std::vector<float> distances;
		for (int d = 0; d < data.size(); ++d) {

			float min_distance = dist::euclid(data[d], cent[0]); // first min initialization
			for (int c = 1; c < cent.size(); ++c) {
				// Find the min distance between data points
				float euc = dist::euclid(data[d], cent[c]);
				if (min_distance > euc) min_distance = euc;
			}
			// Add the minimum distance to distane list.
			distances.push_back(min_distance);
		}

		// Then find the maximum distance from distance list.
		float max_dist = distances[0];
		int max_dist_index = 0;
		for (int d_index = 1; d_index < distances.size(); ++d_index) {
			// Find max distance
			if (max_dist < distances[d_index]) {
				max_dist = distances[d_index];
				max_dist_index = d_index;
			}
		}
		// Generate new center point
		cent.push_back(data[max_dist_index]);
	}
	
	// Print new center points
	std::cout << "\nGenerated centroids\n";
	for (int i = 0; i < cent.size(); ++i) {
		std::cout << i << ". Centroid\n";
		for (int j = 0; j < cent[i].size(); ++j) std::cout << cent[i][j] << ", ";
		std::cout << "\n";
	}

	return cent;
}

std::vector<std::vector<float>> k_means_plus::update_centroids(
	const std::vector<std::vector<float>>& data) {
	/*
	This method updates this classes centroids accoridng to
	data points.
	To excecute update process first of all we find which data point
	is closest to which centroids and after that we find the new centroid points
	that are summed with the data points closest to that centroid.
	*/

	std::vector<std::vector<float>> tmp_centroids;
	std::vector<int> data_counter;

	// initialize to update asynchronously
	for (int i = 0; i < n_clusters; ++i) {
		std::vector<float> tmp;
		for (int j = 0; j < centroids[0].size(); ++j) tmp.push_back(0);
		tmp_centroids.push_back(tmp);
		data_counter.push_back(0);
	}


	for (const std::vector<float>& d : data) {
		std::vector<float> distances;
		/*
		for this data point calculate the distances to every centroid
		and store those distances on distances array
		To decrease lines of code you wrote, you can merge the finding minimum
		operation with here.
		*/
		int min_index = 0;
		float min_dist = dist::euclid(d, centroids[0]);
		for (int i = 1; i < n_clusters; ++i) {
			float euclid = dist::euclid(d,centroids[i]);
			if (min_dist > euclid) {
				min_dist = euclid;
				min_index = i;
			}
		}
		/*
		Now we have the minimum index
		and we know which data is attend to which centroid
		this data is going to attend to centroid which has the min_index

		to calculate the new_centroid
		add every point to correct centroid
		and also data counter
		*/
		for (int i = 0; i < d.size(); i++)
			tmp_centroids[min_index][i] += d[i];
		data_counter[min_index] += 1;
	}

	// Calculate the new centroid points
	for (int i = 0; i < data_counter.size(); ++i)
		for (int j = 0; j < tmp_centroids[i].size(); ++j)
			tmp_centroids[i][j] /= data_counter[i];

	return tmp_centroids;
}