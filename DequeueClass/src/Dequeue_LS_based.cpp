#include "Dequeue_LS_based.h"
#include <iostream>
using namespace std;
template <class T>
Dequeue<T>::Dequeue()
{
    head= NULL;
    tail = NULL;
    curr_capacity=0;
}
template <class T>
Dequeue<T>::~Dequeue()
{

   while(head != NULL)
   {
       pop_back();
   }

}

template <class T>
Dequeue<T>::Dequeue(const Dequeue<T>& other)
{
    *this = other ;//copy ctor
}
template <class T>
Dequeue<T>& Dequeue<T>::operator=(const Dequeue<T>& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    else{
       while(head != NULL)
       {
       pop_back();
       }
       head =rhs.head;
    }
    return *this;
}

/////////////////////modifiers/////////////////////////////////
 template <class T>
 Dequeue<T>::assign(Dequeue<T>::iterator first,Dequeue<T>::iterator last)
 {
    Dequeue<T>::iterator temp =first;
    int counter=0;
    if(head == NULL)
    {
        while(temp != last)
        {
            counter++;
            push_back(*temp);
            ++temp;
        }
    }
    else
    {
        throw string("Error: list is not empty.");
    }

 }
 template <class T>
 Dequeue<T>:: assign (int size ,T& val)
 {
      Dequeue<T>::iterator temp =iterator(head);
    int counter=0;
    if(head == NULL)
    {
        while(counter <size)
        {
            counter++;
            push_back(val);
            ++temp;
        }


    }
    else
    {
        throw string("Error: list is not empty.");
    }
 }
template <class T>
Dequeue<T>::push_front(T val)
{
    node<T>* new_node =new node<T>();
    new_node->data=val;
    if(head ==NULL)
    {
        head=new_node;
        tail =new_node;
    }
    else
    {
      new_node->next=head;
      head->prev=new_node;
      head =new_node;

    }
    curr_capacity++;
}
template <class T>
Dequeue<T>::push_back(T val)
{
     node<T>* new_node =new node<T>();
    new_node->data=val;
    if(head ==NULL)
    {
        head=new_node;
        tail =new_node;
    }
    else
    {
      tail->next=new_node;
      new_node->prev=tail;
      tail =new_node;

    }
    curr_capacity++;
}
template <class T>
Dequeue<T>::pop_front()
{
    node<T> * temp_node=head;
    if(head == NULL)
        throw std::string ("deque is empty");
    else
    {
        head =head-> next;
        head->prev=NULL;
        delete temp_node;
    }
    curr_capacity--;
}
template <class T>
Dequeue<T>::pop_back()
{
 node<T> * temp_node=tail;
    if(tail == NULL)
        throw std::string ("deque is empty");
     if(head==tail)
     {
         delete temp_node;
         head=tail=NULL;
     }
    else
    {
        tail =tail-> prev;
        tail->next=NULL;
        delete temp_node;
    }
    curr_capacity--;
}

template <class T>
Dequeue<T>::print()
{
    node<T> * temp_node=head;
    while(temp_node != NULL)
    {
        cout<<temp_node->data<<endl;
        temp_node=temp_node->next;
    }
}
template <class T>
Dequeue<T>::print_rev()
{
     node<T> * temp_node=tail;
    while(temp_node != NULL)
    {
        cout<<temp_node->data<<endl;
        temp_node=temp_node->prev;
    }
}

 template <class T>
  Dequeue<T>:: insert (Dequeue<T>::iterator prev, const T& val)
 {
   Dequeue<T>::iterator temp =iterator(NULL);
     if(prev ==temp )
        {
         throw string("Error: last position is NULL");
        }
        else
        {
    node<T>* prev_node =prev.Dequeue<T>::iterator::current_node();
    node<T>* new_node =new node<T>();
    new_node->data = val;
    new_node->next=prev_node->next;
    if(prev_node->next !=NULL)
    prev_node->next->prev=new_node;
    prev_node->next =new_node;
    new_node->prev=prev_node;
    curr_capacity++;
        }


 }
 template <class T>
  Dequeue<T>:: erase (Dequeue<T>::iterator prev)
 {
     node<T> * prev_node=prev.Dequeue<T>::iterator::current_node();
     if(prev_node ==NULL || prev_node->next==NULL )
        {
         throw string("Error: last position is NULL");
        }
    node<T>* temp_node =new node<T>();
    temp_node =prev_node->next;
    prev_node->next=prev_node->next->next;
    if(temp_node->next!=NULL)
    prev_node->next->next->prev=prev_node;
    delete (temp_node);
    curr_capacity--;
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
   node<T>* temp_node =head;
  node<T>* prev_node;
    while(temp_node != NULL)
        {
      prev_node=temp_node;
      temp_node=temp_node->next;
      delete prev_node;
  }
  curr_capacity=0;
  head =NULL;
 }
