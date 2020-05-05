#include "KMeans.h"


std::vector<std::vector<float>> KMeans::randomize_centroids(
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
			tmp.push_back(rand() % (int)(max_elements[j] + min_elements[j])+ ((int)min_elements[j]));
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


std::vector<std::vector<float>> KMeans :: update_centroids(
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
	for (int i = 0; i < n_clusters ; ++i) {
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
		for (int i = 0; i < n_clusters; ++i) {
			float dist = 0;
			for (int j = 0; j < d.size(); ++j)
				dist += pow((centroids[i][j] - d[j]), 2);
			distances.push_back(sqrt(dist));
		}


		/*
		find the minimum distance here
		and attend this data point to cluster
		So index is important while finding the minimum
		distance here.
		*/
		int min_index = 0;
		float min_val = distances[min_index];
		for(int i=0;i<distances.size();++i)
			if (distances[i] < min_val) {
				min_val = distances[i];
				min_index = i;
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

float KMeans::calculateError(
	const std::vector<std::vector<float>>& old_centroids,
	const std::vector<std::vector<float>>& n_centroids) {

	// Calculate the euclid distance between the two points
	float euclid = 0;
	for (int i = 0; i < n_clusters; ++i) {
		float eu = 0;
		for (int j = 0; j < old_centroids[i].size(); ++j)
			eu += pow(old_centroids[i][j] - centroids[i][j], 2);
		euclid += sqrt(eu);
	}

	return euclid;
}


void KMeans::fit(
	const std::vector<std::vector<float>>& data) {
	
	/*
	Impliy KMeans logic here.
	1) First of all clusterize every daata point with already
	trained centroids.

	2) And then according to those data points update centroids
	new features.

	3) Calculate the error between the old_centroids and new_centroids
	while error!=0 iterate it. By the way we are taking max_iter from user
	so add max_iter situation to this while loop.
	*/

	// Check if data is valid
	

	this-> centroids  = randomize_centroids(data[0].size(), data);
	float error = 100;
	int iteration = -1;

	while (error != 0 && max_iter>=++iteration) {
		std::vector<std::vector<float>> old_centroids = centroids;
		this->centroids = this->update_centroids(data);

		error = this->calculateError(
			old_centroids,
			centroids);

		// Store error logs
		error_logs.push_back(error);
	}

	// End of kmeans fit
}

int KMeans::predict(
	const std::vector<float>& t) {

	// We can control if this vector array has the same length or not
	// Because if the data feature size is not the same with the centroid
	// size it will give an error
	if (centroids.empty() || centroids[0].size() != t.size()) return -1;
	int min_index = -1;
	float min_dist = 100000; // It is like max integer point
	for (int i = 0; i < centroids.size();i++) {
		float dist = 0;
		for (int j = 0; j < centroids[i].size(); j++) {
			dist += pow(t[j] - centroids[i][j], 2);
		}
		dist = sqrt(dist);
		// std::cout << "Dist: " << dist << "\n";
		if (dist<min_dist ) {
			min_dist = dist;
			min_index = i;
		}
	}


	return min_index;
}

std::vector<int> KMeans::predict(
	const std::vector<std::vector<float>>& t) {
	std::vector<int> cl;

	for (const std::vector<float>& tmp : t) {
		int min_index = -1;
		float min_dist = 1000000; // It is like max integer
		for (int i = 0; i < n_clusters; ++i) {
			float dist = 0;
			for (int j = 0; j < centroids[i].size(); ++j) {
				dist += pow(tmp[j] - centroids[i][j], 2);
			}dist = sqrt(dist);

			if (dist < min_dist) {
				min_dist = dist;
				min_index = i;
			}
		}

		cl.push_back(min_index);
	}
	return cl;
}