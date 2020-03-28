#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Foo
{
public:
    operator int() const {
        return 1;
    }
};

int main()
{

    Foo foo;
    int i = int(foo);
    cout << i << endl;
    return 0;
}