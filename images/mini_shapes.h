#pragma once

#define ROWS 50
#define COLUMNS 50
#define ELEMENTS 2500

typedef unsigned char TData;

// Union type allows same data to be accessed as either a vector or a matrix
union Image
{
  TData vect[ELEMENTS];
  TData mat[ROWS][COLUMNS];  
};

extern Image img = {.vect = { 
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,120,120,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,120,0,0,0,120,120,0,0,138,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,0,0,0,0,0,120,0,0,0,0,0,120,120,0,138,0,0,0,0,0,0,0,0,233,0,0,0,0,0,0,138,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,138,0,0,0,120,0,0,138,0,0,0,0,0,138,0,0,0,0,0,0,0,0,233,233,0,0,0,0,0,0,138,0,0,0,0,120,0,0,0,0,0,0,98,0,0,0,0,0,138,138,0,0,0,0,120,0,0,138,0,0,0,0,0,0,138,0,0,0,0,0,0,233,0,0,233,0,0,0,0,0,0,138,138,0,0,120,0,0,0,0,0,0,98,0,0,0,0,138,0,0,0,0,0,0,120,0,0,138,0,0,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,0,138,0,120,0,0,0,0,0,0,98,0,0,0,138,0,0,0,0,0,0,0,120,0,0,138,0,0,0,0,0,0,0,138,0,0,0,233,0,0,0,0,0,0,233,0,0,0,0,0,0,0,138,120,0,0,0,0,0,0,98,98,138,138,0,0,0,0,0,0,0,0,120,0,0,138,0,0,0,0,0,0,0,0,138,0,233,0,0,0,0,0,0,0,0,233,0,0,0,0,0,0,0,120,0,0,0,0,0,0,98,138,0,0,0,0,0,0,0,0,0,0,120,0,0,138,0,0,0,0,0,0,0,0,0,138,0,0,0,0,0,0,0,0,0,0,233,0,0,0,0,0,0,120,138,138,0,0,0,0,138,98,0,0,0,0,0,0,120,0,0,0,120,0,0,138,0,0,0,0,0,0,0,0,233,138,0,0,0,0,0,0,0,0,0,0,0,233,0,0,0,0,0,120,0,0,138,0,138,138,98,98,0,0,0,0,0,0,120,0,0,0,120,0,0,138,0,0,0,0,0,0,0,233,0,0,138,0,0,0,0,0,0,0,0,0,0,0,233,0,0,0,0,120,0,0,0,138,0,0,98,98,0,0,0,0,0,0,120,0,0,0,120,0,0,138,0,0,0,0,0,0,233,0,0,0,0,138,0,0,0,0,0,0,0,0,0,0,0,233,0,0,0,120,0,138,138,0,138,0,98,98,0,0,0,0,0,0,120,0,0,0,120,0,0,138,0,0,0,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,0,0,0,233,0,0,0,120,138,0,0,0,0,138,98,0,98,0,0,0,0,0,120,0,0,0,120,0,0,138,0,0,0,0,0,233,0,0,0,0,0,0,138,0,0,0,0,0,0,0,0,0,0,0,233,0,0,120,0,0,0,0,0,0,138,138,98,0,0,0,0,0,120,0,0,0,120,0,0,138,0,0,0,0,233,0,0,0,0,0,0,0,0,138,0,0,0,0,0,0,0,0,0,0,0,138,138,120,0,0,0,0,0,0,98,0,138,0,0,0,0,0,120,0,0,0,120,0,0,138,0,0,0,233,0,0,0,0,0,0,0,205,205,138,205,205,205,205,205,205,205,205,205,205,138,205,233,120,205,205,205,205,205,0,98,0,98,138,0,0,0,0,120,0,0,0,120,0,0,138,0,0,233,0,0,0,0,0,0,0,0,205,0,0,138,0,0,0,0,0,0,0,0,138,0,0,0,120,0,0,0,0,205,0,98,0,98,0,138,0,0,0,120,0,0,0,120,0,0,138,0,0,0,233,0,0,0,0,0,0,0,205,0,0,0,138,0,0,0,0,0,138,138,0,0,0,233,120,0,0,0,0,205,0,98,0,98,0,0,138,138,0,120,0,0,0,120,0,0,138,0,0,0,0,233,0,0,0,0,0,0,205,0,0,0,138,0,0,0,0,138,0,0,0,0,233,0,120,0,0,0,0,205,0,98,0,0,98,0,0,0,138,120,0,0,0,120,0,0,138,0,0,0,0,0,233,0,0,0,0,0,205,0,0,0,0,138,0,138,138,0,0,0,0,233,0,0,120,0,0,0,0,205,0,98,0,0,98,0,0,0,120,120,0,0,0,120,0,0,138,0,0,0,0,0,0,233,0,0,0,0,205,0,0,0,0,0,138,0,0,0,0,0,233,0,0,0,120,0,0,0,0,205,0,98,0,0,98,0,120,120,0,120,0,0,0,120,0,0,138,0,0,0,0,0,0,233,0,0,0,0,205,0,0,0,0,138,138,0,0,0,0,0,233,0,0,0,120,0,0,0,0,205,0,98,0,0,120,120,0,0,0,120,0,0,0,120,0,0,138,0,0,0,0,0,0,0,233,0,0,0,205,0,0,138,138,0,0,138,0,0,0,233,0,0,0,0,120,0,0,0,0,205,0,98,0,120,98,0,0,0,0,0,120,0,0,120,0,0,138,0,0,0,0,0,0,0,0,233,0,0,205,0,138,0,0,0,0,0,138,0,233,0,0,0,0,0,120,0,0,0,0,205,0,120,120,0,98,0,0,0,0,0,120,0,0,120,0,0,138,0,0,0,0,0,0,0,0,0,233,0,138,138,0,0,0,0,0,0,138,233,0,0,0,0,0,0,120,0,0,0,0,120,120,98,0,0,0,98,0,0,0,0,120,0,0,120,0,0,138,0,0,0,0,0,0,0,0,0,0,138,205,0,0,0,0,0,0,0,233,138,0,0,0,0,0,0,120,0,0,0,120,205,0,98,0,0,0,98,0,0,0,0,120,0,0,120,0,0,138,0,0,0,0,0,0,0,0,0,138,0,233,0,0,0,0,0,0,233,0,0,138,0,0,0,0,0,120,0,120,120,0,205,0,98,0,0,0,98,0,0,0,0,120,0,0,120,0,0,138,0,0,0,0,0,0,0,138,138,0,0,205,233,0,0,0,0,233,0,0,0,138,0,0,0,0,0,120,120,0,0,0,205,0,98,0,0,0,98,0,0,0,0,120,0,0,120,0,0,138,0,0,0,0,0,0,138,0,0,120,0,205,0,233,0,0,233,0,0,0,0,0,138,0,0,120,120,120,0,0,0,0,205,0,98,0,0,0,98,0,0,0,0,120,0,0,120,0,0,138,0,0,0,0,0,138,0,0,0,120,0,205,0,0,233,233,0,0,0,0,0,0,0,138,120,0,0,120,0,0,0,0,205,0,98,0,0,0,0,98,0,0,0,120,0,0,120,0,0,138,0,0,0,138,138,0,0,0,0,0,120,205,0,0,233,233,0,0,0,0,0,0,120,120,0,0,0,120,0,0,0,0,205,0,98,0,0,0,0,98,0,0,0,120,0,0,120,0,0,138,0,0,138,0,0,0,0,0,0,0,120,205,0,0,0,0,0,0,0,0,120,120,0,0,138,0,0,120,0,0,0,0,205,0,98,0,0,0,0,98,0,0,0,120,0,0,120,0,0,138,0,0,0,0,138,138,0,0,0,0,120,205,0,0,0,0,0,0,0,120,0,0,0,0,0,138,0,120,0,0,0,0,205,0,98,0,0,0,0,98,0,0,0,120,0,0,120,0,0,138,0,0,0,0,0,0,138,138,0,0,120,205,0,0,0,0,0,120,120,0,0,0,0,0,0,138,0,120,0,0,0,0,205,0,98,0,0,0,0,98,0,0,0,120,0,0,120,0,0,138,0,0,0,0,0,0,0,0,138,138,138,120,0,0,0,120,120,0,0,0,0,0,0,0,0,0,138,120,0,0,0,0,205,0,98,0,0,0,0,98,0,0,0,120,0,0,120,0,0,138,0,0,0,0,0,0,0,0,0,0,0,120,138,0,120,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,205,0,98,0,0,0,0,0,98,0,0,120,0,0,120,0,0,138,0,0,0,0,0,0,0,0,0,0,0,120,120,120,138,138,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,205,0,98,0,0,0,0,0,98,0,0,0,0,0,120,0,0,138,0,0,0,0,0,0,0,0,0,0,120,120,205,205,205,205,138,138,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,0,98,0,0,0,0,0,98,0,0,0,0,0,120,0,0,0,0,0,0,0,0,0,0,0,0,120,0,0,120,0,0,0,0,0,138,138,138,0,0,0,0,0,0,0,0,0,0,0,0,0,98,0,0,0,0,0,98,0,0,0,0,0,120,0,0,0,0,0,0,0,0,0,0,120,120,0,0,0,120,0,0,0,0,0,0,0,0,138,138,0,0,0,0,0,0,0,0,0,0,0,98,0,0,0,0,0,98,0,0,0,0,0,120,0,0,0,0,0,0,0,0,120,120,0,0,0,0,0,120,0,0,0,0,0,0,0,0,0,0,138,138,138,0,0,0,0,0,0,0,0,98,0,0,0,0,0,98,0,0,0,0,0,120,0,0,0,0,0,0,120,120,0,0,0,0,0,0,0,120,0,0,0,0,0,0,0,0,0,0,0,0,0,138,138,0,0,0,0,0,0,98,0,0,0,0,0,0,98,0,0,0,0,120,0,0,0,0,0,120,0,0,0,0,0,0,0,0,0,0,120,0,0,0,0,0,0,0,0,0,0,0,0,0,0,138,138,138,0,0,0,98,0,0,0,0,0,0,98,0,0,0,0,0,0,0,0,120,120,209,209,209,209,209,209,209,209,209,209,209,120,209,209,209,209,209,209,209,209,209,209,209,209,209,209,209,209,0,138,138,0,98,98,98,98,98,98,98,98,0,0,0,0,0,0,120,120,0,0,0,0,0,0,0,0,0,0,0,0,0,120,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,138,138,138,0,0,0,0,0,0,0,0,0,0,0,120,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,120,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,138,138,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,0,0,0,0,0,0,0,120,120,120,120,120,120,120,120,120,120,120,120,0,0,120,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 
} };