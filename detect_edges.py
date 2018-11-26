import convolution
import numpy as np



def detect_edges_sobel(img):
    sobel_horizontal = np.array([[1, 2, 1], [0, 0, 0], [-1, -2, -1]])
    sobel_vertical = np.array([[1, 0, -1],[2, 0, -2],[1, 0, -1]])
    sobel = sobel_horizontal * sobel_vertical

    nRows = img.shape[0]
    nCols = img.shape[1]
    flattened = img.reshape(-1)

    #img_sobel_h = convolution.convolution_separable(flattened, sobel_horizontal)
    #img_sobel_v = convolution.convolution_separable(flattened, sobel_vertical)
    #img_sobel = abs(1/np.sqrt(2)) * np.sqrt( (img_sobel_v)**2 + (img_sobel_h)**2 )

    img_sobel = convolution.convolution_separable(flattened, sobel)
    img_sobel = img_sobel.reshape((nRows, nCols))

    return img_sobel


