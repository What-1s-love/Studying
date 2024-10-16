#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>

// �㭪�i� Counting Sort ��� �������� Radix Sort
void countingSort(int arr[], int n, int exp) {
    int* output = new int[n];  // �����i筨� ���i���� ��ᨢ
    int count[10] = { 0 };

    // �i��客�� �i��i��� ��� ������ ���
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // ��i��� count[i], 鮡 �i�⨢ 䠪��i �����i� � ���i����� ��ᨢi
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // ���� ���i���� ��ᨢ
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // ���i�� �i���⮢��i ���祭�� ����� � �ਣi���쭨� ��ᨢ
    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    delete[] output;  // ���� �����i�� ���'���
}

// Radix Sort
void radixSort(int arr[], int n) {
    int maxNum = *std::max_element(arr, arr + n);

    // ��室��� �� ������� ஧���
    for (int exp = 1; maxNum / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

// ������i� ᯨ�� ���� i ��᭨�i�
void generateParticipants(std::string countryNames[], int countries[], int participants[], int numCountries, int numParticipants) {
    std::srand(std::time(0));  // I�i�i��i��� ������� ���������� �ᥫ

    // ������� ���� ���� i ��᢮�� �� �����
    for (int i = 0; i < numCountries; i++) {
        countries[i] = std::rand() % 90 + 10;  // ���� ���� �i� 10 �� 99
    }

    // ������� ��᭨�i� � �i���쭨�� ����ࠬ�
    int index = 0;
    for (int i = 0; i < numCountries; i++) {
        for (int j = 0; j < numParticipants; j++) {
            participants[index++] = countries[i] * 10000 + std::rand() % 10000;
        }
    }
}

int main() {
    const int numCountries = 10;  // ���ਪ���, 10 ����
    const int numParticipantsPerCountry = 1000;  // �� 1000 ��᭨�i� �i� ������ �����
    const int totalParticipants = numCountries * numParticipantsPerCountry;

    // ��ᨢ ��� ���� ����
    std::string countryNames[numCountries] = { "������", "�i���稭�", "�࠭�i�", "I⠫i�", "���",
                                              "������", "����i�", "��⠩", "I��i�", "����ࠫi�" };

    int* countries = new int[numCountries];  // �����i筨� ��ᨢ ��� ���०���� ���i� ����
    int* participants = new int[totalParticipants];  // �����i筨� ��ᨢ ��� ���०���� ��᭨�i�

    // ������� ���i
    generateParticipants(countryNames, countries, participants, numCountries, numParticipantsPerCountry);

    // �������� ᯨ᮪ ���� � ������
    std::cout << "���᮪ ���� � ������:\n";
    for (int i = 0; i < numCountries; i++) {
        std::cout << countryNames[i] << " - " << countries[i] << std::endl;
    }

    // �������� ᯨ᮪ ��᭨�i� ��। ���㢠���
    std::cout << "\n���᮪ ��᭨�i� (�� ���㢠���):\n";
    for (int i = 0; i < 100; i++) {  // ��� �ਪ���� �������� ����i 100 ��᭨�i�
        std::cout << participants[i] << " ";
    }

    // ������ ��᭨�i� �� ��������� Radix Sort
    radixSort(participants, totalParticipants);

    // �������� �i���⮢���� ᯨ᮪ ��᭨�i�
    std::cout << "\n\n���᮪ ��᭨�i� (�i�� ���㢠���):\n";
    for (int i = 0; i < 100; i++) {  // ��� �ਪ���� �������� ����i 100 ��᭨�i�
        std::cout << participants[i] << " ";
    }

    // ���� �����i�� ���'���
    delete[] countries;
    delete[] participants;

    return 0;
}
