#include "matrix_op/matrix_operations.hpp"

using Uint_T = matrix_op::Uint_T;
using Real_T = matrix_op::Real_T;

constexpr Uint_T n_row_A = 2;
constexpr Uint_T m_col_A = 3;
constexpr Uint_T m_col_B = 3;
constexpr Real_T A[n_row_A * m_col_A] = {1., 2., 3., 4., 5., 6.};
constexpr Real_T B[m_col_A * m_col_B] = {1., 2., 3., -1., -2., 3., 1., -1., 3.};
constexpr Real_T x[n_row_A] = {1, -1};

constexpr Real_T mul_ref[m_col_A] = {-3., -3., -3.};
constexpr Real_T A_tr_ref[m_col_A * n_row_A] = {1., 4., 2., 5., 3., 6.};
constexpr Real_T AB_ref[n_row_A * m_col_B] = {2., -5., 18., 5, -8, 45};

int
main()
{
	Real_T A_tr[m_col_A * n_row_A];
	matrix_op::transpose<n_row_A, m_col_A>(A, A_tr);

	Real_T mul[m_col_A];
	matrix_op::right_multiply<m_col_A, n_row_A>(A_tr, x, mul);

	Real_T AB[n_row_A * m_col_B];
	matrix_op::multiply<n_row_A, m_col_A, m_col_B>(A, B, AB);

	bool success = true;

	for (Uint_T i = 0; i < m_col_A * n_row_A; ++i) {
		if (A_tr_ref[i] - A_tr[i]) {
			success = false;
		}
	}

	for (Uint_T i = 0; i < m_col_A; ++i) {
		if (mul_ref[i] - mul[i]) {
			success = false;
		}
	}

	for (Uint_T i = 0; i < n_row_A * m_col_B; ++i) {
		if (AB_ref[i] - AB[i]) {
			success = false;
		}
	}

	if (success) {
		return 0;
	} else {
		return 1;
	}
}