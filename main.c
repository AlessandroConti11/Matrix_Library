#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <unistd.h>

#include "Matrix.h"


/**
 * Generates a matrix - M: row x column.
 *
 * @param row the number of row.
 * @param column the number of column.
 * @return the matrix - M: row x column.
 */
matrix *generateMatrixNxM(int *row, int *column) {
    //Matrix.
    matrix *matrix = NULL;
    //Return scanf value.
    int returnScanf = 0;

    printf("Enter the number of row: ");
    returnScanf = scanf("%d", row);
    assert(returnScanf > 0);
    printf("Enter the number of column: ");
    returnScanf = scanf("%d", column);
    assert(returnScanf > 0);

    matrix = createMatrix(*row, *column);

    for (int i = 0; i < *row; ++i) {
        for (int j = 0; j < *column; ++j) {
            printf("Insert the value for position (%d; %d): ", i, j);
            returnScanf = scanf("%lf", &matrix->matrix[i][j]);
            assert(returnScanf > 0);
        }
    }
    printf("\n");

    return matrix;
}

/**
 * Generates a matrix - M: row x row.
 * @param row the matrix order.
 * @return the matrix - M: row x row.
 */
matrix *generateMatrixNxN(int *row) {
    //Matrix.
    matrix *matrix = NULL;
    //Return scanf value.
    int returnScanf = 0;

    printf("Enter the matrix order: ");
    returnScanf = scanf("%d", row);
    assert(returnScanf > 0);

    matrix = createMatrix(*row, *row);

    for (int i = 0; i < *row; ++i) {
        for (int j = 0; j < *row; ++j) {
            printf("Insert the value for position (%d; %d): ", i, j);
            returnScanf = scanf("%lf", &matrix->matrix[i][j]);
            assert(returnScanf > 0);
        }
    }
    printf("\n");

    return matrix;
}


/**
 * Prints all possible choices.
 */
void printChoice() {
    printf("Choose which operation you want to perform from the following ones:\n"
           " 1. create an identity matrix\n"
           " 2. create a null matrix\n"
           " 3. copy a matrix to another\n"
           " 4. check if a matrix is an identity ones\n"
           " 5. check if a matrix is a null ones\n"
           " 6. check if a matrix is diagonal\n"
           " 7. check if a matrix is anti-diagonal\n"
           " 8. check if a matrix is upper diagonal\n"
           " 9. check if a matrix is lower diagonal\n"
           "10. check if a matrix is symmetric\n"
           "11. check if a matrix is anti-symmetric\n"
           "12. check if a matrix is invertible\n"
           "13. check if a matrix is a row echelon matrix\n"
           "14. check if a matrix is an Hankel matrix\n"
           "15. check if a matrix is a Toeplitz matrix\n"
           "16. transpose a matrix\n"
           "17. invert a matrix, if possible\n"
           "18. transform a matrix into a row echelon matrix\n"
           "19. compute the absolute value of a matrix\n"
           "20. compute the minor\n"
           "21. compute the cofactor\n"
           "22. compute the determinant\n"
           "23. compute the rank\n"
           "24. sum of 2 matrix\n"
           "25. subtract of 2 matrix\n"
           "26. scalar product\n"
           "27. matrix product\n"
           "28. matrix power elevation\n"
           "29. direct sum of 2 matrix\n"
           "30. Kronecker product of 2 matrix\n"
           "31. swap row of a matrix\n"
           "32. swap column of a matrix\n"
           "33. find the maximum value in a matrix\n"
           "34. find the minimum value in a matrix\n"
           "35. find the elements on a matrix diagonal\n"
           "36. find the pivot of a matrix\n"
           "37. decompose a matrix using LU-decomposition\n"
           "38. print the possible choice\n"
           "39. quit"
           "\n\n");
}

/**
 * Handles the user's choice.
 *
 * @param choice the choice.
 */
