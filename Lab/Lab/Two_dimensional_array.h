#ifndef TWO_DIMENSIONAL_ARRAY_H
#define TWO_DIMENSIONAL_ARRAY_H

#include <fstream>

using namespace std;

//Структура двумерного массива
struct Two_dimensional_array {
    int** Array;
};

//Функция ввода двумерного массива
void In_Two_dimensional_array(int N, Two_dimensional_array& T_d_a, ifstream& ifst);

//Функция вывода двумерного массива
void Out_Two_dimensional_array(int N, Two_dimensional_array& T_d_a, ofstream& ofst);

//Функция подсчета суммы элементов двумерного массива
int Sum_Two_dimensional_array(int N, Two_dimensional_array& T_d_a);

#endif //TWO_DIMENSIONAL_ARRAY_H