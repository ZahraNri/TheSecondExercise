#include <iostream>
#include <string>
#include "Time.h"

using namespace std;


int main() {
    Time arr[] = {Time(0, 0),
                  Time(11, 59),
                  Time(12, 0),
                  Time(12, 1),
                  Time(16, 59),
                  Time(17, 0),
                  Time(17, 1),
                  Time(19, 59),
                  Time(20, 0),
                  Time(20, 1),
                  Time(23, 59)};

    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        cout << arr[i].toString() << " is " << arr[i].printTime() << endl;
    }


    Time t;
    int hour, minute;
    do
    {
        cout << "Enter hour: ";
        cin >> hour;
        try {
            t.setHour(hour);
        } catch (exception &e) {
            cout << "Invalid hour" << endl;
            continue;
        }
        break;
    } while (true);
    do
    {
        cout << "Enter minute: ";
        cin >> minute;
        try {
            t.setMinute(minute);
        } catch (exception &e) {
            cout << "Invalid minute" << endl;
            continue;
        }
        break;
    } while (true);

    cout << "Time is " << t.toString() << " and it is " << t.printTime() << endl;
    cout << "hour is " << t.getHour() << endl;
    cout << "minute is " << t.getMinute() << endl;


    // these lines throw exceptions
//    arr[0].setTime(0, 60);
//    arr[0].setHour(25);
//    arr[0].setMinute(90);


    return 0;
}
