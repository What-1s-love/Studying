#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <string>

using namespace std;

class Time {
private:
    int hours;
    int minutes;

public:
    Time(int h, int m);
    void display() const;
    string getPartOfDay() const;
    string to12HourFormat() const;
};

#endif // TIME_H
