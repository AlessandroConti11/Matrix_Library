#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#include "../Matrix.h"


/**
 * Checks if a matrix is an identity ones.
 *
 * @param n the matrix order.
 * @param a the matrix - M: n x n.
 * @return 1 if the matrix is an identity, 0 otherwise.
 */
int isIdentityMatrix(int n, float** a) {
    assert(n > 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            //the matrix is NOT the identity if it does NOT have all 1's on the main diagonal
            if (i == j && a[i][j] != 1) {
                //matrix is NOT the identity
                return 0;
            }
            //the matrix is NOT the identity if it does not have all 0s outside the main diagonal
            if (i != j && a[i][j] != 0) {
                //matrix is NOT the identity
                return 0;
            }
        }
    }

    //matrix is the identity
    return 1;
}

/**
 * Checks if a matrix is a null ones.
 *
 * @param n the number of row.
 * @param m the number of column.
 * @param a the matrix - M: n x m.
 * @return 1 if the matrix is a null matrix, 0 otherwise.
 */
int isNullMatrix(int n, int m, float** a) {
    assert(n > 0);
    assert(m > 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            //the matrix is NOT the null matrix iff it has a value different from 0
            if (a[i][j] != 0) {
                //matrix is NOT the null
                return 0;
            }
        }
    }

    //matrix is the null
    return 1;
}

/**
 * Checks if a matrix is diagonal.
 *
 * @param n the matrix order.
 * @param a the matrix - M: n x n.
 * @return 1 if the matrix is diagonal, 0 otherwise.
 */
int isDiagonalMatrix(int n, float** a) {
    assert(n > 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            //the matrix is NOT diagonal iff a[i][j]!=0, i!=j
            if (i != j && a[i][j] != 0) {
                //matrix is NOT diagonal
                return 0;
            }
        }
    }

    //matrix is diagonal
    return 1;
}

/**
 * Checks if a matrix is antidiagonal.
 *
 * @param n the matrix order.
 * @param a the matrix - M: n x n.
 * @return 1 if the matrx is antidiagonal, 0 otherwise.
 */
int isAntidiagonalMatrix(int n, float** a) {
    assert(n > 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            //the matrix is NOT antidiagonal iff a[i][j]!=0, i+j!=n-1
            if (i + j != n - 1 && a[i][j] != 0) {
                //matrix is NOT antidiagonal
                return 0;
            }
        }
    }
    //matrix is antidiagonal
    return 1;
}

/**
 * Checks if a matrix is an upper diagonal ones.
 *
 * @param n the matrix order.
 * @param a the matrix - M: n x n.
 * @return 1 if the matrix is upper diagonal, 0 otherwise.
 */
int isUpperDiagonalMatrix(int n, float** a) {
    assert(n > 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i > j && a[i][j] != 0) {
                //matrix is NOT the upper diagonal
                return 0;
            }
        }
    }

    //matrix is upper diagonal
    return 1;
}

/**
 * Checks if a matrix is a lower diagonal ones.
 *
 * @param n the matrix order.
 * @param a the matrix - M: n x n.
 * @return 1 if the matrix is lower diagonal, 0 otherwise.
 */
int isLowerDiagonalMatrix(int n, float** a) {
    assert(n > 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i < j && a[i][j] != 0) {
                //matrix is NOT the lower diagonal
                return 0;
            }
        }
    }

    //matrix is lower diagonal
    return 1;
}

/**
 * Checks if a matrix is a symmetric ones.
 *
 * @param n the matrix order.
 * @param a the matrix - M: n x n.
 * @return 1 if the matrix is symmetric, 0 otherwise.
 */
int isSymmetricMatrix(int n, float** a) {
    assert(n > 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] != a[j][i]) {
                //matrix is NOT symmetric diagonal
                return 0;
            }
        }
    }

    //matrix is symmetric diagonal
    return 1;
}

/**
 * Checks if a matrix is a antisymmetric ones.
 *
 * @param n the matrix order.
 * @param a the matrix - M: n x n.
 * @return 1 if the matrix is antisymmetric, 0 otherwise.
 */
int isAntisymmetricMatrix(int n, float** a) {
    assert(n > 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[j][i] != -a[i][j]) {
                //matrix is NOT symmetric diagonal
                return 0;
            }
        }
    }

    //matrix is symmetric diagonal
    return 1;
}

/**
 * Checks if a matrix is invertible.
 *
 * @param n the matrix order.
 * @param a the matrix - M: n x n.
 * @return 1 if the matrix is invertible, 0 otherwise.
 */
int isInvertibleMatrix(int n, float** a) {
    assert(n > 0);

    //matrix is NOT invertible if the determinanti is equalt to 0
    if (determinantMatrix(n, a) == 0) {
        //matrix is NOT invertible
        return 0;
    }

    //matrix is invertible
    return 1;
}

/**
 * Checks if a matrix is a row echelon matrix.
 *
 * @param n the number of row.
 * @param m the number of column.
 * @param a the matrix - M: n x m.
 * @return 1 if the matrix is a row echelon matrix, 0 otherwise.
 */
