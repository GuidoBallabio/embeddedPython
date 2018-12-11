#pragma once
#include "image_union.h"

#define KERNELSIZE 3

class ImageProcessingAlgorithms
{
public:
    // Convolution functions
    static void convolve2Dimg1Dkernel(Image in, Image& out, float* kernel);
    static void convolve1Dimg1Dkernel(Image in, Image& out, float* kernel);
    static void convolve2Dimg2Dkernel(Image in, Image&out, float kernel[KERNELSIZE][KERNELSIZE]);

    // Mathematical operations
    static void scaleImage(Image& img, int value);
    static Image powerOfImage(Image img, int power);
    static Image addImages(Image img1, Image img2);
    static Image sqrtOfImage(Image img);

    static floatImage multiplyImageWithDouble(Image img, floatImage outImg, float val);
    static Image divideImageWithValue(Image img, int val);
};