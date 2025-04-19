#include "Time.h"
#include <iomanip>

using namespace std;

Time::Time(int h, int m) {
    if (h < 0 || h >= 24 || m < 0 || m >= 60) {
        cerr << "Invalid time input! Setting to 00:00." << endl;
        hours = 0;
        minutes = 0;
    }
    else {
        hours = h;
        minutes = m;
    }
}

void Time::display() const {
    cout << setw(2) << setfill('0') << hours << ":"
        << setw(2) << setfill('0') << minutes << endl;
}

string Time::getPartOfDay() const {
    if (hours >= 5 && hours < 12) {
        return "Morning";
    }
    else if (hours >= 12 && hours < 17) {
        return "Afternoon";
    }
    else if (hours >= 17 && hours < 21) {
        return "Evening";
    }
    else {
        return "Night";
    }
}

string Time::to12HourFormat() const {
    int h = (hours == 0 || hours == 12) ? 12 : hours % 12;
    string period = (hours < 12) ? "a.m." : "p.m.";
    return to_string(h) + ":" + (minutes < 10 ? "0" : "") + to_string(minutes) + " " + period;
}
