#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#include "../Matrix.h"


/**
 * Minor of a matrix.
 *
 * @param n the matrix order.
 * @param a the matrix - M: n x n.
 * @param row the row of the matrix to be deleted.
 * @param column the column of the matrix to be deleted.
 * @return the minor of the matrix.
 */
float minor(int n, float** a, int row, int column) {
    assert(n > 0);
    assert(row >= 0);
    assert(row < n);
    assert(column >= 0);
    assert(column < n);

    //Minor row position.
    int minorRow = 0;
    //Minor column position.
    int minorColumn = 0;
    //Minor.
    float** minor = createMatrix(n - 1, n - 1);

    for (int i = 0; i < n; ++i) {
        if (i != row) {

            minorColumn = 0;
            for (int j = 0; j < n; ++j) {
                if (j != column) {
                    minor[minorRow][minorColumn] = a[i][j];
                    minorColumn++;
                }
            }
            minorRow++;
        }
    }

    return determinantMatrix(n - 1, minor);
}

/**
 * Cofactor of a matrix.
 *
 * @param n the matrix order.
 * @param a the matrix - M: n x n.
 * @param row the row of the matrix to be deleted.
 * @param column the column of the matrix to be deleted.
 * @return the cofactor of the matrix.
 */
float cofactor(int n, float** a, int row, int column) {
    assert(n > 0);
    assert(row >= 0);
    assert(row < n);
    assert(column >= 0);
    assert(column < n);

    //Cofactor row position.
    int cofRow = 0;
    //Cofactor column position.
    int cofColumn = 0;
    //Cofactor.
    float** cof = createMatrix(n - 1, n - 1);

    for (int i = 0; i < n; ++i) {
        if (i != row) {

            cofColumn = 0;
            for (int j = 0; j < n; ++j) {
                if (j != column) {
                    cof[cofRow][cofColumn] = a[i][j];
                    cofColumn++;
                }
            }
            cofRow++;
        }
    }

    return (row + column) % 2 == 0 ? determinantMatrix(n - 1, cof) : -determinantMatrix(n - 1, cof);
}

/**
 * Determinant of the matrix.
 *
 * @param n the matrix order.
 * @param a the matrix n x n.
 * @return the determinant of the matrix.
 */
float determinantMatrix(int n, float** a) {
    assert(n > 0);

    //M: 1 x 1
    if (n == 1) {
        return a[0][0];
    }

    //M: 2 x 2
    if (n == 2) {
        return a[0][0] * a[1][1] - a[0][1] * a[1][0];
    }

    //M: n x n with n > 2
    //Determinant to compute.
    float det = 0;

    //det = SUM(a[0][i] * Cof(a[0][i]))
    for (int i = 0; i < n; i++) {
        //compute the cofactor
        det += i % 2 == 0
                   ? a[0][i] * minor(n, a, 0, i)
                   : -a[0][i] * minor(n, a, 0, i);
    }
    return det;
}

/**
 * Rank of a matrix - minor method.
 *
 * @param n the number of row.
 * @param m the number of column.
 * @param a the matrix - M: n x m.
 * @return the rank of the matrix.
 */
int rankMatrix(int n, int m, float** a) {
    assert(n > 0);
    assert(m > 0);

    if (n == m) {
        //if [A] is a square matrix, detA is different from 0 so the rank is the matrix order
        if (determinantMatrix(n, a) != 0) {
            return n;
        }
    }

    //general case for non-square matrices or square matrices with zero determinant

    //The maximum possible rank is the smaller dimension.
    int order = n < m ? n : m;

    for (int k = order; k > 0; --k) {
        //check all k x k minors
        for (int i = 0; i <= n - k; ++i) {
            for (int j = 0; j <= m - k; ++j) {
                //Extracts k x k minor starting at (i, j)
                float** minorMatrix = createMatrix(k, k);

                for (int row = 0; row < k; ++row) {
                    for (int col = 0; col < k; ++col) {
                        minorMatrix[row][col] = a[i + row][j + col];
                    }
                }
                //check if this minor has a non-zero determinant
                if (determinantMatrix(k, minorMatrix) != 0) {
                    return k;
                }
                deleteMatrix(k, k, minorMatrix);
            }
        }
    }

    //if no non-zero determinant minor found, the rank is 0
    return 0;
}


