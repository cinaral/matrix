/*
 * matrix_op
 *  
 * MIT License
 * 
 * Copyright (c) 2022 cinaral
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
//* Transposes A matrix
//* A_tr = A^T
//*
//* inputs:
//* A - [N_ROW * M_COL] matrix
template <size_t N_ROW, size_t M_COL>
static void
transpose(const Real_T (&A)[N_ROW * M_COL], Real_T (&A_tr)[N_ROW * M_COL])
{
	for (size_t i = 0; i < N_ROW; ++i) {
		for (size_t j = 0; j < M_COL; ++j) {
			A_tr[j * N_ROW + i] = A[i * M_COL + j];
		}
	}
}

//* computes right multiply A*x for an matrix A of size N_ROW by M_COL and vector x of size N_ROW
//* res = A*x
//*
//* inputs:
//* A - [N_ROW * M_COL] matrix
//* x - [M_COL] vector
template <size_t N_ROW, size_t M_COL>
static void
right_multiply(const Real_T (&A)[N_ROW * M_COL], const Real_T (&x)[M_COL], Real_T (&mul)[N_ROW])
{
	for (size_t i = 0; i < N_ROW; ++i) {
		const Real_T (&a)[M_COL] = *matrix_op::select_row<N_ROW, M_COL>(i, A);
		mul[i] = dot_product<M_COL>(a, x);
	}
}

//* matrix multiplication
//* mul = A*B
//*
//* inputs:
//* A - [N_ROW_A * M_COL_A] matrix
//* B - [M_COL_A * M_COL_B] matrix
template <size_t N_ROW_A, size_t M_COL_A, size_t M_COL_B>
static void
multiply(const Real_T (&A)[N_ROW_A * M_COL_A], const Real_T (&B)[M_COL_A * M_COL_B], Real_T (&mul)[N_ROW_A * M_COL_B])
{
	for (size_t i = 0; i < N_ROW_A * M_COL_B; ++i) {
		mul[i] = 0;
	}

	for (size_t i = 0; i < N_ROW_A; ++i) {
		for (size_t k = 0; k < M_COL_A; ++k) {
			for (size_t j = 0; j < M_COL_B; ++j) {
				mul[i * M_COL_A + j] += A[i * M_COL_A + k] * B[k * M_COL_B + j];
			}
		}
	}
}
} // namespace matrix_op

#endif
