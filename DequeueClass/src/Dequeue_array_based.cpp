#include "Dequeue_array_based.h"
#include <iostream>
using namespace std;
#include <string>

using namespace std;
template <class T>
Dequeue<T>::Dequeue()
{
    arr=NULL;
    front_idx=-1;
    rear_idx=-1;
    curr_capacity=0;
    curr_size=0;
}
template <class T>
Dequeue<T>::Dequeue(int size)
{
    arr = new T[size];
    for(int i=0 ;i<size;i++)
    arr[i]=(T)0;
    curr_capacity =size;
    curr_size=0;
}
template <class T>
Dequeue<T>::Dequeue(int size,T default_value)
{
    arr = new T[size];
    front_idx=0;
    for(int i=0 ;i<size;i++)
        arr[i]=default_value;
    rear_idx=size-1;
    curr_capacity =size;
    curr_size=size;
}
template <class T>
Dequeue<T>::~Dequeue()
{
    delete arr;

}
template <class T>
Dequeue<T>& Dequeue<T>::operator= (Dequeue<T>& copy_Dequeue)
{
  if(this != &copy_Dequeue)
  {
     this->erase_all_elements();
     curr_size=copy_Dequeue.curr_size;
     curr_capacity=copy_Dequeue.curr_capacity;
     if(curr_capacity !=0)
     {
         arr =new T[curr_capacity];
         memcpy(arr,copy_Dequeue.arr,curr_size *sizeof(T));
     }
     else{

        throw string("Error: Dynamic dequeue memory allocation failure.");
     }


  }
}

template <class T>
Dequeue<T>::erase_all_elements(){

if(curr_capacity>=0)
    delete []arr;
  curr_capacity=0;
  curr_size=0;
  arr =NULL;
}

////////////////iterator functions//////////////////////
template <class T>
Dequeue<T>::iterator::iterator()
{
    ptr=NULL;
}
template <class T>
Dequeue<T>::iterator:: iterator(T* p)
{
ptr=p;
}

template <class T>
bool Dequeue<T>::iterator:: operator== (iterator& rptr)
{
        return (ptr==rptr.ptr);
}
template <class T>
bool Dequeue<T>::iterator:: operator!= (iterator&rptr)
{
    return (ptr!=rptr.ptr);
}
template <class T>
 Dequeue<T>::iterator::operator++()
{
    this->ptr++;
}
template <class T>
 Dequeue<T>::iterator::operator--()
{
    this->ptr--;
}
template <class T>
T Dequeue<T>::iterator:: operator*()
{
    return *ptr;
}
/////////////////iterators///////////////////////////
template <class T>
typename Dequeue<T>::iterator Dequeue<T>:: begin()
{
    return iterator(arr);
}
 template <class T>
typename Dequeue<T>::iterator Dequeue<T>:: end()
{
    return iterator(arr+curr_size);
}
 template <class T>
typename Dequeue<T>::iterator Dequeue<T>:: rbegin()
{
    return iterator(begin());
}
 template <class T>
typename Dequeue<T>::iterator Dequeue<T>:: rend()
{
     return iterator(end());
}
 template <class T>
typename Dequeue<T>::iterator Dequeue<T>:: cbegin()const
{
        return iterator(arr);
}
 template <class T>
typename Dequeue<T>::iterator Dequeue<T>:: cend()const
{
    return iterator(arr+curr_size);
}
 template <class T>
typename Dequeue<T>::iterator Dequeue<T>:: crbegin()const
{
     return iterator(arr+curr_size);
}
 template <class T>
typename Dequeue<T>::iterator Dequeue<T>:: crend()const
{
   return iterator(arr);
}
////////////////////capacity////////////////
 template <class T>
int Dequeue<T>:: size()
{
   return curr_size;
}
  template <class T>
int Dequeue<T>:: max_size()
{
    return curr_capacity;
}

template <class T>
 Dequeue<T>:: resize(int new_size)
{

   if (new_size<=curr_size)
   {

       for(int i=new_size-1 ;i<curr_size;i++)
        arr[i]=(T)0;

      curr_size =new_size;
   }
   else if(new_size>curr_size && new_size<=curr_capacity)
   {

       for(int i=curr_size-1 ;i<new_size;i++)
        arr[i]=(T)0;

      curr_size =new_size;
   }
  else
   {
        T* temp_arr =new T[new_size];
        for(int i=0 ;i<curr_size;i++)
           temp_arr[i]=arr[i];
        for(int i=curr_size-1 ;i<new_size;i++)
           temp_arr[i]=(T)0;
        delete [] arr;
        arr =temp_arr;
   }

}
  template <class T>
 Dequeue<T>:: resize(int new_size,T default_value)
{

if (new_size<=curr_size)
   {

       for(int i=new_size-1 ;i<curr_size;i++)
        arr[i]=default_value;

      curr_size =new_size;
   }
   else if(new_size>curr_size && new_size<=curr_capacity)
   {

       for(int i=curr_size-1 ;i<new_size;i++)
        arr[i]=default_value;

      curr_size =new_size;
   }
  else
   {
        T* temp_arr =new T[new_size];
        for(int i=0 ;i<curr_size;i++)
           temp_arr[i]=arr[i];
        for(int i=curr_size-1 ;i<new_size;i++)
           temp_arr[i]=default_value;
        delete [] arr;
        arr =temp_arr;
   }
}
  template <class T>
int Dequeue<T>:: capacity()
{
    return curr_capacity;
}
  template <class T>
