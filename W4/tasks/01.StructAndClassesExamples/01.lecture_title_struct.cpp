#include <iostream>
#include <string>

using namespace std;


struct Specialization
{
    string value;
    explicit Specialization(const string& new_v)
    {
        value = new_v;
    }
};

struct Course
{
    string value;
    explicit Course(const string& new_v)
    {
        value = new_v;
    }
};

struct Week
{
    string value;
    explicit Week(const string& new_v)
    {
        value = new_v;
    }
};

struct LectureTitle {
    string specialization;
    string course;
    string week;

    LectureTitle(const Specialization& new_s, const Course& new_c, const Week& new_w)
    {
        specialization = new_s.value;
        course = new_c.value;
        week = new_w.value;
    }
};
