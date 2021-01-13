//compile with g++ -std=c++11 -Wall -Werror -pedantic-errors -g  -o test_list list_test.c sorted_list.h sorted_list.cpp


#include <iostream>


#include "sorted_list.h"

using std::cout;
using std::endl;

using mtm::List;
using mtm::ValueNotInList;
void print_list(List l)
{
    cout << "The list is: ";
    for (List::ListIterator i = l.begin(); i != l.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;
    
}

int main()
{
    List l = List();
    l.add(1);
    print_list(l);
    cout << l.contains(1) << endl;
    l.remove(1);
    cout << l.contains(1)<<endl;
    return 0;
}
