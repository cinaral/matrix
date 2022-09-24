#ifndef ROW_OPERATIONS_HPP_CINARAL_220924_1502
#define ROW_OPERATIONS_HPP_CINARAL_220924_1502

#include "types.hpp"

namespace matrix_op
{
//* selects a row from an N_ROW by M_COL matrix
template <uint_t N_ROW, uint_t M_COL>
static void
select_row(const uint_t row_idx, const real_t (&arr)[N_ROW * M_COL], real_t (&sel)[M_COL])
{
	for (uint_t i = 0; i < M_COL; ++i) {
		sel[i] = arr[row_idx * M_COL + i];
	}
}


//* replaces a row of an N_ROW by M_COL matrix
template <uint_t N_ROW, uint_t M_COL>
static void
replace_row(const uint_t row_idx, const real_t (&sel)[M_COL], real_t (&arr)[N_ROW * M_COL])
{
	//* faster than std::memmove(arr + row_idx * M_COL, sel, M_COL * sizeof(real_t));
	//* identical to: *arr + row_idx * M_COL + i = *sel + i
	for (uint_t i = 0; i < M_COL; ++i) {
		arr[row_idx * M_COL + i] = sel[i];
	}
}
} // namespace matrix_op

#endif