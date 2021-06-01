#include "Triangular_matrix.h"

#include <iostream>

void In_Triangular_matrix(int N, Triangular_matrix& T_m, ifstream& ifst)
{
    int Temp_N = N;
    int Array_size = 0;

    while (Temp_N != 0)
    {
        Array_size += Temp_N;
        Temp_N--;
    }

    T_m.Array = new int[Array_size];
    string Alph_num = "0123456789";
    string Temp_Str = "";

    for (int i = 0; i < Array_size; i++)
    {
        ifst >> Temp_Str;

        if (ifst.peek() == EOF) {
            //���������� ��������� � �������
            cout << "Input data is incomplete!";
            exit(1);
        }

        //���� ��������� ����� - ������ ������
        if (Temp_Str == "")
        {
            //���������� ��������� � �������
            cout << "Input data is incomplete!";
            exit(1);
        }

        //���� ����� ���������� � 0
        if (Temp_Str[0] == '0' && Temp_Str.length() > 1)
        {
            //���������� ��������� � �������
            cout << "Input data is incorrect!";
            exit(1);
        }

        //���� �������� ����, ��� ������ �������� ������ �����
        for (int i = 0; i < Temp_Str.length(); i++) {
            if (Alph_num.find(Temp_Str[i]) == -1) {
                //���������� ��������� � �������
                cout << "Input data is incorrect!";
                exit(1);
            }
        }

        T_m.Array[i] = atoi(Temp_Str.c_str());
    }

    ifst.get(); //����� ���������� ��������� ������� � ����� �������� ������ ����� ������, ��������� ���
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