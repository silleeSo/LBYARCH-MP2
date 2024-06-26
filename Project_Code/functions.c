#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

// Function definition
double* generateFixedVector(int size) {
    double* arr = (double*)malloc(size * sizeof(double));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    for (int i = 0; i < size; i++)
        arr[i] = i * 1.0f;
    return arr;
}
double* generateRandomVector(int size) {
    srand(time(NULL));
    double* arr = (double*)malloc(size * sizeof(double));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    for (int i = 0; i < size; i++) //populate with random numbers
        arr[i] = (double)rand() / RAND_MAX;
    return arr;
}

void isCorrect(double sdotC, double sdotAssem) {
    if (sdotC == sdotAssem) {
        printf("The x86-64 kernel output is CORRECT!\n\n");
    }
    else {
        printf("The x86-64 kernel output is INCORRECT!\n\n");
    }
}

double getAverageExecTime(double time) {
    time /= 30;

    return time;
}

