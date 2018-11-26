#include "image_union.h"
#include <iostream>
//#include "exporter.h"
#include <fstream>
#include <string>

#define KERNELSIZE 3

void convolute(Image in, Image out, double* kernel)
{
	for (int i = 0; i < ELEMENTS; ++i)
	{
		int sum = 0;
		for (int j = 0; j < KERNELSIZE; ++j)
		{
			int kOffset = i - ((KERNELSIZE - 1) / 2) + j;

			if (kOffset >= 0 || kOffset > ELEMENTS)
				sum += in.vect[kOffset] * kernel[j];
		}
		out.vect[i] = sum;
	}		
}


static void Export_CSV(Image data)
{
    std::ofstream f;
    f.open("image_processed.csv", std::ios::out | std::ios::trunc);
    
    if(!f.is_open())
    {
        std::cout << "Failed exporting file, could not open file" << std::endl;
        return;
    }

    for (int i = 0; i < ELEMENTS-1; ++i)
        f << data.vect[i] << ",";

    f << data.vect[ELEMENTS-1] << std::endl;
}

int main(int, char**) 
{
	Image out = {};
	
	double k1[] = { -0.70710678 , 0  , 0.70710678 };
	double k2[] = { -0.40824829, -0.81649658  , -0.40824829 };

	convolute(img, out, k1);
	convolute(out, img, k2); // use input buffer as output


	std::cout << "hello world" << std::endl;
  	Export_CSV(img);

  return 0;
}
