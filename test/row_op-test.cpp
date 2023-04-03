#include "matrix_op/row_operations.hpp"
#include <iostream>

using matrix_op::Real_T;
using matrix_op::size_t;

constexpr size_t N_DIM = 2;
constexpr size_t M_DIM = 3;
constexpr Real_T A[N_DIM][M_DIM] = {{1., 2., 3.}, {4., 5., 6.}};
constexpr Real_T B[N_DIM][M_DIM] = {{4., 5., 6.}, {1., 2., 3.}};
constexpr Real_T A_flattened[N_DIM * M_DIM] = {1., 2., 3., 4., 5., 6.};

int
main()
{
	

	Real_T C[N_DIM][M_DIM];
	{
		const Real_T(&sel)[M_DIM] = *matrix_op::select_row<N_DIM, M_DIM>(1, A_flattened); 	
		matrix_op::replace_row<N_DIM>(0, sel, C);
	}
	{
		const Real_T(&sel)[M_DIM] = A[0];
		matrix_op::replace_row<N_DIM>(1, sel, C);
	}
	bool success = true;

	for (size_t i = 0; i < N_DIM; ++i) {
		for (size_t j = 0; j < M_DIM; ++j) {
			if (B[i][j] - C[i][j]) {
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