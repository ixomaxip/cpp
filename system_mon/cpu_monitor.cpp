#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;



enum class CPUState
{
    USER,
    NICE,
    SYSTEM,
    IDLE,
    IOWAIT,
    IRQ,
    SOFTIRQ,
    STEAL,
    GUEST,
    GUEST_NICE,
    Count = 10
};

const int NUM_PRMS = (int)CPUState::Count;

typedef struct CPUData {
    string cpu;
    size_t params[NUM_PRMS];
} CPUData;

int main()
{


    return 0;
}