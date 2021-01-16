#ifndef SORTED_LIST_H
#define SORTER_LIST_H

#include "exceptions.h"
using mtm::ValueNotInList;

namespace mtm
{
    class List;
}
using mtm::List;

//Type Y should support these operations:
// == operator
// T(const T&) - copy constructor
// < operator
typedef int T;
class List
{
private:
    struct Node
    {
        T value;
        Node* next;
        Node(T value);
        Node(T value, Node *next);
    };
    
    int size;
    Node* head;
public:
    class ListIterator
    {
        private:
            Node* current;
        public:
            ListIterator(Node* node);
            const T operator*() const;
            ListIterator& operator++();
            bool operator==(const ListIterator& other);
            bool operator!=(const ListIterator& other);
    };
public:
    List();
    List(const List& list);
    List& operator=(const List& list);
    int get_size(){
        return size;
    }
    void remove(T element);
    bool contains(T element);
    void add(T element);
    ListIterator begin();
    ListIterator end();
    ~List();
};

#endif