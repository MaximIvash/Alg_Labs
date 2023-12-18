// Alg_lab_11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;
// Функция быстрой сортировки
void quicksort(vector<int>& arr, int left, int right) 
{
    if (left < right) 
    {
        int pivot = left;
        for (int i = left + 1; i < right; i++) 
        {
            if (arr[i] < arr[left]) 
            {
                pivot++;
                swap(arr[i], arr[pivot]);
            }
        }
        swap(arr[left], arr[pivot]);
        quicksort(arr, left, pivot);
        quicksort(arr, pivot + 1, right);
    }
}

int main() 
{
    setlocale(LC_ALL, "");
    vector<int> numbers = { 5, 2, 9, 1, 5, 6, 8, 3, 10, 4 };

    cout << "Исходная последовательность: ";
    for (int num : numbers) 
    {
        cout << num << " ";
    }
    
    quicksort(numbers, 0, numbers.size());

    cout << "\nОтсортированная последовательность: ";
    for (int num : numbers) 
    {
        cout << num << " ";
    }

    return 0;
}