void manageChoice(int *choice) {
    //The number of row of the matrices.
    int row1 = 0, row2 = 0;
    //The number of column of the matrices.
    int column1 = 0, column2 = 0;
    //Scalar value.
    double k = 0;
    //Matrices.
    matrix *matrix1 = NULL, *matrix2 = NULL, *res = NULL;
    //Array.
    double *array = NULL;
    //Return scanf value.
    int returnScanf = 0;

    switch (*choice) {
        case 1:
            printf("You chose to create an identity matrix\n\n"
                   "Insert the matrix order: ");
            returnScanf = scanf("%d", &row1);
            assert(returnScanf > 0);

            matrix1 = createIdentityMatrix(row1);
            printMatrix(matrix1);

            deleteMatrix(matrix1);
            printf("\n\n\n");
            break;
        case 2:
            printf("You chose to create a null matrix\n\n"
                   "Insert the number of row: ");
            returnScanf = scanf("%d", &row1);
            assert(returnScanf > 0);
            printf("Insert the number of column: ");
            returnScanf = scanf("%d", &column1);
            assert(returnScanf > 0);

            matrix1 = createNullMatrix(row1, column1);
            printMatrix(matrix1);

            deleteMatrix(matrix1);
            printf("\n\n\n");
            break;
        case 3:
            printf("You chose to copy a matrix into another one\n\n"
                   "Insert the matrix to be copied: \n");
            matrix1 = generateMatrixNxM(&row1, &column1);
            assert(matrix1 != NULL);

            printf("Insert the matrix that is to be overwritten:\n");
            matrix2 = generateMatrixNxM(&row2, &column2);
            assert(matrix2 != NULL);
            assert(row2 >= row1);
            assert(column2 >= column1);

            printf("Before:\n"
                   "Matrix 1:\n");
            printMatrix(matrix1);
            printf("Matrix 2:\n");
            printMatrix(matrix2);

            copyMatrix(matrix1, matrix2);

            printf("After:\n"
                   "Matrix 1:\n");
            printMatrix(matrix1);
            printf("Matrix 2:\n");
            printMatrix(matrix2);

            deleteMatrix(matrix1);
            deleteMatrix(matrix2);
            printf("\n\n\n");
            break;
        case 4:
            printf("You chose to check if a matrix is an identity one\n\n"
                   "Insert the matrix to check: \n");

            matrix1 = generateMatrixNxN(&row1);
            assert(matrix1 != NULL);

            printf("The matrix:\n");
            printMatrix(matrix1);

            printf("The matrix insert %s an identity matrix", isIdentityMatrix(matrix1) == 1 ?
                "is" : "is NOT");

            deleteMatrix(matrix1);
            printf("\n\n\n");
            break;
        case 5:
            printf("You chose to check if a matrix is a null one\n\n"
                   "Insert the matrix to check: \n");

            matrix1 = generateMatrixNxM(&row1, &column1);
            assert(matrix1 != NULL);

            printf("The matrix:\n");
            printMatrix(matrix1);

            printf("The matrix insert %s a null matrix", isNullMatrix(matrix1) == 1 ?
                "is" : "is NOT");

            deleteMatrix(matrix1);
            printf("\n\n\n");
            break;
        case 6:
            printf("You chose to check if a matrix is a diagonal one\n\n"
                   "Insert the matrix to check: \n");

            matrix1 = generateMatrixNxN(&row1);
            assert(matrix1 != NULL);

            printf("The matrix:\n");
            printMatrix(matrix1);

            printf("The matrix insert %s a diagonal matrix", isDiagonalMatrix(matrix1) == 1 ?
                "is" : "is NOT");

            deleteMatrix(matrix1);
            printf("\n\n\n");
            break;
        case 7:
            printf("You chose to check if a matrix is an anti-diagonal one\n\n"
                   "Insert the matrix to check: \n");

            matrix1 = generateMatrixNxN(&row1);
            assert(matrix1 != NULL);

            printf("The matrix:\n");
            printMatrix(matrix1);

            printf("The matrix insert %s an anti-diagonal matrix", isAntidiagonalMatrix(matrix1) == 1 ?
                "is" : "is NOT");

            deleteMatrix(matrix1);
            printf("\n\n\n");
            break;
        case 8:
            printf("You chose to check if a matrix is an upper diagonal one\n\n"
                   "Insert the matrix to check: \n");

            matrix1 = generateMatrixNxN(&row1);
            assert(matrix1 != NULL);

            printf("The matrix:\n");
            printMatrix(matrix1);

            printf("The matrix insert %s an upper diagonal matrix", isUpperDiagonalMatrix(matrix1) == 1 ?
                "is" : "is NOT");

            deleteMatrix(matrix1);
            printf("\n\n\n");
            break;
        case 9:
            printf("You chose to check if a matrix is a lower diagonal one\n\n"
                   "Insert the matrix to check: \n");

            matrix1 = generateMatrixNxN(&row1);
            assert(matrix1 != NULL);

            printf("The matrix:\n");
            printMatrix(matrix1);

            printf("The matrix insert %s a lower diagonal matrix", isLowerDiagonalMatrix(matrix1) == 1 ?
                "is" : "is NOT");

            deleteMatrix(matrix1);
            printf("\n\n\n");
            break;
        case 10:
            printf("You chose to check if a matrix is a symmetric one\n\n"
                   "Insert the matrix to check: \n");

            matrix1 = generateMatrixNxN(&row1);
            assert(matrix1 != NULL);

            printf("The matrix:\n");
            printMatrix(matrix1);

            printf("The matrix insert %s a symmetric matrix", isSymmetricMatrix(matrix1) == 1 ?
                "is" : "is NOT");

            deleteMatrix(matrix1);
            printf("\n\n\n");
            break;
        case 11:
            printf("You chose to check if a matrix is an anti-symmetric one\n\n"
                   "Insert the matrix to check: \n");

            matrix1 = generateMatrixNxN(&row1);
            assert(matrix1 != NULL);

            printf("The matrix:\n");
            printMatrix(matrix1);

            printf("The matrix insert %s an anti-symmetric matrix", isAntisymmetricMatrix(matrix1) == 1 ?
                "is" : "is NOT");

            deleteMatrix(matrix1);
            printf("\n\n\n");
            break;
        case 12:
            printf("You chose to check if a matrix is an invertible one\n\n"
                   "Insert the matrix to check: \n");

            matrix1 = generateMatrixNxN(&row1);
            assert(matrix1 != NULL);

            printf("The matrix:\n");
            printMatrix(matrix1);

            printf("The matrix insert %s an invertible matrix", isInvertibleMatrix(matrix1) == 1 ?
                "is" : "is NOT");

            deleteMatrix(matrix1);
            printf("\n\n\n");
            break;
        case 13:
            printf("You chose to check if a matrix is a row echelon one\n\n"
                   "Insert the matrix to check: \n");

            matrix1 = generateMatrixNxM(&row1, &column1);
            assert(matrix1 != NULL);

            printf("The matrix:\n");
            printMatrix(matrix1);

            printf("The matrix insert %s a row echelon matrix", isRowEchelonMatrix(matrix1) == 1 ?
                       "is" : "is NOT");

            deleteMatrix(matrix1);
            printf("\n\n\n");
            break;
        case 14:
            printf("You chose to check if a matrix is an Hankel one\n\n"
                   "Insert the matrix to check: \n");

            matrix1 = generateMatrixNxN(&row1);
            assert(matrix1 != NULL);

            printf("The matrix:\n");
            printMatrix(matrix1);

            printf("The matrix insert %s an Hankel matrix", isHankelMatrix(matrix1) == 1 ?
                "is" : "is NOT");

            deleteMatrix(matrix1);
            printf("\n\n\n");
            break;
        case 15:
            printf("You chose to check if a matrix is a Toeplitz one\n\n"
                   "Insert the matrix to check: \n");

            matrix1 = generateMatrixNxN(&row1);
            assert(matrix1 != NULL);

            printf("The matrix:\n");
            printMatrix(matrix1);

            printf("The matrix insert %s a Toeplitz matrix", isToeplitzMatrix(matrix1) == 1 ?
                "is" : "is NOT");

            deleteMatrix(matrix1);
            printf("\n\n\n");
            break;
        case 16:
            printf("You chose to transpose a matrix\n\n"
                   "Insert the matrix to be transposed: \n");
            matrix1 = generateMatrixNxM(&row1, &column1);
            assert(matrix1 != NULL);

            matrix2 = createMatrix(column1, row1);
            assert(matrix2 != NULL);

            transposingMatrix(matrix1, matrix2);

            printf("Original:\n");
            printMatrix(matrix1);

            printf("Transpose:\n");
            printMatrix(matrix2);

            deleteMatrix(matrix1);
            deleteMatrix(matrix2);
            printf("\n\n\n");
            break;
        case 17:
            printf("You chose to invert a matrix\n\n"
                   "Insert the matrix to be inverted: \n");
            matrix1 = generateMatrixNxN(&row1);
            assert(matrix1 != NULL);

            if (isInvertibleMatrix(matrix1) == 0) {
                printf("The matrix is NOT invertible\n");
                break;
            }

            matrix2 = createMatrix(row1, row1);
            assert(matrix2 != NULL);
            inverseMatrix(matrix1, matrix2);

            printf("Original:\n");
            printMatrix(matrix1);

            printf("Inverse:\n");
            printMatrix(matrix2);

            deleteMatrix(matrix1);
            deleteMatrix(matrix2);
            printf("\n\n\n");
            break;
        case 18:
            printf("You chose to transform a matrix into a row echelon one\n\n"
                   "Insert the matrix to be transformed in to row echelon: \n");
            matrix1 = generateMatrixNxM(&row1, &column1);
            assert(matrix1 != NULL);

            matrix2 = createMatrix(row1, column1);
            assert(matrix2 != NULL);
            rowEchelonMatrix(matrix1, matrix2);

            printf("Original:\n");
            printMatrix(matrix1);

            printf("Row echelon:\n");
            printMatrix(matrix2);

            deleteMatrix(matrix1);
            deleteMatrix(matrix2);
            printf("\n\n\n");
            break;
        case 19:
            printf("You chose to compute the absolute value of a matrix\n\n"
                   "Insert the matrix: \n");
            matrix1 = generateMatrixNxM(&row1, &column1);
            assert(matrix1 != NULL);

            matrix2 = createMatrix(row1, column1);
            absMatrix(matrix1, matrix2);

            printf("Original:\n");
            printMatrix(matrix1);

            printf("Absolute:\n");
            printMatrix(matrix2);

            deleteMatrix(matrix1);
            deleteMatrix(matrix2);
            printf("\n\n\n");
            break;
        case 20:
            printf("You chose to compute the minor of a matrix\n\n"
                   "Insert the matrix: \n");
            matrix1 = generateMatrixNxN(&row1);
            assert(matrix1 != NULL);

            printf("Insert the row of matrix to delete: ");
            returnScanf = scanf("%d", &row2);
            assert(returnScanf > 0);
            printf("Insert the column of matrix to delete: ");
            returnScanf = scanf("%d", &column1);
            assert(returnScanf > 0);

            printf("Matrix:\n");
            printMatrix(matrix1);

            printf("The minor (%d; %d) of the matrix is: %lf\n", row2, column1, minor(matrix1, row2, column1));

            deleteMatrix(matrix1);
            printf("\n\n\n");
            break;
        case 21:
            printf("You chose to compute the cofactor of a matrix\n\n"
                   "Insert the matrix: \n");
            matrix1 = generateMatrixNxN(&row1);
            assert(matrix1 != NULL);

            printf("Insert the row of matrix to delete: ");
            returnScanf = scanf("%d", &row2);
            assert(returnScanf > 0);
            printf("Insert the column of matrix to delete: ");
            returnScanf = scanf("%d", &column1);
            assert(returnScanf > 0);

            printf("Matrix:\n");
            printMatrix(matrix1);

            printf("The cofactor (%d; %d) of the matrix is: %lf\n", row2, column1, cofactor(matrix1, row2, column1));

            deleteMatrix(matrix1);
            printf("\n\n\n");
            break;
        case 22:
            printf("You chose to compute the determinant of a matrix\n\n"
                   "Insert the matrix: \n");
            matrix1 = generateMatrixNxN(&row1);
            assert(matrix1 != NULL);

            printf("Matrix:\n");
            printMatrix(matrix1);

            printf("The determinant of the matrix is: %lf\n", determinantMatrix(matrix1));

            deleteMatrix(matrix1);
            printf("\n\n\n");
            break;
        case 23:
            printf("You chose to compute the rank of a matrix\n\n"
                   "Insert the matrix: \n");
            matrix1 = generateMatrixNxM(&row1, &column1);
            assert(matrix1 != NULL);

            printf("Matrix:\n");
            printMatrix(matrix1);

            printf("The rank of the matrix is: %d\n", rankMatrix(matrix1));

            deleteMatrix(matrix1);
            printf("\n\n\n");
            break;
        case 24:
            printf("You chose to compute the sum of 2 matrix\n\n"
                   "Insert the first matrix: \n");
            matrix1 = generateMatrixNxM(&row1, &column1);
            assert(matrix1 != NULL);

            printf("Insert the second matrix: \n");
            matrix2 = generateMatrixNxM(&row2, &column2);
            assert(matrix2 != NULL);
            assert(row1 == row2);
            assert(column1 == column2);

            res = createMatrix(row1, column1);
            sumMatrix(matrix1, matrix2, res);

            printMatrix(matrix1);
            printf("+\n");
            printMatrix(matrix2);
            printf("=\n");
            printMatrix(res);

            deleteMatrix(matrix1);
            deleteMatrix(matrix2);
            deleteMatrix(res);
            printf("\n\n\n");
            break;
        case 25:
            printf("You chose to compute the subtraction of 2 matrix\n\n"
                   "Insert the first matrix: \n");
            matrix1 = generateMatrixNxM(&row1, &column1);
            assert(matrix1 != NULL);

            printf("Insert the second matrix: \n");
            matrix2 = generateMatrixNxM(&row2, &column2);
            assert(matrix2 != NULL);
            assert(row1 == row2);
            assert(column1 == column2);

            res = createMatrix(row1, column1);
            subMatrix(matrix1, matrix2, res);

            printMatrix(matrix1);
            printf("-\n");
            printMatrix(matrix2);
            printf("=\n");
            printMatrix(res);

            deleteMatrix(matrix1);
            deleteMatrix(matrix2);
            deleteMatrix(res);
            printf("\n\n\n");
            break;
        case 26:
            printf("You chose to compute the scalar product\n\n"
                   "Insert the K value: ");
            returnScanf = scanf("%lf", &k);
            assert(returnScanf > 0);

            printf("Insert the matrix: \n");
            matrix1 = generateMatrixNxM(&row1, &column1);
            assert(matrix1 != NULL);

            res = createMatrix(row1, column1);
            assert(res != NULL);

            scalarProductMatrix(k, matrix1, res);

            printf("%lf\n"
                   "*\n", k);
            printMatrix(matrix1);
            printf("=\n");
            printMatrix(res);

            deleteMatrix(matrix1);
            deleteMatrix(res);
            printf("\n\n\n");
            break;
        case 27:
            printf("You chose to compute the product of 2 matrix\n\n"
                   "Insert the first matrix: \n");
            matrix1 = generateMatrixNxM(&row1, &column1);
            assert(matrix1 != NULL);

            printf("Insert the second matrix: \n");
            matrix2 = generateMatrixNxM(&row2, &column2);
            assert(matrix2 != NULL);
            assert(column1 == row2);

            res = createMatrix(row1, column2);
            productMatrix(matrix1, matrix2, res);

            printMatrix(matrix1);
            printf("*\n");
            printMatrix(matrix2);
            printf("=\n");
            printMatrix(res);

            deleteMatrix(matrix1);
            deleteMatrix(matrix2);
            deleteMatrix(res);
            printf("\n\n\n");
            break;
        case 28:
            printf("You chose to compute the power elevation\n\n"
                   "Insert the matrix: \n");
            matrix1 = generateMatrixNxN(&row1);
            assert(matrix1 != NULL);

            printf("Insert the exponent: ");
            returnScanf = scanf("%d", &row2);
            assert(returnScanf > 0);

            res = createMatrix(row1, row1);
            assert(res != NULL);

            powerMatrix(matrix1, row2, res);

            printMatrix(matrix1);
            printf("^%d\n"
                   "=\n", row2);
            printMatrix(res);

            deleteMatrix(matrix1);
            deleteMatrix(res);
            printf("\n\n\n");
            break;
        case 29:
            printf("You chose to compute the direct sum of 2 matrix\n\n"
                   "Insert the first matrix: \n");
            matrix1 = generateMatrixNxM(&row1, &column1);
            assert(matrix1 != NULL);

            printf("Insert the second matrix: \n");
            matrix2 = generateMatrixNxM(&row2, &column2);
            assert(matrix2 != NULL);

            res = createMatrix(row1 + row2, column1 + column2);
            directSumMatrix(matrix1, matrix2, res);

            printMatrix(matrix1);
            printf("(+)\n");
            printMatrix(matrix2);
            printf("=\n");
            printMatrix(res);

            deleteMatrix(matrix1);
            deleteMatrix(matrix2);
            deleteMatrix(res);
            printf("\n\n\n");
            break;
        case 30:
            printf("You chose to compute the Kronecker product of 2 matrix\n\n"
                   "Insert the first matrix: \n");
            matrix1 = generateMatrixNxM(&row1, &column1);
            assert(matrix1 != NULL);

            printf("Insert the second matrix: \n");
            matrix2 = generateMatrixNxM(&row2, &column2);
            assert(matrix2 != NULL);

            res = createMatrix(row1 * row2, column1 * column2);
            kroneckerProductMatrix(matrix1, matrix2, res);

            printMatrix(matrix1);
            printf("(*)\n");
            printMatrix(matrix2);
            printf("=\n");
            printMatrix(res);

            deleteMatrix(matrix1);
            deleteMatrix(matrix2);
            deleteMatrix(res);
            printf("\n\n\n");
            break;
        case 31:
            printf("You chose to swap 2 rows of a matrix\n\n"
                   "Insert the matrix: \n");
            matrix1 = generateMatrixNxM(&row1, &column1);
            assert(matrix1 != NULL);

            matrix2 = createMatrix(row1, column1);
            assert(matrix2 != NULL);

            printf("Insert the first row to swap: ");
            returnScanf = scanf("%d", &row2);
            assert(returnScanf > 0);
            assert(row2 <= row1);

            printf("Insert the second row to swap: ");
            returnScanf = scanf("%d", &column2);
            assert(returnScanf > 0);
            assert(column2 <= row1);

            swapRowMatrix(matrix1, row2, column2, matrix2);

            printf("Original:\n");
            printMatrix(matrix1);
            printf("After:\n");
            printMatrix(matrix2);

            deleteMatrix(matrix1);
            deleteMatrix(matrix2);
            printf("\n\n\n");
            break;
        case 32:
            printf("You chose to swap 2 columns of a matrix\n\n"
                   "Insert the matrix: \n");
            matrix1 = generateMatrixNxM(&row1, &column1);
            assert(matrix1 != NULL);

            matrix2 = createMatrix(row1, column1);
            assert(matrix2 != NULL);

            printf("Insert the first column to swap: ");
            returnScanf = scanf("%d", &row2);
            assert(returnScanf > 0);
            assert(row2 <= column1);

            printf("Insert the second column to swap: ");
            returnScanf = scanf("%d", &column2);
            assert(returnScanf > 0);
            assert(column2 <= column1);

            swapColumnMatrix(matrix1, row2, column2, matrix2);

            printf("Original:\n");
            printMatrix(matrix1);
            printf("After:\n");
            printMatrix(matrix2);

            deleteMatrix(matrix1);
            deleteMatrix(matrix2);
            printf("\n\n\n");
            break;
        case 33:
            printf("You chose to find the maximum value in a matrix\n\n"
                   "Insert the matrix: \n");
            matrix1 = generateMatrixNxM(&row1, &column1);
            assert(matrix1 != NULL);

            k = findMaxMatrix(matrix1, &row2, &column2);
            printf("Matrix:\n");
            printMatrix(matrix1);
            printf("The maximum value in the matrix is %lf in position(%d; %d)\n", k, row2, column2);

            deleteMatrix(matrix1);
            printf("\n\n\n");
            break;
        case 34:
            printf("You chose to find the minimum value in a matrix\n\n"
                    "Insert the matrix: \n");
            matrix1 = generateMatrixNxM(&row1, &column1);
            assert(matrix1 != NULL);

            k = findMinMatrix(matrix1, &row2, &column2);

            printf("Matrix:\n");
            printMatrix(matrix1);
            printf("The minimum value in the matrix is %lf in position(%d; %d)\n", k, row2, column2);

            deleteMatrix(matrix1);
            printf("\n\n\n");
            break;
        case 35:
            printf("You chose to find the elements on a matrix diagonal\n\n"
                    "Insert the matrix: \n");
            matrix1 = generateMatrixNxM(&row1, &column1);
            assert(matrix1 != NULL);

            array = diagonalMatrix(matrix1, &row2);
            assert(array != NULL);

            printf("Matrix:\n");
            printMatrix(matrix1);
            printf("The elements in the matrix diagonal are as follows: ");
            for (int i = 0; i < row2; ++i) {
                printf("%lf ", array[i]);
            }
            printf("\n");

            deleteMatrix(matrix1);
            free(array);
            printf("\n\n\n");
            break;
        case 36:
            printf("You chose to find the pivots of a matrix\n\n"
                    "Insert the matrix: \n");
            matrix1 = generateMatrixNxM(&row1, &column1);
            assert(matrix1 != NULL);

            array = pivot(matrix1, &row2);
            assert(array != NULL);

            printf("Matrix:\n");
            printMatrix(matrix1);
            printf("The pivots of the matrix are as follows: ");
            for (int i = 0; i < row2; ++i) {
                printf("%lf ", array[i]);
            }
            printf("\n");

            deleteMatrix(matrix1);
            free(array);
            printf("\n\n\n");
            break;
        case 37:
            printf("You chose to find the matrix decomposition using the LU-Decomposition\n\n"
                    "Insert the matrix: \n");
            matrix1 = generateMatrixNxN(&row1);
            assert(matrix1 != NULL);

            matrix2 = createMatrix(row1, row1);
            assert(matrix2 != NULL);
            res = createMatrix(row1, row1);
            assert(res != NULL);

            luDecomposition(matrix1, matrix2, res);

            printf("The matrix:\n");
            printMatrix(matrix1);
            printf("Can be decompose like [A] = [L] * [U]\n"
                   "The L matrix:\n");
            printMatrix(matrix2);
            printf("The U matrix:\n");
            printMatrix(res);

            deleteMatrix(matrix1);
            deleteMatrix(matrix2);
            deleteMatrix(res);
            printf("\n\n\n");
            break;
        case 38:
            printChoice();
            printf("\n\n\n");
            break;
        default:
            printf("Exit\n");
            *choice = 39;
            printf("\n\n\n");
            break;
    }
}


/**
 * Program Main.
 *
 * @return 0 if the program finished execution successfully.
 */
int main(void) {
    //The user choice.
    int choice = -1;
    //Return scanf value.
    int returScanf = 0;

    do {
        //print all the possible choice
        printChoice();

        //read the choice insert from the user
        printf("Insert your choice: ");
        returScanf = scanf("%d", &choice);
        assert(returScanf > 0);

        //manage the choice
        manageChoice(&choice);

//        sleep(5);

    } while (choice != 39);

    return 0;
}
