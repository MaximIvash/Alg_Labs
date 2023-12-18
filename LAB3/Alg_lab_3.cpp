// Alg_lab_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<cmath>

using namespace std;
int main()
{
    double x;
    cin >> x;
    for (int i = 0; i < log(x) / log(3); i++) {
        for (int j = 0; j < log(x) / log(5); j++) {
            for (int k = 0; k < log(x) / log(7); k++) {
                if (pow(3, i) * pow(5, j) * pow(7, k) <= x) {
                    cout << pow(3, i) * pow(5, j) * pow(7, k) << endl;
                }
            }
        }

    }

}
