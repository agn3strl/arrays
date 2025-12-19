#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include "array.h"


double func(double x)
{
	return 1.8 * x * x - sin(10 * x);
}

double* full_elements(double* A, int n, double x)
{
	for (int i = 0; i < n; i++) {
		A[i] = func(x);
		x += 0.2;
	}
}

int put_elements(double* A, int n)
{
	for (int i = 0; i < n; i++) printf("A[%d] = %.2lf\n", i + 1, A[i]);
	return n;
}

double* calc_elements(double* A, int n)
{
	for (int i = 0; i < n; i++) {
		if (A[i] < 0) A[i] = 0;
	}
	return A;
}

double sum_elements(double* A, int begin, int end)
{
	double sum = 0;
	for (int i = begin; i <= end; i++) sum += A[i - 1];
	return sum;
}

int find_element(double* A, int n, double element)
{
	for (int i = 0; i < n; i++) {
		if (fabs(A[i] - element) < 0.001 * fmax(fabs(A[i]), fabs(element))) {
			return i;
		}
	}
	return -1;
}

int find_last_positive_index(double* A, int n)
{
	for (int i = n - 1; i >= 0; i--) {
		if (A[i] > 0) return i + 1;
	}
}

double find_last_positive_value(double* A, int n)
{
	for (int i = n - 1; i >= 0; i--) {
		if (A[i] > 0) return A[i];
	}
}


double sum_lastpositive(double* A, int n)
{
	int el = 0;
	for (int i = n; i >= 0; i--) {
		if (A[i] > 0) {
			el = i;
			break;
		}
	}
	double sum = 0;
	for (int i = 0; i < el; i++) sum += A[i];
	return sum;
}

void input_elements(double* A, int n)
{
	for (int i = 0; i < n; i++) {
		float temp;
		printf("a[%d] = ", i + 1);
		scanf("%f", &temp);
		if (temp > -1 && temp < 1) A[i] = temp;
		else {
			puts("Значение не соответствует интервалу от -1 до 1");
			break;
		}
	}
}

int delete_k(double* A, int size, int start, int k)
{
	int n = size - k;
	for (int i = start; i < (size - k); i++) A[i] = A[i + k];
	return n;
}

double* insert_k(double* A, int size, int k, double* elementsinsert)
{
	int min_index = 0;
	double min_value = A[0];
	for (int i = 1; i < size; i++) {
		if (A[i] < min_value) {
			min_value = A[i];
			min_index = i;
		}
	}

	int new_size = size + k;
	double* temp = (double*)realloc(A, new_size * sizeof(double));
	if (temp == NULL) {
		printf("error\n");
		return NULL;
	}

	for (int i = 0; i <= min_index; i++) {
		temp[i] = A[i];
	}

	for (int i = 0; i < k; i++) {
		temp[min_index + 1 + i] = elementsinsert[i];
	}

	for (int i = min_index + 1; i < size; i++) {
		temp[i + k] = A[i];
	}

	return temp;
}