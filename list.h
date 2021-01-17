#ifndef SORTED_LIST_H
#define SORTED_LIST_H
#include <assert.h>
#include <stdlib.h>
#include "list.h"
#include "exceptions.h"
using mtm::ValueNotInList;

namespace mtm
{
    template <typename T>
    class List;
}
using mtm::List;

//Type T should support these operations:
// == operator
// T(const T&) - copy constructor
// < operator

template <typename T>
class List
{
private:
    struct Node
    {
        T* value_p;
        Node* next;
        Node(T value): value_p(new T(value)), next(NULL) {}
        Node(T value, Node* next): value_p(new T(value)), next(next) {}
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
            const T operator*() const{
                return *(this->current->value_p);
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
    List(): size(0), head(NULL) {}

    ~List()
    {
        while(this->head)
        {
            Node *temp = this->head;
            this->head = this->head->next;
            delete temp->value_p;
            delete temp;
        }
    }

    List(const List& list): size(list.size)
    {
        if(list.size > 0)
        {
            assert(list.head);
            this->head = new Node(*(list.head->value_p));
            Node* current_copy_node = this->head;
            Node* current_original_node = list.head;
            while(current_original_node->next)
            {
                current_copy_node->next = new Node(*(current_original_node->next->value_p));

                current_copy_node = current_copy_node->next;
                current_original_node = current_original_node->next;
            }
        }
        else
        {
            this->head = NULL;
        }
    }

    List& operator=(const List& list)
    {
        if(this == &list)
        {
            return *this;
        }
        Node *new_head = NULL;
        if(list.size != 0)
        {
            assert(list.head);
            new_head = new Node(*(list.head->value_p));
            Node* current_list_node = list.head;
            Node* current_new_head_node = new_head;
            while(current_list_node->next)
            {
                current_new_head_node->next = new Node(*(current_list_node->next->value_p));
                current_new_head_node = current_new_head_node->next;
                current_list_node = current_list_node->next;
            }
        }
        while(this->head)
        {
            Node* temp = this->head;
            this->head = this->head->next;
            delete temp;
        }
        this->head = new_head;
        this->size = list.size;
        return *this;
    }
    
    bool contains(T element)
    {
        Node* current = head;
        while(current)
        {
            if(element == *(current->value_p))
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void add(T element)
    {
        Node *new_node = new Node(element);
        Node *current = this->head;
        if(!current)
        {
            assert(this->size == 0);
            this->head = new_node;
            this->size++;
            return;
        }
        if(*(new_node->value_p) < *(current->value_p))
        {
            new_node->next = current;
            this->head = new_node;
            this->size++;
            return;
        }
        while(current->next && *(current->next->value_p) < *(new_node->value_p)) //SMALLER value IN THE BEGGINING 
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
        this->size++;
    }
    void remove(T element)//currently removes the first occurents of element
    {
        if(!this->head)
        {
            throw ValueNotInList();
        }
        if(*(this->head->value_p) == element)
        {
            Node* temp = this->head;
            this->head = temp->next;
            delete temp;
            this->size--;
            return;
        }
        Node *current = this->head;
        while(current->next)
        {
            if(*(current->next->value_p) == element)
            {
                Node* temp = current->next;
                current->next = current->next->next;
                this->size--;
                delete temp;
                return;
            }
            current = current->next;
        }
        throw ValueNotInList();
    }
    
    ListIterator end() const
    {
        return ListIterator(NULL);
    }

    ListIterator begin() const
    {
        return ListIterator(this->head);
    }
};

#endif