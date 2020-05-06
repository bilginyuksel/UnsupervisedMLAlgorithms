#include "Printer.h"

// Helper function to display frames good.
int digitCalculator(int num) {
	int digit_counter = 0;
	if (num == 0) return 1;
	while (num != 0) {
		digit_counter++;
		num /= 10;
	}
	return digit_counter;
}	

void print::dataFrame(
	std::string title,
	const std::vector<std::vector<float>>& d) {
	for (int i = 0; i < d[0].size() * 22; i++) std::cout << "-";
	std::cout << "\n";
	std::cout << std::setw(d[0].size() * 24 / 2) << title << "\n";
	for (int i = 0; i < d[0].size() * 22; i++) std::cout << "-";
	std::cout <<"\n";
	std::cout << "Index"<< std::setw(18);
	for (int i = 0; i < d[0].size(); ++i) std::cout<<i<<(i+1!=d[0].size()?std::setw(20):std::setw(5));
	std::cout << "|\n";

	for (int i = 0; i < d.size();++i) {
		std::cout << i << std::setw(23-digitCalculator(i));
		for (int j = 0; j < d[i].size(); ++j) {
			std::cout << std::showpoint<< d[i][j]<< ((j+1)!=d[i].size()?std::setw(20):std::setw(5));
		}
		std::cout <<"|\n";
	}
	for (int i = 0; i < d[0].size() * 22; i++) std::cout << "-";
	std::cout << "\n";
}