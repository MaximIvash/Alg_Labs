// Alg_lab_8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

// Функция для нахождения максимального элемента в массиве
int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

// Функция для поразрядной сортировки массива по указанному разряду
void countingSort(int arr[], int n, int exp)
{
    const int radix = 10; // основание системы счисления (десятичная система)
    int output[n];
    int count[radix] = { 0 };

    // Подсчет количества элементов по указанному разряду
    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % radix]++;
    }

    // Изменение счетчика таким образом, чтобы он содержал реальную позицию данного разряда в выходном массиве
    for (int i = 1; i < radix; i++)
    {
        count[i] += count[i - 1];
    }

    // Построение отсортированного массива
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % radix] - 1] = arr[i];
        count[(arr[i] / exp) % radix]--;
    }

    // Копирование отсортированного массива в исходный массив
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

// Функция для поразрядной сортировки массива
void radixSort(int arr[], int n)
{
    int max = getMax(arr, n);

    // Сортировать массив по каждому разряду, начиная с младшего до старшего
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countingSort(arr, n, exp);
    }
}

int main()
{
    setlocale(LC_ALL, "");
    int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int n = sizeof(arr) / sizeof(arr[0]);
    radixSort(arr, n);
    cout << "Исходная последовательность: ";
    cout << "{ 170, 45, 75, 90, 802, 24, 2, 66 }" << endl;
    cout << "Отсортированная последовательность чисел методом поразрядной сортировки: " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
   
    return 0;
}

