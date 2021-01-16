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
    ListIterator begin() const;
    ListIterator end() const;
    ~List();
};


namespace 
    {
    template <typename T>
    typename List<T>::Node::Node(T value, Node* next): value(value), next(next) {}

    template <typename T>
    List<T>::Node<T>::Node(T value): value(value), next(NULL) {}

    template <typename T>
    List<T>::List(): size(0), head(NULL) {}

    template <typename T>
    List<T>::List(const List<T>& list): size(list.size)
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

    template <typename T>
    List<T>& List<T>::operator=(const List<T>& list)
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

    template <typename T>
    bool List<T>::contains(T element)
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

    template <typename T>
    void List<T>::add(T element)
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

    template <typename T>
    void List<T>::remove(T element)//currently removes the first occurence of element
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

    template <typename T>
    List<T>::~List()
    {
        while(this->head)
        {
            Node *temp = this->head;
            this->head = this->head->next;
            delete temp;
        }
    }

    template <typename T>
    List<T>::ListIterator List<T>::begin() const
    {
        return List::ListIterator(this->head);
    }

    template <typename T>
    List::ListIterator List<T>::end () const
    {
        return List::ListIterator(NULL);
    }

    template <typename T>
    List<T>::ListIterator<T>::ListIterator(Node* node) :current(node){}

    template <typename T>
    const T List<T>::ListIterator<T>::operator*() const
    {
        return this->current->value;
    }

    template <typename T>
    List<T>::ListIterator<T>& List<T>::ListIterator::operator++()
    {
        this->current = this->current->next;
        return *this;
    }

    template <typename T>
    bool List<T>::ListIterator::operator==(const List<T>::ListIterator& other)
    {
        return this->current == other.current;
    }

    template <typename T>
    bool List<T>::ListIterator::operator!=(const List<T>::ListIterator& other)
    {
        return !(*this==other);
    }
}    


#endif