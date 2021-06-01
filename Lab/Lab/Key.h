#ifndef KEY_H
#define KEY_H

//Иднетификатор матрицы
enum Key {
    DIAGONAL_MATRIX, //Диагональная матрицы
    TWO_DIMENSIONAL_ARRAY, //Двумерный массив
    TRIANGULAR_MATRIX, //Треугольная матрица
    ERROR //Ошибочный массив (некорректный ввод данных)
};

//Способ вывода матрицы
enum Key_out {
    BY_LINE, //По строкам
    BY_COLUMN, //По столбцам
    ONE_DIMENSIONAL //В виде одномерного массива
};

#endif //KEY_H