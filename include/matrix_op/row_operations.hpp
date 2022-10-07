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

#ifndef ROW_OPERATIONS_HPP_CINARAL_220924_1502
#define ROW_OPERATIONS_HPP_CINARAL_220924_1502

#include "types.hpp"

namespace matrix_op
{
//* selects a row from an N_ROW by M_COL matrix
//* returns a pointer to array (*)[M_COL]
//*
//* inputs:
//* 1. row_idx - row number
//* 2. mat - N_ROW by M_COL matrix
//*
//* usage:
//* const real_t (&row) = *matrix_op::select_row<N_ROW, M_COL>(row_idx, mat);
template <uint_t N_ROW, uint_t M_COL>
static const real_t (*select_row(const uint_t row_idx, const real_t (&mat)[N_ROW * M_COL]))[M_COL]
{
	const real_t(*row_ptr)[M_COL] = (real_t(*)[M_COL])(mat + row_idx * M_COL);
	return row_ptr;
}

//* replaces a row of an N_ROW by M_COL matrix
//*
//* inputs:
//* 1. row_idx - row number
//* 2. row - M_COL vector
//* usage:
//* matrix_op::replace_row<N_ROW, [OPTIONAL] M_COL>(row_idx, row, mat);
template <uint_t N_ROW, uint_t M_COL>
static void
replace_row(const uint_t row_idx, const real_t (&row)[M_COL], real_t (&mat)[N_ROW * M_COL])
{
	//* faster than std::memmove(mat + row_idx * M_COL, row, M_COL * sizeof(real_t));
	//* identical to: *mat + row_idx * M_COL + i = *row + i
	for (uint_t i = 0; i < M_COL; ++i) {
		mat[row_idx * M_COL + i] = row[i];
	}
}
} // namespace matrix_op

#endif
