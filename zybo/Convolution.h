#pragma once
#include "types.h"

#define KERNELSIZE 3
#define ROWS 50
#define COLUMNS 50

class Convolution
{
public:
	template<typename T, T_size rows, T_size cols>
	void convolve2Dimg2Dkernel(Image<T,rows,cols> in, Image<T, rows, cols> &out, float kernel[KERNELSIZE][KERNELSIZE])
	{
		int offset = static_cast<int>(KERNELSIZE - 1) / 2;
		int row_start = offset;
		int row_end = ROWS - offset - 1;
		int col_start = offset;
		int col_end = COLUMNS - offset - 1;

		int sum = 0;
		int row_offset = 0;
		int col_offset = 0;

		for (int col = col_start; col < col_end; ++col)
		{
			for (int row = row_start; row < row_end; ++row)
			{
				sum = 0;
				for (int kCol = 0; kCol < KERNELSIZE; ++kCol)
				{
					for (int kRow = 0; kRow < KERNELSIZE; ++kRow)
					{
						row_offset = row - offset + kRow;
						col_offset = col - offset + kCol;
						sum += ((int)in.mat[row_offset][col_offset]) * kernel[kRow][kCol];
					}
				}
				// hack to ensure we dont get weird values
				if (sum > 255)
					sum = 255;
				if (sum < 0)
					sum = 0;
				out.mat[row][col] = sum;
			}
		}
	}
};