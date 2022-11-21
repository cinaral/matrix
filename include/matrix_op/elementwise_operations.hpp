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

#ifndef ELEMENTWISE_OPERATIONS_HPP_CINARAL_220924_1506
#define ELEMENTWISE_OPERATIONS_HPP_CINARAL_220924_1506

#include "types.hpp"

namespace matrix_op
{
//* scales an array of DIM with a scalar
//* x_scaled = scale*x
//*
//* inputs:
//* scale - scaling factor
//* x - [DIM] array
template <size_t DIM>
static void
scale(const Real_T scale, const Real_T (&x)[DIM], Real_T (&x_scaled)[DIM])
{
	for (size_t i = 0; i < DIM; ++i) {
		x_scaled[i] = scale * x[i];
	}
}

//* sums two arrays of DIM size
//* sum = x + y
//*
//* inputs:
//* x - [DIM] array 1
//* y - [DIM] array 2
template <size_t DIM>
static void
sum(const Real_T (&x)[DIM], const Real_T (&y)[DIM], Real_T (&sum)[DIM])
{
	for (size_t i = 0; i < DIM; ++i) {
		sum[i] = x[i] + y[i];
	}
}

//* subtracts two arrays
//* sub = x - y
//*
//* inputs:
//* x - [DIM] array 1
//* y - [DIM] array 2
template <size_t DIM>
static void
subtract(const Real_T (&x)[DIM], const Real_T (&y)[DIM], Real_T (&sub)[DIM])
{
	for (size_t i = 0; i < DIM; ++i) {
		sub[i] = x[i] - y[i];
	}
}

//* sums two arrays of DIM size with weights
//* sum = x_weight*x + y_weight*y
//*
//* inputs:
//* x_weight - weight of x
//* x - [DIM] array 1
//* y_weight - weight of y
//* y - [DIM] array 2
template <size_t DIM>
static void
weighted_sum(const Real_T x_weight, const Real_T (&x)[DIM], const Real_T y_weight, const Real_T (&y)[DIM],
             Real_T (&sum)[DIM])
{
	for (size_t i = 0; i < DIM; ++i) {
		sum[i] = x_weight * x[i] + y_weight * y[i];
	}
}
} // namespace matrix_op

#endif
