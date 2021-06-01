#include "Matrix.h"
#include "Two_dimensional_array.h"
#include "Diagonal_matrix.h"

#include <iostream>
#include <string>

Matrix* In_Matrix(ifstream& ifst) {
    Matrix* M; //Создаем указатель на матрицу
    string Temp_Str = "";

    getline(ifst, Temp_Str);

    //Проверка того, что файл либо содержит ошибочный идентификтор Машины,
    //либо не содержит его вовсе
    if ((Temp_Str != "1") && (Temp_Str != "2") && (Temp_Str != "3")) {
        //Возможно идентификатора нет, потому что это конец файл
        if (ifst.peek() == EOF) {
            return 0;
        }
        else { //В ином случае идентификатор отсутствует вовсе, либо он ошибочен
            //Завершение программы с ошибкой
            cout << "Input data is incomplete or incorrect!";
            exit(1);
        }
    }

    int K = atoi(Temp_Str.c_str());

    M = new Matrix; //Выделяем память под матрицу

    if (K == 1)
    {
        M->K = TWO_DIMENSIONAL_ARRAY; //Записываем тип матрицы
    }
    else if (K == 2)
    {
        M->K = DIAGONAL_MATRIX; //Записываем тип матрицы
    }
    else if (K == 3)
    {
        M->K = TRIANGULAR_MATRIX; //Записываем тип матрицы
    }
    
    getline(ifst, Temp_Str);

    if (ifst.peek() == EOF) {
        //Завершение программы с ошибкой
        cout << "Input data is incomplete!";
        exit(1);
    }

    if ((Temp_Str != "1") && (Temp_Str != "2") && (Temp_Str != "3"))
    {
        //Завершение программы с ошибкой
        cout << "Input data is incorrect!";
        exit(1);
    }

    int Key_out = atoi(Temp_Str.c_str());

    if (Key_out == 1)
    {
        M->K_o = BY_LINE;
    }
    else if (Key_out == 2)
    {
        M->K_o = BY_COLUMN;
    }
    else if (Key_out == 3)
    {
        M->K_o = ONE_DIMENSIONAL;
    }

    getline(ifst, Temp_Str);

    string Alph_num = "0123456789";

    //Цикл проверки того, что строка содержит только цифры
    for (int i = 0; i < Temp_Str.length(); i++) {
        if (Alph_num.find(Temp_Str[i]) == -1) {
            //Завершение программы с ошибкой
            cout << "Input data is incorrect!";
            exit(1);
        }
    }

    M->N = atoi(Temp_Str.c_str()); //Записываем размерность матрицы

    if (K == 1)
    {
        In_Two_dimensional_array(M->N, M->T_d_a, ifst);
    }
    else if (K == 2)
    {
        In_Diagonal_matrix(M->N, M->D_m, ifst);
    }
    else if (K == 3)
    {
        In_Triangular_matrix(M->N, M->T_m, ifst);
    }

    return M;
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
    else if (M->K == TRIANGULAR_MATRIX)
    {
        Out_Triangular_matrix(M->K_o, M->N, M->T_m, ofst); //Выводим диагональную матрицу
    }
    else
    {
        ofst << "Incorrect element!" << endl;
    }
}

int Sum_Matrix(Matrix* M) {
    if (M->K == TWO_DIMENSIONAL_ARRAY)
    {
        return Sum_Two_dimensional_array(M->N, M->T_d_a);
    }
    else if (M->K == DIAGONAL_MATRIX)
    {
        return Sum_Diagonal_matrix(M->N, M->D_m);
    }
    else if (M->K == TRIANGULAR_MATRIX)
    {
        return Sum_Triangular_matrix(M->N, M->T_m);
    }
    else
    {
        return -1;
    }
}

bool Compare(Matrix* First, Matrix* Second)
{
    return Sum_Matrix(First) > Sum_Matrix(Second);
}