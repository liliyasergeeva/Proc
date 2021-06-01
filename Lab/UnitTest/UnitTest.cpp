#include "pch.h"
#include "CppUnitTest.h"

#include "../Lab/Container.h"
#include "../Lab/Key.h"
#include "../Lab/Matrix.h"
#include "../Lab/Diagonal_matrix.h"
#include "../Lab/Two_dimensional_array.h"
#include "../Lab/Triangular_matrix.h"

#include "../Lab/Container.cpp"
#include "../Lab/Matrix.cpp"
#include "../Lab/Diagonal_matrix.cpp"
#include "../Lab/Two_dimensional_array.cpp"
#include "../Lab/Triangular_matrix.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		TEST_METHOD(In_Two_Dim_Test) //Тест проверки ввода двумерного массива
		{
			Two_dimensional_array T_d_a_Exp;

			T_d_a_Exp.Array = new int* [3];

			for (int i = 0; i < 3; i++) {
				T_d_a_Exp.Array[i] = new int[3];
			}

			T_d_a_Exp.Array[0][0] = 1;
			T_d_a_Exp.Array[0][1] = 2;
			T_d_a_Exp.Array[0][2] = 3;
			T_d_a_Exp.Array[1][0] = 4;
			T_d_a_Exp.Array[1][1] = 0;
			T_d_a_Exp.Array[1][2] = 6;
			T_d_a_Exp.Array[2][0] = 7;
			T_d_a_Exp.Array[2][1] = 5;
			T_d_a_Exp.Array[2][2] = 9;

			Two_dimensional_array T_d_a_Act;

			ifstream ifst("../Lab/in_two_dim.txt");

			In_Two_dimensional_array(3, T_d_a_Act, ifst);

			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					Assert::AreEqual(T_d_a_Exp.Array[i][j], T_d_a_Act.Array[i][j]);
				}
			}
		}
		TEST_METHOD(In_Diagonal_Test) //Тест проверки ввода диагональной матрицы
		{
			Diagonal_matrix D_m_Exp;

			D_m_Exp.Array = new int[4];

			D_m_Exp.Array[0] = 9;
			D_m_Exp.Array[1] = 7;
			D_m_Exp.Array[2] = 2;
			D_m_Exp.Array[3] = 1;

			Diagonal_matrix D_m_Act;

			ifstream ifst("../Lab/in_diagonal.txt");

			In_Diagonal_matrix(4, D_m_Act, ifst);

			for (int i = 0; i < 4; i++) {
				Assert::AreEqual(D_m_Exp.Array[i], D_m_Act.Array[i]);
			}
		}
		TEST_METHOD(In_Triangular_Test) //Тест проверки ввода треугольной матрицы
		{
			Triangular_matrix T_m_Exp;

			T_m_Exp.Array = new int[10];

			T_m_Exp.Array[0] = 1;
			T_m_Exp.Array[1] = 2;
			T_m_Exp.Array[2] = 3;
			T_m_Exp.Array[3] = 4;
			T_m_Exp.Array[4] = 5;
			T_m_Exp.Array[5] = 6;
			T_m_Exp.Array[6] = 7;
			T_m_Exp.Array[7] = 8;
			T_m_Exp.Array[8] = 9;
			T_m_Exp.Array[9] = 0;

			Triangular_matrix T_m_Act;

			ifstream ifst("../Lab/in_triangular.txt");

			In_Triangular_matrix(4, T_m_Act, ifst);

			for (int i = 0; i < 10; i++) {
				Assert::AreEqual(T_m_Exp.Array[i], T_m_Act.Array[i]);
			}
		}
		TEST_METHOD(In_Matrix_Test) //Тест проверки ввода матрицы
		{
			Diagonal_matrix D_m;

			D_m.Array = new int[4];

			D_m.Array[0] = 9;
			D_m.Array[1] = 7;
			D_m.Array[2] = 2;
			D_m.Array[3] = 1;

			Matrix* M_Exp = new Matrix();

			M_Exp->K = DIAGONAL_MATRIX;
			M_Exp->K_o = BY_COLUMN;
			M_Exp->N = 4;
			M_Exp->D_m = D_m;

			ifstream ifst("../Lab/in_matrix.txt");

			Matrix* M_Act = In_Matrix(ifst);

			Assert::AreEqual((int)M_Exp->K, (int)M_Act->K);
			Assert::AreEqual((int)M_Exp->K_o, (int)M_Act->K_o);
			Assert::AreEqual(M_Exp->N, M_Act->N);

			for (int i = 0; i < 4; i++) {
				Assert::AreEqual(M_Exp->D_m.Array[i], M_Act->D_m.Array[i]);
			}
		}
		TEST_METHOD(Out_Two_dim_Test)
		{
			Two_dimensional_array T_d_a_Act;

			T_d_a_Act.Array = new int* [3];

			for (int i = 0; i < 3; i++) {
				T_d_a_Act.Array[i] = new int[3];
			}

			T_d_a_Act.Array[0][0] = 1;
			T_d_a_Act.Array[0][1] = 2;
			T_d_a_Act.Array[0][2] = 3;
			T_d_a_Act.Array[1][0] = 4;
			T_d_a_Act.Array[1][1] = 0;
			T_d_a_Act.Array[1][2] = 6;
			T_d_a_Act.Array[2][0] = 7;
			T_d_a_Act.Array[2][1] = 5;
			T_d_a_Act.Array[2][2] = 9;

			ofstream ofst("../Lab/out_two_dim_act.txt");

			Out_Two_dimensional_array(BY_LINE, 3, T_d_a_Act, ofst);

			ifstream ifst_exp("../Lab/out_two_dim_exp.txt");
			ifstream ifst_act("../Lab/out_two_dim_act.txt");

			string Expected;
			getline(ifst_exp, Expected, '\0');
			string Actual;
			getline(ifst_act, Actual, '\0');

			Assert::AreEqual(Expected, Actual);
		}
		TEST_METHOD(Out_Diagonal_Test)
		{
			Diagonal_matrix D_m_Act;

			D_m_Act.Array = new int[4];

			D_m_Act.Array[0] = 9;
			D_m_Act.Array[1] = 7;
			D_m_Act.Array[2] = 2;
			D_m_Act.Array[3] = 1;

			ofstream ofst("../Lab/out_diagonal_act.txt");

			Out_Diagonal_matrix(BY_COLUMN, 4, D_m_Act, ofst);

			ifstream ifst_exp("../Lab/out_diagonal_exp.txt");
			ifstream ifst_act("../Lab/out_diagonal_act.txt");

			string Expected;
			getline(ifst_exp, Expected, '\0');
			string Actual;
			getline(ifst_act, Actual, '\0');

			Assert::AreEqual(Expected, Actual);
		}
		TEST_METHOD(Out_Triangular_Test)
		{
			Triangular_matrix T_m_Act;

			T_m_Act.Array = new int[9];

			T_m_Act.Array[0] = 1;
			T_m_Act.Array[1] = 2;
			T_m_Act.Array[2] = 3;
			T_m_Act.Array[3] = 4;
			T_m_Act.Array[4] = 5;
			T_m_Act.Array[5] = 6;
			T_m_Act.Array[6] = 7;
			T_m_Act.Array[7] = 8;
			T_m_Act.Array[8] = 9;
			T_m_Act.Array[9] = 0;

			ofstream ofst("../4lab/out_triangular_act.txt");

			Out_Triangular_matrix(BY_LINE, 4, T_m_Act, ofst);

			ifstream ifst_exp("../Lab/out_triangular_exp.txt");
			ifstream ifst_act("../Lab/out_triangular_act.txt");

			string Expected;
			getline(ifst_exp, Expected, '\0');
			string Actual;
			getline(ifst_act, Actual, '\0');

			Assert::AreEqual(Expected, Actual);
		}
		TEST_METHOD(Out_Matrix_Test)
		{
			Two_dimensional_array T_d_a;

			T_d_a.Array = new int* [3];

			for (int i = 0; i < 3; i++) {
				T_d_a.Array[i] = new int[3];
			}

			T_d_a.Array[0][0] = 1;
			T_d_a.Array[0][1] = 2;
			T_d_a.Array[0][2] = 3;
			T_d_a.Array[1][0] = 4;
			T_d_a.Array[1][1] = 0;
			T_d_a.Array[1][2] = 6;
			T_d_a.Array[2][0] = 7;
			T_d_a.Array[2][1] = 5;
			T_d_a.Array[2][2] = 9;

			Matrix* M_Act = new Matrix();

			M_Act->K = TWO_DIMENSIONAL_ARRAY;
			M_Act->K_o = BY_LINE;
			M_Act->N = 3;
			M_Act->T_d_a = T_d_a;

			ofstream ofst("../Lab/out_matrix_act.txt");

			Out_Matrix(M_Act, ofst);

			ifstream ifst_exp("../Lab/out_matrix_exp.txt");
			ifstream ifst_act("../Lab/out_matrix_act.txt");

			string Expected;
			getline(ifst_exp, Expected, '\0');
			string Actual;
			getline(ifst_act, Actual, '\0');

			Assert::AreEqual(Expected, Actual);
		}
		TEST_METHOD(Sum_Test)
		{
			Diagonal_matrix D_m;

			D_m.Array = new int[4];

			D_m.Array[0] = 9;
			D_m.Array[1] = 7;
			D_m.Array[2] = 2;
			D_m.Array[3] = 1;

			Matrix* M = new Matrix();

			M->K = DIAGONAL_MATRIX;
			M->N = 4;
			M->D_m = D_m;

			int Sum_Exp = 19;
			int Sum_Act = Sum_Matrix(M);

			Assert::AreEqual(Sum_Exp, Sum_Act);
			Assert::AreEqual(Sum_Exp, Sum_Act);
		}
		TEST_METHOD(Compare_Test)
		{
			Two_dimensional_array T_d_a_First;
			Two_dimensional_array T_d_a_Second;

			T_d_a_First.Array = new int* [3];
			T_d_a_Second.Array = new int* [3];

			for (int i = 0; i < 3; i++) {
				T_d_a_First.Array[i] = new int[3];
				T_d_a_Second.Array[i] = new int[3];
			}

			T_d_a_Second.Array[0][0] = 0;
			T_d_a_First.Array[0][0] = 1;

			T_d_a_Second.Array[0][1] = T_d_a_First.Array[0][1] = 2;
			T_d_a_Second.Array[0][2] = T_d_a_First.Array[0][2] = 3;
			T_d_a_Second.Array[1][0] = T_d_a_First.Array[1][0] = 4;
			T_d_a_Second.Array[1][1] = T_d_a_First.Array[1][1] = 0;
			T_d_a_Second.Array[1][2] = T_d_a_First.Array[1][2] = 6;
			T_d_a_Second.Array[2][0] = T_d_a_First.Array[2][0] = 7;
			T_d_a_Second.Array[2][1] = T_d_a_First.Array[2][1] = 5;
			T_d_a_Second.Array[2][2] = T_d_a_First.Array[2][2] = 9;

			Matrix* M_First = new Matrix();

			M_First->K = TWO_DIMENSIONAL_ARRAY;
			M_First->N = 3;
			M_First->T_d_a = T_d_a_First;

			Matrix* M_Second = new Matrix();

			M_Second->K = TWO_DIMENSIONAL_ARRAY;
			M_Second->N = 3;
			M_Second->T_d_a = T_d_a_Second;

			bool Act = Compare(M_First, M_Second);
			bool Exp = true;

			Assert::AreEqual(Exp, Act);
		}
		TEST_METHOD(Sort_Test)
		{
			//Введем информацию их файла
			ifstream ifst("../Lab/input.txt");

			Container Cont;

			Init_Container(Cont);

			In_Container(Cont, ifst);

			ofstream ofst("../Lab/sort_act.txt");

			//Отсортируем
			Sort(Cont);

			//Выведем отсортированный контейнер
			Out_Container(Cont, ofst);

			//Считаем то, что вывели ранее, и то, что должно было получиться при сортировке 
			ifstream ifst_exp("../Lab/sort_exp.txt");
			ifstream ifst_act("../Lab/sort_act.txt");

			//Сравниваем
			string Exp;
			getline(ifst_exp, Exp, '\0');
			string Act;
			getline(ifst_act, Act, '\0');

			Assert::AreEqual(Exp, Act);
		}
	};
}