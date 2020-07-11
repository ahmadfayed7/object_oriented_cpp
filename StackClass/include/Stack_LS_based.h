#ifndef STACK_H
#define STACK_H

template <typename T>
struct node {
 T data ;
 node* next ;
};
template <class T>
class Stack
{
    public:
        Stack();
        virtual ~Stack();
        Stack(const Stack& other);
        Stack& operator=(const Stack& other);
        push(T val);
        pop();
        T top();
        empty();
        int size();
        swap( Stack& other);
    protected:

    private:
        node<T> * head;
        int capacity;
};

#endif // STACK_H
