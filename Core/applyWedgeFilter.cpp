#include "LDH.h"

std::shared_ptr<Mat> applyWedgeFilter(const std::shared_ptr<Mat> op, const shared_ptr<Mat> filter)
{
	auto epsilon = 0.0001;
	Mat res = *op + epsilon;
	return make_shared<Mat>(res.mul(*filter));
}