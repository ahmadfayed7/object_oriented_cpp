#include "Vector.h"
#include <string>

using namespace std;
template <class T>
Vector<T>::Vector()
{
    arr=NULL;
    curr_size=0;
    curr_capacity=0;
}
template <class T>
Vector<T>::Vector(int size)
{
    arr = new T[size];
    for(int i=0 ;i<size;i++)
    arr[i]=(T)0;
    curr_capacity =size;
    curr_size=0;
}
template <class T>
Vector<T>::Vector(int size,T default_value)
{
    arr = new T[size];
    for(int i=0 ;i<size;i++)
        arr[i]=default_value;
    curr_capacity =size;
    curr_size=size;
}
template <class T>
Vector<T>::~Vector()
{

}
template <class T>
Vector<T>& Vector<T>::operator= (Vector<T>& copy_vector)
{
  if(this != &copy_vector)
  {
     this->erase_all_elements();
     curr_size=copy_vector.curr_size;
     curr_capacity=copy_vector.curr_capacity;
     if(curr_capacity !=0)
     {
         arr =new T[curr_capacity];
         memcpy(arr,copy_vector.arr,curr_size *sizeof(T));
     }
     else{

        throw string("Error: DynamicVector memory allocation failure.");
     }


  }
}

template <class T>
Vector<T>::erase_all_elements(){

if(curr_capacity>0)
    delete []arr;
  curr_capacity=0;
  curr_size=0;
  arr =NULL;
}

////////////////iterator functions//////////////////////
template <class T>
Vector<T>::iterator::iterator()
{
    ptr=NULL;
}
template <class T>
Vector<T>::iterator:: iterator(T* p)
{
ptr=p;
}

template <class T>
bool Vector<T>::iterator:: operator== (iterator& rptr)
{
        return (ptr==rptr.ptr);
}
template <class T>
bool Vector<T>::iterator:: operator!= (iterator&rptr)
{
    return (ptr!=rptr.ptr);
}
template <class T>
 Vector<T>::iterator::operator++()
{
    this->ptr++;
}
template <class T>
 Vector<T>::iterator::operator--()
{
    this->ptr--;
}
template <class T>
T Vector<T>::iterator:: operator*()
{
    return *ptr;
}
/////////////////iterators///////////////////////////
template <class T>
typename Vector<T>::iterator Vector<T>:: begin()
{
    return iterator(arr);
}
 template <class T>
typename Vector<T>::iterator Vector<T>:: end()
{
    return iterator(arr+curr_size);
}
 template <class T>
typename Vector<T>::iterator Vector<T>:: rbegin()
{
    return iterator(begin());
}
 template <class T>
typename Vector<T>::iterator Vector<T>:: rend()
{
     return iterator(end());
}
 template <class T>
typename Vector<T>::iterator Vector<T>:: cbegin()const
{
        return iterator(arr);
}
 template <class T>
typename Vector<T>::iterator Vector<T>:: cend()const
{
    return iterator(arr+curr_size);
}
 template <class T>
typename Vector<T>::iterator Vector<T>:: crbegin()const
{
     return iterator(arr+curr_size);
}
 template <class T>
typename Vector<T>::iterator Vector<T>:: crend()const
{
   return iterator(arr);
}
////////////////////capacity////////////////
 template <class T>
int Vector<T>:: size()
{
   return curr_size;
}
  template <class T>
int Vector<T>:: max_size()
{
    return curr_capacity;
}

template <class T>
 Vector<T>:: resize(int new_size)
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
 Vector<T>:: resize(int new_size,T default_value)
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
int Vector<T>:: capacity()
{
    return curr_capacity;
}
  template <class T>
bool Vector<T>:: empty()
{
  if(curr_size == 0)
    return true;
  else
    return false;
}
 template <class T>
 Vector<T>::reserve(int new_size)
{

  if(new_size>curr_capacity)
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
 Vector<T>::shrink_to_fit()
{
  if(curr_size<curr_capacity)
   {
        T* temp_arr =new T[curr_size];
        for(int i=0 ;i<curr_size;i++)
           temp_arr[i]=arr[i];
        delete [] arr;
        arr =temp_arr;
        curr_capacity=curr_size;
   }
}
/////////////////////////element access  /////////////////////
template <class T>
T& Vector<T>::operator[ ] (int index){

 if(index > (curr_size-1))
    {
		throw string("Error: Array out of bounds.");
	}
  return arr[index];
}

template <class T>
T Vector<T>:: at(int index)
{
    return arr[index];
}
template <class T>
T Vector<T>:: front()
{
    return arr[0];
}
template <class T>
T Vector<T>:: back ()
{
    return arr[curr_size-1];
}
template <class T>
T* Vector<T>:: data()
{
    return arr;
}
////////////////////////modifiers/////////////////////////
 template <class T>
 Vector<T>::assign(Vector<T>::iterator first,Vector<T>::iterator last)
 {
    Vector<T>::iterator temp =first;
    int counter=0;
    while(temp != last)
    {
        ++temp;
        counter++;
    }
    temp =first;
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
 Vector<T>:: assign (int n ,T& val)
 {

    T* temp_arr =new T[n];
    for(int i=0;i<n;i++)
    {
      temp_arr[i] = val;
    }
    arr=temp_arr;
    curr_size=n;
    curr_capacity=n;
 }
 template <class T>
 Vector<T>::push_back (const T& val)
 {
   if(curr_size>=curr_capacity)
   {
       if(curr_capacity==0)
       {
           curr_capacity=1;
       }
       else
       {
           curr_capacity =curr_capacity*2;
       }
       T* temp_arr =new T[curr_capacity];
      if (temp_arr == NULL)
		{
			throw string("Error: DynamicVector memory allocation failure.");
		}
      if(curr_size>=1)
      {
          memcpy(temp_arr,arr,curr_size*sizeof(T));
      }
      delete []arr;
      arr=temp_arr;
      arr[curr_size]=val;
      curr_size++;
   }
   else
    {
     arr[curr_size]=val;
      curr_size++;
    }
 }
 template <class T>
 Vector<T>::pop_back()
 {
     arr[curr_size]=(T)0;
     curr_size--;
 }
 template <class T>
  Vector<T>:: insert (int  position, const T& val)
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
    }
    else
    {
     throw string("Error: position is out range of the  vector.");
    }
 }
 template <class T>
  Vector<T>:: erase (int position)
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
 Vector<T>::swap (Vector& x)
 {
   Vector * temp=this;
   *this=x;
   x=*temp;

 }
 template <class T>
 Vector<T>::clear() noexcept
 {
   if(curr_capacity>0)
    delete []arr;
  curr_capacity=0;
  curr_size=0;
  arr =NULL;
 }
template <class T>
 Vector<T>:: print()
 {
     for(int i =0;i<curr_size;i++)
         cout<<arr[i]<< endl;
 }
//for comman template class issue in c++//
template class Vector<int>;
template class Vector<float>;
template class Vector<double>;
template class Vector<long>;
template class Vector<string>;
