#include <iostream>
#include <map>
#include <vector>

using namespace std;
/*
input:
3
eat tea
find search
master stream

output:
YES
NO
YES
*/

void print_map(const map<char, int>& m)
{
    for (const auto& item : m)
    {
        cout << item.first << ": " << item.second << endl;
    }
}

 map<char, int> BuildCharCounters(const string & w)
 {
     map<char, int> cnt;
     for (const auto& c : w)
         ++cnt[c];
     return cnt;
 }

string is_anagrams(const string& w1, const string& w2)
{
    string res;
    if (BuildCharCounters(w1) == BuildCharCounters(w2)){
        res = "YES";
    } else {
        res = "NO";
    }

    return res;
}
void test(void)
{   
    struct test_data
    {
        string w1;
        string w2;
        string answer;
    };

    vector<test_data> td = {
        {"eat", "tea", "YES"},
        {"find", "search", "NO"},
        {"master", "stream", "YES"},
        {"", "", "YES"},
        {"aaaaa", "aaa", "NO"},

    };

    for (const auto& item : td)
    {
        if (is_anagrams(item.w1, item.w2) == item.answer)
            cout << "Ok" << endl;
        else
            cout << "Error" << endl;
    }

}

void get_answer()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        string w1 ,w2;
        cin >> w1 >> w2;
        cout << is_anagrams(w1, w2) << endl;
    }
}

int main()
{
    // test();
    get_answer();

    return 0;
}