#include "List.h"
#include <iostream>
#include <string>
#define MAX_SIZE 1000000
using namespace std;
template <class T>
List<T>::List()
{
    head=NULL;
    tail=NULL;
    curr_size=0;
}
template <class T>
List<T>::List(int size,T default_value)
{
    head=NULL;
    tail=NULL;
    curr_size=0;
    for(int i=0;i<size;i++)
    {
        push_back(default_value);
    }

}
template <class T>
List<T>::~List()
{
  this->erase_all_elements();
}
template <class T>
List<T>& List<T>::operator= (List<T>& copy_list)
{

     curr_size=copy_list.curr_size;
     this->erase_all_elements();
     head =copy_list.head;
     tail=copy_list.tail;

}

template <class T>
List<T>::erase_all_elements(){

  node<T>* temp_node =head;
  node<T>* prev_node;
    while(temp_node != NULL)
        {
      prev_node=temp_node;
      temp_node=temp_node->next;
      delete prev_node;
  }
  curr_size=0;
  head =NULL;
}

////////////////iterator functions//////////////////////
template <class T>
List<T>::iterator::iterator()
{
    ptr=NULL;
}
template <class T>
List<T>::iterator:: iterator(node<T>* p)
{
         ptr=p;
}

template <class T>
bool List<T>::iterator:: operator== ( const iterator& rptr)
{
        return (ptr==rptr.ptr);
}
template <class T>
bool List<T>::iterator:: operator!= (const iterator&rptr)
{
    return (ptr!=rptr.ptr);
}
template <class T>
typename List<T>::iterator& List<T>::iterator::operator++()
{
    ptr=ptr->next;
    return *this;
}
template <class T>
 typename List<T>::iterator& List<T>::iterator::operator--()
{
    ptr=ptr->prev;
    return *this;
}
template <class T>
T List<T>::iterator:: operator*()
{
       return ptr->data;
}
template <class T>
node<T>* List<T>::iterator:: current_node()
{
 return ptr;
}
/////////////////iterators///////////////////////////
template <class T>
typename List<T>::iterator List<T>:: begin()
{
    return iterator(head);
}
 template <class T>
typename List<T>::iterator List<T>:: end()
{
    return iterator(tail);
}
 template <class T>
typename List<T>::iterator List<T>:: rbegin()
{
    return iterator(begin());
}
 template <class T>
typename List<T>::iterator List<T>:: rend()
{
     return iterator(end());
}
 template <class T>
typename List<T>::iterator List<T>:: cbegin()const
{
        return iterator(head);
}
 template <class T>
typename List<T>::iterator List<T>:: cend()const
{
    return iterator(tail);
}
 template <class T>
typename List<T>::iterator List<T>:: crbegin()const
{
     return iterator(tail);
}
 template <class T>
typename List<T>::iterator List<T>:: crend()const
{
   return iterator(head);
}
////////////////////capacity////////////////
 template <class T>
int List<T>:: size()
{
   return curr_size;
}
  template <class T>
int List<T>:: max_size()
{
    return MAX_SIZE;
}

  template <class T>
bool List<T>:: empty()
{
  if(head == NULL)
    return true;
  else
    return false;
}

/////////////////////////element access  /////////////////////



template <class T>
T List<T>:: front()
{
    return head->data;
}
template <class T>
T List<T>:: back ()
{
    return tail->data;
}

////////////////////////modifiers/////////////////////////
 template <class T>
 List<T>::assign(List<T>::iterator first,List<T>::iterator last)
 {
    List<T>::iterator temp =first;
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
 List<T>:: assign (int size ,T& val)
 {
      List<T>::iterator temp =iterator(head);
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
 List<T>::push_back (const T& val)
 {
  node<T>* new_node =new node<T>();
      new_node->data=val;
      curr_size++;
     if(head ==NULL)
        {

            new_node->next=NULL;
            new_node->prev =NULL;
            tail =new_node;
            head=new_node;
        }
      else{

            tail->next=new_node;
            new_node->prev=tail;
            tail =new_node;

      }
 }
 template <class T>
 List<T>::pop_back()
 {
     node<T>* temp_node;
     curr_size--;
     if(head ==NULL)
     {
         throw string("Error: list is  empty.");
     }

        if(tail->prev==NULL)
        {
           temp_node =tail;
          head=NULL;
            tail=NULL;
           delete (temp_node);

        }
        else{
            temp_node =tail;
            tail->prev->next=NULL;
            delete (temp_node);
        }
 }
 template <class T>
  List<T>:: insert (List<T>::iterator prev, const T& val)
 {
   List<T>::iterator temp =iterator(NULL);
     if(prev ==temp )
        {
         throw string("Error: last position is NULL");
        }
        else
        {
    node<T>* prev_node =prev.List<T>::iterator::current_node();
    node<T>* new_node =new node<T>();
    new_node->data = val;
    new_node->next=prev_node->next;
    if(prev_node->next !=NULL)
    prev_node->next->prev=new_node;
    prev_node->next =new_node;
    new_node->prev=prev_node;
    curr_size++;
        }


 }
 template <class T>
  List<T>:: erase (List<T>::iterator prev)
 {
     node<T> * prev_node=prev.List<T>::iterator::current_node();
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
    curr_size--;
 }

template <class T>
 List<T>::swap (List& x)
 {
   List * temp=this;
   *this=x;
   x=*temp;

 }
 template <class T>
 List<T>::clear() noexcept
 {
   node<T>* temp_node =head;
  node<T>* prev_node;
    while(temp_node != NULL)
        {
      prev_node=temp_node;
      temp_node=temp_node->next;
      delete prev_node;
  }
  curr_size=0;
  head =NULL;
 }
template <class T>
 List<T>:: print()
 {
     node<T> * temp =head;
     while(temp!=NULL)
     {
       cout<<temp->data<<endl;
       temp=temp->next;
     }
 }
template <class T>
 List<T>:: push_front (const T& val)
 {
node<T>* new_node =new node<T>();
     new_node->data = val;
     curr_size++;
     if(head ==NULL)
        {

            new_node->next=NULL;
            new_node->prev =NULL;
            head=new_node;
            tail=new_node;
        }
      else{

            new_node->next=head;
            new_node->prev=NULL;
            head =new_node;
      }
 }
template <class T>
 List<T>::pop_front ()
 {
     node<T>* temp_node =head;
    curr_size--;
     if(head ==NULL)
        {

            throw string("Error: list is empty");
        }
    else if(head ==tail)
        {
            delete (temp_node);
            head =NULL;
            tail=NULL;
        }
      else{

            head =head->next;
            head->prev=NULL;
            delete (temp_node);
      }
 }
//for comman template class issue in c++//
template class List<int>;
template class List<float>;
template class List<double>;
template class List<long>;
template class List<string>;
