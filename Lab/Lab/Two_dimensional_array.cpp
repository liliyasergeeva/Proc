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

void Out_Two_dimensional_array(int N, Two_dimensional_array& T_d_a, ofstream& ofst)
{
    ofst << "It's two dimensional matrix with dimension = " << N << endl; //Выводим размерность массива

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            ofst << T_d_a.Array[i][j] << " "; //Выводим элементы массива
        }

        ofst << endl;
    }
}

int Sum_Two_dimensional_array(int N, Two_dimensional_array& T_d_a)
{
    int Sum = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            Sum += T_d_a.Array[i][j];
        }
    }

    return Sum;
}