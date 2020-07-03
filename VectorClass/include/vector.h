#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
template <class T>
class Vector
{
    public:
        Vector();
        Vector(int Size);
        Vector(int size,T default_value);
        Vector<T>& operator= (Vector<T>& copy_vector);
        erase_all_elements();
        virtual ~Vector();

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
 insert (int position, const T& val);
int erase (int position);
swap (Vector& x);
 clear() noexcept;

 //////////////////////print function////////////////
 print();
    protected:

    private:
        T* arr;
        int curr_size;
        int curr_capacity;

};



#endif // VECTOR_H
