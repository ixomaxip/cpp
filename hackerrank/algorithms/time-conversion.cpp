#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string time) {
    /*
     * Write your code here.
     */
    //hh:mm:ss(AP|PM)
    stringstream ss(time);
    int h, m, s;
    char d;
    ss >> h >> d >> m >> d >> s;
    ss.seekp(-2, ios_base::end);
    string part_of_day;
    ss >> part_of_day;
    if (h == 12) {
        if (part_of_day == "AM") {
            h = 0;
        }
    } else  if (part_of_day == "PM") {
        h += 12;
    }
    stringstream out;
    out << setw(2) << setfill('0') << h << ":"
        << setw(2) << setfill('0') << m << ":"
        << setw(2) << setfill('0') << s;

    return out.str();
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    string s = "01:05:45PM";
    // getline(cin, s);

    string result = timeConversion(s);

    cout << result << "\n";

    // fout.close();

    return 0;
}
