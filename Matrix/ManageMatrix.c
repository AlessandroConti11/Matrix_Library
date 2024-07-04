#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdarg.h>

#include "../Matrix.h"


/**
 * Creates a matrix - M: n x m.
 *
 * @param n the number of row.
 * @param m the number of column.
 * @return the matrix - M: n x m.
 */
float** createMatrix(int n, int m) {
    assert(n > 0);
    assert(m > 0);

    //The matrix to create.
    float **a = (float **) malloc(n * sizeof(float *));
    assert(a != NULL);

    for (int i = 0; i < n; ++i) {
        a[i] = (float *) malloc(m * sizeof(float));
        assert(a[i] != NULL);
    }

    return a;
}

/**
 * Creates a identity matrix - M: n x n.
 *
 * @param n the matrix order.
 * @return the identity matrix - M: n x n.
 */
float** createIdentityMatrix(int n) {
    assert(n > 0);

    //The matrix to create.
    float **a = (float **) malloc(n * sizeof(float *));
    assert(a != NULL);

    for (int i = 0; i < n; ++i) {
        a[i] = (float *) calloc(n, sizeof(float));
        assert(a[i] != NULL);

        a[i][i] = 1;
    }

    return a;
}

/**
 * Creates a null matrix - M: n x n.
 *
 * @param n the matrix order.
 * @return the null matrix - M: n x n.
 */
float** createNullMatrix(int n) {
    assert(n > 0);

    //The matrix to create.
    float **a = (float **) malloc(n * sizeof(float *));
    assert(a != NULL);

    for (int i = 0; i < n; ++i) {
        a[i] = (float *) calloc(n, sizeof(float));
        assert(a[i] != NULL);
    }

    return a;
}

/**
 * Initialize a matrix.
 *
 * @param n the number of row.
 * @param m the number of column.
 * @param a the matrix to initialize - M: n x m.
 * @param ... the matrix elements.
 */
void initializeMatrix(int n, int m, float** a, ...) {
    assert(n > 0);
    assert(m > 0);

    //Matrix elements.
    va_list elements;

    va_start(elements, a);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a[i][j] = va_arg(elements, double);
        }
    }

    va_end(elements);
}

/**
 * Copies a matrix.
 *
 * @param n the number of row.
 * @param m the number of column.
 * @param a the matrix to be copied - M: n x m.
 * @param b the copied matrix - M: n x m.
 */
void copyMatrix(int n, int m, float** a, float** b) {
    assert(n > 0);
    assert(m > 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            b[i][j] = a[i][j];
        }
    }
}

/**
 * Deletes a matrix.
 *
 * @param n the number of row.
 * @param m the number of column.
 * @param a the matrix to delete - M: n x m.
 */
void deleteMatrix(int n, int m, float** a) {
    assert(n > 0);
    assert(m > 0);

    if (a == NULL) {
        return;
    }

    //for each row
    for (int i = 0; i < n; i++) {
        free(a[i]);
        assert(a[i] != NULL);
    }

    free(a);
    assert(a != NULL);
}

/**
 * Prints a matrix.
 * digits integer part: 5
 * digits decimal part: 5
 *
 * @param n the number of row.
 * @param m the number of column.
 * @param a the matrix to print - M: n x m.
 */
void printMatrix(int n, int m, float** a) {
    assert(n > 0);
    assert(m > 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%5.5f ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}