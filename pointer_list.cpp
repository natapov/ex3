#include "pointer_list.h"

using namespace mtm;

PointerList::PointerList(): size(0), head(nullptr) {}


PointerList::~PointerList()
{
    while(this->head)
    {
        Node *temp = this->head;
        this->head = this->head->next;
        delete temp->value;
        delete temp;
    }
}

PointerList::PointerList(const PointerList& list): size(list.size)
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
        this->head = nullptr;
    }
}

PointerList& PointerList::operator=(const PointerList& list)
{
    if(this == &list){
        return *this;
    }
    Node *new_head = nullptr;
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

bool PointerList::contains(BaseEvent* element) const
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

void PointerList::add(BaseEvent* element)
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
    while(current->next && *(current->next->value) < *(new_node->value))
    {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    this->size++;
}

PointerList::ListIterator PointerList::end() const
{
    return ListIterator(nullptr);
}

PointerList::ListIterator PointerList::begin() const
{
    return ListIterator(this->head);
}

PointerList::ListIterator::ListIterator(Node* node):current(node){}

mtm::BaseEvent& PointerList::ListIterator::operator*() const{
    return *(current->value);
}
PointerList::ListIterator& PointerList::ListIterator::operator++(){
    this->current = this->current->next;
    return *this;
}
bool PointerList::ListIterator::operator==(const ListIterator& other) const {
    return this->current == other.current;
}
bool PointerList::ListIterator::operator!=(const ListIterator& other) const {
    return !(*this==other);
}
