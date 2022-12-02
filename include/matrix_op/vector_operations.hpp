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

#ifndef VECTOR_OPERATIONS_HPP_CINARAL_220924_1507
#define VECTOR_OPERATIONS_HPP_CINARAL_220924_1507

#include "types.hpp"

namespace matrix_op
{
/*
 * Returns the dot product of two vectors.
 * 
 * `product = dot_product<OPT: DIM>(x, y)`
 *
 * `product`: dot product of `x` and `y`
 *
 * 1. `x`: vector 1
 * 2. `y`: vector 2
 */
template <size_t DIM>
static Real_T
dot_product(const Real_T (&x)[DIM], const Real_T (&y)[DIM])
{
	Real_T res = 0;

	for (size_t i = 0; i < DIM; ++i) {
		res += x[i] * y[i];
	}
	return res;
}
} // namespace matrix_op

#endif
