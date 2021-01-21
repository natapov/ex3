#include <stdbool.h>
#include <string>
#include <vector>
#include <ostream>
#include <iostream>
using std::cout;
using std::endl;

class BadInput{};
template<class T>
void print(std::vector<T> vec)
{
    for (T element: vec)
    {
        cout << element;
    }
    cout << endl;
}

template<class T>
std::vector<T> slice(std::vector<T> vec, int start, int step, int stop)
{
    if(start < 0 || stop < 0 || step <=0)
    {
        throw BadInput();
    }
    // if(start >= stop) explicit checking of this shouldn't be necessary
    // {
    //     return std::vector<T>();
    // }
    std::vector<T> new_vec;
    for(; start < stop; start += step)
    {
        new_vec.push_back(vec[start]);
    }
    return new_vec;
}
class A {
    public:
    std::vector<int*> values;
    void add(int x) { 
        values.push_back(new int(x)); 
    }
};
int main()
{
    // this syntax initializes a vector with values a,b,c,d,e
    std::vector<char> vec1 {'a', 'b', 'c', 'd', 'e'};
   
    // returns vector with values a,c
    std::vector<char> vec_sliced = slice(vec1, 0, 2, 4);
    print(vec_sliced);
    
    // returns vector with values b,c,d,e
    std::vector<char> vec_sliced2 = slice(vec1, 1, 1, 5);
    print(vec_sliced2);

    // returns an empty vector 
    std::vector<char> vec_sliced3 = slice(vec1, 5, 2, 3);
    print(vec_sliced3);
     

    // part B

    A a, sliced;
    a.add(0); a.add(1); a.add(2); a.add(3); a.add(4); a.add(5);
    sliced.values = slice(a.values, 1, 1, 4);
    *(sliced.values[0]) = 800;
    std::cout << *(a.values[1]) << std::endl;
    return 0;

}