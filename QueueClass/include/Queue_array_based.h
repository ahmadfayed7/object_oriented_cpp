#ifndef QUEUE_H
#define QUEUE_H

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
       reserve(int new_capacity);
    protected:

    private:
        T *arr;
        int curr_capacity;
        int rear_idx ;
        int front_idx;
};

#endif // QUEUE_H
