#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <stdio.h>

// Given the number of rows and columns, allocates space for the matrix,
// and return the pointer to the matrix.
int **allocateMatrix(int numRows, int numCols);

// Free the space allocated for the matrix.
void freeMatrix(int **matrix, int numRows, int numCols);

// Populate the matrix using the data read from the specified file.
void readMatrix(FILE *fp, int **matrix, int numRows, int numCols);

// Print out the matrix on standard output.
void printMatrix(int **matrix, int numRows, int numCols);

// Compute the range of all the elements in row r of the matrix.
// Recall the range is the maximum minus the minimum.
int rangeRow(int **matrix, int numRows, int numCols, int r); 

// Print the four values at the corners of the matrix in the following format.
// top-left    top-right
// bottom-left bottom-right
void printCorners(int **matrix, int numRows, int numCols);

// Return the sum of all the elements in the specified submatrix.
int sumSubMatrix(int **matrix, int startRow, int endRow, int startCol, int endCol);

#endif
