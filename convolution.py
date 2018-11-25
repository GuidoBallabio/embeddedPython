import numpy as np


def convolution(img, kernel):
    nCols = img.shape[1]
    nRows = img.shape[0]
    nK = kernel.shape[1] # assume square matrix
    
    offset = int((nK-1)/2)
    row_start = offset
    row_end = nRows - offset - 1
    col_start = offset
    col_end = nCols - offset - 1
    
    out = np.zeros((nRows-offset,nCols-offset))
    
    for col in range(col_start,col_end):
        for row in range(row_start,row_end):
            s = 0
            for k_col in range(0,nK):
                for k_row in range(0,nK):
                    row_offset = row - offset + k_row
                    col_offset = col - offset + k_col
                    s = s + (img[row_offset, col_offset]) * kernel[k_row,k_col]
            out[row,col] = s
    return out
