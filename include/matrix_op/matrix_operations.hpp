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
template <uint_t N_ROW, uint_t M_COL>
static void
transpose(const real_t (&A)[N_ROW * M_COL], real_t (&A_tr)[N_ROW * M_COL])
{
	for (uint_t i = 0; i < N_ROW; ++i) {
		for (uint_t j = 0; j < M_COL; ++j) {
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
template <uint_t N_ROW, uint_t M_COL>
static void
right_multiply(const real_t (&A)[N_ROW * M_COL], const real_t (&x)[M_COL], real_t (&mul)[N_ROW])
{
	for (uint_t i = 0; i < N_ROW; ++i) {
		const real_t (&a)[M_COL] = *matrix_op::select_row<N_ROW, M_COL>(i, A);
		mul[i] = dot_product<M_COL>(a, x);
	}
}

//* matrix multiplication
//* mul = A*B
//*
//* inputs:
//* A - [N_ROW_A * M_COL_A] matrix
//* B - [M_COL_A * M_COL_B] matrix
template <uint_t N_ROW_A, uint_t M_COL_A, uint_t M_COL_B>
static void
multiply(const real_t (&A)[N_ROW_A * M_COL_A], const real_t (&B)[M_COL_A * M_COL_B], real_t (&mul)[N_ROW_A * M_COL_B])
{
	for (uint_t i = 0; i < N_ROW_A * M_COL_B; ++i) {
		mul[i] = 0;
	}

	for (uint_t i = 0; i < N_ROW_A; ++i) {
		for (uint_t k = 0; k < M_COL_A; ++k) {
			for (uint_t j = 0; j < M_COL_B; ++j) {
				mul[i * M_COL_A + j] += A[i * M_COL_A + k] * B[k * M_COL_B + j];
			}
		}
	}
}
} // namespace matrix_op

#endif