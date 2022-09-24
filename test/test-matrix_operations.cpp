#include "matrix_op/matrix_operations.hpp"

using uint_t = matrix_op::uint_t;
using real_t = matrix_op::real_t;

constexpr uint_t n_row_A = 2;
constexpr uint_t m_col_A = 3;
constexpr uint_t m_col_B = 3;
constexpr real_t A[n_row_A * m_col_A] = {1., 2., 3., 4., 5., 6.};
constexpr real_t B[m_col_A * m_col_B] = {1., 2., 3., -1., -2., 3., 1., -1., 3.};
constexpr real_t x[n_row_A] = {1,-1};

constexpr real_t A_tr_ref[m_col_A * n_row_A] = {1., 4., 2., 5., 3., 6.};
constexpr real_t AB_ref[n_row_A * m_col_B] = {2., -5., 18., 5, -8, 45};


int
main()
{
	real_t A_tr[m_col_A * n_row_A];
	matrix_op::transpose<n_row_A, m_col_A>(A, A_tr);

	real_t mul[m_col_A];
	matrix_op::right_multiply<m_col_A, n_row_A>(A_tr, x, mul);

	real_t AB[n_row_A * m_col_B];
	matrix_op::multiply<n_row_A, m_col_A, m_col_B>(A, B, AB);

	bool success = true;

	for (uint_t i = 0; i < m_col_A*n_row_A; ++i) {
		if (A_tr_ref[i] - A_tr[i]) {
			success = false;
		}
	}

	for (uint_t i = 0; i < n_row_A*m_col_B; ++i) {
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