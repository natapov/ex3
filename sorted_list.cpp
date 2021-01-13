#include <assert.h>
#include <stdlib.h>

#include "sorted_list.h"

using mtm::List;

List::Node::Node(T value, Node* next): value(value), next(next) {}
List::Node::Node(T value): value(value), next(NULL) {}

List::List(): size(0), head(NULL) {}
bool List::contains(T element)
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

void List::add(T element)
{
    Node *new_node = new Node(element);
    Node *current = head;
    if(!current)
    {
        assert(this->size == 0);
        head = new_node;
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
    size++;
    return;
}
void List::remove(T element)//currently removes the first occurents of element
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

List::ListIterator List::begin()
{
    return List::ListIterator(this->head);
}

List::ListIterator List::end()
{
    return List::ListIterator(NULL);
}

List::ListIterator::ListIterator(Node* node) :current(node){}

const T List::ListIterator::operator*() const
{
    return this->current->value;
}
List::ListIterator& List::ListIterator::operator++()
{
    this->current = this->current->next;
    return *this;
}
bool List::ListIterator::operator==(const List::ListIterator& other)
{
    return this->current == other.current;
}
bool List::ListIterator::operator!=(const List::ListIterator& other)
{
    return !(*this==other);
}