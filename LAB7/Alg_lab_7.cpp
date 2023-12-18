// Alg_lab_7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

void shellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "");
    int arr[] = { 8, 2, 5, 3, 1,-10,0 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Исходная последовательность чисел: " << endl;
    cout << "{ 8, 2, 5, 3, 1,-10,0 }" << endl;
    cout << "Отсортированная последовательность" << endl;
    shellSort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}