#include "Matrix.h"
#include "Two_dimensional_array.h"
#include "Diagonal_matrix.h"

Matrix* In_Matrix(ifstream& ifst) {
    Matrix* M; //Создаем указатель на матрицу
    int K;

    ifst >> K; //Считываем идентификатор матрицы

    if (K == 1)
    {
        M = new Matrix; //Выделяем память под матрицу
        M->K = TWO_DIMENSIONAL_ARRAY; //Записываем тип матрицы

        int K_out = 0;

        ifst >> K_out; //Считываем способ вывода матрицы

        if (K_out == 1)
        {
            M->K_o = BY_LINE;
        }
        else if (K_out == 2)
        {
            M->K_o = BY_COLUMN;
        }
        else if (K_out == 3)
        {
            M->K_o = ONE_DIMENSIONAL;
        }

        ifst >> M->N; //Считываем размерность матрицы
        
        In_Two_dimensional_array(M->N, M->T_d_a, ifst); //Считываем элементы матрицы

        return M;
    }
    else if (K == 2)
    {
        M = new Matrix; //Выделяем память под матрицу
        M->K = DIAGONAL_MATRIX; //Записываем тип матрицы

        int K_out = 0;

        ifst >> K_out; //Считываем способ вывода матрицы

        if (K_out == 1)
        {
            M->K_o = BY_LINE;
        }
        else if (K_out == 2)
        {
            M->K_o = BY_COLUMN;
        }
        else if (K_out == 3)
        {
            M->K_o = ONE_DIMENSIONAL;
        }

        ifst >> M->N; //Считываем размерность матрицы
        
        In_Diagonal_matrix(M->N, M->D_m, ifst); //Считываем элементы матрицы

        return M;
    }
    else
    {
        return 0;
    }
}

void Out_Matrix(Matrix* M, ofstream& ofst) {
    if (M->K == TWO_DIMENSIONAL_ARRAY)
    {
        Out_Two_dimensional_array(M->K_o, M->N, M->T_d_a, ofst); //Выводим обычный двумерный массив
    }
    else if (M->K == DIAGONAL_MATRIX)
    {
        Out_Diagonal_matrix(M->K_o, M->N, M->D_m, ofst); //Выводим диагональную матрицу
    }
    else
    {
        ofst << "Incorrect element!" << endl;
    }
}