/**
 * Sum of matrices.
 *
 * @param n the number of row.
 * @param m the number of column.
 * @param a the first matrix - M: n x m.
 * @param b the second matrix - M: n x m.
 * @param res the result: [a] + [b] - M: n x m.
 */
void sumMatrix(int n, int m, float** a, float** b, float** res) {
    assert(n > 0);
    assert(m > 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            res[i][j] = a[i][j] + b[i][j];
        }
    }
}

/**
 * Difference of matrices.
 *
 * @param n the number of row.
 * @param m the number of column.
 * @param a the first matrix - M: n x m.
 * @param b the second matrix - M: n x m.
 * @param res the result: [a] + [b] - M: n x m.
 */
void subMatrix(int n, int m, float** a, float** b, float** res) {
    assert(n > 0);
    assert(m > 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            res[i][j] = a[i][j] - b[i][j];
        }
    }
}

/**
 * Matrix scalar product.
 *
 * @param n the number of row.
 * @param m the number of column.
 * @param scalar the scalar number.
 * @param a the matrix - M: n x m.
 * @param res the result: scalar * [a] - M: n x m.
 */
void scalarProductMatrix(int n, int m, float scalar, float** a, float** res) {
    assert(n > 0);
    assert(m > 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            res[i][j] = scalar * a[n][m];
        }
    }
}

/**
 * Product of matrices.
 *
 * @param n the number of row in the first matrix.
 * @param p the number of column in the first matrix and the number of row in the second matrix.
 * @param m the number of column in the second matrix.
 * @param a the first matrix - M: n x p.
 * @param b the second matrix - M: p x m.
 * @param res the result: [a] x [b] - M: n x m.
 */
void productMatrix(int n, int p, int m, float** a, float** b, float** res) {
    assert(n > 0);
    assert(p > 0);
    assert(m > 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            res[i][j] = 0;
            for (int k = 0; k < m; ++k) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

/**
 * Matrix power elevation.
 *
 * @param n the matrix order.
 * @param a the matrix - M: n x n.
 * @param k the exponent.
 * @param res the result: [a]^k - M: n x n.
 */
void powerMatrix(int n, float** a, int k, float** res) {
    assert(n > 0);
    assert(k >= 0);

    //Temporary matrix.
    float** tmp = createMatrix(n, n);

    //initialize the res matrix
    deleteMatrix(n, n, res);
    res = createIdentityMatrix(n);

    //compute the power
    for (int i = 0; i < k; ++i) {
        productMatrix(n, n, n, res, a, tmp);
        copyMatrix(n, n, tmp, res);
    }

    //delete
    deleteMatrix(n, n, tmp);
}

/**
 * Direct sum of matrices.
 *
 * @param n the number of row of the first matrix.
 * @param m the number of column of the first matrix.
 * @param p the number of row of the second matrix.
 * @param q the number of column of the second matrix.
 * @param a the first matrix - M: n x m.
 * @param b the second matrix - M: p x q.
 * @param res the result: [a] (+) [b] - M: n+p x m+q.
 */
void directSumMatrix(int n, int m, int p, int q, float** a, float** b, float** res) {
    assert(n > 0);
    assert(m > 0);
    assert(p > 0);
    assert(q > 0);

    for (int i = 0; i < n + p; ++i) {
        for (int j = 0; j < m + q; ++j) {
            //upper left corner - first matrix
            if (i < n && j < m) {
                res[i][j] = a[i][j];
            }
            //bottom right corner - second matrix
            else if (i >= n && j >= m) {
                res[i][j] = b[i - n][j - m];
            }
            //other position - 0
            else {
                res[i][j] = 0;
            }
        }
    }
}

/**
 * Kronecker product of matrices.
 *
 * @param n the number of row of the first matrix.
 * @param m the number of column of the first matrix.
 * @param p the number of row of the second matrix.
 * @param q the number of column of the second matrix.
 * @param a the first matrix - M: n x m.
 * @param b the second matrix - M: p x q.
 * @param res the result: [a] (x) [b] - M: n*p x m*q.
 */
void kroneckerProductMatrix(int n, int m, int p, int q, float** a, float** b, float** res) {
    assert(n > 0);
    assert(m > 0);
    assert(p > 0);
    assert(q > 0);

    for (int i = 0; i < n * p; ++i) {
        for (int j = 0; j < m * q; ++j) {
            res[i][j] = a[i /p][j / q] * b[i % p][j % q];
        }
    }
}