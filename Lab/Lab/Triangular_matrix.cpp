#include "Triangular_matrix.h"

void In_Triangular_matrix(int N, Triangular_matrix& T_m, ifstream& ifst)
{
    //Корректируем размер треугольной матрицы
    int Temp_N = N;
    int Array_size = 0;

    while (Temp_N != 0)
    {
        Array_size += Temp_N;
        Temp_N--;
    }

    T_m.Array = new int[Array_size];
    
    for (int i = 0; i < Array_size; i++)
    {
        ifst >> T_m.Array[i]; //Записываем элементы матрицы
    }
}

void Out_Triangular_matrix(int N, Triangular_matrix& T_m, ofstream& ofst)
{
    ofst << "It's triangular matrix with dimension = " << N << endl;
    
    int Array_index = 0; //Иднекс для прохода ненулевых элементов матрицы

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i >= j)
            {
                ofst << T_m.Array[Array_index] << " ";
                Array_index++;
            }
            else
            {
                ofst << "0 ";
            }
        }
        ofst << endl;
    }
}