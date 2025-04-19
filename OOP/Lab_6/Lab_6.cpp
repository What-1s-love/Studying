#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class DynamicArray1D {
private:
    int* array;
    int size;

public:
    // ����������� �� �������������
    DynamicArray1D() : array(nullptr), size(0) {}

    // ����������� �����������
    DynamicArray1D(int size) {
        this->size = size;
        array = new int[size];
    }

    // ����������
    ~DynamicArray1D() {
        delete[] array;
    }

    // ����� ����������� ����������� (�������� ����� � �������)
    void autoInitialize(int min, int max) {
        srand(time(0));
        for (int i = 0; i < size; ++i) {
            array[i] = min + rand() % (max - min + 1);
        }
    }

    // ����� �������� � ���������
    void inputFromKeyboard() {
        cout << "Enter " << size << " elements:\n";
        for (int i = 0; i < size; ++i) {
            cout << "[" << i << "]: ";
            cin >> array[i];
        }
    }

    // ����� ��������� ������ �� �����
    void printArray() const {
        cout << "Array: ";
        for (int i = 0; i < size; ++i) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    // �����, ���� ������� ������ ����������� �䒺���� ��������
    double averageOfNegatives() const {
        int sum = 0, count = 0;
        for (int i = 0; i < size; ++i) {
            if (array[i] < 0) {
                sum += array[i];
                ++count;
            }
        }
        if (count == 0) return 0.0; // ���� �䒺���� ����
        return static_cast<double>(sum) / count;
    }

    // ����� ������ ������� ���������� ������
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

// ������� �������
int main() {
    int n;
    cout << "Enter the array size: ";
    cin >> n;

    DynamicArray1D array(n);     // ��������� ��'���� � ������� �������
    array.fillArray();           // ���������� ������
    array.printArray();          // ���� ������

    double average = array.averageOfNegatives(); // ���������� ����������
    cout << "Average of negative elements: " << average << endl;

    return 0;
}
