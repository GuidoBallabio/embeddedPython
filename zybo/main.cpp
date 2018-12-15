#include <iostream>
#include "types.h"
#include "LoaderFile.h"
#include <assert.h>
#include "ImageProcessingSW.h"
#include "HoughTransformSW.h"


constexpr size_t img_rows = 256;
constexpr size_t img_cols = 256;
constexpr size_t acc_rows = (img_rows + img_cols) * 2;
constexpr size_t acc_cols = 180;


constexpr size_t kernel_size = 3;

constexpr float f = (1 / float(9));

typedef int16_t T_data;
typedef float T_kernel;
typedef float T_accumulator;

// Images for outputing data
Image<T_data, img_rows, img_cols> in;
Image<T_data, img_rows, img_cols> out = { 0 };
Image<T_data, img_rows, img_cols> blur;
Image<T_data, img_rows, img_cols> edge = { 0 };
Image<T_data, img_rows, img_cols> thresholded;
// Hough
Image<T_data, img_rows, img_cols> hough_lines;
Image<T_accumulator, acc_rows, acc_cols> accumulator = { 0 };
float dNonZero[img_cols * img_rows] = { 0 };
float fiNonZero[img_cols * img_rows] = { 0 };
// Convolution: blur and edge
Image<T_kernel, kernel_size, kernel_size> blur_kernel = { f,f,f,f,f,f,f,f,f };
Image<T_kernel, kernel_size, kernel_size> sobel_kernel = { 2,2,0,2,0,-2,0,-2,-2 };

int main(int, char**) 
{
	LoaderFile<T_data>& loader = LoaderFile<T_data>("in_file","out_file_blur");

	size_t s = loader.LoadData(in.vect);
	assert(s == img_rows * img_cols);

	ImageProcessingSW processor;	
	HoughTransformSW hough;

	processor.convolve<T_data, T_kernel, img_rows, img_cols, kernel_size, kernel_size>(in.mat, blur.mat, blur_kernel.mat);
	loader.ExportData(blur.vect, s);

	loader.SetOutputFile("out_file_blur_edge");
	processor.convolve<T_data, T_kernel, img_rows, img_cols, kernel_size, kernel_size>(blur.mat, edge.mat, sobel_kernel.mat);
	loader.ExportData(edge.vect, s);

	loader.SetOutputFile("out_file_threshold");
	T_data meanVal = ImageMaths::mean<T_data, img_rows, img_cols>(in.mat);
	ImageMaths::threshold<T_data, img_rows, img_cols>(edge.mat, thresholded.mat, meanVal);
	loader.ExportData(thresholded.vect, s);

	loader.SetOutputFile("out_file_hough_lines");
	hough.houghTransform<T_data, T_accumulator, img_rows, img_cols, acc_rows, acc_cols>(thresholded.mat, hough_lines.mat, accumulator.mat, dNonZero, fiNonZero, 0.40f);
	loader.ExportData(hough_lines.vect, s);

	loader.SetOutputFile("out_file_hough_img");
	ImageMaths::threshold<T_data, img_rows, img_cols>(in.mat, out.mat, 50);
	ImageMaths::addImages<T_data, img_rows, img_cols>(hough_lines.mat, out.mat, out.mat);
	loader.ExportData(out.vect, s);

	return 0;
}
