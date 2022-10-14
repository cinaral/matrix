#include "matrix_op/elementwise_operations.hpp"

using Uint_T = matrix_op::Uint_T;
using Real_T = matrix_op::Real_T;

constexpr Uint_T dim = 3;
constexpr Real_T x[dim] = {1, 1.5, -2};
constexpr Real_T y[dim] = {-.5, -.5, 1};
constexpr Real_T z[dim] = {.5, 1, -1};

int
main()
{
	Real_T x_scaled[dim];
	matrix_op::scale(2, x, x_scaled);

	Real_T zeros_1[dim];
	matrix_op::weighted_sum(2, x, -1, x_scaled, zeros_1);

	Real_T u[dim];
	matrix_op::sum(x, y, u);

	Real_T zeros_2[dim];
	matrix_op::subtract(u, z, zeros_2);

	bool success = true;

	for (Uint_T i = 0; i < dim; ++i) {
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