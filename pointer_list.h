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

//BaseEventype BaseEvent* should support these operations:
// == operator
// BaseEvent*(const BaseEvent*&) - copy constructor
// < operator
class PointerList
{
private:
    struct Node
    {
        BaseEvent* value;
        Node* next;
        Node(BaseEvent* value): value(value), next(nullptr) {}
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
        //#TODO: MOVE TO CPP
            ListIterator(Node* node);
            mtm::BaseEvent& operator*() const;
            ListIterator& operator++();
            bool operator==(const ListIterator& other) const;
            bool operator!=(const ListIterator& other) const;
    };
public:
    PointerList();
    ~PointerList();
    PointerList(const PointerList& list);
    PointerList& operator=(const PointerList& list);
    bool contains(BaseEvent* element) const;
    void add(BaseEvent* element);
    ListIterator end() const;
    ListIterator begin() const;
};

#endif