#include "matrix_op/row_operations.hpp"
#include <iostream>

using Uint_T = matrix_op::Uint_T;
using Real_T = matrix_op::Real_T;

constexpr Uint_T n_row = 2;
constexpr Uint_T m_col = 3;
constexpr Real_T A[n_row * m_col] = {1., 2., 3., 4., 5., 6.};
constexpr Real_T C[n_row * m_col] = {4., 5., 6., 1., 2., 3.};

int
main()
{
	Real_T B[n_row * m_col];
	{
	const Real_T (&sel)[m_col] = *matrix_op::select_row<n_row, m_col>(1, A);
	matrix_op::replace_row<n_row>(0, sel, B);
	}
	{
	const Real_T (&sel)[m_col] = *matrix_op::select_row<n_row, m_col>(0, A);
	matrix_op::replace_row<n_row>(1, sel, B);
	}

	bool success = true;

	for (Uint_T i = 0; i < n_row*m_col; ++i) {
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