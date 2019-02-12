#!/bin/sh

gcc -O3 main.c mergesort.c heapsort.c -o ../build/sort
../build/sort
