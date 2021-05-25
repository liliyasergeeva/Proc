#ifndef MATRIX_H
#define MATRIX_H

#include "Key.h"
#include "Diagonal_matrix.h"
#include "Two_dimensional_array.h"
#include "Triangular_matrix.h"

//Структура "матрицы"
struct Matrix {
    Key K; //Идентификатор матрицы - диагональная или обычный двумерный массив
    int N; //Длина массива

    //Объект диагональной матрицы, обычного двумерного массива или треугольной матрицы
    union {
        Diagonal_matrix D_m;
        Two_dimensional_array T_d_a;
        Triangular_matrix T_m;
    };
};

//Функция ввода матрицы
Matrix* In_Matrix(ifstream& ifst);

//Функция вывода матрица
void Out_Matrix(Matrix* M, ofstream& ofst);

//Функция подсчет суммы элементов матрицы
int Sum_Matrix(Matrix* M);

//Функция сравнения сумм элементов матриц
bool Compare(Matrix* First, Matrix* Second);

#endif //MATRIX_H