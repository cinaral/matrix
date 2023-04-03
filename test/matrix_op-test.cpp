#include "matrix_op/matrix_operations.hpp"

using matrix_op::Real_T;
using matrix_op::size_t;

constexpr size_t N_DIM_A = 2;
constexpr size_t M_DIM_A = 3;
constexpr size_t M_DIM_B = 3;
constexpr Real_T A[N_DIM_A][M_DIM_A] = {{1., 2., 3.}, {4., 5., 6.}};
constexpr Real_T B[M_DIM_A][M_DIM_B] = {{1., 2., 3.}, {-1., -2., 3.}, {1., -1., 3.}};
constexpr Real_T x[N_DIM_A] = {1, -1};

constexpr Real_T mul_ref[M_DIM_A] = {-3., -3., -3.};
constexpr Real_T A_tr_ref[M_DIM_A][N_DIM_A] = {{1., 4.}, {2., 5.}, {3., 6.}};
constexpr Real_T AB_ref[N_DIM_A][M_DIM_B] = {{2., -5., 18.}, {5, -8, 45}};

int
main()
{
	Real_T A_tr[M_DIM_A][N_DIM_A];
	matrix_op::transpose<N_DIM_A, M_DIM_A>(A, A_tr);

	Real_T mul[M_DIM_A];
	matrix_op::right_multiply(A_tr, x, mul);

	Real_T AB[N_DIM_A][M_DIM_B];
	matrix_op::multiply<N_DIM_A, M_DIM_A, M_DIM_B>(A, B, AB);

	bool success = true;

	for (size_t i = 0; i < M_DIM_A; ++i) {
		for (size_t j = 0; j < M_DIM_A; ++j) {
			if (A_tr_ref[i][j] - A_tr[i][j]) {
				success = false;
			}
		}
	}

	for (size_t i = 0; i < M_DIM_A; ++i) {
		if (mul_ref[i] - mul[i]) {
			success = false;
		}
	}

	for (size_t i = 0; i < N_DIM_A; ++i) {
		for (size_t j = 0; j < M_DIM_B; ++j) {
			if (AB_ref[i][j] - AB[i][j]) {
				success = false;
			}
		}
	}

	if (success) {
		return 0;
	} else {
		return 1;
	}
}