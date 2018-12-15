#pragma once
#include "types.h"


/*
Interface for classes that provides algorithms related to image processing.
The purpose of this interface is to facilitate allocating functionality to either software or hardware implementations.
*/
class IImageProcessing
{
public:
	
	/*
	Performs a convolution of the image with the specified kernel
	@param in the input image
	@param out the result of the convolution
	@param kernel the kernel used for the convolution
	*/
	template<typename T_image, typename T_kernel, T_size i_rows , T_size i_cols, T_size k_rows, T_size k_cols>
	void convolve
	(
	const Image<T_image,i_rows,i_cols>& in,
	Image<T_image, i_rows, i_cols>& out,
	const Image<T_kernel, k_rows, k_cols> kernel
	);

};