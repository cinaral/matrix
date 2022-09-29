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