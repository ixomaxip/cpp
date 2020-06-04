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
    string number;
    size_t params[NUM_PRMS];
} CPUData;

ostream& operator<<(ostream& out, const CPUData& cpu) {
    out << cpu.number << endl;
    for (const auto& prm : cpu.params) {
        out << '\t' << prm;
    }
    out << endl;
    return out;
}

int main()
{
    ifstream cpu_stats_file("/proc/stat");

    string line;
    while (getline(cpu_stats_file, line)) {
        if (line.compare(0, 3, "cpu") == 0) {
            CPUData cpu;
            stringstream ss(line);
            ss >> cpu.number;
            for (int i = 0; i < NUM_PRMS; ++i) {
                ss >> cpu.params[i];
            }
            cout << cpu;
        }
    }


    return 0;
}