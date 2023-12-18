// Alg_lab_5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main()
{
	setlocale(LC_ALL, "");
	int arr[] = { 8, 2, 5, 3, 1, 0,-10 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Исходная последовательность" << endl;
	cout << "{ 8, 2, 5, 3, 1, 0, -10}" << endl;
	cout << "Отсортированная последовательность" << endl;
	insertionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
	return 0;
}
