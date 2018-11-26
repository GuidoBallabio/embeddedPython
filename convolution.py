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


def convolution_separable(data, kernel):
    U,S,V = np.linalg.svd(kernel)
    s = S[0] # scaling factor
    v = U[:,0]
    h = V.T[:,0]

    #a = np.convolve(data,v,mode="same")
    #b = np.convolve(a,h,mode="same")

    nK = kernel.shape[1] # assume square matrix
    offset = int((nK-1)/2)
    nData = data.shape[0]

    outA = np.zeros(nData)
    outB = np.zeros(nData)

    for i in range(offset,nData-offset):
        out_sum = 0
        for k in range(0,nK):
            row_offset = i - offset + k
            out_sum = out_sum + (data[row_offset]) * v[k]
        outA[i] = out_sum

    for i in range(offset,nData-offset):
        out_sum = 0
        for k in range(0,nK):
            row_offset = i - offset + k
            out_sum = out_sum + (outA[row_offset]) * h[k]
        outB[i] = out_sum

    return outB

def convolution_np(data, kernel, einstein=False):
    U,S,V = np.linalg.svd(kernel)
    s = S[0] # scaling factor
    v = U[:,0]
    h = V.T[:,0]

    nK = kernel.shape[1] # assume square matrix
    offset = int((nK-1)/2)
    nData = data.shape[0]

    outA = np.zeros(nData)
    outB = np.zeros(nData)

    def einFun():
        for i in range(offset,nData-offset):
            row_offset = i - offset
            outA[i] += np.einsum('i,i->', data[row_offset:row_offset+nK], v) #(data[row_offset:row_offset+nK]* v).sum()

        for i in range(offset,nData-offset):
            row_offset = i - offset
            outB[i] += np.einsum('i,i->', outA[row_offset:row_offset+nK], h)
    
    def viewFun():
        def rolling_view(a):
            shape = (a.shape[-1] - nK + 1, nK)
            strides = a.strides + (a.strides[-1],)
            return np.lib.stride_tricks.as_strided(a, shape=shape, strides=strides)
        
        view = rolling_view(data)
        outA[offset:-offset] += view @ v

        view = rolling_view(outA)
        outB[offset:-offset] = view @ h  

    if einstein:
        einFun()
    else:
        viewFun()
    return outB
