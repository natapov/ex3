
#include <iostream>
using namespace std;

int main()
{
    int temp = 1;
    int& a = temp;
    int& b(a);
    b++;
    cout << a << endl;
    return 0;
}