#ifndef MATRIX_H
#define MATRIX_H

#include "Key.h"
#include "Diagonal_matrix.h"
#include "Two_dimensional_array.h"

//Структура "матрицы"
struct Matrix {
    Key K; //Идентификатор матрицы - диагональная или обычный двумерный массив
    int N; //Длина массива

    //Объект диагональной матрицы или обычного двумерного массива
    union {
        Diagonal_matrix D_m;
        Two_dimensional_array T_d_a;
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