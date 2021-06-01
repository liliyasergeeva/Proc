#include "Diagonal_matrix.h"

#include <iostream>

void In_Diagonal_matrix(int N, Diagonal_matrix& D_m, ifstream& ifst)
{
    D_m.Array = new int[N]; //Выделяем память для диагональной матрицы
    string Alph_num = "0123456789";
    string Temp_Str = "";

    for (int i = 0; i < N; i++)
    {
        ifst >> Temp_Str;

        if (ifst.peek() == EOF) {
            //Завершение программы с ошибкой
            cout << "Input data is incomplete!";
            exit(1);
        }

        //Если считанное числе - пустая строка
        if (Temp_Str == "")
        {
            //Завершение программы с ошибкой
            cout << "Input data is incomplete!";
            exit(1);
        }

        //Если число начинается с 0
        if (Temp_Str[0] == '0' && Temp_Str.length() > 1)
        {
            //Завершение программы с ошибкой
            cout << "Input data is incorrect!";
            exit(1);
        }

        //Цикл проверки того, что строка содержит только цифры
        for (int i = 0; i < Temp_Str.length(); i++) {
            if (Alph_num.find(Temp_Str[i]) == -1) {
                //Завершение программы с ошибкой
                cout << "Input data is incorrect!";
                exit(1);
            }
        }

        D_m.Array[i] = atoi(Temp_Str.c_str());
    }

    ifst.get(); //После считывания элементов массива в файле остается символ конца строки, считываем его
}

void Out_Diagonal_matrix(Key_out K_o, int N, Diagonal_matrix& D_m, ofstream& ofst)
{
    ofst << "It's diagonal matrix with dimension = " << N << endl; //Выводим размерность матрицы

    if (K_o == BY_LINE)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i == j)
                {
                    ofst << D_m.Array[i] << " ";
                }
                else
                {
                    ofst << "0 ";
                }
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
                if (i == j)
                {
                    ofst << D_m.Array[j] << " ";
                }
                else
                {
                    ofst << "0 ";
                }
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
                if (i == j)
                {
                    ofst << D_m.Array[i] << " ";
                }
                else
                {
                    ofst << "0 ";
                }
            }
        }

        ofst << endl;
    }
}

int Sum_Diagonal_matrix(int N, Diagonal_matrix& D_m)
{
    int Sum = 0;

    for (int i = 0; i < N; i++)
    {
        Sum += D_m.Array[i];
    }
    return Sum;
}