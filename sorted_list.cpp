#include <assert.h>
#include <stdlib.h>
#include <sorted_list.h>

List::Node::Node(T value, Node* next): value(value), next(next) {}
List::Node::Node(T value): value(value), next(NULL) {}
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
    Node *new_node = new Node(element);
    Node *current = head;
    if(!current)
    {
        throw valueNotInList();
    }
    Node* last;
    while(current-> && current->next->value != new_node->value)
    {
        
    }
    
}
List::ListIterator begin()
{
    return ListIterator(this->current);
}

List::ListIterator end()
{
    return ListIterator(NULL);
}

List::ListIterator::ListIterator(const List& list) :current(list.head){}
const T* List::ListIterator::operator*() const
{
    return this->current->value;
}
ListIterator& List::ListIterator::operator++()
{
    this->current = this->current->next;
    return *this;
}
bool ListIterator::operator==(const ListIterator& other)
{
    return this->current == other->current;
}
bool ListIterator::operator!=(const ListIterator& other)
{
    return !(*this==other);
}