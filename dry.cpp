#include <stdbool.h>
#include <string>
#include <vector>
#include <ostream>
#include <iostream>
#include <memory>
using std::cout;
using std::endl;

class BadInput{};
// PRINT FUNCTION
// template<class T>
// void print(std::vector<T> vec)
// {
//     for (T element: vec)
//     {
//         cout << element;
//     }
//     cout << endl;
// }

template<class T>
std::vector<T> slice(std::vector<T> vec, int start, int step, int stop)
{
    if(start < 0 || stop < 0 || step <=0)
    {
        throw BadInput();
    }
    std::vector<T> new_vec;
    for(; start < stop; start += step)
    {
        new_vec.push_back(vec[start]);
    }
    return new_vec;
}
class A {
    public:
    std::vector<std::shared_ptr<int>> values;
    void add(int x) {
        values.push_back(std::shared_ptr<int>(new int(x))); 
    }
};
int main()
{
    A a, sliced;
    a.add(0); a.add(1); a.add(2); a.add(3); a.add(4); a.add(5);
    sliced.values = slice(a.values, 1, 1, 4);
    *(sliced.values[0]) = 800;
    std::cout << *(a.values[1]) << std::endl;
    return 0;

}