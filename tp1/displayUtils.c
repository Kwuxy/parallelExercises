//
// Created by vincent on 05/10/2019.
//

#include "immintrin.h"
#include "displayUtils.h"
#include <stdio.h>

void runExercise(char *exerciseNumber, void (*exercise)()) {
    printf("\n-------------------- Exercise %s --------------------\n", exerciseNumber);
    exercise();
    printf("\n");
}

void __m256DisplayResult(__m256 vector1, __m256 vector2, __m256 result) {
    __m256DisplayResultHeader();
    __m256DisplayResultContent(vector1, vector2, result);
}

void __m256DisplayResultHeader() {
    printf("vector1\t\tvector2\t\tresult\n");
    printf("----------------------------------\n");
}

void __m256DisplayResultContent(__m256 vector1, __m256 vector2, __m256 result) {
    for(int i = 0; i < 8; i++) {
        printf("%.6f\t%.6f\t%.6f\n", vector1[i], vector2[i], result[i]);
    }
}

void __m256iDisplayResult(__m256i vector1, __m256i vector2, __m256i result) {
    __int32_t *displayVector1 = (__int32_t *) &vector1;
    __int32_t *displayVector2 = (__int32_t *) &vector2;
    __int32_t *displayResult = (__int32_t *) &result;

    printf("vector1\t\tvector2\t\tresult\n");
    printf("-------------------------------\n");

    for(int i = 0; i < 8; i++) {
        printf("%d\t\t\t%d\t\t\t%d\n", displayVector1[i], displayVector2[i], displayResult[i]);
    }
}