#include "Time.h"

using namespace std;

int main() {
    Time t1(14, 30);
    t1.display();
    cout << "Part of day: " << t1.getPartOfDay() << endl;
    cout << "12-hour format: " << t1.to12HourFormat() << endl;
    return 0;
}
