#include "Triangular_matrix.h"

void In_Triangular_matrix(int N, Triangular_matrix& T_m, ifstream& ifst)
{
    int Temp_N = N;
    int Array_size = 0;

    while (Temp_N != 0)
    {
        Array_size += Temp_N;
        Temp_N--;
    }

    T_m.Array= new int[Array_size];
    
    for (int i = 0; i < Array_size; i++)
    {
        ifst >> T_m.Array[i];
    }
}

void Out_Triangular_matrix(Key_out K_o, int N, Triangular_matrix& T_m, ofstream& ofst)
{
    ofst << "It's triangular matrix with dimension = " << N << endl;
    
    int Array_index = 0;

    int** Temp_array = new int* [N];

    for (int i = 0; i < N; i++)
    {
        Temp_array[i] = new int[N];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i >= j)
            {
                Temp_array[i][j] = T_m.Array[Array_index];
                Array_index++;
            }
            else
            {
                Temp_array[i][j] = 0;
            }
        }
    }

    if (K_o == BY_LINE)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                ofst << Temp_array[i][j] << " ";
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
                ofst << Temp_array[j][i] << " ";
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
                ofst << Temp_array[i][j] << " ";
            }
        }
        ofst << endl;
    }
}

int Sum_Triangular_matrix(int N, Triangular_matrix& T_m)
{
    int Temp_N = N;
    int Array_size = 0;

    while (Temp_N) {
        Array_size += Temp_N;
        Temp_N--;
    }

    int Sum = 0;

    for (int i = 0; i < Array_size; i++) {
        Sum += T_m.Array[i];
    }

    return Sum;
}