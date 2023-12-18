// Alg_lab_9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;    
    int left = 2 * i + 1;    // Левый потомок
    int right = 2 * i + 2;    // Правый потомок

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Рекурсивно приводим поддерево к пирамидальному виду
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Построение кучи (перегруппировка массива)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i > 0; i--) {
        // Перемещаем текущий корень в конец
        swap(arr[0], arr[i]);

        // Вызываем процедуру heapify на уменьшенной куче
        heapify(arr, i, 0);
    }
}

int main() {
    setlocale(LC_ALL, "");
    vector<int> arr = { 1,12,9,5,6,10 };
    int n = arr.size();
    cout << "Исходная последовательность" << endl;
    cout << "{ 1,12,9,5,6,10 }" << endl;
    cout << "Отсортированная последовательность" << endl;
    heapSort (arr);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
