#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include "exporter.h"
#include "imageProcessingAlgorithms.h"
//#include "image_union.h"
#include "math.h"



int main(int, char**) 
{
	Image img_sobel_h = {0};
	Image img_sobel_v = {0};
	Image out = {0};
	Image img_sobel = {0};
	
	// These values are found from performing an SVD on the sobel kernel in python
	double k1[] = { -0.70710678 , 0  , 0.70710678 };
	double k2[] = { -0.40824829, -0.81649658  , -0.40824829 };
	
	float sobel_horizontal[3][3] = { {1, 2, 1}, {0, 0, 0}, {-1, -2, -1} };
	float sobel_vertical[3][3] = { {1,0,-1}, {2,0,-2}, {1,0,-1}};
	float laplacian[KERNELSIZE][KERNELSIZE] = { {1,1,1}, {1,-8,1}, {1,1,1}};
	float sobel[KERNELSIZE][KERNELSIZE] = { {2,2,0}, {2,0,-2}, {0,-2,-2} };

	float val = static_cast<float>(static_cast<float>(1)/9);
	float averageFilter[KERNELSIZE][KERNELSIZE] = {{val, val, val}, {val, val, val}, {val, val, val}};
	
	ImageProcessingAlgorithms::convolve2Dimg2Dkernel(img, out,  averageFilter);

	//convolute(out, img_sobel_h, laplacian);
	//ImageProcessingAlgorithms::convolve2Dimg2Dkernel(out, img_sobel_h, sobel_horizontal);
	//ImageProcessingAlgorithms::convolve2Dimg2Dkernel(out, img_sobel_v, sobel_vertical);
	ImageProcessingAlgorithms::convolve2Dimg2Dkernel(out, img_sobel, sobel);

  	Export_CSV(img_sobel, "./../image_processed.csv");
	std::cout << "Finished exporting img" << std::endl;

  return 0;
}
