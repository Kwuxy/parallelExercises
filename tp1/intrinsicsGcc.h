//
// Created by vincent on 09/10/2019.
//

#ifndef TP1_INTRINSICSGCC_H
#define TP1_INTRINSICSGCC_H

#define MAXY 16
#define MAXX 8

typedef int vectorY __attribute__ ((vector_size(MAXY * sizeof(int))));
typedef int vectorImage __attribute__ ((vector_size(MAXX * sizeof(vectorY))));

void runAllIntrinsicsGccExercises();

void gccExercise3();

void displayImage(vectorImage *input);

#endif //TP1_INTRINSICSGCC_H
