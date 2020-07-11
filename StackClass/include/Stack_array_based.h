#ifndef STACK_H
#define STACK_H


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
        reserve(int new_capacity);
        T top();
        empty();
        int size();
        swap( Stack& other);
    protected:

    private:
        T *arr ;
        int curr_size;
        int curr_capacity;
};

#endif // STACK_H
