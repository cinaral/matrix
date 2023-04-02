#include "matrix_op.hpp"
#include "matrix_op/matrix_operations.hpp"
#include "matrix_op/row_operations.hpp"

using Real_T = matrix_op::Real_T;

constexpr Real_T A[2][3] = {{1., 2., 3.}, {4., 5., 6.}};
const Real_T (&u)[3] = A[0];
const Real_T (&v)[3] = A[1];
constexpr Real_T B[3][2] = {{1., 2.}, {3., 4.}, {5., 6.}};

int
main()
{
	/** elementwise operations **/
	Real_T w[3];
	matrix_op::scale(2, v, w);
	matrix_op::sum(u, v, w);
	matrix_op::subtract(u, v, w);
	matrix_op::weighted_sum(2, u, 3, v, w);

	Real_T C[2][3];
	matrix_op::scale(2, A, C);
	matrix_op::sum(A, A, C);
	matrix_op::subtract(A, A, C);
	matrix_op::weighted_sum(2, A, 3, A, C);

	/** vector operations **/
	matrix_op::dot_product(u, v);

	/** matrix operations **/
	Real_T A_copy[2][3];
	matrix_op::replace_row(0, u, A_copy);
	matrix_op::replace_row(1, v, A_copy);

	Real_T A_transpose[3][2];
	matrix_op::transpose(A, A_transpose);

	Real_T D[2];
	matrix_op::right_multiply(A, u, D);

	Real_T E[2][2];
	matrix_op::multiply(A, B, E);

	return 0;
}