#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>

// Функцiя Counting Sort для допомоги Radix Sort
void countingSort(int arr[], int n, int exp) {
    int* output = new int[n];  // Динамiчний вихiдний масив
    int count[10] = { 0 };

    // Пiдраховуємо кiлькiсть появ кожної цифри
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Змiнюємо count[i], щоб мiстив фактичнi позицiї у вихiдному масивi
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Будуємо вихiдний масив
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Копiюємо вiдсортованi значення назад у оригiнальний масив
    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    delete[] output;  // Очищаємо динамiчну пам'ять
}

// Radix Sort
void radixSort(int arr[], int n) {
    int maxNum = *std::max_element(arr, arr + n);

    // Проходимо по кожному розряду
    for (int exp = 1; maxNum / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

// Генерацiя списку країн i учасникiв
void generateParticipants(std::string countryNames[], int countries[], int participants[], int numCountries, int numParticipants) {
    std::srand(std::time(0));  // Iнiцiалiзуємо генератор випадкових чисел

    // Генеруємо коди країн i присвоюємо їм назви
    for (int i = 0; i < numCountries; i++) {
        countries[i] = std::rand() % 90 + 10;  // Коди країн вiд 10 до 99
    }

    // Генеруємо учасникiв з унiкальними номерами
    int index = 0;
    for (int i = 0; i < numCountries; i++) {
        for (int j = 0; j < numParticipants; j++) {
            participants[index++] = countries[i] * 10000 + std::rand() % 10000;
        }
    }
}

int main() {
    const int numCountries = 10;  // Наприклад, 10 країн
    const int numParticipantsPerCountry = 1000;  // По 1000 учасникiв вiд кожної країни
    const int totalParticipants = numCountries * numParticipantsPerCountry;

    // Масив для назв країн
    std::string countryNames[numCountries] = { "Україна", "Нiмеччина", "Францiя", "Iталiя", "США",
                                              "Канада", "Японiя", "Китай", "Iндiя", "Австралiя" };

    int* countries = new int[numCountries];  // Динамiчний масив для збереження кодiв країн
    int* participants = new int[totalParticipants];  // Динамiчний масив для збереження учасникiв

    // Генеруємо данi
    generateParticipants(countryNames, countries, participants, numCountries, numParticipantsPerCountry);

    // Виводимо список країн з кодами
    std::cout << "Список країн з кодами:\n";
    for (int i = 0; i < numCountries; i++) {
        std::cout << countryNames[i] << " - " << countries[i] << std::endl;
    }

    // Виводимо список учасникiв перед сортуванням
    std::cout << "\nСписок учасникiв (до сортування):\n";
    for (int i = 0; i < 100; i++) {  // Для прикладу виведемо першi 100 учасникiв
        std::cout << participants[i] << " ";
    }

    // Сортуємо учасникiв за допомогою Radix Sort
    radixSort(participants, totalParticipants);

    // Виводимо вiдсортований список учасникiв
    std::cout << "\n\nСписок учасникiв (пiсля сортування):\n";
    for (int i = 0; i < 100; i++) {  // Для прикладу виведемо першi 100 учасникiв
        std::cout << participants[i] << " ";
    }

    // Очищаємо динамiчну пам'ять
    delete[] countries;
    delete[] participants;

    return 0;
}
