#include "Two_dimensional_array.h"

void In_Two_dimensional_array(int N, Two_dimensional_array& T_d_a, ifstream& ifst)
{
    T_d_a.Array = new int* [N]; //Выделение памяти под массив

    for (int i = 0; i < N; i++)
    {
        T_d_a.Array[i] = new int[N]; //Выделение памяти под массив
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            ifst >> T_d_a.Array[i][j]; //Ввод элемента массива
        }
    }
}

void Out_Two_dimensional_array(Key_out K_o, int N, Two_dimensional_array& T_d_a, ofstream& ofst)
{
    ofst << "It's two dimensional matrix with dimension = " << N << endl; //Выводим размерность массива

    if (K_o == BY_LINE)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                ofst << T_d_a.Array[i][j] << " ";
            }
            ofst << endl;
        }
    }
    else if (K_o == BY_COLUMN)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                ofst << T_d_a.Array[j][i] << " ";
            }
            ofst << endl;
        }
    }
    else if (K_o == ONE_DIMENSIONAL)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                ofst << T_d_a.Array[i][j] << " ";
            }
        }

        ofst << endl;
    }
}