#include "sort.hpp"

Sorting::Sorting() {}

int Sorting::sorting(int limit){
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    // using nanosec instead sec
    srand((time_t)ts.tv_nsec);

    return (rand() % limit) + 1;
}