#include "LDH.h"

std::shared_ptr<vector<vector<cv::Point>>> initializeWedgeFilters(const std::string path)
{
	auto _128_H = loadFilter(path + "\\WD_HOR_128.bin");
	auto _128_V = loadFilter(path + "\\WD_VER_128.bin");
	auto _128_D = loadFilter(path + "\\WD_DIA_128.bin");

	auto _64_H = loadFilter(path + "\\WD_HOR_64.bin");
	auto _64_V = loadFilter(path + "\\WD_VER_64.bin");
	auto _64_D = loadFilter(path + "\\WD_DIA_64.bin");

	auto _32_H = loadFilter(path + "\\WD_HOR_32.bin");
	auto _32_V = loadFilter(path + "\\WD_VER_32.bin");
	auto _32_D = loadFilter(path + "\\WD_DIA_32.bin");

	vector<vector<Point>> filters;
	filters.push_back(*_128_H);
	filters.push_back(*_128_V);
	filters.push_back(*_128_D);

	filters.push_back(*_64_H);
	filters.push_back(*_64_V);
	filters.push_back(*_64_D);

	filters.push_back(*_32_H);
	filters.push_back(*_32_V);
	filters.push_back(*_32_D);

	return make_shared<vector<vector<Point>>>(filters);
}