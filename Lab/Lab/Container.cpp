#include "Container.h"

void Init_Container(Container& C) {
    C.Len = 0;
}

void In_Container(Container& C, ifstream& ifst) {
    while (!ifst.eof()) //Читаем до конца файла
    {
        if ((C.Cont[C.Len] = In_Matrix(ifst)) != 0) //Считываем очередную матрицу 
        { 
            C.Len++;

            if (C.Len == C.Max_len) //Проверка на переполнение контейнера
            {
                break;
            }
        }
    }
}

void Out_Container(Container& C, ofstream& ofst) {
    ofst << "Container contains " << C.Len 
        << " elements." << endl; //Выводим длину контейнера

    for (int i = 0; i < C.Len; i++)
    {
        ofst << i << ": "; //Выводим номер матрицы
        Out_Matrix(C.Cont[i], ofst); //Выводим матрицу
    }
}

void Clear_Container(Container& C) {
    for (int i = 0; i < C.Len; i++) 
    {
        delete C.Cont[i]; //Очищаем память, вылеленную для каждой матрицы
    }
    
    C.Len = 0;
}