#ifndef ARRAYS_H
#define ARRAYS_H

double func(double x); // функция для вычисления элементов массива

/**
 * Заполнение массива значениями
 * @param A указатель на массив
 * @param n размер массива
 * @return указатель на заполненный массив
 */
double* full_elements(double* A, int n, double x); 

/**
 * Печать элементов массива
 * @param A указатель на массив
 * @param n размер массива
 * @return количество выведенных элементов
 */
int put_elements(double* A, int n); 

/**
 * Обработка элементов массива согласно индивидуальному варианту - обнуление отрицательных элементов
 * @param A указатель на массив
 * @param n размер массива
 * @return указатель на обработанный массив
 */
double* calc_elements(double* A, int n);

/**
 * Вычисление суммы элементов массива в диапазоне [begin, end]
 * @param A указатель на массив
 * @param begin начальный индекс (включительно)
 * @param end конечный индекс (включительно)
 * @return сумма элементов
 */
double sum_elements(double* A, int begin, int end); 

/**
 * Поиск элемента в массиве
 * @param A указатель на массив
 * @param n размер массива
 * @param element искомый элемент
 * @return индекс найденного элемента или -1 если не найден
 */
int find_element(double* A, int n, double element); 

/**
 * Поиск индекса последнего положительного элемента
 * @param A указатель на массив
 * @param n размер массива
 * @return индекс найденного элемента или -1 если не найден
 */
int find_last_positive_index(double* A, int n); 

/**
 * Поиск значения последнего положительного элемента
 * @param A указатель на массив
 * @param n размер массива
 * @return значение найденного элемента или -1 если не найдено
 */
double find_last_positive_value(double* A, int n); 

/**
 * Сумма всех элементов массива, расположенных до последнего положительного элемента
 * @param A указатель на массив
 * @param n размер массива
 * @return значение суммы
 */
double sum_lastpositive(double* A, int n); 

/**
 * Ввод новых элементов массива
 * @param A указатель на массив
 * @param n размер массива
 */
void input_elements(double* A, int n); 

/**
 * Удаление выбранных элементов массива
 * @param A указатель на массив
 * @param size размер массива
 * @param start элемент, после которого начать удаление
 * @param количество элементов, которые необходимо удалить
 * @return число элементов массива 
 */
int delete_k(double* A, int size, int start, int k);

/**
 * Вставка выбранных элементов массива
 * @param A указатель на массив
 * @param size размер массива
 * @param количество элементов, которые необходимо вставить
 * @return указатель на обработанный массив
 */
double* insert_k(double* A, int size, int k); // вставка элемента

#endif
