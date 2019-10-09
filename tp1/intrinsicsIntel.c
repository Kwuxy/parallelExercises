/*
 * Created by vincent on 05/10/2019
 *
 * For more informations about the functions used in this file, check out this link :
 *      https://software.intel.com/sites/landingpage/IntrinsicsGuide/#expand=4002,4930,4929,2553
 * */

#include "immintrin.h"
#include "displayUtils.h"
#include "intrinsicsIntel.h"

void runAllIntrinsicsIntelExercises() {
    runExercise("1", exercise1);
    runExercise("2", exercise2);
    runExercise("3", exercise3);
    runExercise("4 V1", exercise4v1);
    runExercise("4 V2", exercise4v2);
}

void exercise1() {
    __m256 vector1 = _mm256_set_ps(1, 2, 3, 4, 5, 6, 7, 8);
    __m256 vector2 = _mm256_set_ps(1, 2, 3, 4, 5, 6, 7, 8);

    __m256 result = _mm256_mul_ps(vector1, vector2);
    __m256DisplayResult(vector1, vector2, result);
}

void exercise2() {
    __m256i vector1 = _mm256_set_epi32(1, 2, 3, 4, 5, 6, 7, 8);
    __m256i vector2 = _mm256_set_epi32(1, 2, 3, 4, 5, 6, 7, 8);

    /*
     * `_mm256_mul_epi32` takes 2 vectors of __m256i (eight int32 values each) and returns a __m256i with four int64 values
     *
     * `_mm256_mullo_epi32` takes 2 vectors of __m256i and returns a __m256i with eight int32 values. Each value contain
     *      the low half of the result. You need to use `_mm256_mulhi_epi32` to get the high half of the calculation or
     *      use `_mm256_mul_epi32` twice instead of mullo & mulhi.
     * */
    __m256i result = _mm256_mullo_epi32(vector1, vector2);

    __m256iDisplayResult(vector1, vector2, result);
}

void exercise3() {
    __m256 vector1[2] = {_mm256_set_ps(1, 2, 3, 4, 5, 6, 7, 8), _mm256_set_ps(9, 10, 11, 12, 13, 14, 15, 16)};
    __m256 vector2[2] = {_mm256_set_ps(1, 2, 3, 4, 5, 6, 7, 8), _mm256_set_ps(9, 10, 11, 12, 13, 14, 15, 16)};

    __m256 result[2];
    __m256DisplayResultHeader();
    for(char i = 1; i >= 0; i--) {
        result[i] = _mm256_mul_ps(vector1[i], vector2[i]);
        __m256DisplayResultContent(vector1[i], vector2[i], result[i]);
    }
}

void exercise4v1() {
    __m256 vector1 = _mm256_set_ps(1, 2, 3, 4, 5, 6, 7, 8);
    __m256 vector2 = _mm256_set_ps(1, 2, 3, 4, 5, 6, 7, 8);

    __m256 result = _mm256_mul_ps(vector1, vector2);
    result = _mm256_add_ps(result, vector2);
    __m256DisplayResult(vector1, vector2, result);
}

void exercise4v2() {
    __m256 vector1 = _mm256_set_ps(1, 2, 3, 4, 5, 6, 7, 8);
    __m256 vector2 = _mm256_set_ps(1, 2, 3, 4, 5, 6, 7, 8);

//    fma stands for fused multiply-add for more informations, check out https://en.wikipedia.org/wiki/FMA_instruction_set
    __m256 result = _mm256_fmadd_ps(vector1, vector2, vector2);
    __m256DisplayResult(vector1, vector2, result);
}
