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
            // mtm::BaseEvent* operator*() {
            //     return this->current->value;
            // }
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
    PointerList(): size(0), head(NULL) {}

    ~PointerList()
    {
        while(this->head)
        {
            Node *temp = this->head;
            this->head = this->head->next;
            delete temp->value;
            delete temp;
        }
    }

    PointerList(const PointerList& list): size(list.size)
    {
        if(list.size > 0)
        {
            assert(list.head);
            this->head = new Node(list.head->value);
            Node* current_copy_node = this->head;
            Node* current_original_node = list.head;
            while(current_original_node->next)
            {
                current_copy_node->next = new Node(current_original_node->next->value->clone());

                current_copy_node = current_copy_node->next;
                current_original_node = current_original_node->next;
            }
        }
        else
        {
            this->head = NULL;
        }
    }

    PointerList& operator=(const PointerList& list)
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
                current_new_head_node->next = new Node(current_list_node->next->value->clone());
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
    
    bool contains(const BaseEvent* element)
    {
        Node* current = head;
        while(current)
        {
            if(*(element) == *(current->value))
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void add(BaseEvent* element)
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
        if(*(new_node->value) < *(current->value))
        {
            new_node->next = current;
            this->head = new_node;
            this->size++;
            return;
        }
        while(current->next && *(current->next->value) < *(new_node->value)) //SMALLER value IN BaseEvent*HE BEGGINING 
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
        this->size++;
    }
    // void remove(const T& element)//currently removes the first occurence of element
    // {
    //     if(!this->head)
    //     {
    //         throw ValueNotInList();
    //     }
    //     if(this->head->value == element)
    //     {
    //         Node* temp = this->head;
    //         this->head = temp->next;
    //         delete temp;
    //         this->size--;
    //         return;
    //     }
    //     Node *current = this->head;
    //     while(current->next)
    //     {
    //         if(current->next->value == element)
    //         {
    //             Node* temp = current->next;
    //             current->next = current->next->next;
    //             this->size--;
    //             delete temp;
    //             return;
    //         }
    //         current = current->next;
    //     }
    //     throw ValueNotInList();
    // }
    
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