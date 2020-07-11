#include "Stack_array_based.h"
#include <iostream>
#include <string>
using namespace std;
template <class T>
Stack<T>::Stack()
{
         arr =NULL ;
         curr_size=0;
        curr_capacity=0;
}
template <class T>
Stack<T>::~Stack()
{
      while(curr_size != 0)
         {
             pop();
         }
}
template <class T>
Stack<T>::Stack(const Stack<T>& other)
{
    *this = other;
}
template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& rhs)
{
    if (this == &rhs) return *this;
      else
        {
          while(curr_size != 0)
         {
             pop();
         }
          return *this;
        }

}
template <class T>
Stack<T>::reserve(int new_capacity)
{
    T * temp = new T[new_capacity];

    for(int i=0 ; i<curr_size;i++)
    {
        temp[i]=arr[i];
    }
    delete arr;
    arr=temp;
    curr_capacity=new_capacity;
}
  template <class T>
Stack<T>::push(T val)
{
   if(curr_capacity<=curr_size)
   {
       reserve(curr_capacity*2+1);
   }
    arr[curr_size]=val;
    curr_size++;
}
  template <class T>
Stack<T>::pop()
{
    if(curr_size==0)
    {
        throw string("Error: stack is not empty.");
    }

    curr_size--;
    if(curr_size<curr_capacity/2)
        reserve(curr_capacity/2);
}
template <class T>
T Stack<T>:: top()
{
    return arr[curr_size-1];
}

template <class T>
Stack<T>::empty()
{
    if(curr_size==0)
        return true;
    else
        return false;
}
template <class T>
int Stack<T>:: size()
{
    return curr_size;
}
template <class T>
Stack<T>::swap( Stack& other)
{
    T* temp =arr;
     arr=other.arr;
     other.arr=temp;

}
//for comman template class issue in c++//
template class Stack<int>;
template class Stack<float>;
template class Stack<double>;
template class Stack<long>;
//template class Stack<string>;
