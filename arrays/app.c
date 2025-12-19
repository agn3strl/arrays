#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include "array.h"
#define N 10

int task11();
int task14(int size);
int task16(int size);


int main()
{
	system("chcp 1251");

	puts("Лабораторные работы 11, 14, 16, 19, 25: Работа с массивами ===\n");
	puts("\n");

	int size;
	printf("Введите количество элементов массива: ");
	scanf("%d", &size);
	puts("\n");

	printf("РАБОТА 11\n");
	task11();
	puts("\n");

	printf("РАБОТА 14\n");
	task14(size);
	puts("\n");

	printf("РАБОТА 16\n");
	task16(size);

	return 0;
}

int task11()
{
	float A[N], B[N];

	// ЗАДАНИЕ 1 - Заполнение массива
	printf("Введите элементы массива:\n");
	for (int i = 0; i < N; i++) {
		float temp;
		printf("a[%d] = ", i + 1);
		scanf("%f", &temp);
		A[i] = temp;
	}

	// ЗАДАНИЕ 2 - Преобразование массива
	for (int i = 0; i < N; i++) {
		if (A[i] < 0) B[i] = 0;
		else B[i] = A[i];
	}
	puts("\n");

	// ЗАДАНИЕ 3 - Печать массива
	printf("Значения исходного и преобразованного массивов:\n");
	printf("|  № |  A[i]  |  B[i]  |\n");
	for (int i = 0; i < N; i++) {
		printf("| %2d | %6.2f | %6.2f |\n", i + 1, A[i], B[i]);
	}
	puts("\n");

	// ДЗ - Сумма всех элементов массива, расположенных до последнего положительного элемента
	int el = 0;
	for (int i = N; i >= 0; i--) {
		if (A[i] > 0) {
			el = i;
			break;
		}
	}
	double sum = 0;
	for (int i = 0; i < el; i++) sum += A[i];
	printf("ДЗ: Cумма всех элементов массива, расположенных до последнего положительного элемента равна %.2f\n", sum);
}



int task14(int size)
{
	double* array;
	array = (double*)malloc(size * sizeof(double));
	if (array == NULL) {
		puts("error");
		return -1;
	}

	// ЗАДАНИЕ 1 - Заполнение массива значениями из функции func(x)
	double x;
	printf("Введите значения аргумента функции, по которой будут вычисленны элементы массива: ");
	scanf("%lf", &x);
	full_elements(array, size, x);
	puts("\n");

	// ЗАДАНИЕ 2 - Печать и преобразование массива
	printf("Печать элементов массива, вычисленных по функции 1,8x^2 - sin 10x:\n");
	put_elements(array, size);
	puts("\n");

	array = calc_elements(array, size);
	printf("Печать элементов преобразованного массива с обнуленными отрицательными элементами:\n");
	put_elements(array, size);
	puts("\n");

	// ЗАДАНИЕ 3 - Вычисление суммы элементов массива
	int begin, end;
	printf("Введите номер начального и конечного элементов массива\nдля вычисления суммы через пробел: ");
	scanf("%d %d", &begin, &end);
	printf("Сумма элементов с %d элемента по %d элемент равна %.2lf\n", begin, end, sum_elements(array, begin, end));
	puts("\n");

	// ЗАДАНИЕ 4 - Поиск в массиве значения равного a
	double el = 0;
	printf("Введите значение для проверки его наличия в массиве: ");
	scanf("%lf", &el);
	find_element(array, size, el);
	if (find_element(array, size, el) != -1) printf("A[%d] - элемент массив со значением %.2lf\n", find_element(array, size, el), el);
	else printf("В массиве не содержится элемента со значением %.2lf\n", el);
	puts("\n");

	// ЗАДАНИЕ 5 - Поиск в массиве последнего положительного элемента
	printf("Последний положительный элемент массива A[%d] = %.2lf\n", find_last_positive_index(array, size), find_last_positive_value(array, size));
	puts("\n");

	// ДЗ - Сумма всех элементов массива, расположенных до последнего положительного элемента
	printf("ДЗ: Cумма всех элементов массива,\nрасположенных до последнего положительного элемента равна %.2f\n", sum_lastpositive(array, size));
	puts("\n");
}

int task16(int size)
{

	double* array;
	double* newarray;
	
	array = (double*)malloc(size * sizeof(double));
	if (array == NULL) {
		puts("error");
		return -1;
	}

	// ЗАДАНИЕ 1 - Заполнение и печать массива значениями из функции func(x)
	double x;
	printf("Введите значения аргумента функции, по которой будут вычисленны элементы массива: ");
	scanf("%lf", &x);
	full_elements(array, size, x);
	puts("\n");

	printf("Печать элементов массива, вычисленных по функции 1,8x^2 - sin 10x:\n");
	put_elements(array, size);
	puts("\n");

	newarray = (double*)malloc(size * sizeof(double));
	if (newarray == NULL) {
		puts("error");
		return -1;
	}
	for (int i = 0; i < size; i++) {
		newarray[i] = array[i];
	}

	// ЗАДАНИЕ 2 - Печать и преобразование массива
	calc_elements(newarray, size);
	printf("Печать элементов массива с обнуленными отрицательными элементами:\n");
	put_elements(newarray, size);
	puts("\n");

	free(array);
	free(newarray);

	array = (double*)malloc(size * sizeof(double));
	if (array == NULL) {
		puts("error");
		return -1;
	}

	// ЗАДАНИЕ 3 - Удаление элементов массива
	printf("Введите элементы массива (значения от -1 до 1):\n");
	input_elements(array, size);
	puts("\n");

	int k;
	printf("Введите количество элементов массива, которые необходимо удалить: ");
	scanf("%d", &k);

	int s;
	printf("Введите, после какого элемента начать производить удаление: ");
	scanf("%d", &s);

	newarray = (double*)malloc(size * sizeof(double));
	if (newarray == NULL) {
		puts("error");
		return -1;
	}

	int newsize = delete_k(array, size, s, k);
	put_elements(array, size - k);
	puts("\n");

	// ЗАДАНИЕ 4 - Вставка элементов массива
	int c;
	printf("Введите количество элементов для вставки после минимального: ");
	scanf("%d", &c);

	double* elementsinsert = (double*)malloc(c * sizeof(double));
	if (elementsinsert == NULL) {
		puts("error");
		free(array);
		return -1;
	}

	printf("Введите %d элементов для вставки после минимального:\n", c);
	for (int i = 0; i < c; i++) {
		printf("A[%d] = ", i + 1);
		scanf("%lf", &elementsinsert[i]);
	}
	puts("\n");

	// Вставляем элементы
	double* result_array = insert_k(array, newsize, c, elementsinsert);
	if (result_array != NULL) {
		printf("Массив после вставки %d элементов после минимального:\n", c);
		put_elements(result_array, newsize + c);
		free(result_array);
	}

	return 0;

}
