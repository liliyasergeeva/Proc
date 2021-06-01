#ifndef KEY_H
#define KEY_H

//Иднетификатор матрицы
enum Key {
    DIAGONAL_MATRIX, //Диагональная матрицы
    TWO_DIMENSIONAL_ARRAY, //Двумерный массив
    TRIANGULAR_MATRIX,
    ERROR
};

//Способ вывода матрицы
enum Key_out {
    BY_LINE, //По строкам
    BY_COLUMN, //По столбцам
    ONE_DIMENSIONAL //В виде одномерного массива
};

#endif //KEY_H