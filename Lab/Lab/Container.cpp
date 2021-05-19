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

        ofst << "Sum of matrix elements = " << Sum_Matrix(C.Cont[i]) << endl;
    }
}

void Clear_Container(Container& C) {
    for (int i = 0; i < C.Len; i++) 
    {
        delete C.Cont[i]; //Очищаем память, вылеленную для каждой матрицы
    }
    
    C.Len = 0;
}

void Sort(Container& C)
{
    //Сортируем пузырьком
    for (int i = 0; i < C.Len - 1; i++) 
    { 
        for (int j = i + 1; j < C.Len; j++) 
        { 
            //Компаратором сравниваем суммы элементов матриц
            if (Compare(C.Cont[i], C.Cont[j])) 
            { 
                Matrix* Temp = C.Cont[i]; 
                C.Cont[i] = C.Cont[j]; 
                C.Cont[j] = Temp; 
            } 
        } 
    }
}