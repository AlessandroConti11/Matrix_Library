#include <stdio.h>
#include <assert.h>

#include "Matrix.h"


float** generateMatrix(int *row, int *column) {
    //Matrix.
    float **matrix = NULL;
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
            returnScanf = scanf("%f", &matrix[i][j]);
            assert(returnScanf > 0);
        }
    }
    printf("\n");

    return matrix;
}


void printChoice() {
    printf("Choose which operation you want to perform from the following ones:\n"
           "1. create an identity matrix\n"
           "2. create a null matrix\n"
           "3. copy a matrix to another\n"
           "4. check if a matrix is an identity ones\n"
           "5. check if a matrix is a null ones\n"
           "6. check if a matrix is diagonal\n"
           "7. check if a matrix is anti-diagonal\n"
           "8. check if a matrix is upper diagonal\n"
           "9. check if a matrix is lower diagonal\n"
           "10. check if a matrix is symmetric\n"
           "11. check if a matrix is anti-symmetric\n"
           "12. check if a matrix is invertible\n"
           "13. check if a matrix is a step-matrix\n"
           "14. check if a matrix is an Hankel matrix\n"
           "15. check if a matrix is a Toeplitz matrix\n"
           "16. transpose a matrix\n"
           "17. invert a matrix, if possible\n"
           "18. transform a matrix into a stepped matrix\n"
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
           "39. quit\n"
           "\n\n");
}

void manageChoice(int *choice) {
    //The number of row of the matrices.
    int row1, row2;
    //The number of column of the matrices.
    int column1, column2;
    //Matrices.
    float **matrix1 = NULL, **matrix2 = NULL;
    //Return scanf value.
    int returnScanf = 0;

    switch (*choice) {
        case 1:
            printf("You chose to create an identity matrix\n\n"
                   "Insert the matrix order: ");
            returnScanf = scanf("%d", &row1);
            matrix1 = createIdentityMatrix(row1);
            printMatrix(row1, row1, matrix1);
            deleteMatrix(row1, row1, matrix1);
            break;
        case 2:
            printf("You chose to create a null matrix\n\n"
                   "Insert the matrix order: ");
            returnScanf = scanf("%d", &row1);
            matrix1 = createNullMatrix(row1);
            printMatrix(row1, row1, matrix1);
            deleteMatrix(row1, row1, matrix1);
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
        case 12:
            break;
        case 13:
            break;
        case 14:
            break;
        case 15:
            break;
        case 16:
            break;
        case 17:
            break;
        case 18:
            break;
        case 19:
            break;
        case 20:
            break;
        case 21:
            break;
        case 22:
            break;
        case 23:
            break;
        case 24:
            break;
        case 25:
            break;
        case 26:
            break;
        case 27:
            break;
        case 28:
            break;
        case 29:
            break;
        case 30:
            break;
        case 31:
            break;
        case 32:
            break;
        case 33:
            break;
        case 34:
            break;
        case 35:
            break;
        case 36:
            break;
        case 37:
            break;
        case 38:
            break;
        default:
            *choice = 39;
            break;
    }
}


int main(void) {
    //The user choice.
    int choice = -1;
    //Return scanf value.
    int returScanf = 0;

    do {
        printChoice();

        printf("Insert your choice: ");
        returScanf = scanf("%d", &choice);
        assert(returScanf > 0);

        manageChoice(&choice);

    } while (choice != 39);



    return 0;
}
