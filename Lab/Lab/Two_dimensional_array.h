#ifndef TWO_DIMENSIONAL_ARRAY_H
#define TWO_DIMENSIONAL_ARRAY_H

#include <fstream>

#include "Key.h"

using namespace std;

//Структура двумерного массива
struct Two_dimensional_array {
    int** Array;
};

//Функция ввода двумерного массива
void In_Two_dimensional_array(int N, Two_dimensional_array& T_d_a, ifstream& ifst);

//Функция вывода двумерного массива
void Out_Two_dimensional_array(Key_out K_o, int N, Two_dimensional_array& T_d_a, ofstream& ofst);

#endif //TWO_DIMENSIONAL_ARRAY_H