bool Dequeue<T>:: empty()
{
  if(curr_size == 0)
    return true;
  else
    return false;
}
 template <class T>
 Dequeue<T>::reserve(int new_capacity)
{

      T*temp = new T[new_capacity];
    if(front_idx >-1)
    {
        int end_idx=(rear_idx+curr_capacity-front_idx)%curr_capacity;
        for(int i=0 ;i<=end_idx;i++)
        temp[i]=arr[(front_idx+i)%(curr_capacity)];

    }
    delete arr;
    arr= temp;
    curr_capacity=new_capacity;
}
 template <class T>
 Dequeue<T>::shrink_to_fit()
{
  if(curr_size<curr_capacity)
   {
        int end_idx=(rear_idx+curr_capacity-front_idx)%curr_capacity;
        T* temp_arr =new T[curr_size];
        front_idx=0;
        for(int i=0 ;i<end_idx;i++)
           temp_arr[i]=arr[i];
        rear_idx=end_idx-1;
        delete [] arr;
        arr =temp_arr;
        curr_capacity=curr_size;
   }
}
/////////////////////////element access  /////////////////////
template <class T>
T& Dequeue<T>::operator[ ] (int index){

 if(index > (curr_size-1))
    {
		throw string("Error: Array out of bounds.");
	}
  return arr[index];
}

template <class T>
T Dequeue<T>:: at(int index)
{
    return arr[index];
}
template <class T>
T Dequeue<T>:: front()
{
    return arr[0];
}
template <class T>
T Dequeue<T>:: back ()
{
    return arr[curr_size-1];
}
template <class T>
T* Dequeue<T>:: data()
{
    return arr;
}
////////////////////////modifiers/////////////////////////
 template <class T>
 Dequeue<T>::assign(Dequeue<T>::iterator first,Dequeue<T>::iterator last)
 {
    Dequeue<T>::iterator temp =first;
    int counter=0;
    while(temp != last)
    {
        ++temp;
        counter++;
    }
    temp =first;
    front_idx=0;
    rear_idx=counter-1;
    T* temp_arr =new T[counter];
    for(int i=0;i<counter;i++)
    {
      temp_arr[i] = *temp;
      ++temp;
    }
    arr=temp_arr;
    curr_size=counter;
    curr_capacity=counter;
 }
 template <class T>
 Dequeue<T>:: assign (int n ,T& val)
 {

    T* temp_arr =new T[n];
    front_idx=0;
    rear_idx=n-1;
    for(int i=0;i<n;i++)
    {
      temp_arr[i] = val;
    }
    arr=temp_arr;
    curr_size=n;
    curr_capacity=n;
 }
 template <class T>
 Dequeue<T>::push_back (const T& val)
 {
    if(curr_size==curr_capacity)
         {reserve(2*curr_capacity+1);}

        if(front_idx == -1)
            front_idx=rear_idx=0;
        else
            rear_idx=(rear_idx+1)%curr_capacity;

        arr[rear_idx]=val;
       curr_size++;
 }
 template <class T>
 Dequeue<T>::pop_back()
 {
      if(front_idx==rear_idx)
        front_idx=rear_idx=-1;
    else
        rear_idx=(rear_idx-1+curr_capacity)%curr_capacity;

    curr_size--;

    if(curr_size<curr_capacity/2)
        reserve(curr_capacity/2);
 }
 template <class T>
 Dequeue<T>::push_front (const T& val)
 {
     if(curr_size==curr_capacity)
        {reserve(2*curr_capacity+1);}
        if(front_idx == -1)
            front_idx=rear_idx=0;
        else
            front_idx=(front_idx-1+curr_capacity)%curr_capacity;

        arr[front_idx]=val;
        curr_size++;
 }
 template <class T>
 Dequeue<T>::pop_front()
 {
      if(front_idx==rear_idx)
        front_idx=rear_idx=-1;
    else
        front_idx=(front_idx+1)%curr_capacity;

    curr_size--;

    if(curr_size<curr_capacity/2)
        reserve(curr_capacity/2);
 }
 template <class T>
  Dequeue<T>:: insert (int  position, const T& val)
 {
    if(curr_size<curr_capacity && position<=curr_capacity)
    {
        int temp_index= position;
        for(int i=curr_size-1;i>position-1;i--)
            {
                arr[i+1]=arr[i];
            }
        arr[position]=val;
        curr_size++;
        rear_idx=(rear_idx+1)%curr_capacity;
    }
    else if (position<=curr_capacity)
    {
       T* temp_arr =new T[curr_capacity+1];
       for(int i=0;i<curr_size;i++)
            {
                temp_arr[i]=arr[i];
            }
        int temp_index= position;
        for(int i=curr_size-1;i<position-1;i--)
            {
                arr[i+1]=arr[i];
            }
        arr[position]=val;
         curr_size++;;
         curr_capacity++;
         rear_idx=(rear_idx+1)%curr_capacity;
    }
    else
    {
     throw string("Error: position is out range of the  vector.");
    }
 }
 template <class T>
  Dequeue<T>:: erase (int position)
 {
     if(position<=curr_capacity)
     {
        int temp_index= position;
        for(int i=position-1;i<curr_size-1;i--)
            {
                arr[i]=arr[i+1];
            }
         curr_size--;;
         curr_capacity--;
     }
     else
        {
            throw string("Error: position is out range of the  vector.");
        }
 }

template <class T>
 Dequeue<T>::swap (Dequeue& x)
 {
   Dequeue * temp=this;
   *this=x;
   x=*temp;

 }
 template <class T>
 Dequeue<T>::clear() noexcept
 {
   if(curr_capacity>0)
    delete []arr;
  curr_capacity=0;
  curr_size=0;
  arr =NULL;
 }
template <class T>
 Dequeue<T>:: print()
 {
     for(int i =0;i<curr_size;i++)
         cout<<arr[i]<< endl;
 }
template class Dequeue<int>;
