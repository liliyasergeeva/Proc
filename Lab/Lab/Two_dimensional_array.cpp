#include "Two_dimensional_array.h"

#include <iostream>

void In_Two_dimensional_array(int N, Two_dimensional_array& T_d_a, ifstream& ifst)
{
    T_d_a.Array = new int* [N]; //��������� ������ ��� ������

    for (int i = 0; i < N; i++) {
        T_d_a.Array[i] = new int[N]; //��������� ������ ��� ������
    }

    string Alph_num = "0123456789";
    string Temp_Str = "";

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ifst >> Temp_Str;

            if (ifst.peek() == EOF) {
                //���������� ��������� � �������
                cout << "Input data is incomplete!";
                exit(1);
            }

            //���� ��������� ����� - ������ ������
            if (Temp_Str == "") {
                //���������� ��������� � �������
                cout << "Input data is incomplete!";
                exit(1);
            }

            //���� ����� ���������� � 0
            if ((Temp_Str[0] == '0') && (Temp_Str.length() > 1)) {
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

            T_d_a.Array[i][j] = atoi(Temp_Str.c_str());
        }
    }

    ifst.get(); //����� ���������� ��������� ������� � ����� �������� ������ ����� ������, ��������� ���
}

void Out_Two_dimensional_array(Key_out K_o, int N, Two_dimensional_array& T_d_a, ofstream& ofst) {
    ofst << "It's two dimensional matrix with dimension = " << N << endl; 

    if (K_o == BY_LINE) { //����� �� �������
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                ofst << T_d_a.Array[i][j] << " ";
            }

            ofst << endl;
        }

        ofst << endl;
    }
    else if (K_o == BY_COLUMN) { //����� �� ��������
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                ofst << T_d_a.Array[j][i] << " ";
            }

            ofst << endl;
        }

        ofst << endl;
    }
    else if (K_o == ONE_DIMENSIONAL) { //����� � ���� ����������� �������
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                ofst << T_d_a.Array[i][j] << " ";
            }
        }

        ofst << endl;
    }
}

int Sum_Two_dimensional_array(int N, Two_dimensional_array& T_d_a) {
    int Sum = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Sum += T_d_a.Array[i][j];
        }
    }

    return Sum;
}