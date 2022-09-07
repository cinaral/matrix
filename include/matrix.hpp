#ifndef MATRIX_HPP_CINARAL_220814_0342
#define MATRIX_HPP_CINARAL_220814_0342

//* basic matrix operations

namespace matrix
{

using uint_t = unsigned long long int;
#ifdef __USE_SINGLE_PRECISION__
using real_t = float;
#else
using real_t = double;
#endif

//* selects a row from an N_ROW by M_COL matrix
template <uint_t M_COL>
static const real_t *
select_row(const uint_t row_idx, const real_t arr[])
{
	const real_t *row_ptr = arr + row_idx * M_COL;
	return row_ptr;
}

//* replaces a row of an N_ROW by M_COL matrix
template <uint_t M_COL>
static void
replace_row(const uint_t row_idx, const real_t sel[], real_t arr[])
{
	//* faster than std::memmove(arr + row_idx * M_COL, sel, M_COL * sizeof(real_t));
	//* identical to: *arr + row_idx * M_COL + i = *sel + i
	for (uint_t i = 0; i < M_COL; ++i) {
		arr[row_idx * M_COL + i] = sel[i];
	}
}

//* sums two arrays of DIM size
template <uint_t DIM>
static void
sum(const real_t x[], const real_t y[], real_t sum[])
{
	for (uint_t i = 0; i < DIM; ++i) {
		sum[i] = x[i] + y[i];
	}
}

//* sums two arrays of DIM size
template <uint_t DIM>
static void
weighted_sum(const real_t x_weight, const real_t x[], const real_t y_weight, const real_t y[], real_t sum[])
{
	for (uint_t i = 0; i < DIM; ++i) {
		sum[i] = x_weight * x[i] + y_weight * y[i];
	}
}

//* subtracts two arrays
template <uint_t DIM>
static void
subtract(const real_t x[], const real_t y[], real_t subt[])
{
	for (uint_t i = 0; i < DIM; ++i) {
		subt[i] = x[i] - y[i];
	}
}

//* scales an array of DIM with a scalar
template <uint_t DIM>
static void
scale(const real_t scale, const real_t x[], real_t x_scaled[])
{
	for (uint_t i = 0; i < DIM; ++i) {
		x_scaled[i] = scale * x[i];
	}
}

//* computes <x, y> for two arrays of DIM size
template <uint_t DIM>
static real_t
dot_product(const real_t x[], const real_t y[])
{
	real_t res = 0;

	for (uint_t i = 0; i < DIM; ++i) {
		res += x[i] * y[i];
	}
	return res;
}

//* computes A*x for an N_ROW by M_COL matrix A
template <uint_t N_ROW, uint_t M_COL>
static void
right_multiply(const real_t A[], const real_t x[], real_t res[])
{
	for (uint_t i = 0; i < N_ROW; ++i) {
		const real_t *a = select_row<M_COL>(i, A);
		res[i] = dot_product<M_COL>(a, x);
	}
}

//* A^T
template <uint_t N_ROW, uint_t M_COL>
static void
transpose(const real_t A[], real_t A_tr[])
{
	for (uint_t i = 0; i < N_ROW; ++i) {
		for (uint_t j = 0; j < M_COL; ++j) {
			A_tr[j * N_ROW + i] = A[i * M_COL + j];
		}
	}
}

//* matrix multiplication
template <uint_t A_N_ROW, uint_t A_M_COL, uint_t B_P_COL>
static void
multiply(const real_t A[], const real_t B[], real_t multip[])
{
	for (uint_t i = 0; i < A_N_ROW * B_P_COL; ++i) {
		multip[i] = 0;
	}

	for (uint_t i = 0; i < A_N_ROW; ++i) {
		for (uint_t k = 0; k < A_M_COL; ++k) {
			for (uint_t j = 0; j < B_P_COL; ++j) {
				multip[i * A_M_COL + j] += A[i * A_M_COL + k] * B[k * B_P_COL + j];
			}
		}
	}
}

} // namespace matrix

#endif