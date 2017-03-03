#include "LDH.h"

std::shared_ptr<Mat> hadamard(const std::shared_ptr<Mat> op, const std::shared_ptr<Mat> tr)
{
	Mat res = (*tr) * (*op) * (*tr);
	return(make_shared<Mat>(res));
}