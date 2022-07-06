#include "string"

#ifndef UNTITLED_TIME_H
#define UNTITLED_TIME_H


class Time {

private:
    int hour;
    int minute;

public:
    Time();
    Time(int hour);
    Time(int hour, int minute);
    ~Time();

    int getHour() const;
    void setHour(int hour);
    int getMinute() const;
    void setMinute(int minute);

    void setTime(int hour, int minute);
    std::string printTime() const;

    int compare(const Time &t) const;

    std::string toString() const ;
};


#endif //UNTITLED_TIME_H
