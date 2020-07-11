#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
struct node
{
    T data ;
    node* next;
    node* prev;
};
template <class T>
class Queue
{
    public:
        Queue();
        virtual ~Queue();
        Queue(const Queue& other);
        Queue& operator=(const Queue& other);
        push(T val);
        pop();
       T front();
       T back();
       bool empty();
       int size();
       swap(Queue& other);
    protected:

    private:
        node<T> *head;
        node<T> *tail;
        int curr_capacity;
};

#endif // QUEUE_H
