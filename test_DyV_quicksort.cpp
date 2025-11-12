#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include "DyV.h"

using namespace std;

template<typename T>
int Partition_Ultimo(vector<T>& v, int ini, int fin) {
    T pivote = v[fin];
    int i = ini;
    for (int j = ini; j < fin; j++) {
        if (v[j] <= pivote) {
            swap(v[i], v[j]);
            i++;
        }
    }
    swap(v[i], v[fin]);
    return i;
}

template<typename T>
void QuickSort_Ultimo(vector<T>& v, int ini, int fin) {
    if (ini < fin) {
        int p = Partition_Ultimo(v, ini, fin);
        QuickSort_Ultimo(v, ini, p - 1);
        QuickSort_Ultimo(v, p + 1, fin);
    }
}

template<typename T>
int Partition_Primero(vector<T>& v, int ini, int fin) {
    swap(v[ini], v[fin]);
    return Partition_Ultimo(v, ini, fin);
}

template<typename T>
void QuickSort_Primero(vector<T>& v, int ini, int fin) {
    if (ini < fin) {
        int p = Partition_Primero(v, ini, fin);
        QuickSort_Primero(v, ini, p - 1);
        QuickSort_Primero(v, p + 1, fin);
    }
}

template<typename T>
int Partition_Central(vector<T>& v, int ini, int fin) {
    int mid = (ini + fin) / 2;
    swap(v[mid], v[fin]);
    return Partition_Ultimo(v, ini, fin);
}

template<typename T>
void QuickSort_Central(vector<T>& v, int ini, int fin) {
    if (ini < fin) {
        int p = Partition_Central(v, ini, fin);
        QuickSort_Central(v, ini, p - 1);
        QuickSort_Central(v, p + 1, fin);
    }
}

template<typename T>
int Partition_Aleatorio(vector<T>& v, int ini, int fin) {
    int r = ini + rand() % (fin - ini + 1);
    swap(v[r], v[fin]);
    return Partition_Ultimo(v, ini, fin);
}

template<typename T>
void QuickSort_Aleatorio(vector<T>& v, int ini, int fin) {
    if (ini < fin) {
        int p = Partition_Aleatorio(v, ini, fin);
        QuickSort_Aleatorio(v, ini, p - 1);
        QuickSort_Aleatorio(v, p + 1, fin);
    }
}

int main() {
    srand(time(nullptr));
    const int N = 50000;
    vector<int> datos;
    for (int i = 0; i < N; i++)
        datos.push_back(rand() % 100000);

    cout << "=== Comparación de QuickSort ===\n";

    {
        vector<int> v = datos;
        auto start = chrono::high_resolution_clock::now();
        QuickSort_Ultimo(v, 0, v.size() - 1);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> dur = end - start;
        cout << "Pivote último: " << dur.count() << " ms\n";
    }

    {
        vector<int> v = datos;
        auto start = chrono::high_resolution_clock::now();
        QuickSort_Primero(v, 0, v.size() - 1);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> dur = end - start;
        cout << "Pivote primero: " << dur.count() << " ms\n";
    }

    {
        vector<int> v = datos;
        auto start = chrono::high_resolution_clock::now();
        QuickSort_Central(v, 0, v.size() - 1);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> dur = end - start;
        cout << "Pivote central: " << dur.count() << " ms\n";
    }

    {
        vector<int> v = datos;
        auto start = chrono::high_resolution_clock::now();
        QuickSort_Aleatorio(v, 0, v.size() - 1);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> dur = end - start;
        cout << "Pivote aleatorio: " << dur.count() << " ms\n";
    }

    return 0;
}
