// Бєліков В.В
// ОПП на мові С++
// Лабораторна робота 5
// Кінцевий срок подання: 19 вересня
// Використано часу 120 хв
// Це моя власна робота. Не було використано ніяких допоміжних засобів та осіб
//
// Програма створює масив та сортує його 5-ма способами вирішуючи, який метод найкращий.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>  // Для використання INT_MAX та INT_MIN

using namespace std;

const int SIZE = 100000;  // Розмір масиву

// Функції для сортування
void swap(int& a, int& b, long long& operations);
long long bubbleSort(int arr[], int n);
long long selectionSort(int arr[], int n);
long long insertionSort(int arr[], int n);
long long mergeSort(int arr[], int l, int r, long long& operations);
void merge(int arr[], int l, int m, int r, long long& operations);
long long quickSort(int arr[], int low, int high, long long& operations);
int partition(int arr[], int low, int high, long long& operations);
void copyArray(const int source[], int destination[], int n);

int main() {

    srand(time(0));

    // Параметри для зберігання результатів
    long long totalOperationsBubble = 0, minOperationsBubble = LLONG_MAX, maxOperationsBubble = 0;
    long long totalOperationsSelection = 0, minOperationsSelection = LLONG_MAX, maxOperationsSelection = 0;
    long long totalOperationsInsertion = 0, minOperationsInsertion = LLONG_MAX, maxOperationsInsertion = 0;
    long long totalOperationsMerge = 0, minOperationsMerge = LLONG_MAX, maxOperationsMerge = 0;
    long long totalOperationsQuick = 0, minOperationsQuick = LLONG_MAX, maxOperationsQuick = 0;

    // Масиви
    int* originalArray = new int[SIZE];      // Оригінальний масив
    int* bubbleSortArray = new int[SIZE];    // Масив для сортування бульбашкою
    int* selectionSortArray = new int[SIZE]; // Масив для сортування вибором
    int* insertionSortArray = new int[SIZE]; // Масив для сортування вставкою
    int* mergeSortArray = new int[SIZE];     // Масив для сортування злиттям
    int* quickSortArray = new int[SIZE];     // Масив для швидкого сортування

    for (int t = 0; t < 100; t++) {
        // Заповнення масиву випадковими значеннями
        for (int i = 0; i < SIZE; i++) {
            originalArray[i] = rand();
        }

        // Копіювання масиву для кожного алгоритму сортування
        copyArray(originalArray, bubbleSortArray, SIZE);
        copyArray(originalArray, selectionSortArray, SIZE);
        copyArray(originalArray, insertionSortArray, SIZE);
        copyArray(originalArray, mergeSortArray, SIZE);
        copyArray(originalArray, quickSortArray, SIZE);

        // Сортування та підрахунок операцій
        long long operationsBubble = bubbleSort(bubbleSortArray, SIZE);
        long long operationsSelection = selectionSort(selectionSortArray, SIZE);
        long long operationsInsertion = insertionSort(insertionSortArray, SIZE);
        long long operationsMerge = 0;
        mergeSort(mergeSortArray, 0, SIZE - 1, operationsMerge);
        long long operationsQuick = 0;
        quickSort(quickSortArray, 0, SIZE - 1, operationsQuick);

        // Оновлення статистики для бульбашкового сортування
        totalOperationsBubble += operationsBubble;
        if (operationsBubble > maxOperationsBubble) maxOperationsBubble = operationsBubble;
        if (operationsBubble < minOperationsBubble) minOperationsBubble = operationsBubble;

        // Оновлення статистики для сортування вибором
        totalOperationsSelection += operationsSelection;
        if (operationsSelection > maxOperationsSelection) maxOperationsSelection = operationsSelection;
        if (operationsSelection < minOperationsSelection) minOperationsSelection = operationsSelection;

        // Оновлення статистики для сортування вставкою
        totalOperationsInsertion += operationsInsertion;
        if (operationsInsertion > maxOperationsInsertion) maxOperationsInsertion = operationsInsertion;
        if (operationsInsertion < minOperationsInsertion) minOperationsInsertion = operationsInsertion;

        // Оновлення статистики для сортування злиттям
        totalOperationsMerge += operationsMerge;
        if (operationsMerge > maxOperationsMerge) maxOperationsMerge = operationsMerge;
        if (operationsMerge < minOperationsMerge) minOperationsMerge = operationsMerge;

        // Оновлення статистики для швидкого сортування
        totalOperationsQuick += operationsQuick;
        if (operationsQuick > maxOperationsQuick) maxOperationsQuick = operationsQuick;
        if (operationsQuick < minOperationsQuick) minOperationsQuick = operationsQuick;
    }

    // Очищення пам'яті
    delete[] originalArray;
    delete[] bubbleSortArray;
    delete[] selectionSortArray;
    delete[] insertionSortArray;
    delete[] mergeSortArray;
    delete[] quickSortArray;

    // Виведення результатів
    cout << "Bubble Sort: Min = " << minOperationsBubble << ", Avg = " << totalOperationsBubble / 100 << ", Max = " << maxOperationsBubble << endl;
    cout << "Selection Sort: Min = " << minOperationsSelection << ", Avg = " << totalOperationsSelection / 100 << ", Max = " << maxOperationsSelection << endl;
    cout << "Insertion Sort: Min = " << minOperationsInsertion << ", Avg = " << totalOperationsInsertion / 100 << ", Max = " << maxOperationsInsertion << endl;
    cout << "Merge Sort: Min = " << minOperationsMerge << ", Avg = " << totalOperationsMerge / 100 << ", Max = " << maxOperationsMerge << endl;
    cout << "Quick Sort: Min = " << minOperationsQuick << ", Avg = " << totalOperationsQuick / 100 << ", Max = " << maxOperationsQuick << endl;

    // Визначення найкращого алгоритму
    if ((totalOperationsBubble / 100) <= (totalOperationsSelection / 100) && (totalOperationsBubble / 100) <= (totalOperationsInsertion / 100) && (totalOperationsBubble / 100) <= (totalOperationsMerge / 100) && (totalOperationsBubble / 100) <= (totalOperationsQuick / 100)) {
        cout << "Bubble sort is the best sorting algorithm on average.\n";
    }
    else if ((totalOperationsSelection / 100) <= (totalOperationsBubble / 100) && (totalOperationsSelection / 100) <= (totalOperationsInsertion / 100) && (totalOperationsSelection / 100) <= (totalOperationsMerge / 100) && (totalOperationsSelection / 100) <= (totalOperationsQuick / 100)) {
        cout << "Selection sort is the best sorting algorithm on average.\n";
    }
    else if ((totalOperationsInsertion / 100) <= (totalOperationsBubble / 100) && (totalOperationsInsertion / 100) <= (totalOperationsSelection / 100) && (totalOperationsInsertion / 100) <= (totalOperationsMerge / 100) && (totalOperationsInsertion / 100) <= (totalOperationsQuick / 100)) {
        cout << "Insertion sort is the best sorting algorithm on average.\n";
    }
    else if ((totalOperationsMerge / 100) <= (totalOperationsBubble / 100) && (totalOperationsMerge / 100) <= (totalOperationsSelection / 100) && (totalOperationsMerge / 100) <= (totalOperationsInsertion / 100) && (totalOperationsMerge / 100) <= (totalOperationsQuick / 100)) {
        cout << "Merge sort is the best sorting algorithm on average.\n";
    }
    else {
        cout << "Quick sort is the best sorting algorithm on average.\n";
    }

    return 0;
}

