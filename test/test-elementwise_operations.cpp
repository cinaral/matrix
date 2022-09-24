#include "matrix_op/elementwise_operations.hpp"

using uint_t = matrix_op::uint_t;
using real_t = matrix_op::real_t;

constexpr uint_t dim = 3;
constexpr real_t x[dim] = {1, 1.5, -2};
constexpr real_t y[dim] = {-.5, -.5, 1};
constexpr real_t z[dim] = {.5, 1, -1};

int
main()
{
	real_t x_scaled[dim];
	matrix_op::scale(2, x, x_scaled);

	real_t zeros_1[dim];
	matrix_op::weighted_sum(2, x, -1, x_scaled, zeros_1);

	real_t u[dim];
	matrix_op::sum(x, y, u);

	real_t zeros_2[dim];
	matrix_op::subtract(u, z, zeros_2);

	bool success = true;

	for (uint_t i = 0; i < dim; ++i) {
		if (zeros_1[i] || zeros_2[i]) {
			success = false;
		}
	}

	if (success) {
		return 0;
	} else {
		return 1;
	}
}