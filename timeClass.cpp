#include <iostream>
using namespace std;

class Time {
    int hours;
    int minutes;
    int seconds;

public:

    Time(int hours, int minutes, int seconds) {
        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
    }

    Time(){
        hours = 0;
        minutes = 0;
        seconds = 0;
    }


    void addedTime(Time &A, Time &B) {
        Time C;  

        C.seconds = A.seconds + B.seconds;
        C.minutes = A.minutes + B.minutes;
        C.hours = A.hours + B.hours;

        if (C.seconds >= 60) {
            C.seconds = C.seconds - 60;
            C.minutes = C.minutes + 1;
        } 

        if (C.minutes >= 60) {
            C.minutes = C.minutes - 60;  
            C.hours = C.hours + 1;
        } 

    }
};

int main() {
    Time time1(2, 45, 30);
    Time time2(3, 50, 45);

    time1.addedTime(time1, time2);

    return 0;
}