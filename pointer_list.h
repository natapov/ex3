#ifndef POINTER_LIST_H
#define POINTER_LIST_H
#include <assert.h>
#include <stdlib.h>
#include "list.h"
#include "exceptions.h"
#include "base_event.h"
using mtm::ValueNotInList;

namespace mtm
{
    class PointerList;
}
using mtm::PointerList;

//BaseEvent*ype BaseEvent* should support these operations:
// == operator
// BaseEvent*(const BaseEvent*&) - copy constructor
// < operator
//typedef mtm::BaseEvent* BaseEvent*;
class PointerList
{
private:
    struct Node
    {
        BaseEvent* value;
        Node* next;
        Node(BaseEvent* value): value(value), next(NULL) {}
        Node(BaseEvent* value, Node* next): value(value), next(next) {}
    };
    
    int size;
    Node* head;
public:
    class ListIterator
    {
        private:
            Node* current;
        public:
            ListIterator(Node* node) :current(node){}
            mtm::BaseEvent& operator*() const{
                return (*(current->value));
            }
            ListIterator& operator++(){
               this->current = this->current->next;
               return *this;
            }
            bool operator==(const ListIterator& other){
                return this->current == other.current;
            }
            bool operator!=(const ListIterator& other)
            {
                return !(*this==other);
            }
    };
public:
    PointerList();
    ~PointerList();
    PointerList(const PointerList& list);
    PointerList& operator=(const PointerList& list);
    bool contains(const BaseEvent* element);
    void add(BaseEvent* element);
    ListIterator end() const;
    ListIterator begin() const;
};

#endif