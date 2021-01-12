typedef int T;
class Set
{
    typedef struct List
    {
        T value;
        List* next;
    }*Node;
    
    int size;
    Node head;
public:
    bool contians(T element)
    {
        Node current = head; 
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
    
};