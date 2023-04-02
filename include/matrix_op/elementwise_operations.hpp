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

#ifndef ELEMENTWISE_OPERATIONS_HPP_CINARAL_220924_1506
#define ELEMENTWISE_OPERATIONS_HPP_CINARAL_220924_1506

#include "types.hpp"

namespace matrix_op
{
/* `scale(scale, v, OUT:scale * v)`:
 * Scales a vector with a scalar.
 */
template <size_t DIM>
void
scale(const Real_T scale, const Real_T (&v)[DIM], Real_T (&v_scaled)[DIM])
{
	for (size_t i = 0; i < DIM; ++i) {
		v_scaled[i] = scale * v[i];
	}
}

/* `scale(scale, A, OUT:scale * A)`:
 * Scales a matrix with a scalar.
 */
template <size_t N_DIM, size_t M_DIM>
void
scale(const Real_T scale, const Real_T (&A)[N_DIM][M_DIM], Real_T (&A_scaled)[N_DIM][M_DIM])
{
	for (size_t i = 0; i < N_DIM; ++i) {
		for (size_t j = 0; j < M_DIM; ++j) {
			A_scaled[i][j] = scale * A[i][j];
		}
	}
}

/* `sum(u, v, OUT:u + v)`:
 * Sums two vectors.
 */
template <size_t DIM>
void
sum(const Real_T (&u)[DIM], const Real_T (&v)[DIM], Real_T (&sum)[DIM])
{
	for (size_t i = 0; i < DIM; ++i) {
		sum[i] = u[i] + v[i];
	}
}

/* `sum(A, B, OUT:A + B)`:
 * Sums two matrices.
 */
template <size_t N_DIM, size_t M_DIM>
void
sum(const Real_T (&A)[N_DIM][M_DIM], const Real_T (&B)[N_DIM][M_DIM], Real_T (&sum)[N_DIM][M_DIM])
{
	for (size_t i = 0; i < N_DIM; ++i) {
		for (size_t j = 0; j < M_DIM; ++j) {
			sum[i][j] = A[i][j] + B[i][j];
		}
	}
}

/* `subtract(u, v, OUT:u - v)`:
 * Subtracts two vectors.
 */
template <size_t DIM>
void
subtract(const Real_T (&x)[DIM], const Real_T (&y)[DIM], Real_T (&sub)[DIM])
{
	for (size_t i = 0; i < DIM; ++i) {
		sub[i] = x[i] - y[i];
	}
}

/* `subtract(A, B, OUT:A - B)`:
 * Subtracts two matrices.
 */
template <size_t N_DIM, size_t M_DIM>
void
subtract(const Real_T (&A)[N_DIM][M_DIM], const Real_T (&B)[N_DIM][M_DIM],
         Real_T (&sum)[N_DIM][M_DIM])
{
	for (size_t i = 0; i < N_DIM; ++i) {
		for (size_t j = 0; j < M_DIM; ++j) {
			sum[i][j] = A[i][j] - B[i][j];
		}
	}
}

/*  `weighted_sum(u_weight, u, v_weight, v, OUT:u_weight * u + v_weight * v)`:
 * Sums two vectors after weighting.
 */
template <size_t DIM>
void
weighted_sum(const Real_T u_weight, const Real_T (&u)[DIM], const Real_T v_weight,
             const Real_T (&v)[DIM], Real_T (&sum)[DIM])
{
	for (size_t i = 0; i < DIM; ++i) {
		sum[i] = u_weight * u[i] + v_weight * v[i];
	}
}

/*  `weighted_sum(A_weight, A, B_weight, B, OUT:A_weight * A + B_weight * B)`:
 * Sums two matrices after weighting.
 */
template <size_t N_DIM, size_t M_DIM>
void
weighted_sum(const Real_T A_weight, const Real_T (&A)[N_DIM][M_DIM], const Real_T B_weight,
             const Real_T (&B)[N_DIM][M_DIM], Real_T (&sum)[N_DIM][M_DIM])
{
	for (size_t i = 0; i < N_DIM; ++i) {
		for (size_t j = 0; j < M_DIM; ++j) {
			sum[i][j] = A_weight * A[i][j] + B_weight * B[i][j];
		}
	}
}
} // namespace matrix_op
#endif
