// Alg_lab_4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
//Сортировка
void Comb_Sort(int arr[], int n)
{
    int gap = n;
    while (gap != 1)
    {
        // Вычисляем шаг прочесывания
        gap = int(gap / 1.3);
        if (gap < 1)
            gap = 1;
        // Проходим по последовательности для сравнения и обмена элементов
        for (int i = 0; i < n - gap; i++)
        {
            if (arr[i] > arr[i + gap])
            {
                swap(arr[i], arr[i + gap]);
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "");
    int arr[] = { 8, 2, 5, 3, 1,-10,0 };
    // Вычисляем размер массива
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Исходная последовательность: " << endl;
    cout << "{ 8, 2, 5, 3, 1, -10, 0}" << endl;
    cout << "Отсортированная последовательность: " << endl;
    Comb_Sort(arr, n);
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    
    return 0;
}