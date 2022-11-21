#include "matrix_op/vector_operations.hpp"

using size_t = matrix_op::size_t;
using Real_T = matrix_op::Real_T;

constexpr size_t dim = 3;
constexpr Real_T x[dim] = {1, 1.5, -2};
constexpr Real_T y[dim] = {-.5, -.5, 1};
constexpr Real_T ref_dot = -3.25;
int
main()
{
	const Real_T dot = matrix_op::dot_product(x, y);

	if (dot == ref_dot) {
		return 0;
	} else {
		return 1;
	}
}