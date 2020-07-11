#include "Stack_LS_based.h"
#include <iostream>
#include <string>
using namespace std;
template <class T>
Stack<T>::Stack()
{
    head=NULL;
    capacity=0;
}
template <class T>
Stack<T>::~Stack()
{
      while(head != NULL)
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
          while(head != NULL)
         {
             pop();
         }
          return *this;
        }

}
  template <class T>
Stack<T>::push(T val)
{
    node<T>* new_node =new node<T>();
    new_node->data =val;
    capacity++;
    if(head ==NULL)
    {
        head=new_node;
    }
    else{

        new_node->next=head;
        head=new_node;
    }
}
  template <class T>
Stack<T>::pop()
{
    if(head ==NULL)
    {
        throw string("Error: stack is not empty.");
    }

    node<T>* temp_node =head;
    capacity--;
     if(head->next ==NULL)
     {
         delete (temp_node);
         head=NULL;
     }
     else{

        head = head-> next;
       delete temp_node;
     }
}
template <class T>
T Stack<T>:: top()
{
    return head->data;
}

template <class T>
Stack<T>::empty()
{
    if(head==NULL)
        return true;
    else
        return false;
}
template <class T>
int Stack<T>:: size()
{
    return capacity;
}
template <class T>
Stack<T>::swap( Stack& other)
{
     node<T>* temp_node =head;
     head =other.head;
     other.head=temp_node;
}
//for comman template class issue in c++//
template class Stack<int>;
template class Stack<float>;
template class Stack<double>;
template class Stack<long>;
//template class Stack<string>;
