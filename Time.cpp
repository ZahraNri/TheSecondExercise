#include "Time.h"
#include <iostream>

Time::Time() {
    hour = 0;
    minute = 0;
}

Time::~Time() {}

Time::Time(int hour) : hour(hour), minute(0) {}

Time::Time(int hour, int minute) : hour(hour), minute(minute) {}

int Time::getHour() const {
    return hour;
}

void Time::setHour(int h) {
    if (h > 23 || h < 0) throw std::exception();
    hour = h;
}

int Time::getMinute() const {
    return minute;
}

void Time::setMinute(int m) {
    if (m > 59 || m < 0) throw std::exception();
    minute = m;
}

void Time::setTime(int h, int m) {
    setHour(h);
    setMinute(m);
}


std::string Time::printTime() const {
    if (compare(Time(0, 0)) == 0 ||
        (compare(Time(0, 0)) == 1 && compare(Time(12, 0)) == -1))
        return "morning";
    if (compare(Time(12, 0)) == 0)
        return "noon";
    if (compare(Time(12, 0)) == 1 && compare(Time(17, 0)) == -1)
        return "afternoon";
    if (compare(Time(16, 59)) == 1 && compare(Time(20, 0)) == -1)
        return "evening";
    if ((compare(Time(19, 59)) == 1 && compare(Time(23, 59)) == -1)
        || (compare(Time(23, 59)) == 0))
        return "night";
    return "";
}

int Time::compare(const Time &t) const {
    if (hour > t.hour) return 1;
    if (hour < t.hour) return -1;
    if (minute > t.minute) return 1;
    if (minute < t.minute) return -1;
    return 0;
}

std::string Time::toString() const {
    std::string s;
    if (hour < 10) s += "0";
    s += std::to_string(hour) + ":";
    if (minute < 10) s += "0";
    s += std::to_string(minute);
    return s;
}


