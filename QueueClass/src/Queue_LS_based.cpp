#include "Queue_LS_based.h"
#include <iostream>

using namespace std;
template <class T>
Queue<T>::Queue()
{
    head=NULL;
    tail=NULL;
    curr_capacity=0;
}
template <class T>
Queue<T>::~Queue()
{
    //dtor
}
template <class T>
Queue<T>::Queue(const Queue& other)
{
    //copy ctor
}
template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

template <class T>
Queue<T>::push(T val)
{
    node<T> *new_node =new node<T>();
    new_node->data =val;
    curr_capacity++;
    if(head ==NULL)
    {
        head=new_node;
        tail=new_node;
    }
    else{

        tail->next=new_node;
        new_node->prev=tail;
        tail =new_node;
    }
}
template <class T>
Queue<T>::pop()
{
 node<T>* temp_node=head;
    if(head ==NULL)
    {
       throw string("ERROR :queue is empty");
    }
curr_capacity--;
    if(head==tail)
    {
        delete temp_node;
        head=tail=NULL;
    }
    else{

        head=head->next;
        head->prev=NULL;
        delete temp_node;
    }
}
template <class T>
T Queue<T>:: front()
{
    if(head ==NULL)
    return (T)0;
    else
    return head->data;
}
template <class T>
T Queue<T>:: back()
{
    if(tail ==NULL)
    return (T)0;
    else
    return tail->data;
}
template <class T>
bool Queue<T>::empty()
{
    if(curr_capacity==0)
        return true ;
    else
        return false;
}
template <class T>
int Queue<T>::size()
{
    return curr_capacity;
}
template <class T>
Queue<T>::swap(Queue& other)
{
    node<T> *temp =head;
    head =other.head;
    other.head=temp;
}
template class Queue<int>;
template class Queue<float>;
template class Queue<double>;
template class Queue<long>;
template class Queue<string>;
