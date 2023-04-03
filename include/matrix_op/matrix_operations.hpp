/*
 * matrix_op
 *
 * MIT License
 *
 * Copyright (c) 2022 Cinar, A. L.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do
 * so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef MATRIX_OPERATIONS_HPP_CINARAL_220924_1506
#define MATRIX_OPERATIONS_HPP_CINARAL_220924_1506

#include "row_operations.hpp"
#include "types.hpp"
#include "vector_operations.hpp"

namespace matrix_op
{
/* `transpose<OPT:N_DIM, M_DIM>(A, OUT:A_transposed)'
 * Transposes a matrix.
 */
template <size_t N_DIM, size_t M_DIM>
void
transpose(const Real_T (&A)[N_DIM][M_DIM], Real_T (&A_transpose)[M_DIM][N_DIM])
{
	for (size_t i = 0; i < N_DIM; ++i) {
		for (size_t j = 0; j < M_DIM; ++j) {
			A_transpose[j][i] = A[i][j];
		}
	}
}

/* `right_multiply<OPT:N_DIM, M_DIM>(A, v, OUT:A * v)`:
 * Computes right multiply A*x for an matrix A of size N_DIM by M_DIM and vector x of size N_DIM.
 */
template <size_t N_DIM, size_t M_DIM>
void
right_multiply(const Real_T (&A)[N_DIM][M_DIM], const Real_T (&x)[M_DIM], Real_T (&mul)[N_DIM])
{
	for (size_t i = 0; i < N_DIM; ++i) {
		const Real_T(&a)[M_DIM] = A[i];
		mul[i] = dot_product(a, x);
	}
}

/* `multiply<OPT:A_N_DIM, A_M_DIM, B_M_DIM>(A, B, OUT:mul)`:
 * matrix multiplication of A[A_N_DIM][A_M_DIM] and B[B_N_DIM][B_M_DIM].
 */
template <size_t A_N_DIM, size_t A_M_DIM, size_t B_M_DIM>
void
multiply(const Real_T (&A)[A_N_DIM][A_M_DIM], const Real_T (&B)[A_M_DIM][B_M_DIM],
         Real_T (&mul)[A_N_DIM][B_M_DIM])
{
	for (size_t i = 0; i < A_N_DIM; ++i) {
		for (size_t j = 0; j < B_M_DIM; ++j) {
			mul[i][j] = 0;
		}
	}

	for (size_t i = 0; i < A_N_DIM; ++i) {
		for (size_t k = 0; k < A_M_DIM; ++k) {
			for (size_t j = 0; j < B_M_DIM; ++j) {
				mul[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}
} // namespace matrix_op

#endif
