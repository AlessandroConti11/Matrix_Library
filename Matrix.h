#ifndef CIPHER_MATRIX_H

    #define CIPHER_MATRIX_H


    /**
     * Struct --> represents an n x m matrix.
     *
     * @details matrix - M: n x m.
     * @details n - number of row.
     * @details m - number of column.
     */
    struct Matrix {
        float **matrix;
        int n;
        int m;
    };

    //*****************//
    //  MANAGE MATRIX  //
    //*****************//


    /**
    * Creates a matrix - M: n x m.
    *
    * @param n the number of row.
    * @param m the number of column.
    * @return the matrix - M: n x m.
    */
    struct Matrix *createMatrix(int n, int m);

    /**
    * Creates an identity matrix - M: n x n.
    *
    * @param n the matrix order.
    * @return the identity matrix - M: n x n.
    */
    float** createIdentityMatrix(int n);

    /**
    * Creates a null matrix - M: n x n.
    *
    * @param n the matrix order.
    * @return the null matrix - M: n x n.
    */
    float** createNullMatrix(int n);

    /**
    * Initialize a matrix.
    *
    * @param n the number of row.
    * @param m the number of column.
    * @param a the matrix to initialize - M: n x m.
    * @param ... the matrix elements.
    */
    void initializeMatrix(int n, int m, float** a, ...);

    /**
    * Copies a matrix.
    *
    * @param n the number of row.
    * @param m the number of column.
    * @param a the matrix to be copied - M: n x m.
    * @param b the copied matrix - M: n x m.
    */
    void copyMatrix(int n, int m, float** a, float** b);

    /**
    * Deletes a matrix.
    *
    * @param n the number of row.
    * @param m the number of column.
    * @param a the matrix to delete - M: n x m.
    */
    void deleteMatrix(int n, int m, float** a);

    /**
    * Prints a matrix.
    * digits integer part: 5
    * digits decimal part: 5
    *
    * @param n the number of row.
    * @param m the number of column.
    * @param a the matrix to print - M: n x m.
    */
    void printMatrix(int n, int m, float** a);


    //******************************************************************************************************************//


    //***************//
    //  MATRIX TYPE  //
    //***************//


    /**
    * Checks if a matrix is an identity ones.
    *
    * @param n the matrix order.
    * @param a the matrix - M: n x n.
    * @return 1 if the matrix is an identity, 0 otherwise.
    */
    int isIdentityMatrix(int n, float** a);

    /**
    * Checks if a matrix is a null ones.
    *
    * @param n the number of row.
    * @param m the number of column.
    * @param a the matrix - M: n x m.
    * @return 1 if the matrix is a null matrix, 0 otherwise.
    */
    int isNullMatrix(int n, int m, float** a);

    /**
    * Checks if a matrix is diagonal.
    *
    * @param n the matrix order.
    * @param a the matrix - M: n x n.
    * @return 1 if the matrix is diagonal, 0 otherwise.
    */
    int isDiagonalMatrix(int n, float** a);

    /**
    * Checks if a matrix is anti-diagonal.
    *
    * @param n the matrix order.
    * @param a the matrix - M: n x n.
    * @return 1 if the matrix is anti-diagonal, 0 otherwise.
    */
    int isAntidiagonalMatrix(int n, float** a);

    /**
    * Checks if a matrix is an upper diagonal ones.
    *
    * @param n the matrix order.
    * @param a the matrix - M: n x n.
    * @return 1 if the matrix is upper diagonal, 0 otherwise.
    */
    int isUpperDiagonalMatrix(int n, float** a);

    /**
    * Checks if a matrix is a lower diagonal ones.
    *
    * @param n the matrix order.
    * @param a the matrix - M: n x n.
    * @return 1 if the matrix is lower diagonal, 0 otherwise.
    */
    int isLowerDiagonalMatrix(int n, float** a);

    /**
    * Checks if a matrix is a symmetric ones.
    *
    * @param n the matrix order.
    * @param a the matrix - M: n x n.
    * @return 1 if the matrix is symmetric, 0 otherwise.
    */
    int isSymmetricMatrix(int n, float** a);

    /**
    * Checks if a matrix is a antisymmetric ones.
    *
    * @param n the matrix order.
    * @param a the matrix - M: n x n.
    * @return 1 if the matrix is antisymmetric, 0 otherwise.
    */
    int isAntisymmetricMatrix(int n, float** a);

    /**
    * Checks if a matrix is invertible.
    *
    * @param n the matrix order.
    * @param a the matrix - M: n x n.
    * @return 1 if the matrix is invertible, 0 otherwise.
    */
    int isInvertibleMatrix(int n, float** a);

    /**
    * Checks if a matrix is a row echelon matrix.
    *
    * @param n the number of row.
    * @param m the number of column.
    * @param a the matrix - M: n x m.
    * @return 1 if the matrix is a row echelon matrix, 0 otherwise.
    */
    int isRowEchelonMatrix(int n, int m, float** a);

    /**
    * Checks if a matrix is an Hankel matrix.
    *
    * @param n the matrix order.
    * @param a the matrix - M: n x n.
    * @return 1 if the matrix is an Hankel matrix, 0 otherwise.
    */
    int isHankelMatrix(int n, float** a);

    /**
    * Checks if a matrix is a Toeplitz matrix.
    *
    * @param n the matrix order.
    * @param a the matrix - M: n x n.
    * @return 1 if the matrix is a Toeplitz matrix, 0 otherwise.
    */
    int isToeplitzMatrix(int n, float** a);


    /**
    * Matrix transposition.
    *
    * @param n the number of row.
    * @param m the number of column.
    * @param a the matrix - M: n x m.
    * @param trans the result: [a]^T - M: m x n.
    */
    void transposingMatrix(int n, int m, float** a, float** trans);

    /**
    * Matrix inverse - cofactor matrix method.
    *
    * @param n the matrix order.
    * @param a the matrix - M: n x n.
    * @param inv the inverse of the matrix - M: n x n.
    */
    void inverseMatrix(int n, float** a, float** inv);

    /**
    * Row echelon matrix - Gaussian elimination method.
    *
    * @param n the number of row.
    * @param m the number of column.
    * @param a the matrix - M: n x m.
    * @param step the row echelon transformed matrix - M: n x m.
    */
    void rowEchelonMatrix(int n, int m, float** a, float** step);

    /**
    * Absolute value matrix.
    *
    * @param n the number of row.
    * @param m the number of column.
    * @param a the matrix - M: n x m.
    * @param abs the absolute value matrix - M: n x m.
    */
    void absMatrix(int n, int m , float** a, float** abs);


    //******************************************************************************************************************//


    //********************//
    //  MATRIX OPERATION  //
    //********************//


    /**
    * Minor of a matrix.
    *
    * @param n the matrix order.
    * @param a the matrix - M: n x n.
    * @param row the row of the matrix to be deleted.
    * @param column the column of the matrix to be deleted.
    * @return the minor of the matrix.
    */
    float minor(int n, float** a, int row, int column);

    /**
    * Cofactor of a matrix.
    *
    * @param n the matrix order.
    * @param a the matrix - M: n x n.
    * @param row the row of the matrix to be deleted.
    * @param column the column of the matrix to be deleted.
    * @return the cofactor of the matrix.
    */
    float cofactor(int n, float** a, int row, int column);

    /**
    * Determinant of the matrix.
    *
    * @param n the matrix order.
    * @param a the matrix n x n.
    * @return the determinant of the matrix.
    */
    float determinantMatrix(int n, float** a);

    /**
    * Rank of a matrix - minor method.
    *
    * @param n the number of row.
    * @param m the number of column.
    * @param a the matrix - M: n x m.
    * @return the rank of the matrix.
    */
    int rankMatrix(int n, int m, float** a);


    /**
    * Sum of matrices.
    *
    * @param n the number of row.
    * @param m the number of column.
    * @param a the first matrix - M: n x m.
    * @param b the second matrix - M: n x m.
    * @param res the result: [a] + [b] - M: n x m.
    */
    void sumMatrix(int n, int m, float** a, float** b, float** res);

    /**
    * Difference of matrices.
    *
    * @param n the number of row.
    * @param m the number of column.
    * @param a the first matrix - M: n x m.
    * @param b the second matrix - M: n x m.
    * @param res the result: [a] + [b] - M: n x m.
    */
    void subMatrix(int n, int m, float** a, float** b, float** res);

    /**
    * Matrix scalar product.
    *
    * @param n the number of row.
    * @param m the number of column.
    * @param scalar the scalar number.
    * @param a the matrix - M: n x m.
    * @param res the result: scalar * [a] - M: n x m.
    */
    void scalarProductMatrix(int n, int m, float scalar, float** a, float** res);

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
    void productMatrix(int n, int p, int m, float** a, float** b, float** res);

    /**
    * Matrix power elevation.
    *
    * @param n the matrix order.
    * @param a the matrix - M: n x n.
    * @param k the exponent.
    * @param res the result: [a]^k - M: n x n.
    */
    void powerMatrix(int n, float** a, int k, float** res);

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
    void directSumMatrix(int n, int m, int p, int q, float** a, float** b, float** res);

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
    void kroneckerProductMatrix(int n, int m, int p, int q, float** a, float** b, float** res);


    //******************************************************************************************************************//


    //***************************//
    //  MATRIX UTILITY FUNCTION  //
    //***************************//


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
    void swapRowMatrix(int n, int m, float** a, int row1, int row2, float** swap);

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
    void swapColumnMatrix(int n, int m, float** a, int col1, int col2, float** swap);

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
    float findMaxMatrix(int n, int m, float** a, int* rowPos, int* colPos);

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
    float findMinMatrix(int n, int m, float** a, int* rowPos, int* colPos);

    /**
    * Finds the elements on a matrix diagonal.
    *
    * @param n the number of row.
    * @param m the number of column.
    * @param a the matrix - M: n x m.
    * @return the list of elements on the matrix diagonal.
    */
    float* diagonalMatrix(int n, int m, float** a);

    /**
    * Finds the pivots in a matrix.
    *
    * @param n the number of row.
    * @param m the number of column.
    * @param a the matrix - M: n x m.
    * @param pivotsNumber the number of pivots.
    * @return the list of pivots.
    */
    float* pivot(int n, int m, float** a, int *pivotsNumber);

    /**
    * Decomposition of a matrix using Lower-Upper Decomposition - [A]=[L]*[U].
    *
    * @param n the matrix order.
    * @param a the matrix - M: n x n.
    * @param l the lower triangular matrix - M: n x n.
    * @param u the upper triangular matrix - M: n x n.
    */
    void luDecomposition(int n, float** a, float** l, float** u);

#endif