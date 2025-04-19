#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class DynamicArray1D {
private:
    int* array;
    int size;

public:
    // Конструктор за замовчуванням
    DynamicArray1D() : array(nullptr), size(0) {}

    // Конструктор ініціалізації
    DynamicArray1D(int size) {
        this->size = size;
        array = new int[size];
    }

    // Деструктор
    ~DynamicArray1D() {
        delete[] array;
    }

    // Метод автоматичної ініціалізації (випадкові числа у діапазоні)
    void autoInitialize(int min, int max) {
        srand(time(0));
        for (int i = 0; i < size; ++i) {
            array[i] = min + rand() % (max - min + 1);
        }
    }

    // Метод введення з клавіатури
    void inputFromKeyboard() {
        cout << "Enter " << size << " elements:\n";
        for (int i = 0; i < size; ++i) {
            cout << "[" << i << "]: ";
            cin >> array[i];
        }
    }

    // Метод виведення масиву на екран
    void printArray() const {
        cout << "Array: ";
        for (int i = 0; i < size; ++i) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    // Метод, який повертає середнє арифметичне від’ємних елементів
    double averageOfNegatives() const {
        int sum = 0, count = 0;
        for (int i = 0; i < size; ++i) {
            if (array[i] < 0) {
                sum += array[i];
                ++count;
            }
        }
        if (count == 0) return 0.0; // якщо від’ємних немає
        return static_cast<double>(sum) / count;
    }

    // Метод вибору способу заповнення масиву
    void fillArray() {
        int choice;
        cout << "Choose how to fill the array:\n";
        cout << "1 - automatic filling\n";
        cout << "2 - Input from keyboard\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int min, max;
            cout << "Enter the minimum and maximum values: ";
            cin >> min >> max;
            autoInitialize(min, max);
            break;
        }
        case 2:
            inputFromKeyboard();
            break;
        default:
            cout << "Invalid choice! No filling done." << endl;
            break;
        }
    }
};

// Головна функція
int main() {
    int n;
    cout << "Enter the array size: ";
    cin >> n;

    DynamicArray1D array(n);     // створення об'єкта з заданим розміром
    array.fillArray();           // заповнення масиву
    array.printArray();          // вивід масиву

    double average = array.averageOfNegatives(); // обчислення середнього
    cout << "Average of negative elements: " << average << endl;

    return 0;
}
