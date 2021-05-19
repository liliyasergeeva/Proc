#ifndef CONTAINER_H
#define CONTAINER_H

#include <fstream>

#include "Matrix.h"

using namespace std;

//Контейнер
struct Container {
    enum { 
        Max_len = 100 
    }; // Максимальная длина контейнера

    int Len; // Текущая длина
    Matrix* Cont[Max_len]; //Массив матриц
};

//Функция инициализации контейнера
void Init_Container(Container& C);

//Функция ввода элементов в контейнер
void In_Container(Container& C, ifstream& ifst);

//Функция вывод контейнера
void Out_Container(Container& C, ofstream& ofst);

//Функция очистки контейнера
void Clear_Container(Container& C);

#endif //CONTAINER_H