// Функція для обміну значеннями
void swap(int& a, int& b, long long& operations) {
    int temp = a;
    a = b;
    b = temp;
    operations += 3; // три операції: присвоєння значень
}

// Функція для сортування бульбашковим методом
long long bubbleSort(int arr[], int n) {
    long long operations = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            operations++; // порівняння
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1], operations); // обмін
            }
        }
    }
    return operations;
}

// Функція для сортування методом вибору
long long selectionSort(int arr[], int n) {
    long long operations = 0;
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            operations++; // порівняння
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx], operations); // обмін
    }
    return operations;
}

// Функція для сортування методом вставки
long long insertionSort(int arr[], int n) {
    long long operations = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            operations++; // порівняння
            arr[j + 1] = arr[j];
            operations++; // присвоєння
            j--;
        }
        arr[j + 1] = key;
    }
    return operations;
}

// Функція для сортування злиттям
long long mergeSort(int arr[], int l, int r, long long& operations) {
    if (l >= r) return operations;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m, operations);
    mergeSort(arr, m + 1, r, operations);
    merge(arr, l, m, r, operations);
    return operations;
}

// Функція для злиття двох підмасивів
void merge(int arr[], int l, int m, int r, long long& operations) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int* L = new int[n1];
    int* R = new int[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
        operations++; // присвоєння
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[m + 1 + i];
        operations++; // присвоєння
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        operations++; // порівняння
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        operations++; // присвоєння
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        operations++; // присвоєння
    }
    delete[] L;
    delete[] R;
}

// Функція для швидкого сортування
long long quickSort(int arr[], int low, int high, long long& operations) {
    if (low < high) {
        int pi = partition(arr, low, high, operations);
        quickSort(arr, low, pi - 1, operations);
        quickSort(arr, pi + 1, high, operations);
    }
    return operations;
}

// Функція для розбиття масиву для швидкого сортування
int partition(int arr[], int low, int high, long long& operations) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        operations++; // порівняння
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j], operations);
        }
    }
    swap(arr[i + 1], arr[high], operations);
    return (i + 1);
}

// Функція для копіювання масиву
void copyArray(const int source[], int destination[], int n) {
    for (int i = 0; i < n; i++) {
        destination[i] = source[i];
    }
}
