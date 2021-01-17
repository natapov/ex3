//compile with g++ -std=c++11 -Wall -Werror -pedantic-errors -g  -o test_list list_test.cpp list.h


#include <iostream>
#include "List.h"

using std::cout;
using std::endl;
using mtm::List;
using mtm::ValueNotInList;

void print_list(List<int>& l)
{
    cout << "The List is: ";
    for (List<int>::ListIterator i = l.begin(); i != l.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;
}

List<int> create_long_list()
{
    List<int> l = List<int>();
    for (int i = 10; i > 0; i--)
    {
        l.add(i);   
        print_list(l);
    }
    return l;
    
}

void print_contains(List<int> l, int i)
{
    if(l.contains(i))
    {
        cout << "List contains the number " << i << endl;
    }
    else
    {
        cout << "List does not contain number" << i << endl;
    }
    
}

int main()
{
    List<int> l = create_long_list();
    print_list(l);
    l.remove(3);
    print_list(l);
    l.remove(8);
    print_list(l);
    l.remove(9);
    print_list(l);
    print_contains(l, 1);
    print_contains(l, 18);
    print_contains(l, 10);
    print_contains(l, 8);

    List<int> l1(l);
    print_list(l1);
    l1 = l;
    print_list(l1);
    l1.remove(10);
    print_list(l1);
    l1.remove(1);
    l1.remove(2);
    l1.remove(4);
    l1.remove(5);
    l1.remove(6);
    print_list(l1);
    l1.remove(7);
    l1.add(1);
    print_list(l1);

}
