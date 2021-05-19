#include "Diagonal_matrix.h"

void In_Diagonal_matrix(int N, Diagonal_matrix& D_m, ifstream& ifst)
{
    D_m.Array = new int[N]; //Выделяем память для диагональной матрицы
    
    for (int i = 0; i < N; i++)
    {
        ifst >> D_m.Array[i]; //Записываем новый элемент в матрицу
    }
}

void Out_Diagonal_matrix(int N, Diagonal_matrix& D_m, ofstream& ofst)
{
    ofst << "It's diagonal matrix with dimension = " << N << endl; //Выводим размерность матрицы

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
            {
                ofst << D_m.Array[i] << " "; //Выводим элемент матрицы; (i == j) -> только по диагонали
            }
            else
            {
                ofst << "0 "; //(i != j) -> не диагональ, выводим нули
            }
        }

        ofst << endl;
    }
}