﻿// UnsupervisedLib.cpp : Defines the entry point for the application.
//

#include "UnsupervisedLib.h"
#include "algos/Kmeans.h"
#include "util/Printer.h"
#include "algos/bagglomerative.h"
#include "algos/Hierarchical.h"
#include "algos/kbase.h"
#include "algos/lsr.h"

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
	
	k.fit(d);
	print p;
	p.dataFrame("Data Points", d);
	p.dataFrame("Final Centroid Values",k.centroids);
	
	for (float f : k.error_logs)
		std::cout << "Error: " << f << "\n";
	
	std::vector<float> f{ 2,4,1 };
	std::cout << "Prediction : " << k.predict(f)<<"\n";

	for (int kk : k.predict(d)) {
		std::cout << "Prediction : " << kk<<"\n";
	}

	const std::vector<std::vector<float>> dd{
		{1.25,0},
		{-1,5.2},
		{3.1,4.3},
		{-1.25,3.21},
		{0,-5.82},
		{3.1,1.7}};
	// HierarchicalTree tree;
	// tree.build(dd);

	// std::cout << "\n--------------------------------------\n";
	// std::cout << "\n*******************************************\n";
	hierarchicalTree t;
	t.build(d);
	
	k_median m(2, 100);
	m.fit(d);
	p.dataFrame("Final Centroid Values", m.centroids);
	for (int kk : m.predict(d)) {
		std::cout << "Prediction : " << kk << "\n";
	}
	/*
	k_means_plus pl(2, 100);
	pl.fit(d);
	*/
	std::vector<std::pair<float, float>> pair;
	pair.push_back(std::make_pair(2, 4));
	pair.push_back(std::make_pair(3, 5));
	pair.push_back(std::make_pair(5, 7));
	pair.push_back(std::make_pair(7, 10));
	pair.push_back(std::make_pair(9, 15));
	LSR lsr;
	lsr.fit(pair);
	lsr.displayEquation();
	std::cout<<"Prediction: "<< lsr.predict(8)<<"\n";
	
	return 0;
}
