#include "matrix_op/vector_operations.hpp"

using uint_t = matrix_op::uint_t;
using real_t = matrix_op::real_t;

constexpr uint_t dim = 3;
constexpr real_t x[dim] = {1, 1.5, -2};
constexpr real_t y[dim] = {-.5, -.5, 1};
constexpr real_t ref_dot = -3.25;
int
main()
{
	const real_t dot = matrix_op::dot_product(x, y);

	if (dot == ref_dot) {
		return 0;
	} else {
		return 1;
	}
}