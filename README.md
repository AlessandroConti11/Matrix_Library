# Matrix_Library


Author: Alessandro Conti - [AlessandroConti11](https://github.com/AlessandroConti11)

License: [MIT license](LICENSE).


Tags: `#C`, `#cofactor`, `#determinant`, `#inverse_matrix`, `#matrix`, `#matrix_operation`, `#matrix_type`, `#minor`, `#pivot`, `#rank`, `#row_echelon_matrix`, `#transpose_matrix`.


## Specification

The project aims to create a library that contains all useful functions for handling matrices and their operations.
<br>
<br>
*For all functions that require a result: you must provide the requested data structure (you can also use the one present as input).*

| **Operation**                                      | **Function**                                                            | **Description**                                                                                                                                   |
|----------------------------------------------------|-------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------|
| create a matrix N x M                              | __matrix *createMatrix(int n, int m);__                                 | create an empty matrix                                                                                                                            |
| create identity matrix N x N                       | __matrix *createIdentityMatrix(int n);__                                | create an identity matrix                                                                                                                         |
| create a null matrix N x M                         | __matrix *createNullMatrix(int n, int m);__                             | create a null matrix                                                                                                                              |
| initialize a matrix N x M                          | __void initializeMatrix(matrix *a, ...);__                              | initialize an empty matrix by filling it by rows                                                                                                  |
| copy a matrix                                      | __void copyMatrix(matrix *a, matrix *b);__                              | copy a matrix to another                                                                                                                          |
| delete a matrix                                    | __void deleteMatrix(matrix *a);__                                       | delete a given matrix                                                                                                                             |
| print a matrix                                     | __void printMatrix(matrix *a);__                                        | print a given matrix                                                                                                                              |
| check if a matrix is an identity matrix            | __int isIdentityMatrix(matrix *a);__                                    | check whether the matrix only elements on the main diagonal equal 1 and the others equal                                                          |
| check if a matrix is a null matrix                 | __int isNullMatrix(matrix *a);__                                        | check whether the all matrix elements are equal to 0                                                                                              |
| check if a matrix is a diagonal matrix             | __int isDiagonalMatrix(matrix *a);__                                    | check whether the matrix has all elements not on the main diagonal equal to 0                                                                     |
| check if a matrix is anti-diagonal matrix          | __int isAntidiagonalMatrix(matrix *a);__                                | check whether the matrix has all elements not on the secondary diagonal equal to 0                                                                |
| check if a matrix is an upper diagonal matrix      | __int isUpperDiagonalMatrix(matrix *a);__                               | check whether the matrix has all elements below the main diagonal equal to 0                                                                      |
| check if a matrix is a lower diagonal matrix       | __int isLowerDiagonalMatrix(matrix *a);__                               | check whether the matrix has all elements above the main diagonal equal to 0                                                                      |
| check if a matrix is a symmetric matrix            | __int isSymmetricMatrix(matrix *a);__                                   | check whether the matrix has all the element (i, j) equal to the element (j, i)                                                                   |
| check if a matrix is an anti-symmetric matrix      | __int isAntisymmetricMatrix(matrix *a);__                               | check whether the matrix has the elements (i, j) opposite to those (j, i)                                                                         |
| check if a matrix is invertible                    | __int isInvertibleMatrix(matrix *a);__                                  | check whether the determinant is different from 0                                                                                                 |
| check if a matrix is a row-echelon matrix          | __int isRowEchelonMatrix(matrix *a);__                                  | check whether the first nonzero element of each row is further to the right than the first nonzero element of the previous row.                   |
| check if a matrix is an Hankel matrix              | __int isHankelMatrix(matrix *a);__                                      | check whether the matrix has all the element (i, j) equal to the element (i-1, j+1)                                                               |
| check if a matrix is a Toeplitz matrix             | __int isToeplitzMatrix(matrix *a);__                                    | check whether the matrix has all the element (i, j) equal to the element (i-1, j-1)                                                               |
| transpose a matrix                                 | __void transposingMatrix(matrix *a, matrix *trans);__                   | the transposed matrix is given by the elements (j, i)                                                                                             |
| invert a matrix                                    | __void inverseMatrix(matrix *a, matrix *inv);__                         | inverse the matrix using the method of cofactors                                                                                                  |
| transform a matrix to a row-echelon matrix         | __void rowEchelonMatrix(matrix *a, matrix *step);__                     | transform the matrix using the Gaussian elimination method                                                                                        |
| compute the absolute matrix                        | __void absMatrix(matrix *a, matrix *abs);__                             | compute the absolute value for each matrix element                                                                                                |
| compute the minor of a matrix                      | __double minor(matrix *a, int row, int column);__                       | compute the minor (row, column)-th, the determinant of the matrix without the row and the column specified                                        |
| compute the cofactor of a matrix                   | __double cofactor(matrix *a, int row, int column);__                    | compute the cofactor (row, column)-th, the (-1)^(row+column) determinant of the matrix without the row and the column specified                   |
| compute the determinant of a matrix                | __double determinantMatrix(matrix *a);__                                | compute the determinant of the matrix                                                                                                             |
| compute the rank of a matrix                       | __int rankMatrix(matrix *a);__                                          | compute the rank of the matrix using the minor method                                                                                             |
| compute the sum between two matrices               | __void sumMatrix(matrix *a, matrix *b, matrix *res);__                  | compute the sum between two given matrices                                                                                                        |
| compute the difference between two matrices        | __void subMatrix(matrix *a, matrix *b, matrix *res);__                  | compute the difference between two given matrices                                                                                                 |
| compute the scalar product of a matrix             | __void scalarProductMatrix(double scalar, matrix *a, matrix *res);__    | compute the scalar product of the matrix                                                                                                          |
| compute the product between two matrices           | __void productMatrix(matrix *a, matrix *b, matrix *res);__              | compute the product between two given matrices                                                                                                    |
| compute the power elevation of a matrix            | __void powerMatrix(matrix *a, int k, matrix *res);__                    | compute the power elevation of the matrix                                                                                                         |
| compute the direct sum between two matrices        | __void directSumMatrix(matrix *a, matrix *b, matrix *res);__            | compute the direct sum between two matrices, the first matrix is placed in the upper-left corner and the second matrix in the bottom-right corner |
| compute the Kronecker product between two matrices | __void kroneckerProductMatrix(matrix *a, matrix *b, matrix *res);__     | compute the Kronecker product between two matrices                                                                                                |
| swap two rows of a matrix                          | __void swapRowMatrix(matrix *a, int row1, int row2, matrix *swap);__    | swap two rows of given matrix                                                                                                                     |
| swap two column of a matrix                        | __void swapColumnMatrix(matrix *a, int col1, int col2, matrix *swap);__ | swap two column of given matrix                                                                                                                   |
| find the maximum value in a matrix                 | __double findMaxMatrix(matrix *a, int *rowPos, int *colPos);__          | find the maximum value in the matrix and return its position                                                                                      |
| find the minimum value in a matrix                 | __double findMinMatrix(matrix *a, int *rowPos, int *colPos);__          | find the minimum value in the matrix and return its position                                                                                      |
| find the elements on the diagonal of a matrix      | __double *diagonalMatrix(matrix *a, int *numberOfElements);__           | find the elements on the diagonal of the matrix                                                                                                   |
| find the pivot in a matrix                         | __double *pivot(matrix *a, int *pivotsNumber);__                        | find the pivots in the matrix transforming it in a row-echelon matrix                                                                             |
| decompose a matrix using Lower-Upper decomposition | __void luDecomposition(matrix *a, matrix *l, matrix *u);__              | decompose a matrix using Lower-Upper decomposition, the matrix is decomposed in a lower triangular matrix and an upper triangular matrix          |


## How to run

0. install gcc
    ```bash
    sudo apt-get install gcc 
    ```
1. compile the project
    ```bash
    gcc -Wall -Werror -O2 -g3 main.c -o EXECUTABLE 
    ```
2. run the project
    ```bash
    ./EXECUTABLE
    ```


<br>

The Makefile in the repository can also be used to compile the code.
- this option allows you to compile with the following tags: *-Wall -Werror -O2 -g3*
   ```bash
   make compile
   ```
- if you want to specify different tags, you can set them
   ```bash
   make compile CFLAGS=YOUR_FLAGS
   ```
- if you want to use Address SANitizer
   ```bash
   make asan
   ```
- if you want to delete some file - default is the executable file
   ```bash
   make clean
   ```


## Contribute

- If you find a security vulnerability, do NOT open an issue. Email [Alessandro Conti](mailto:ale.conti.1101@gmail.com) instead.
- If you find a bug or error or want to add some other function that is not implemented yet
  1. **FORK** the repo
  2. **CLONE** the project to your own machine
  3. **COMMIT** to your own branch
  4. **PUSH** your work back up to your fork
  5. submit a **PULL REQUEST** so that I can review your changes
  > NOTE: Be sure to merge the latest from "upstream" before making a pull request!
 
### Code Style

Each new function must be documented using the following style:
- *Short function description*: A brief description explaining what the function does.
- *@details*: A detailed section describing how the function works, explaining the algorithms and logic used.
- *@warning*: A section listing all the assumptions made by the function, such as the preconditions that the parameters must fulfil.
- *Blank line*: Add a blank line to separate the documentation sections.
- *@param*: A list of the parameters required by the function, each accompanied by a brief description of its role and type.
- *@return*: A description of what the function returns, including the data type.

Within the function, *each variable* must be commented out to explain its purpose. 
In general, any additional comments that might improve understanding of the code are welcome. 😃
