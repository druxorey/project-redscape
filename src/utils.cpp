#include <iostream>
#include <chrono>
#include "../include/utils.hpp"

void sleep(int miliseconds) {
    auto get_time = std::chrono::system_clock::now();
    auto get_time_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(get_time);

    long long int actual_time = get_time_ms.time_since_epoch().count();
    long long int end_time = actual_time + miliseconds;

    while (actual_time < end_time) {
        get_time = std::chrono::system_clock::now();
        get_time_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(get_time);
        actual_time = get_time_ms.time_since_epoch().count();
    }
}


void clear() {
	system("clear");
}


void refresh(int rate) {
	sleep(rate);
	clear();
}
