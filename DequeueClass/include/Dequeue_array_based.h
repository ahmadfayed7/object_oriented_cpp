#ifndef DEQUEUE_H
#define DEQUEUE_H


template <class T>
class Dequeue
{
    public:
        Dequeue();
        Dequeue(int Size);
        Dequeue(int size,T default_value);
        Dequeue<T>& operator= (Dequeue<T>& copy_vector);
        erase_all_elements();
        virtual ~Dequeue();

 class iterator{
   private :
       T* ptr;
   public:
    explicit iterator();
    explicit iterator(T* p);

    bool operator== (iterator& rptr);
    bool operator!= (iterator&rptr);
     operator++();
     operator--();
    T operator*();
 };
//////////////////iterators///////////////////////
 iterator begin();
 iterator end();
 iterator rbegin();
 iterator rend();
 iterator cbegin() const;
 iterator cend()const;
 iterator crbegin()const;
 iterator crend() const;
//////////////////////capacity//////////////////////
 int size();
 int max_size();
resize(int new_size);
resize(int new_size,T default_value);
 int capacity();
 bool empty();
reserve(int new_size);
shrink_to_fit();
////////////////////element access////////////////////////////////
T& operator[ ] (int index);
T at(int index);
T front();
T back ();
T* data();

///////////////////modifiers////////////////////////////////////
 assign(iterator first,iterator last);
 assign (int n ,T& val);
push_back (const T& val) ;
pop_back();
push_front (const T& val) ;
pop_front();
 insert (int position, const T& val);
int erase (int position);
swap (Dequeue& x);
 clear() noexcept;

 //////////////////////print function////////////////
 print();
    protected:

    private:
        T* arr;
        int front_idx;
        int rear_idx;
        int curr_capacity;
        int curr_size;

};
#endif // DEQUEUE_H
