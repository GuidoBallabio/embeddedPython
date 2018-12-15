#pragma once
#include "types.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class ImageMaths
{
public:
	template<typename T_img, size_t i_rows, size_t i_cols>
	static void threshold(T_img in[i_rows][i_cols], T_img out[i_rows][i_cols], uint8_t threshold)
	{
		for (int c = 0; c < i_cols; c++)
		{
			for (int r = 0; r < i_rows; r++)
			{
				out[r][c] = (in[r][c] >= threshold ? 1 : 0);
			}
		}
	}

	template<typename T_img, size_t i_rows, size_t i_cols>
	static T_img mean(T_img in[i_rows][i_cols])
	{
		long meanVal = 0;
		for (int c = 0; c < i_cols; c++)
		{
			for (int r = 0; r < i_rows; r++)
			{
				meanVal += in[r][c];
			}
		}
		meanVal = meanVal / (i_rows * i_cols);
		return meanVal;
	}

	template<typename T_img, size_t i_rows, size_t i_cols>
	static T_img findMax(T_img in[i_rows][i_cols])
	{
		T_img accMax = 0;
		for (int c = 0; c < i_cols; c++)
		{
			for (int r = 0; r < i_rows; r++)
			{
				if (in[r][c] > accMax)
				{
					accMax = in[r][c];
				}
			}
		}
		return accMax;
	}

	template<typename T_img, size_t i_rows, size_t i_cols>
	static void scaleImage(T_img in[i_rows][i_cols], T_img out[i_rows][i_cols], T_img accMax)
	{
		for (int c = 0; c < i_cols; c++)
		{
			for (int r = 0; r < i_rows; r++)
			{
				out[r][c] = in[r][c] / accMax;
			}
		}
	}

	template<typename T_img, size_t i_rows, size_t i_cols>
	static void addImages(T_img in1[i_rows][i_cols], T_img in2[i_rows][i_cols], T_img out[i_rows][i_cols])
	{
		for (int c = 0; c < i_cols; c++)
		{
			for (int r = 0; r < i_rows; r++)
			{
				out[r][c] = in1[r][c] + in2[r][c];
			}
		}
	}
};