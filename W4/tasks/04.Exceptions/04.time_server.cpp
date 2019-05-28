#include <iostream>
#include <exception>
#include <string>
using namespace std;

string AskTimeServer()
{
    string response = "01:34:32";
    // throw system_error(error_code());
    // throw invalid_argument("");
    return response;
}

class TimeServer
{
public:
    string GetCurrentTime()
    {
    }

private:
    string LastFetchedTime = "00:00:00";
};

int main() {
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}