#ifndef DIAGONAL_MATRIX_H
#define DIAGONAL_MATRIX_H

#include <fstream>

#include "Key.h"

using namespace std;

//Структура "диагональная матрица"
struct Diagonal_matrix {
    int* Array; //Массив
};

//Функция ввода диагональной матрицы
void In_Diagonal_matrix(int N, Diagonal_matrix& D_m, ifstream& ifst);

//Функция вывода диагональной матрицы
void Out_Diagonal_matrix(Key_out K_o, int N, Diagonal_matrix& D_m, ofstream& ofst);

//Функция подсчета суммы элементов диагональной матрицы
int Sum_Diagonal_matrix(int N, Diagonal_matrix& D_m);

#endif //DIAGONAL_MATRIX_H