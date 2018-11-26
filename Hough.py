import convert_image
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.cm as cm

# First use, create header
#loadImage.write_header(loadImage.preprocess_image("image"), "image.h", delimiter=", ")



def hough_transform(edgeImg):
    # Hough preparation
    edgeImgRows = edgeImg.shape[0]
    edgeImgCols = edgeImg.shape[1]

    edgeImgDiagonal = int(np.power((np.sqrt(edgeImgRows + edgeImgCols)), 2))

    # Accumulator for Hough Space
    acc = np.zeros((2*edgeImgDiagonal, 180))

    # Calculating Hough Space
    for r in range(0, edgeImgRows):
        for c in range(0, edgeImgCols):
            if edgeImg[r,c] == 1:
                for fi in range(0, 180):
                    d = int(round((r*np.cos(np.pi*fi/180)+c*np.sin(np.pi*fi/180))+edgeImgDiagonal))
                    acc[d, fi] += 1

    # Normalize hough space
    acc = acc/np.amax(acc)
    houghSpace = 1 - acc

    [d, fi] = np.nonzero(acc > 0.55)

    # Put lines on picture // needs finishing
    dK = np.zeros((edgeImgRows, edgeImgCols))

    for k in range(0, len(fi)):
        for s in range(0, edgeImgCols):
            r =int(round(-np.tan(np.pi*fi[k]/180)*s + (d[k]-edgeImgDiagonal)/np.cos(np.pi*fi[k]/180)))
            if 1 < r and r < edgeImgRows:
                    dK[r, s] = 255

    dK = (dK)/255
    img_w_lines = dK  + edgeImg

    return img_w_lines
