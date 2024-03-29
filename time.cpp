// Author: Zuhayer Tashin
// Course: CSCI-135
// Instructor: Tong Yi
// Assignment: Lab 10D
// Create a new program time.cpp. 
// (Copy the class Time declaration in your program, it should be placed before main() function.)

#include <iostream>
#include <string>
using namespace std;

enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

class Time { 
public:
    int h;
    int m;
};

class Movie { 
public: 
    string title;
    Genre genre;     // only one genre per movie
    int duration;    // in minutes
};

class TimeSlot { 
public: 
    Movie movie;     // what movie
    Time startTime;  // when it starts
};

Time addMinutes(Time time0, int min){
    Time time = time0;
    int minutes = min;
    while (minutes >= 60) {
        // If minutes is 60 or more, we need to adjust the time
        time.h += 1;    // Increment the hour by 1
        minutes -= 60;  // Subtract 60 minutes from the total
    }

        // Adding the remaining minutes to the current time
    time.m += minutes;

    // If minutes exceed 60, adjust hours accordingly
    if (time.m >= 60) {
        time.h += 1;    // Increment the hour by 1
        time.m -= 60;   // Subtract 60 minutes
    }

    return time;
}

void printMovie(Movie mv){
    string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

void printTimeSlot(TimeSlot ts){
    printMovie(ts.movie);
    cout << " [ starts at "<< ts.startTime.h << ":" <<  ts.startTime.m <<", ends by ";
    ts.startTime = addMinutes({ts.startTime.h, ts.startTime.m}, ts.movie.duration); // Updates the start time of the movie which will be the end time of the movie
    cout << ts.startTime.h << ":" << ts.startTime.m <<  " ]" << endl;   
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
    TimeSlot Next;
    Next.movie = nextMovie;
    printTimeSlot(ts);
    Next.startTime = addMinutes({ts.startTime.h, ts.startTime.m}, ts.movie.duration); // Updates the next start time of the movie which is the endtime of the first movie
    printTimeSlot(Next);
    return Next;
}

// Test Function
int main(){
    // Movie movie1 = {"Back to the Future", COMEDY, 116};
    Movie movie2 = {"Black Panther", ACTION, 134};
    Movie movie1 = {"Back to the Future", COMEDY, 116};  
    TimeSlot morning = {movie1, {9, 15}};
    scheduleAfter(morning, movie2);      
    return 0; 
}