////////////////iterator functions//////////////////////
template <class T>
Dequeue<T>::iterator::iterator()
{
    ptr=NULL;
}
template <class T>
Dequeue<T>::iterator:: iterator(node<T>* p)
{
         ptr=p;
}

template <class T>
bool Dequeue<T>::iterator:: operator== ( const iterator& rptr)
{
        return (ptr==rptr.ptr);
}
template <class T>
bool Dequeue<T>::iterator:: operator!= (const iterator&rptr)
{
    return (ptr!=rptr.ptr);
}
template <class T>
typename Dequeue<T>::iterator& Dequeue<T>::iterator::operator++()
{
    ptr=ptr->next;
    return *this;
}
template <class T>
 typename Dequeue<T>::iterator& Dequeue<T>::iterator::operator--()
{
    ptr=ptr->prev;
    return *this;
}
template <class T>
T Dequeue<T>::iterator:: operator*()
{
       return ptr->data;
}
template <class T>
node<T>* Dequeue<T>::iterator:: current_node()
{
 return ptr;
}
/////////////////iterators///////////////////////////
template <class T>
typename Dequeue<T>::iterator Dequeue<T>:: begin()
{
    return iterator(head);
}
 template <class T>
typename Dequeue<T>::iterator Dequeue<T>:: end()
{
    return iterator(tail);
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
        return iterator(head);
}
 template <class T>
typename Dequeue<T>::iterator Dequeue<T>:: cend()const
{
    return iterator(tail);
}
 template <class T>
typename Dequeue<T>::iterator Dequeue<T>:: crbegin()const
{
     return iterator(tail);
}
 template <class T>
typename Dequeue<T>::iterator Dequeue<T>:: crend()const
{
   return iterator(head);
}
////////////////////capacity////////////////
template <class T>
int Dequeue<T>:: size()
{
   return curr_capacity;
}
template <class T>
int Dequeue<T>:: max_size()
{
    return curr_capacity;
}

template <class T>
bool Dequeue<T>:: empty()
{
  if(head == NULL)
    return true;
  else
    return false;
}
/////////////////////////element access  /////////////////////
template <class T>
T& Dequeue<T>::operator[ ] (int index){
if(index > (curr_capacity-1))
    {
		throw string("Error: Array out of bounds.");
	}
 node<T> * temp =head;
 int i=0;
 while (i<index)
 {

     temp=temp->next;
 }


  return temp->data;
}

template <class T>
T Dequeue<T>:: at(int index)
{
    if(index > (curr_capacity-1))
    {
		throw string("Error: Array out of bounds.");
	}
 node<T> * temp =head;
 int i=0;
 while (i<index)
 {

     temp=temp->next;
 }


  return temp->data;
}
template <class T>
T Dequeue<T>:: front()
{
    if(head ==NULL)
        return (T)INT_MAX;
    else
        return head->data;
}
template <class T>
T Dequeue<T>:: back()
{
    if(head ==NULL)
        return (T)INT_MAX;
    else
        return tail->data;
}

template class Dequeue<int>;
