// Alg_lab_6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int minPos = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minPos])
            {
                minPos = j;
            }
        }
        swap(arr[i], arr[minPos]);
    }
}

int main()
{
    setlocale(LC_ALL, "");
    int arr[]= { 8, 2, 5, 3, 1,-10,0 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Исходная последовательность" << endl;
    cout << "{ 8, 2, 5, 3, 1,-10,0 }" << endl;
    cout << "Отсортированная последовательность" << endl;
    selectionSort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}

