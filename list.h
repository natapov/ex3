#ifndef LIST_H
#define LIST_H
//THIS IS A TEMPLATED LIST THAT STORES VALUES OF TYPE "T" BY VALUE
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

//Type Y should support these operations:
// == operator
// T(const T&) - copy constructor
// < operator
//typedef int T;
template <typename T>
class List
{
private:
    struct Node
    {
        T value;
        Node* next;
        Node(T value): value(value), next(NULL) {}
        Node(T value, Node* next): value(value), next(next) {}
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
            T operator*() const{    //zeev previously was "const T" but i removed it because T is returned by value
                return this->current->value;
            }
            ListIterator& operator++(){
               this->current = this->current->next;
               return *this;
            }
            bool operator==(const ListIterator& other) const{
                return this->current == other.current;
            }
            bool operator!=(const ListIterator& other) const{
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
            delete temp;
        }
    }

    List(const List& list): size(list.size)
    {
        if(list.size > 0)
        {
            assert(list.head);
            this->head = new Node(list.head->value);
            Node* current_copy_node = this->head;
            Node* current_original_node = list.head;
            while(current_original_node->next)
            {
                current_copy_node->next = new Node(current_original_node->next->value);

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
            new_head = new Node(list.head->value);
            Node* current_list_node = list.head;
            Node* current_new_head_node = new_head;
            while(current_list_node->next)
            {
                current_new_head_node->next = new Node(current_list_node->next->value);
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
    
    bool contains(T element) const
    {
        Node* current = head;
        while(current)
        {
            if(element == current->value)
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
        if(new_node->value < current->value)
        {
            new_node->next = current;
            this->head = new_node;
            this->size++;
            return;
        }
        while(current->next && current->next->value < new_node->value) //SMALLER value IN THE BEGGINING 
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
        if(this->head->value == element)
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
            if(current->next->value == element)
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
