#!/usr/bin/python

import cv2 as cv
import numpy as np
from io import StringIO
from textwrap import dedent

import argparse
import detect_edges


def preprocess_image(image_file):
    # read image
    img = cv.imread("sudoku.png", cv.IMREAD_GRAYSCALE)
    # edge detection
    #edges = cv.Canny(img, 50, 200, None, 3)
    edges = detect_edges.detect_edges_sobel(img)

    return edges
    
def write_header(image_arr, output_file, delimiter=', '):
    '''
    Given an image array (2D) writes a C/C++ header file which statically defines it.
    '''

    tmp_file = StringIO()

    np.savetxt(tmp_file, image_arr, fmt="%d", delimiter=delimiter)

    rows = map(lambda x: '{' + x[:] + '},', tmp_file.getvalue().splitlines())
    full = "\n".join(rows)[:-1]

    file_header = f"""\
            #pragma once

            #define ROWS {image_arr.shape[0]}
            #define COLUMNS {image_arr.shape[1]}

            static const unsigned char image[ROWS][COLUMNS] = {{{{
            {{}} 
            }}}};
            #endif
           """

    with open(output_file, "w") as f:
        f.write(dedent(file_header).format(full))
        
def read_header(header_file, delimiter=', '):
    '''
    Read header file and outputs the relative array.
    '''

    with open(header_file, "r") as f:
        s = f.read()

    s = s.split('\n', 6)[6][:-11]  # original output of np.savetxt

    rows2 = map(lambda x: x[1:-2], s.splitlines())
    full2 = "\n".join(rows2)

    tmp_file = StringIO(full2)
    arr = np.loadtxt(tmp_file, dtype=np.uint8, delimiter=delimiter)
    
    return arr
    
    
if __name__ == '__main__':
    parser = argparse.ArgumentParser(prog='convert-image')
    parser.add_argument('--delimiter', '-d', default=', ')
    subparsers = parser.add_subparsers(dest='command', title='subcommands')
    
    create_header = subparsers.add_parser('header')
    create_header.add_argument('image')
    create_header.add_argument('--output', '-o', default="image.h")

    args = parser.parse_args()
    
    if args.command == 'header':
        write_header(preprocess_image(args.image), args.output, delimiter=args.delimiter)
