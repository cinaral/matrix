#include "matrix_op/elementwise_operations.hpp"

using matrix_op::Real_T;
using matrix_op::size_t;

constexpr size_t dim = 3;
constexpr Real_T x[dim] = {1, 1.5, -2};
constexpr Real_T y[dim] = {-.5, -.5, 1};
constexpr Real_T z[dim] = {.5, 1, -1};

constexpr size_t n_dim = 3;
constexpr size_t m_dim = 3;
constexpr Real_T A[n_dim][m_dim] = {{1, 2}, {1.5, 3}, {-2, -3}};
constexpr Real_T B[n_dim][m_dim] = {{-.5, -1.}, {-.5, -1}, {1, 2}};
constexpr Real_T C[n_dim][m_dim] = {{.5, 1}, {1, 2}, {-1, -1}};

int
main()
{
	bool success = true;
	{
		Real_T x_scaled[dim];
		matrix_op::scale(2, x, x_scaled);

		Real_T zeros_1[dim];
		matrix_op::weighted_sum(2, x, -1, x_scaled, zeros_1);

		Real_T u[dim];
		matrix_op::sum(x, y, u);

		Real_T zeros_2[dim];
		matrix_op::subtract(u, z, zeros_2);

		for (size_t i = 0; i < dim; ++i) {
			if (zeros_1[i] || zeros_2[i]) {
				success = false;
			}
		}
	}
	{
		Real_T A_scaled[n_dim][m_dim];
		matrix_op::scale(2, A, A_scaled);

		Real_T zeros_1[n_dim][m_dim];
		matrix_op::weighted_sum(2, A, -1, A_scaled, zeros_1);

		Real_T D[n_dim][m_dim];
		matrix_op::sum(A, B, D);

		Real_T zeros_2[n_dim][m_dim];
		matrix_op::subtract(D, C, zeros_2);

		for (size_t i = 0; i < n_dim; ++i) {
			for (size_t j = 0; j < m_dim; ++j) {
				if (zeros_1[i][j] || zeros_2[i][j]) {
					success = false;
				}
			}
		}
	}
	if (success) {
		return 0;
	} else {
		return 1;
	}
}