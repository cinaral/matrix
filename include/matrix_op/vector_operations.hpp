#ifndef VECTOR_OPERATIONS_HPP_CINARAL_220924_1507
#define VECTOR_OPERATIONS_HPP_CINARAL_220924_1507

#include "types.hpp"

namespace matrix_op
{
//* computes <x, y> for two vector of size DIM
//* res = <x,y>
//*
//* inputs:
//* x - [DIM] vector 1
//* y - [DIM] vector 2
template <uint_t DIM>
static real_t
dot_product(const real_t (&x)[DIM], const real_t (&y)[DIM])
{
	real_t res = 0;

	for (uint_t i = 0; i < DIM; ++i) {
		res += x[i] * y[i];
	}
	return res;
}
} // namespace matrix_op

#endif