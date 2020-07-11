#include "Queue_array_based.h"
#include <iostream>

using namespace std;
template <class T>
Queue<T>::Queue()
{
        arr=NULL;
        rear_idx=0;
        front_idx=0;
        curr_capacity=0;
}
template <class T>
Queue<T>::~Queue()
{
    while(rear_idx != 0)
         {
             pop();
         }
}
template <class T>
Queue<T>::Queue(const Queue& other)
{
     *this = other;
}
template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& rhs)
{
    if (this == &rhs) return *this;
      else
        {
          while(rear_idx != 0)
         {
             pop();
         }
          return *this;
        }
}
template <class T>
Queue<T>::reserve(int new_capacity)
{
    T * temp = new T[new_capacity];

    for(int i=0 ; i<rear_idx;i++)
    {
        temp[i]=arr[i];
    }
    delete arr;
    arr=temp;
    curr_capacity=new_capacity;
}
template <class T>
Queue<T>::push(T val)
{
   if(curr_capacity<=rear_idx)
   {
       reserve(curr_capacity*2+1);
   }
    arr[rear_idx]=val;
    rear_idx++;
}
template <class T>
Queue<T>::pop()
{

    if(rear_idx ==0)
    {
       throw string("ERROR :queue is empty");
    }

   front_idx++;
   if(front_idx==rear_idx)
   {
       rear_idx=front_idx=0;
   }
   if(rear_idx < curr_capacity/2)
     reserve(curr_capacity/2);

}
template <class T>
T Queue<T>:: front()
{
    if(rear_idx ==0)
    return (T)0;
    else
    return arr[rear_idx-1];
}
template <class T>
T Queue<T>:: back()
{
    if(rear_idx ==0)
    return (T)0;
    else
    return arr[front_idx];
}
template <class T>
bool Queue<T>::empty()
{
    if(rear_idx==0)
        return true ;
    else
        return false;
}
template <class T>
int Queue<T>::size()
{
    return rear_idx;
}
template <class T>
Queue<T>::swap(Queue& other)
{
    T *temp =arr;
    arr =other.arr;
    other.arr=temp;
}
template class Queue<int>;
template class Queue<float>;
template class Queue<double>;
template class Queue<long>;
template class Queue<string>;
