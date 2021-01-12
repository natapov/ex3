#ifndef SORTED_LIST_H
#define SORTER_LIST_H

typedef int T;
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
            ListIterator(const Node* node);
            const T* operator*() const;
            ListIterator& operator++();
            bool operator==(const ListIterator& other);
            bool operator!=(const ListIterator& other);
    };

    int get_size(){
        return size;
    }
    void remove(T element);
    bool contains(T element);
    void add(T element);
    ListIterator begin();
    ListIterator end();
};

#endif