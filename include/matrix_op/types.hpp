#ifndef TYPES_HPP_CINARAL_220924_1452
#define TYPES_HPP_CINARAL_220924_1452

namespace matrix_op
{
using uint_t = unsigned long long int;
#ifdef __USE_SINGLE_PRECISION__
using real_t = float;
#else
using real_t = double;
#endif
} // namespace matrix_op

#endif