int isRowEchelonMatrix(int n, int m, float** a) {
    assert(n > 0);
    assert(m > 0);

    //Last column position different from 0.
    int index = -1;
    //First non-zero element in the current row.
    int firstNonZero = -1;

    for (int i = 0; i < n; ++i) {
        firstNonZero = -1;
        for (int j = 0; j < m; ++j) {
            //all positions before the last index whose value is different from 0 must be 0
            if (a[i][j] != 0) {
                firstNonZero = j;
                break;
            }
        }

        //the whole row consists of 0
        if (firstNonZero == -1) {
            continue;
        }

        //the first non-zero element of the current row is in a column later than the previous row
        if (firstNonZero <= index) {
            //matrix is NOT step matrix
            return 0;
        }

        index = firstNonZero;
    }

    //matrix is step matrix
    return 1;
}

/**
 * Checks if a matrix is an Hankel matrix.
 *
 * @param n the matrix order.
 * @param a the matrix - M: n x n.
 * @return 1 if the matrix is an Hankel matrix, 0 otherwise.
 */
int isHankelMatrix(int n, float** a) {
    assert(n > 0);

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            //a[i][j] == a[i-1][j+1]
            if (a[i][j] != a[i - 1][j + 1]) {
                //matrix is NOT Hankel matrix
                return 0;
            }
        }
    }
    //matrix is Hankel matrix
    return 1;
}

/**
 * Checks if a matrix is a Toeplitz matrix.
 *
 * @param n the matrix order.
 * @param a the matrix - M: n x n.
 * @return 1 if the matrix is a Toeplitz matrix, 0 otherwise.
 */
int isToeplitzMatrix(int n, float** a) {
    assert(n > 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            //a[i][j] == a[i-1][j-1]
            if (i - 1 >= 0 && j - 1 >= 0 && a[i][j] != a[i - 1][j - 1]) {
                //matrix is NOT Toeplitz matrix
                return 0;
            }
        }
    }
    //matrix is Toeplitz matrix
    return 1;
}


/**
 * Matrix transposition.
 *
 * @param n the number of row.
 * @param m the number of column.
 * @param a the matrix - M: n x m.
 * @param trans the result: [a]^T - M: m x n.
 */
void transposingMatrix(int n, int m, float** a, float** trans) {
    assert(n > 0);
    assert(m > 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            trans[j][i] = a[i][j];
        }
    }
}

/**
 * Matrix inverse - cofactor matrix method.
 *
 * @param n the matrix order.
 * @param a the matrix - M: n x n.
 * @param inv the inverse of the matrix - M: n x n.
 */
void inverseMatrix(int n, float** a, float** inv) {
    assert(isInvertibleMatrix(n, a) == 1);

    //Inverse of the determinant
    float invDet = (float) 1 / determinantMatrix(n, a);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inv[j][i] = invDet * cofactor(n, a, i, j);
        }
    }
}


/**
 * Row echelon matrix - Gaussian elimination method.
 *
 * @param n the number of row.
 * @param m the number of column.
 * @param a the matrix - M: n x m.
 * @param step the row echelon transformed matrix - M: n x m.
 */
void rowEchelonMatrix(int n, int m, float** a, float** step) {
    assert(n > 0);
    assert(m > 0);

    //Pivot row position.
    int elX = 0;
    //Pivot column position.
    int elY = 0;
    //Counter for rows.
    int counter = 0;
    //Cofactor.
    float cofactor = 0;
    //First non-null position.
    int pivotFound = 0;

    copyMatrix(n, m, a, step);

    while (elX < n && elY < m) {
        pivotFound = 0;
        for (int j = elY; j < m && !pivotFound; ++j) {
            for (int i = elX; i < n && !pivotFound; ++i) {
                if (step[i][j] != 0) {
                    elX = i;
                    elY = j;
                    pivotFound = 1;
                }
            }
        }

        //exit if no pivot found
        if (!pivotFound) {
            break;
        }

        //swap the current row with the one that has the first element different from 0
        swapRowMatrix(n, m, step, elX, counter, step);

        //eliminate all elements below the pivot
        for (int i = counter + 1; i < n; ++i) {
            if (step[i][elY] != 0) {
                cofactor = step[i][elY];
                for (int j = elY; j < m; ++j) {
                    step[i][j] -= cofactor * step[counter][j];
                }
            }
        }

        elX = counter + 1;
        elY++;
        counter++;
    }
}

/**
 * Absolute value matrix.
 *
 * @param n the number of row.
 * @param m the number of column.
 * @param a the matrix - M: n x m.
 * @param abs the absolute value matrix - M: n x m.
 */
void absMatrix(int n, int m , float** a, float** abs) {
    assert(n > 0);
    assert(m > 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            abs[i][j] = a[i][j] < 0 ? -a[i][j] : a[i][j];
        }
    }
}