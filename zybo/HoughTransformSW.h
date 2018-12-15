#pragma once
#include <cmath>
#include <iostream> 
#include <algorithm>
#include "types.h"
#include "ImageMaths.h"
#include <assert.h>


class HoughTransformSW
{
public:

	template<typename T_img, typename T_acc, size_t i_rows, size_t i_cols, size_t a_rows, size_t a_cols>
	void houghTransform(
		T_img in[i_rows][i_cols], 
		T_img out[i_rows][i_cols], 
		T_acc acc[a_rows][a_cols], 
		T_acc dNonZero[a_rows * a_cols], 
		T_acc fiNonZero[a_rows * a_cols],
		float threshold)
	{
		assert(threshold >= 0 && threshold <= 1);

		int edgeImgDiagonal = 0;
		T_size d = 0;
		T_size outRow = 0;
		T_size nonZeroCount = 0;

		// Edge Image Diagonal
		edgeImgDiagonal += (int)pow(sqrt(i_rows + i_cols), 2);

		// Calculating hough space
		for (T_size c = 0; c < i_cols; c++)
		{
			for (T_size r = 0; r < i_rows; r++)
			{
				if (in[r][c] == 1)
				{
					for (T_size fi = 0; fi < a_cols; fi++)
					{
						d = static_cast<T_size>(roundf((r*cos(M_PI * fi / a_cols) + c * sin(M_PI * fi / a_cols)) + edgeImgDiagonal));
						acc[d][fi]++;
					}
				}
			}
		}

		// Finding max value of ACC
		T_acc accMax = ImageMaths::findMax<T_acc,a_rows,a_cols>(acc);

		// Normalize Hough Space. Divide by max.
		ImageMaths::scaleImage<T_acc, a_rows, a_cols>(acc, acc, accMax);
		
		for (T_size c = 0; c < a_cols; c++)
		{
			for (T_size r = 0; r < a_rows; r++)
			{
				if (acc[r][c] > threshold)
				{
					dNonZero[nonZeroCount] = r;
					fiNonZero[nonZeroCount] = c;
					nonZeroCount++;
				}
			}
		}

		// Putting the lines on a picture. This is an empty matrix with just the lines.
		for (int k = 0; k < nonZeroCount; k++)
		{
			for (int c = 0; c < i_cols; c++)
			{
				outRow = (T_size)round(-tan(M_PI*fiNonZero[k] / a_cols)*c + (dNonZero[k] - edgeImgDiagonal) / cos(M_PI*fiNonZero[k] / a_cols));
				if (outRow > 1 && outRow < i_rows)
				{
					out[outRow][c] = 1;
				}
			}
		}
	};


};