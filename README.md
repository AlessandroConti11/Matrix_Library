# Matrix_Library


Author: Alessandro Conti - [AlessandroConti11](https://github.com/AlessandroConti11)

License: [MIT license](LICENSE).

Tags: xxx.


## Specification

xx


## How to run

xxx

To ensure that the project works properly, you must compile it and run it in a Unix environment from the terminal by following these steps:

0. install gcc
    ```bash
    sudo apt-get install gcc 
    ```
1. compile the project
    ```bash
    gcc -Wall -Werror -O2 -g3 main.c -o EXECUTABLE 
    ```
2. run the project
    - with entering the arguments from the command line
      ```bash
      ./EXECUTABLE MIN MAX
      ```
    - without entering the arguments from the command line
      ```bash
      ./EXECUTABLE
      # at the beginning you will be asked to enter the minimum and maximum value
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


## Final consideration

xxx