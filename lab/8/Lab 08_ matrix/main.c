#include <stdio.h>

#include "matrix.h"

int main(int argc, char *argv[]) {
    if (argc!=2) {
        printf("Usage: %s datafile\n", argv[0]);
        return 1;
    }

    FILE *fp=fopen(argv[1], "r");
    if (fp==NULL) {
        printf("Unable to open %s for reading\n", argv[1]);
        return 2;
    }

    int **matrix;
    int numRows, numCols;
    fscanf(fp, "%d%d", &numRows, &numCols);
    printf("numRows=%d, numCols=%d\n", numRows, numCols);

    matrix = allocateMatrix(numRows, numCols);

    readMatrix(fp, matrix, numRows, numCols);
    printMatrix(matrix, numRows, numCols);

    printf("The range of the first row is %d\n", rangeRow(matrix, numRows, numCols, 0) );
    printf("The range of the last row is %d\n", rangeRow(matrix, numRows, numCols, numRows-1) );

    printCorners(matrix, numRows, numCols);
    
    int startRow, endRow, startCol, endCol;
    printf("Enter the startRow, endRow, startCol, endCol (zero-based):\n");
    scanf("%d%d%d%d", &startRow, &endRow, &startCol, &endCol);
    printf("Sum of submatrix is %d\n", sumSubMatrix(matrix, startRow, endRow, startCol, endCol));

    freeMatrix(matrix, numRows, numCols);

    return 0;
}
