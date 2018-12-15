#pragma once

typedef size_t T_size;

typedef char T_kernel_data;

// Union type allows same data to be accessed as either a vector or a matrix
template<typename T, size_t rows, size_t cols>
union Image
{
	T vect[rows*cols];
	T mat[rows][cols];
};