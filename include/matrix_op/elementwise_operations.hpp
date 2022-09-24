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
template <uint_t DIM>
static void
scale(const real_t scale, const real_t (&x)[DIM], real_t (&x_scaled)[DIM])
{
	for (uint_t i = 0; i < DIM; ++i) {
		x_scaled[i] = scale * x[i];
	}
}

//* sums two arrays of DIM size
//* sum = x + y
//*
//* inputs:
//* x - [DIM] array 1
//* y - [DIM] array 2
template <uint_t DIM>
static void
sum(const real_t (&x)[DIM], const real_t (&y)[DIM], real_t (&sum)[DIM])
{
	for (uint_t i = 0; i < DIM; ++i) {
		sum[i] = x[i] + y[i];
	}
}

//* subtracts two arrays
//* sub = x - y
//*
//* inputs:
//* x - [DIM] array 1
//* y - [DIM] array 2
template <uint_t DIM>
static void
subtract(const real_t (&x)[DIM], const real_t (&y)[DIM], real_t (&sub)[DIM])
{
	for (uint_t i = 0; i < DIM; ++i) {
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
template <uint_t DIM>
static void
weighted_sum(const real_t x_weight, const real_t (&x)[DIM], const real_t y_weight, const real_t (&y)[DIM],
             real_t (&sum)[DIM])
{
	for (uint_t i = 0; i < DIM; ++i) {
		sum[i] = x_weight * x[i] + y_weight * y[i];
	}
}
} // namespace matrix_op

#endif