#include "CountryQuiz.h"
#include <iostream>
#include <cstdlib> // ��� rand() � srand()
#include <ctime>   // ��� time()

using namespace std;

// ����������� ��� ����������� ������
CountryQuiz::CountryQuiz() : correctAnswers(0), wrongAnswers(0) 
{
    loadCountries();
    srand(time(0)); // ����������� ���������� ���������� �����
}

// ����� ��� ������������ ���� �� �� �������
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

// ����� ��� ��������� ��������� �����
std::string CountryQuiz::getRandomCountry() const 
{
    auto it = countries.begin();
    std::advance(it, rand() % countries.size());

    return it->first;
}

// �������� ���� ��������
void CountryQuiz::startQuiz() 
{
    char continueQuiz;
    do 
    {
        // ��������� ��������� ����� �� ����� ������
        string selectedCountry = getRandomCountry();
        cout << "What is the capital of " << selectedCountry << "? ";
        string userAnswer;
        getline(cin, userAnswer);

        // �������� ������
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
        cin.ignore(); // ������� ������ ���� cin

    } 
    
   while (continueQuiz == 'y' || continueQuiz == 'Y');
}

// ����� ��� ������ ����������
void CountryQuiz::displayResults() const 
{
    cout << "\nQuiz Results:\n";
    cout << "Correct answers: " << correctAnswers << "\n";
    cout << "Wrong answers: " << wrongAnswers << "\n";
}
