//
// Created by vincent on 05/10/2019.
//

#ifndef TP1_DISPLAYUTILS_H
#define TP1_DISPLAYUTILS_H

#include "immintrin.h"

void runExercise(char *exerciseNumber, void (*exercise)());

void __m256DisplayResult(__m256 vector1, __m256 vector2, __m256 result);
void __m256DisplayResultHeader();
void __m256DisplayResultContent(__m256 vector1, __m256 vector2, __m256 result);

void __m256iDisplayResult(__m256i vector1, __m256i vector2, __m256i result);

#endif //TP1_DISPLAYUTILS_H
