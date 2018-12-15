#pragma once
#include "types.h"
//(Image<T, i_rows, i_cols>& in, Image<T, i_rows, i_cols>& out, Image<T, k_rows, k_cols>& kernel)

class ImageProcessingSW
{
public:
    // Convolution functions
	template<typename T_img, typename T_kernel, size_t i_rows, size_t i_cols, size_t k_rows, size_t k_cols >
	void convolve
	(T_img in[i_rows][i_cols], T_img out[i_rows][i_cols], T_kernel kernel[k_rows][k_cols])
	{
		// assert that k rows and cols are uneven
		assert(k_rows % 2 != 0);
		assert(k_cols % 2 != 0);

		typedef unsigned int TOffset;

		// At the boundary of the matrix, convolution is not possible.
		// Since the kernel lies outside the matrix.
		// Instead these pixels are ignored.
		const TOffset rs = floor((k_rows - 1) / 2);
		const TOffset cs = floor((k_cols - 1) / 2);

		const TOffset re = i_rows - rs;
		const TOffset ce = i_cols - cs;

		for (TOffset r = rs; r < re; ++r)
			for (TOffset c = cs; c < ce; ++c)
			{
				T_img sum = 0;
				for (TOffset kc = 0; kc < k_cols; ++kc)
					for (TOffset kr = 0; kr < k_rows; ++kr)
					{
						unsigned int row_offset = r - rs + kr;
						unsigned int col_offset = c - cs + kc;
						sum += in[row_offset][col_offset] * kernel[kr][kc];
					}
				out[r][c] = sum;
			}
	};

};