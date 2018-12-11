#include "imageProcessingAlgorithms.h"
#include <math.h>

Image ImageProcessingAlgorithms::divideImageWithValue(Image img, int val)
{
	for (int c = 0; c < COLUMNS; ++c)
		for (int r = 0; r < ROWS; ++r)
		{
			img.mat[r][c] = static_cast<float>(img.mat[r][c])/val;
		}
	return img;
}


floatImage ImageProcessingAlgorithms::multiplyImageWithDouble(Image img, floatImage outImg, float val)
{
	for (int c = 0; c < COLUMNS; ++c)
		for (int r = 0; r < ROWS; ++r)
		{
			outImg.mat[r][c] = static_cast<float>(img.mat[r][c]) * val;
		}
	return outImg;
}

Image ImageProcessingAlgorithms::sqrtOfImage(Image img)
{
	for (int c = 0; c < COLUMNS; ++c)
		for (int r = 0; r < ROWS; ++r)
		{
			img.mat[r][c] = sqrt(img.mat[r][c]);
		}
	return img;
}

Image ImageProcessingAlgorithms::addImages(Image img1, Image img2)
{
	// todo: check that the size of the images are the same
	for (int c = 0; c < COLUMNS; ++c)
		for (int r = 0; r < ROWS; ++r)
		{
			img1.mat[r][c] = img1.mat[r][c] + img2.mat[r][c];
		}
	return img1;
}

Image ImageProcessingAlgorithms::powerOfImage(Image img, int power)
{
	for (int c = 0; c < COLUMNS; ++c)
		for (int r = 0; r < ROWS; ++r)
		{
			img.mat[r][c] = pow(static_cast<float>(img.mat[r][c]), power);
		}
	return img;
}


void ImageProcessingAlgorithms::scaleImage(Image& img, int value)
{
	for (int c = 0; c < COLUMNS; ++c)
		for (int r = 0; r < ROWS; ++r)
		{
			img.mat[r][c] = static_cast<float>(img.mat[r][c])/value;
		}
}


void ImageProcessingAlgorithms::convolve2Dimg2Dkernel(Image in, Image&out, float kernel[KERNELSIZE][KERNELSIZE])
{
	int offset = static_cast<int>(KERNELSIZE-1)/2;
	int row_start = offset;
    int row_end = ROWS - offset - 1;
    int col_start = offset;
    int col_end = COLUMNS - offset - 1;

	int sum = 0;
	int row_offset = 0;
	int col_offset = 0;

	for (int col = col_start; col < col_end; ++col)
		for (int row = row_start; row < row_end; ++row)
		{
			sum = 0;
			for (int kCol =  0; kCol < KERNELSIZE; ++kCol)
				for (int kRow = 0; kRow < KERNELSIZE; ++kRow)
				{
					row_offset = row - offset + kRow;
					col_offset = col - offset + kCol;
					sum += ((int)in.mat[row_offset][col_offset]) * kernel[kRow][kCol];

				}
				// hack to ensure we dont get weird values
				if (sum > 255)
					sum = 255;
				if (sum < 0)
					sum = 0;
				out.mat[row][col] = sum;
		}
}



void ImageProcessingAlgorithms::convolve2Dimg1Dkernel(Image in, Image& out, float* kernel)
{
    int offset = int((KERNELSIZE-1)/2);
	// Set up the offsets, so that we don't convolve the edge of the image with the kernel width
    int row_start = offset;
    int row_end = ROWS - offset - 1;
    int col_start = offset;
    int col_end = COLUMNS - offset - 1;

	for (int col = col_start; col < col_end; ++col)
		for (int row = row_start; row < row_end; ++row)
		{
			float sum = 0;
			for (int j = 0; j < KERNELSIZE; ++j)
			{
				int rowOffset = row - offset + j;
				int colOffset = col - offset + j;
				sum += (int)in.mat[rowOffset, colOffset] * kernel[j];
			}
			out.mat[row][col] = sum;
		}	
}

void ImageProcessingAlgorithms::convolve1Dimg1Dkernel(Image in, Image& out, float* kernel)
{
    int offset = int((KERNELSIZE-1)/2);
	int sum = 0;
	int startOffset = offset;
	//int endOffset = 

	for (int i = startOffset; i < ELEMENTS; ++i)
	{
		sum = 0;
		for (int j = 0; j < KERNELSIZE; ++j)
		{
			int kOffset = i - offset + j;

			sum += static_cast<int>(in.vect[kOffset]) * kernel[j];
		}
		out.vect[i] = sum;
	}	
}