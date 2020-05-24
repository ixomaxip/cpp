// You will be given two arrays of integers and asked to determine all integers that satisfy the following two conditions:
//     - The elements of the first array are all factors of the integer being considered
//     - The integer being considered is a factor of all elements of the second array
// These numbers are referred to as being between the two arrays. You must determine how many such numbers exist.


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int gcd(int a, int b) {
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

int getTotalX(vector<int> a, vector<int> b) {

    int gcd_b = b[0];
    
    //find GCD for b
    for (size_t i = 1; i < b.size(); ++i) {
        gcd_b = gcd(b[i], gcd_b);
    }
    //find all factors fo gcd_b
    vector<int> considered;
    for (int i = 1; i*i <= gcd_b; ++i) {
        if (gcd_b % i == 0) {
            considered.push_back(i);
            if (gcd_b / i != i) {
                considered.push_back(gcd_b / i);
            }
        }
    }
    //check considered int is devided by elements from a
    int res = 0;
    for (auto& d : considered) {
        bool div_a = true;
        for (auto& aa : a) {
            div_a &= (d % aa == 0);
        }
        if (div_a) {
            res++;
        }
    }
    return res;
}

int main()
{

    // vector<int> arr = {2, 4};
    // vector<int> brr = {16, 32, 96};
    vector<int> arr = {2, 6};
    vector<int> brr = {24, 36};

    int total = getTotalX(arr, brr);
    cout << total << endl;


/*
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    string brr_temp_temp;
    getline(cin, brr_temp_temp);

    vector<string> brr_temp = split(rtrim(brr_temp_temp));

    vector<int> brr(m);

    for (int i = 0; i < m; i++) {
        int brr_item = stoi(brr_temp[i]);

        brr[i] = brr_item;
    }
    int total = getTotalX(arr, brr);

    fout << total << "\n";

    fout.close();
*/

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

