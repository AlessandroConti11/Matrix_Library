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
    struct Matrix *createIdentityMatrix(int n);

    /**
    * Creates a null matrix - M: n x n.
    *
    * @param n the number of row.
    * @param m the number of column.
    * @return the null matrix - M: n x n.
    */
    struct Matrix *createNullMatrix(int n, int m);

    /**
    * Initialize a matrix.
    *
    * @param a the matrix to initialize - M: n x m.
    * @param ... the matrix elements.
    */
    void initializeMatrix(struct Matrix *a, ...);

    /**
     * Copies a matrix.
     *
     * @param a the matrix to be copied - M: n x m.
     * @param b the copied matrix - M: p x q with p>=n && q>=m.
     */
    void copyMatrix(struct Matrix *a, struct Matrix *b);

    /**
    * Deletes a matrix.
    *
    * @param a the matrix to delete - M: n x m.
    */
    void deleteMatrix(struct Matrix *a);

    /**
    * Prints a matrix.
    * digits integer part: 5
    * digits decimal part: 5
    *
    * @param a the matrix to print - M: n x m.
    */
    void printMatrix(struct Matrix *a);


    //******************************************************************************************************************//


    //***************//
    //  MATRIX TYPE  //
    //***************//


    /**
    * Checks if a matrix is an identity ones.
    *
    * @param a the matrix - M: n x n.
    * @return 1 if the matrix is an identity, 0 otherwise.
    */
    int isIdentityMatrix(struct Matrix *a);

    /**
    * Checks if a matrix is a null ones.
    *
    * @param a the matrix - M: n x m.
    * @return 1 if the matrix is a null matrix, 0 otherwise.
    */
    int isNullMatrix(struct Matrix *a);

    /**
    * Checks if a matrix is diagonal.
    *
    * @param a the matrix - M: n x n.
    * @return 1 if the matrix is diagonal, 0 otherwise.
    */
    int isDiagonalMatrix(struct Matrix *a);

    /**
    * Checks if a matrix is anti-diagonal.
    *
    * @param a the matrix - M: n x n.
    * @return 1 if the matrix is anti-diagonal, 0 otherwise.
    */
    int isAntidiagonalMatrix(struct Matrix *a);

    /**
    * Checks if a matrix is an upper diagonal ones.
    *
    * @param a the matrix - M: n x n.
    * @return 1 if the matrix is upper diagonal, 0 otherwise.
    */
    int isUpperDiagonalMatrix(struct Matrix *a);

    /**
    * Checks if a matrix is a lower diagonal ones.
    *
    * @param a the matrix - M: n x n.
    * @return 1 if the matrix is lower diagonal, 0 otherwise.
    */
    int isLowerDiagonalMatrix(struct Matrix *a);

    /**
    * Checks if a matrix is a symmetric ones.
    *
    * @param a the matrix - M: n x n.
    * @return 1 if the matrix is symmetric, 0 otherwise.
    */
    int isSymmetricMatrix(struct Matrix *a);

    /**
    * Checks if a matrix is a antisymmetric ones.
    *
    * @param a the matrix - M: n x n.
    * @return 1 if the matrix is antisymmetric, 0 otherwise.
    */
    int isAntisymmetricMatrix(struct Matrix *a);

    /**
    * Checks if a matrix is invertible.
    *
    * @param a the matrix - M: n x n.
    * @return 1 if the matrix is invertible, 0 otherwise.
    */
    int isInvertibleMatrix(struct Matrix *a);

    /**
    * Checks if a matrix is a row echelon matrix.
    *
    * @param a the matrix - M: n x m.
    * @return 1 if the matrix is a row echelon matrix, 0 otherwise.
    */
    int isRowEchelonMatrix(struct Matrix *a);

    /**
    * Checks if a matrix is an Hankel matrix.
    *
    * @param a the matrix - M: n x n.
    * @return 1 if the matrix is an Hankel matrix, 0 otherwise.
    */
    int isHankelMatrix(struct Matrix *a);

    /**
    * Checks if a matrix is a Toeplitz matrix.
    *
    * @param a the matrix - M: n x n.
    * @return 1 if the matrix is a Toeplitz matrix, 0 otherwise.
    */
    int isToeplitzMatrix(struct Matrix *a);


    /**
    * Matrix transposition.
    *
    * @param a the matrix - M: n x m.
    * @param trans the result: [a]^T - M: m x n.
    */
    void transposingMatrix(struct Matrix *a, struct Matrix *trans);

    /**
    * Matrix inverse - cofactor matrix method.
    *
    * @param a the matrix - M: n x n.
    * @param inv the inverse of the matrix - M: n x n.
    */
    void inverseMatrix(struct Matrix *a, struct Matrix *inv);

    /**
    * Row echelon matrix - Gaussian elimination method.
    *
    * @param a the matrix - M: n x m.
    * @param step the row echelon transformed matrix - M: n x m.
    */
    void rowEchelonMatrix(struct Matrix *a, struct Matrix *step);

    /**
    * Absolute value matrix.
    *
    * @param a the matrix - M: n x m.
    * @param abs the absolute value matrix - M: n x m.
    */
    void absMatrix(struct Matrix *a, struct Matrix *abs);


    //******************************************************************************************************************//


    //********************//
    //  MATRIX OPERATION  //
    //********************//


    /**
    * Minor of a matrix.
    *
    * @param a the matrix - M: n x n.
    * @param row the row of the matrix to be deleted.
    * @param column the column of the matrix to be deleted.
    * @return the minor of the matrix.
    */
    float minor(struct Matrix *a, int row, int column);

    /**
    * Cofactor of a matrix.
    *
    * @param a the matrix - M: n x n.
    * @param row the row of the matrix to be deleted.
    * @param column the column of the matrix to be deleted.
    * @return the cofactor of the matrix.
    */
    float cofactor(struct Matrix *a, int row, int column);

    /**
    * Determinant of the matrix.
    *
    * @param a the matrix n x n.
    * @return the determinant of the matrix.
    */
    float determinantMatrix(struct Matrix *a);

    /**
    * Rank of a matrix - minor method.
    *
    * @param a the matrix - M: n x m.
    * @return the rank of the matrix.
    */
    int rankMatrix(struct Matrix *a);


    /**
    * Sum of matrices.
    *
    * @param a the first matrix - M: n x m.
    * @param b the second matrix - M: n x m.
    * @param res the result: [a] + [b] - M: n x m.
    */
    void sumMatrix(struct Matrix *a, struct Matrix *b, struct Matrix *res);

    /**
    * Difference of matrices.
    *
    * @param a the first matrix - M: n x m.
    * @param b the second matrix - M: n x m.
    * @param res the result: [a] + [b] - M: n x m.
    */
    void subMatrix(struct Matrix *a, struct Matrix *b, struct Matrix *res);

    /**
    * Matrix scalar product.
    *
    * @param scalar the scalar number.
    * @param a the matrix - M: n x m.
    * @param res the result: scalar * [a] - M: n x m.
    */
    void scalarProductMatrix(float scalar, struct Matrix *a, struct Matrix *res);

    /**
    * Product of matrices.
    *
    * @param a the first matrix - M: n x p.
    * @param b the second matrix - M: p x m.
    * @param res the result: [a] x [b] - M: n x m.
    */
    void productMatrix(struct Matrix *a, struct Matrix *b, struct Matrix *res);

    /**
    * Matrix power elevation.
    *
    * @param a the matrix - M: n x n.
    * @param k the exponent.
    * @param res the result: [a]^k - M: n x n.
    */
    void powerMatrix(struct Matrix *a, int k, struct Matrix *res);

    /**
    * Direct sum of matrices.
    *
    * @param a the first matrix - M: n x m.
    * @param b the second matrix - M: p x q.
    * @param res the result: [a] (+) [b] - M: n+p x m+q.
    */
    void directSumMatrix(struct Matrix *a, struct Matrix *b, struct Matrix *res);

    /**
    * Kronecker product of matrices.
    *
    * @param a the first matrix - M: n x m.
    * @param b the second matrix - M: p x q.
    * @param res the result: [a] (x) [b] - M: n*p x m*q.
    */
    void kroneckerProductMatrix(struct Matrix *a, struct Matrix *b, struct Matrix *res);


    //******************************************************************************************************************//


    //***************************//
    //  MATRIX UTILITY FUNCTION  //
    //***************************//


    /**
    * Swaps 2 rows of a matrix.
    *
    * @param a the matrix - M: n x m.
    * @param row1 the first row to swap.
    * @param row2 the second row to swap.
    * @param swap the swapped matrix.
    */
    void swapRowMatrix(struct Matrix *a, int row1, int row2, struct Matrix *swap);

    /**
    * Swaps 2 columns of a matrix.
    *
    * @param a the matrix - M: n x m.
    * @param col1 the first column to swap.
    * @param col2 the second column to swap.
    * @param swap the swapped matrix.
    */
    void swapColumnMatrix(struct Matrix *a, int col1, int col2, struct Matrix *swap);

    /**
    * Find the maximum value in a matrix.
    *
    * @param a the matrix - M: n x m.
    * @param rowPos the row that contains the position with the maximum value.
    * @param colPos the column that contains the position with the maximum value.
    * @return the maximum value in the matrix.
    */
    float findMaxMatrix(struct Matrix *a, int *rowPos, int *colPos);

    /**
    * Find the minimum value in a matrix.
    *
    * @param a the matrix - M: n x m.
    * @param rowPos the row that contains the position with the minimum value.
    * @param colPos the column that contains the position with the minimum value.
    * @return the minimum value in the matrix.
    */
    float findMinMatrix(struct Matrix *a, int *rowPos, int *colPos);

    /**
    * Finds the elements on a matrix diagonal.
    *
    * @param a the matrix - M: n x m.
    * @param numberOfElements the number of elements on the diagonal.
    * @return the list of elements on the matrix diagonal.
    */
    float* diagonalMatrix(struct Matrix *a, int *numberOfElements);

    /**
    * Finds the pivots in a matrix.
    *
    * @param a the matrix - M: n x m.
    * @param pivotsNumber the number of pivots.
    * @return the list of pivots.
    */
    float* pivot(struct Matrix *a, int *pivotsNumber);

    /**
    * Decomposition of a matrix using Lower-Upper Decomposition - [A]=[L]*[U].
    *
    * @param a the matrix - M: n x n.
    * @param l the lower triangular matrix - M: n x n.
    * @param u the upper triangular matrix - M: n x n.
    */
    void luDecomposition(struct Matrix *a, struct Matrix *l, struct Matrix *u);

#endif