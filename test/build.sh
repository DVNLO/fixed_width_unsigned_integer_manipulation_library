#! /bin/bash
gcc -Wextra -Wall -Werror -O3 -std=c99 -march=native -funroll-all-loops -iquote ./../include ./test.c ./../source/*.c 