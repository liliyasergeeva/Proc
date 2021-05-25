#ifndef TRIANGULAR_MATRIX_H
#define TRIANGULAR_MATRIX_H

#include <fstream>

#include "Key.h"

using namespace std;

struct Triangular_matrix {
    int* Array;
};

//Функция ввода двумерного массива
void In_Triangular_matrix(int N, Triangular_matrix& T_m, ifstream& ifst);

//Функция вывода двумерного массива
void Out_Triangular_matrix(Key_out K_o, int N, Triangular_matrix& T_m, ofstream& ofst);

//Функция подсчета суммы элементов треугольной матрицы
int Sum_Triangular_matrix(int N, Triangular_matrix& T_m);

#endif // TRIANGULAR_MATRIX_H
