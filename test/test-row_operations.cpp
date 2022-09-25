#include "matrix_op/row_operations.hpp"
#include <iostream>

using uint_t = matrix_op::uint_t;
using real_t = matrix_op::real_t;

constexpr uint_t n_row = 2;
constexpr uint_t m_col = 3;
constexpr real_t A[n_row * m_col] = {1., 2., 3., 4., 5., 6.};
constexpr real_t C[n_row * m_col] = {4., 5., 6., 1., 2., 3.};

int
main()
{
	real_t B[n_row * m_col];
	{
	const real_t (&sel)[m_col] = *matrix_op::select_row<n_row, m_col>(1, A);
	matrix_op::replace_row<n_row>(0, sel, B);
	}
	{
	const real_t (&sel)[m_col] = *matrix_op::select_row<n_row, m_col>(0, A);
	matrix_op::replace_row<n_row>(1, sel, B);
	}

	bool success = true;

	for (uint_t i = 0; i < n_row*m_col; ++i) {
		if (C[i] - B[i]) {
			success = false;
		}
	}

	if (success) {
		return 0;
	} else {
		return 1;
	}
}