#include <iostream>
#include "types.h"
#include "LoaderFile.h"
#include <assert.h>
#include "ImageProcessingSW.h"


constexpr size_t img_rows = 512;
constexpr size_t img_cols = 512;


constexpr size_t kernel_size = 3;

constexpr float f = (1 / float(9));

typedef float T_data;
typedef float T_kernel;

Image<T_data, img_rows, img_cols> in;
Image<T_data, img_rows, img_cols> out;
Image<T_kernel, kernel_size, kernel_size> kernel = { f,f,f,f,f,f,f,f,f };
//Image<T_kernel, kernel_size, kernel_size> kernel = { -1,-2,-1,0,0,0,1,2,1};

int main(int, char**) 
{
	ILoader<T_data>& loader = LoaderFile<T_data>("in_file","out_file");

	size_t s = loader.LoadData(in.vect);
	assert(s == img_rows * img_cols);

	ImageProcessingSW processor;	

	processor.convolve<T_data, T_kernel, img_rows, img_cols, kernel_size, kernel_size>(in.mat, out.mat, kernel.mat);

	loader.ExportData(out.vect, s);

	return 0;
}
