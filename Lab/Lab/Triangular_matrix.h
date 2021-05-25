#ifndef TRIANGULAR_MATRIX_H
#define TRIANGULAR_MATRIX_H

#include <fstream>

using namespace std;

struct Triangular_matrix {
    int* Array;
};

//Функция ввода треугольной матрицы
void In_Triangular_matrix(int N, Triangular_matrix& T_m, ifstream& ifst);

//Функция вывода треугольной матрицы
void Out_Triangular_matrix(int N, Triangular_matrix& T_m, ofstream& ofst);

#endif // TRIANGULAR_MATRIX_H
