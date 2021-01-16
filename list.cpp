#include <assert.h>
#include <stdlib.h>
#include "list.h"

using mtm::List;

List::Node::Node(T value, Node* next): value(value), next(next) {}
List::Node::Node(T value): value(value), next(NULL) {}

List::List(): size(0), head(NULL) {}
List::List(const List& list): size(list.size)
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

List& List::operator=(const List& list)
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
List::~List()
{
    while(this->head)
    {
        Node *temp = this->head;
        this->head = this->head->next;
        delete temp;
    }
}

List::ListIterator List::begin() const
{
    return List::ListIterator(this->head);
}

List::ListIterator List::end () const
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