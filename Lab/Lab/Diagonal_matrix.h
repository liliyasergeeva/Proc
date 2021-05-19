#ifndef DIAGONAL_MATRIX_H
#define DIAGONAL_MATRIX_H

#include <fstream>
using namespace std;

//Структура диагональной матрицы
struct Diagonal_matrix {
    int* Array;
};

//Функция ввода диагональной матрицы
void In_Diagonal_matrix(int N, Diagonal_matrix& D_m, ifstream& ifst);

//Функция вывода диагональной матрицы
void Out_Diagonal_matrix(int N, Diagonal_matrix& D_m, ofstream& ofst);

#endif //DIAGONAL_MATRIX_H