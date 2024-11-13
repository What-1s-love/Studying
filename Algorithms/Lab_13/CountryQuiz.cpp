#include "CountryQuiz.h"
#include <iostream>
#include <cstdlib> // для rand() і srand()
#include <ctime>   // для time()

using namespace std;

// Конструктор для ініціалізації змінних
CountryQuiz::CountryQuiz() : correctAnswers(0), wrongAnswers(0) 
{
    loadCountries();
    srand(time(0)); // Ініціалізація генератора випадкових чисел
}

// Метод для завантаження країн та їх столиць
void CountryQuiz::loadCountries() 
{
    countries = 
    {
        {"Ukraine", "Kyiv"}, {"France", "Paris"}, {"Germany", "Berlin"},
        {"Spain", "Madrid"}, {"Italy", "Rome"}, {"Portugal", "Lisbon"},
        {"Poland", "Warsaw"}, {"Netherlands", "Amsterdam"}, {"Belgium", "Brussels"},
        {"Austria", "Vienna"}, {"Switzerland", "Bern"}, {"Norway", "Oslo"},
        {"Sweden", "Stockholm"}, {"Finland", "Helsinki"}, {"Denmark", "Copenhagen"},
        {"Greece", "Athens"}, {"Turkey", "Ankara"}, {"Egypt", "Cairo"},
        {"Japan", "Tokyo"}, {"South Korea", "Seoul"}
    };
}

// Метод для отримання випадкової країни
std::string CountryQuiz::getRandomCountry() const 
{
    auto it = countries.begin();
    std::advance(it, rand() % countries.size());

    return it->first;
}

// Основний цикл вікторини
void CountryQuiz::startQuiz() 
{
    char continueQuiz;
    do 
    {
        // Отримання випадкової країни та запит відповіді
        string selectedCountry = getRandomCountry();
        cout << "What is the capital of " << selectedCountry << "? ";
        string userAnswer;
        getline(cin, userAnswer);

        // Перевірка відповіді
        if (userAnswer == countries[selectedCountry]) 
        {
            cout << "Correct!\n";
            correctAnswers++;
        }
        else 
        {
            cout << "Wrong. The correct answer is " << countries[selectedCountry] << ".\n";
            wrongAnswers++;
        }

        cout << "Do you want to continue? (y/n): ";
        cin >> continueQuiz;
        cin.ignore(); // очистка буфера після cin

    } 
    
   while (continueQuiz == 'y' || continueQuiz == 'Y');
}

// Метод для виводу результатів
void CountryQuiz::displayResults() const 
{
    cout << "\nQuiz Results:\n";
    cout << "Correct answers: " << correctAnswers << "\n";
    cout << "Wrong answers: " << wrongAnswers << "\n";
}
