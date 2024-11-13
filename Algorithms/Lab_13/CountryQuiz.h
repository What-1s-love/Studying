#ifndef COUNTRYQUIZ_H
#define COUNTRYQUIZ_H

#include <map>
#include <string>

class CountryQuiz 
{
public:

    CountryQuiz();
    void startQuiz();
    void displayResults() const;

private:

    std::map<std::string, std::string> countries;
    int correctAnswers;
    int wrongAnswers;
    void loadCountries();
    std::string getRandomCountry() const;
};

#endif
