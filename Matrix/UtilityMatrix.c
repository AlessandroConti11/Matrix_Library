#include <assert.h>
#include <stdlib.h>

#include "../Matrix.h"


/**
 * Swaps 2 rows of a matrix.
 *
 * @param n the number of row.
 * @param m the number of column.
 * @param a the matrix - M: n x m.
 * @param row1 the first row to swap.
 * @param row2 the second row to swap.
 * @param swap the swapped matrix.
 */
void swapRowMatrix(int n, int m, float** a, int row1, int row2, float** swap) {
    assert(n > 0);
    assert(m > 0);
    assert(row1 <= n);
    assert(row2 <= n);
    
    //Temporary variable used for the swap procedure.
    float tmp = 0;

    copyMatrix(n, m, a, swap);

    for (int i = 0; i < m; ++i) {
        tmp = a[row1][i];
        swap[row1][i] = a[row2][i];
        swap[row2][i] = tmp;
    }
}

/**
 * Swaps 2 columns of a matrix.
 *
 * @param n the number of row.
 * @param m the number of column.
 * @param a the matrix - M: n x m.
 * @param col1 the first column to swap.
 * @param col2 the second column to swap.
 * @param swap the swapped matrix.
 */
void swapColumnMatrix(int n, int m, float** a, int col1, int col2, float** swap) {
    assert(n > 0);
    assert(m > 0);
    assert(col1 <= m);
    assert(col2 <= m);
    
    //Temporary variable used for the swap procedure.
    float tmp = 0;

    copyMatrix(n, m, a, swap);

    for (int i = 0; i < n; ++i) {
        tmp = a[i][col1];
        swap[i][col1] = a[i][col2];
        swap[i][col2] = tmp;
    }
}

/**
 * Find the maximum value in a matrix.
 *
 * @param n the number of row.
 * @param m the number of column.
 * @param a the matrix - M: n x m.
 * @param rowPos the row that contains the position with the maximum value.
 * @param colPos the column that contains the position with the maximum value.
 * @return the maximum value in the matrix.
 */
float findMaxMatrix(int n, int m, float** a, int* rowPos, int* colPos) {
    //Initialize the maximum value.
    float max = a[0][0];
    *rowPos = 0;
    *colPos = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] > max) {
                max = a[i][j];
                *rowPos = i;
                *colPos = j;
            }
        }
    }
    return max;
}

/**
 * Find the minimum value in a matrix.
 *
 * @param n the number of row.
 * @param m the number of column.
 * @param a the matrix - M: n x m.
 * @param rowPos the row that contains the position with the minimum value.
 * @param colPos the column that contains the position with the minimum value.
 * @return the minimum value in the matrix.
 */
float findMinMatrix(int n, int m, float** a, int* rowPos, int* colPos) {
    //Initialize the maximum value.
    float min = a[0][0];
    *rowPos = 0;
    *colPos = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] < min) {
                min = a[i][j];
                *rowPos = i;
                *colPos = j;
            }
        }
    }
    return min;
}

/**
 * Finds the elements on a matrix diagonal.
 *
 * @param n the number of row.
 * @param m the number of column.
 * @param a the matrix - M: n x m.
 * @return the list of elements on the matrix diagonal.
 */
float* diagonalMatrix(int n, int m, float** a) {
    assert(n > 0);
    assert(m > 0);

    int min = n < m ? n : m;
    float* diagonalValues = malloc(min * sizeof(float));

    for (int i = 0; i < min; ++i) {
        diagonalValues[i] = a[i][i];
    }

    return diagonalValues;
}


/**
 * Finds the pivots in a matrix.
 *
 * @param n the number of row.
 * @param m the number of column.
 * @param a the matrix - M: n x m.
 * @param pivotsNumber the number of pivots.
 * @return the list of pivots.
 */
float* pivot(int n, int m, float** a, int *pivotsNumber) {
    //The step matrix.
    float** step = createMatrix(n, m);
    //The pivot list.
    float* pivots = malloc(n * sizeof(float));
    //The counter of pivots found.
    int pivotCounter = 0;

    stepMatrix(n, m, a, step);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (step[i][j] != 0) {
                pivots[pivotCounter] = a[i][j];
                pivotCounter++;
                break;
            }
        }
    }

    *pivotsNumber = pivotCounter - 1;
    free(step);
    return pivots;
}

/**
 * Decomposition of a matrix using Lower-Upper Decomposition - [A]=[L]*[U].
 *
 * @param n the matrix order.
 * @param a the matrix - M: n x n.
 * @param l the lower triangular matrix - M: n x n.
 * @param u the upper triangular matrix - M: n x n.
 */
void luDecomposition(int n, float** a, float** l, float** u) {
    assert(n > 0);

    //Used to compute the elements of the matrix U.
    float sum = 0;

    //initialize L and U matrix
    deleteMatrix(n, n, l);
    l = createNullMatrix(n);
    deleteMatrix(n, n, u);
    u = createNullMatrix(n);

    for (int i = 0; i < n; ++i) {
        //compute U matrix
        for (int j = 0; j < n; ++j) {
            sum = 0;
            for (int k = 0; k < i; ++k) {
                sum += l[i][k] * u[k][j];
            }
            u[i][j] = a[i][j] - sum;
        }

        //compute L matrix
        for (int k = 0; k < n; ++k) {
            if (i==k) {
                l[i][i] = 1;
            }
            else {
                sum = 0;
                for (int j = 0; j < i; ++j) {
                    sum += l[k][j] * u[j][i];
                }
                l[k][i] = (float) (a[k][i] - sum) / u[i][i];
                if (l[k][i] == -0) {
                    l[k][i] = 0;
                }
            }
        }
    }
}