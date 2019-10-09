//
// Created by vincent on 09/10/2019.
//

#include <stdlib.h>
#include <stdio.h>
#include "intrinsicsGcc.h"
#include "displayUtils.h"

void runAllIntrinsicsGccExercises() {
    runExercise("3", gccExercise3);
}

void gccExercise3() {
    /*
     * VectorImage represents an image as a vector
     * Data is set as a simple array with size MAXY * MAXX
     * Line 1 is [0; MAXY - 1], Line 2 is [MAXY; 2 * MAXY - 1], ... Last line is [MAXY * (MAXX - 1); MAXY * MAXX - 1]
     * */
    vectorImage image = {};

    for(int i = 0; i < MAXY; i++) {
        for(int j = 0; j < MAXX; j++) {
            image[i * MAXY + j] = rand() % 10;
        }
    }

    displayImage(&image);
    image = image * 34;
    displayImage(&image);
}

void displayImage(vectorImage *input) {
    vectorImage image = *input;

    printf("\t\t");
    for(int j = 0; j < MAXX; j++) {
        printf("%d\t", j);
    }

    printf("\n\t");
    for(int j = 0; j < MAXX + 1; j++) {
        printf("----");
    }

    printf("\n");

    for(int i = 0; i < MAXY; i++) {
        printf("%d\t|\t", i);
        for(int j = 0; j < MAXX; j++) {
            printf("%d\t", image[i * MAXY + j]);
        }
        printf("\n");
    }

    printf("\n\n");
}